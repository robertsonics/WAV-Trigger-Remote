// **************************************************************************
//     Filename: DOWNLOADER.H
// Date Created: 8/23/2013
//      Version: 0.01
//
//
//  COPYRIGHT (c) Robertsonics 2013. All Rights Reserved
//
// **************************************************************************

#ifndef __DOWN_H_3000605__
#define __DOWN_H_3000605__

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../../../juce/modules/juce_core/time/juce_Time.h"
#include "Serial.h"

#define DLSTATE_IDLE			0

#define DLSTATE_CONNECTING		1
#define DLSTATE_ERASING			2
#define DLSTATE_PROGRAMMING_0	3
#define DLSTATE_PROGRAMMING_1	4
#define DLSTATE_PROGRAMMING_2	5
#define DLSTATE_PROGRAMMING_3	6
#define DLSTATE_PROGRAMMING_4	7
#define DLSTATE_PROGRAMMING_5	8
#define DLSTATE_PROGRAMMING_6	9
#define DLSTATE_PROGRAMMING_7	10
#define DLSTATE_PROGRAMMING_8	11
#define DLSTATE_PROGRAMMING_9	12
#define DLSTATE_DONE			13

#define DLSTATE_ERROR_CONNECT	20
#define DLSTATE_ERROR_ERASE		21
#define DLSTATE_ERROR_PROGRAM	22

class Downloader : public Thread, public ChangeBroadcaster {

public:
	Downloader() : Thread ("Downloader Thread") {
		m_State = DLSTATE_IDLE;
		m_portOpenFlag = false;
		m_hexFileSelectedFlag = false;
		pSP = nullptr;
		pInStream = nullptr;
		pOutStream = nullptr;
	}
	~Downloader();
	void run();
	bool openPort(String portName);
	void closePort(void);
	void setFile(File hexFile);
	int getState()				{ return m_State; }
	bool isPortOpen()			{ return m_portOpenFlag; }
	bool isHexFileSelected()	{ return m_hexFileSelectedFlag; }
			
private:

	bool connect(void);
	bool erase(void);
	bool program(void);

	bool readBytes (unsigned char *pBuf, int numBytes, int timeOut);
	void flushReceiver(void);
	unsigned char calcChecksum(unsigned char *pBuf, int n);

	SerialPort *pSP;
	SerialPortOutputStream *pOutStream;
	SerialPortInputStream *pInStream;

	Time *pTime;
	File hexFile;

	int m_State;
	bool m_portOpenFlag;
	bool m_hexFileSelectedFlag;

}; // end class Downloader

#endif
