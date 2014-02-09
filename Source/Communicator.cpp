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
#include "Commands.h"


// **************************************************************************
// run
void Communicator::run() {

int i;
unsigned char rxDat;

	// Clear out our receive buffer
	for (i = 0; i < 1024; i++)
		m_rxBuff[i] = 0;
	m_rxPtr = 0;

	m_State = COMM_STARTED;
	sendChangeMessage();

	// Receive thread main loop
	while (!threadShouldExit()) {

		// Parse the input stream one byte at a time
		while (pInStream->getTotalLength() > 0) {
			pInStream->read((unsigned char *)&rxDat, 1);

			// If we're waiting for the header
			if ((m_rxPtr == 0) && (!m_msgReadyFlag)) {
				if (rxDat == 0xf0)
					m_rxPtr = 1;
			}
			else if (m_rxPtr == 1) {
				if (rxDat == 0xaa)
					m_rxPtr = 2;
				else
					m_rxPtr = 0;
			}

			// If this is the length
			else if (m_rxPtr == 2) {
				if ((rxDat > 0) && (rxDat < MAX_MESSAGE_LENGTH)) {
					m_rxLen = rxDat - 1;
					m_rxBuff[0] = (unsigned char)rxDat - 2;
					m_rxPtr = 3;
				}
				else
					m_rxPtr = 0;
			}

			// Otherwise save in local buffer until last byte
			else if (m_rxPtr > 2) {
				if (m_rxPtr == m_rxLen) {
					if (rxDat == 0x55) {
						m_msgReadyFlag = true;
						sendChangeMessage();
					}
					m_rxPtr = 0;
				}
				else {
					m_rxBuff[m_rxPtr - 2] = rxDat;
					if (++m_rxPtr >= MAX_MESSAGE_LENGTH)
						m_rxPtr = 0;
				}
			}
		}
		sleep(1);

	}

	m_State = COMM_STOPPED;
	sendChangeMessage();
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
		this->startThread();
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

	this->stopThread(2000);

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
// getDeviceInfo
bool Communicator::getDeviceInfo(void) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	// First, send the get version command
	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x05;
	xbuf[3] = GET_VERSION;
	xbuf[4] = 0x55;
	pOutStream->write(xbuf, 5);

	// Wait a bit...
	sleep(200);

	// Then send the get info command
	xbuf[3] = GET_SYS_INFO;
	pOutStream->write(xbuf, 5);
	return true;
}


// **************************************************************************
// getDeviceStatus
bool Communicator::getDeviceStatus(void) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x05;
	xbuf[3] = GET_STATUS;
	xbuf[4] = 0x55;
	pOutStream->write(xbuf, 5);
	return true;
}


// **************************************************************************
// stopAll
bool Communicator::stopAll(void) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x05;
	xbuf[3] = STOP_ALL;
	xbuf[4] = 0x55;
	pOutStream->write(xbuf, 5);
	return true;
}


// **************************************************************************
// stopAll
bool Communicator::volume(int iVol) {

unsigned char xbuf[8];
unsigned short uVal;

	if (pSP == nullptr)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x07;
	xbuf[3] = VOLUME;
	uVal = (unsigned short)iVol;
	xbuf[4] = (unsigned char)uVal;
	xbuf[5] = (unsigned short)(uVal >> 8);
	xbuf[6] = 0x55;
	pOutStream->write(xbuf, 7);
	return true;
}


// **************************************************************************
// controlTrack
bool Communicator::controlTrack(int mode, int trackNum) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	if (trackNum > 999)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x08;
	xbuf[3] = CONTROL_TRACK;
	xbuf[4] = (unsigned char)mode;
	xbuf[5] = (unsigned char)trackNum;
	xbuf[6] = (unsigned char)(trackNum >> 8);
	xbuf[7] = 0x55;
	pOutStream->write(xbuf, 8);
	return true;
}


// **************************************************************************
// trackVolume
bool Communicator::trackVolume(int trackNum, int iVol) {

unsigned char xbuf[8];
unsigned short uVal;

	if (pSP == nullptr)
		return false;

	if (trackNum > 999)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x09;
	xbuf[3] = TRACK_VOLUME;
	xbuf[4] = (unsigned char)trackNum;
	xbuf[5] = (unsigned char)(trackNum >> 8);
	uVal = (unsigned short)iVol;
	xbuf[6] = (unsigned char)uVal;
	xbuf[7] = (unsigned short)(uVal >> 8);
	xbuf[8] = 0x55;
	pOutStream->write(xbuf, 9);
	return true;
}


// **************************************************************************
// ampPower
bool Communicator::ampPower(bool ampState) {

unsigned char xbuf[8];

	if (pSP == nullptr)
		return false;

	xbuf[0] = 0xF0;
	xbuf[1] = 0xaa;
	xbuf[2] = 0x06;
	xbuf[3] = AMP_POWER;
	if (ampState)
		xbuf[4] = 0x01;
	else
		xbuf[4] = 0x00;
	xbuf[5] = 0x55;
	pOutStream->write(xbuf, 6);
	return true;
}


// **************************************************************************
// getMessage
int Communicator::getMessage(unsigned char * pDest) {

int dLen;

	dLen = (int)m_rxBuff[0];
	if (dLen >= MAX_MESSAGE_LENGTH)
		return 0;
	memcpy(pDest, &m_rxBuff[1], dLen);
	return dLen;

}


// **************************************************************************
// Read bytes
//bool Communicator::readBytes(unsigned char *pBuf, int numBytes, int timeOut)
//{
//
//int64 now;
//
//	pTime = new Time;
//	now = pTime->currentTimeMillis();
//	while ((pInStream->getTotalLength() < numBytes) && ((pTime->currentTimeMillis() - now) < timeOut));
//	if (pInStream->getTotalLength() >= numBytes) {
//		pInStream->read(pBuf, numBytes);
//		delete pTime;
//		return true;
//	}
//	delete pTime;
//	return false;
//}


// **************************************************************************
// Free state
Communicator::~Communicator()
{
	//delete pCt;
	stopThread (2000);
	
} // end Communicator::~Communicator()



