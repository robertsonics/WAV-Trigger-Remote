// **************************************************************************
//     Filename: COMMUNICATOR.CPP
// Date Created: 8/23/2013
//      Version: 0.01
//
//
//  COPYRIGHT (c) Robertsonics 2013. All Rights Reserved
//
// **************************************************************************
//
// Revision History
//
// Date/Rev  Description
// --------  -----------
//
// V0.01     First version created.
// 8/23/13


#include "Communicator.h"
#include "Serial.h"


// **************************************************************************
// run
void Communicator::run() {

	// Connect
	m_State = DLSTATE_CONNECTING;
	sendChangeMessage();
	sleep(1000);
	if (!connect()) {
		m_State = DLSTATE_ERROR_CONNECT;
		sendChangeMessage();
		sleep(1000);
		return;
	}

	// Erase
	m_State = DLSTATE_ERASING;
	sendChangeMessage();
	sleep(1000);
	if (!erase()) {
		m_State = DLSTATE_ERROR_ERASE;
		sendChangeMessage();
		sleep(1000);
		return;
	}

	// Program
	m_State = DLSTATE_PROGRAMMING_0;
	sendChangeMessage();
	sleep(1000);
	if (!program()) {
		m_State = DLSTATE_ERROR_PROGRAM;
		sendChangeMessage();
		sleep(1000);
		return;
	}
	m_State = DLSTATE_DONE;
	sendChangeMessage();
	sleep(1000);

	return;
}


// **************************************************************************
// openPort
bool Communicator::openPort( String portName )
{

#if WIN32

String portID;

	int i = portName.indexOf("COM");
	if (i >= 0) {
		portID = portName.substring(i, i+5);
		if (portID.contains(")"))
			portID = portID.substring(0, 4);
	}
	pSP = new SerialPort(portID, SerialPortConfig(57600, 8, SerialPortConfig::SERIALPORT_PARITY_EVEN, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));

#else

	pSP = new SerialPort(portName, SerialPortConfig(57600, 8, SerialPortConfig::SERIALPORT_PARITY_EVEN, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));

#endif

	if (pSP->exists())
	{
		// Create streams for reading/writing
		pOutStream = new SerialPortOutputStream(pSP);
		pInStream = new SerialPortInputStream(pSP);
		m_portOpenFlag = true;
		return true;
	}
	else {
		pOutStream = nullptr;
		pInStream = nullptr;
		m_portOpenFlag = false;
		return false;
	}
}


// **************************************************************************
// closePort
void Communicator::closePort(void)
{

	if (pOutStream != nullptr) {
		delete pOutStream;
		pOutStream = nullptr;
	}
	if (pInStream != nullptr) {
		delete pInStream;
		pInStream = nullptr;
	}
	if (pSP != nullptr) {
		pSP->close();
		pSP = nullptr;
	}
	m_portOpenFlag = false;
}


// **************************************************************************
// getVersion
bool Communicator::getVersion(String *pStrVersion) {

unsigned char xbuf[64];
unsigned char rbuf[64];

	// Send the WAV Trigger version string command
	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x01;
	xbuf[3] = 0x55;
	flushReceiver();
	pOutStream->write(xbuf, 4);
	if (!readBytes(rbuf, 16, 500))
		return false;
	if (rbuf[0] != 0x55)
		return false;

	return true;

}

// **************************************************************************
// setFile
void Communicator::setFile(File f)
{

	hexFile = f;
	m_hexFileSelectedFlag = true;
}


// **************************************************************************
// connect
bool Communicator::connect(void)
{

int retries = 0;
bool contact = false;
unsigned char xbuf[64];
unsigned char rbuf[64];
int cnt;

	// Flush the input buffer
	flushReceiver();
	for (retries = 0; retries < 64; retries++)
		rbuf[retries] = 0;
	retries = 0;

	// Send the initial contact command and wait for the response
	xbuf[0] = 0x7f;
	do {
		pOutStream->write(xbuf, 1);
		if (readBytes(rbuf, 1, 250)) {
			if (rbuf[0] == 0x79)
				contact = true;
		}			
	} while ((retries++ < 50) && (!contact));

	// If max number of retries, return failure
	if (!contact)
		return false;

	// Send the version command to determine the correct erase command
	xbuf[0] = 0x00;
	xbuf[1] = 0xff;
	flushReceiver();
	pOutStream->write(xbuf, 2);
	if (!readBytes(rbuf, 2, 250))
		return false;
	if (rbuf[0] != 0x79)
		return false;
	cnt = rbuf[1];
	if (cnt > 64)
		return false;
	if (!readBytes(rbuf, cnt, 250))
		return false;

	// TODO: May want to save and display version number
	// TODO: May want to confirm erase command

	return true;
}


// **************************************************************************
// erase
bool Communicator::erase(void)
{

unsigned char xbuf[8];
unsigned char rbuf[64];

	// Send the write unprotect command
	//xbuf[0] = 0x73;
	//xbuf[1] = 0x8c;
	//flushReceiver();
	//pOutStream->write(xbuf, 2);
	//if (!readBytes(rbuf, 1, 250))
	//	return false;
	//if (rbuf[0] != 0x79)
	//	return false;

	// Send the extended erase command
	xbuf[0] = 0x44;
	xbuf[1] = 0xbb;
	flushReceiver();
	pOutStream->write(xbuf, 2);
	if (!readBytes(rbuf, 1, 500))
		return false;
	if (rbuf[0] != 0x79)
		return false;

	xbuf[0] = 0xff;
	xbuf[1] = 0xff;
	xbuf[2] = 0x00;
	flushReceiver();
	pOutStream->write(xbuf, 3);
	if (!readBytes(rbuf, 1, 30000))
		return false;
	if (rbuf[0] != 0x79)
		return false;

	return true;

}


// **************************************************************************
// program
bool Communicator::program(void)
{

unsigned char xbuf[8];
unsigned char rbuf[8];
unsigned char dbuf[258];
StringArray hexRecords;
String rec;
String subrec;
int numRecords;
int i, j, n;
int recSize;
int recAddress;
int recType;
int numBytes;
unsigned char bDat;
unsigned char bChk;

	hexFile.readLines(hexRecords);
	numRecords = hexRecords.size();
	numBytes = 0;
	for (i = 0; i < 256; i++)
		dbuf[i] = 0;

	for (n = 0; n < numRecords; n++) {

		if (n == 100) {
			m_State = DLSTATE_PROGRAMMING_1;
			sendChangeMessage();
		}
		else if (n == 200) {
			m_State = DLSTATE_PROGRAMMING_2;
			sendChangeMessage();
		}
		else if (n == 300) {
			m_State = DLSTATE_PROGRAMMING_3;
			sendChangeMessage();
		}
		else if (n == 400) {
			m_State = DLSTATE_PROGRAMMING_4;
			sendChangeMessage();
		}
		else if (n == 500) {
			m_State = DLSTATE_PROGRAMMING_5;
			sendChangeMessage();
		}
		else if (n == 600) {
			m_State = DLSTATE_PROGRAMMING_6;
			sendChangeMessage();
		}
		else if (n == 700) {
			m_State = DLSTATE_PROGRAMMING_7;
			sendChangeMessage();
		}
		else if (n == 800) {
			m_State = DLSTATE_PROGRAMMING_8;
			sendChangeMessage();
		}
		else if (n == 900) {
			m_State = DLSTATE_PROGRAMMING_9;
			sendChangeMessage();
		}

		rec = hexRecords[n];
		if (rec.length() > 0) {

			if (rec[0] != ':')
				return false;
			subrec = rec.substring(1, 3);
			recSize = subrec.getHexValue32();
			subrec = rec.substring(3, 7);
			recAddress = subrec.getHexValue32();
			subrec = rec.substring(7, 9);
			recType = subrec.getHexValue32();

			switch (recType) {

				case 00:
					numBytes = 0;
					for (i = 0; i < 256; i++)
						dbuf[i] = 0;
					for (j = 0; j < recSize; j++) {
						subrec = rec.substring( (9 + (j*2)), (11 + (j*2)));
						bDat = (unsigned char)subrec.getHexValue32();
						dbuf[1 + numBytes++] = bDat;
					}

					// Send the Write Memory command
					xbuf[0] = 0x31;
					xbuf[1] = 0xce;
					flushReceiver();
					pOutStream->write(xbuf, 2);
					if (!readBytes(rbuf, 1, 500))
						return false;
					if (rbuf[0] != 0x79)
						return false;

					// Send the start address
					xbuf[0] = 0x08;
					xbuf[1] = 0x00;
					xbuf[2] = (recAddress >> 8) & 0xff;
					xbuf[3] = recAddress & 0xff;
					xbuf[4] = calcChecksum(xbuf, 4);
					flushReceiver();
					pOutStream->write(xbuf, 5);
					if (!readBytes(rbuf, 1, 500))
						return false;
					if (rbuf[0] != 0x79)
						return false;

					// Send the byte count - 1
					flushReceiver();
					dbuf[0] = (unsigned char)(numBytes - 1);
					pOutStream->write(dbuf, 1);

					// Now send the data
					bChk = calcChecksum(dbuf, numBytes + 1);
					pOutStream->write(&dbuf[1], numBytes);

					// Send the checksum and wait for an ACK
					xbuf[0] = bChk;
					pOutStream->write(xbuf, 1);
					if (!readBytes(rbuf, 1, 1000))
						return false;
					if (rbuf[0] != 0x79)
						return false;

				break;

				case 04:
				break;

			} // switch (recType) {

		} // if (rec.length() > 0) 

	} // for (n = 0; n < numRecords; n++)

	return true;

}


// **************************************************************************
// Flush receiver
void Communicator::flushReceiver(void)
{

unsigned char rxDat;

	while(!pInStream->isExhausted())
		pInStream->read(&rxDat, 1);
}


// **************************************************************************
// CalcChecksum
unsigned char Communicator::calcChecksum(unsigned char *pBuf, int n)
{

int i;
unsigned char c;

	c = pBuf[0];
	for (i = 1; i < n; i++) {
		c = c ^ pBuf[i];
	}
	return c;



}


// **************************************************************************
// Read bytes
bool Communicator::readBytes(unsigned char *pBuf, int numBytes, int timeOut)
{

int64 now;

	pTime = new Time;
	now = pTime->currentTimeMillis();
	while ((pInStream->getTotalLength() < numBytes) && ((pTime->currentTimeMillis() - now) < timeOut));
	if (pInStream->getTotalLength() >= numBytes) {
		pInStream->read(pBuf, numBytes);
		delete pTime;
		return true;
	}
	delete pTime;
	return false;
}


// **************************************************************************
// Free state
Communicator::~Communicator()
{
	//delete pCt;
	stopThread (2000);
	
} // end Communicator::~Communicator()



