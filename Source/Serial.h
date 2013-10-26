//SerialPort.h
/*Serial port class for accessing serial ports in an asyncronous buffered manner

contributed by graffiti
 
Updated for current Juce API 8/1/12 Marc Lindahl



a typical serialport scenario may be:
{
	//get a list of serial ports installed on the system, as a StringPairArray containing a friendly name and the port path
	StringPairArray portlist = SerialPort::getSerialPortPaths();
	if(portlist.size())
	{
		//open the first port on the system
		SerialPort * pSP = new SerialPort(portlist.getAllValues()[0], SerialPortConfig(9600, 8, SerialPortConfig::SERIALPORT_PARITY_NONE, SerialPortConfig::STOPBITS_1, SerialPortConfig::FLOWCONTROL_NONE));
		if(pSP->exists())
		{
			//create streams for reading/writing
			SerialPortOutputStream * pOutputStream = new SerialPortOutputStream(pSP);
			SerialPortInputStream * pInputStream = new SerialPortInputStream(pSP);

			pOutputStream->write("hello world via serial", 22); //write some bytes

			//read chars one at a time:
			char c;
			while(!pInputStream->isExhausted())
				pInputStream->read(&c, 1);

			//or, read line by line:
			String s;
			while(pInputStream->canReadLine())
				s = pInputStream->readNextLine();

			//or ask to be notified when a new line is available:
			pInputStreams->addChangeListener(this); //we must be a ChangeListener to receive notifications
			pInputStream->setNotify(SerialPortInputStream::NOTIFY_ON_CHAR, '\n');

			//or ask to be notified whenever any character is received
			//NOTE - use with care at high baud rates!!!!
			pInputStream->setNotify(SerialPortInputStream::NOTIFY_ALWAYS);

			//please see class definitions for other features/functions etc		
		}
	}
}
*/
#ifndef _SERIALPORT_H_
#define _SERIALPORT_H_

#include "../JuceLibraryCode/JuceHeader.h"
#include "../../../../juce/modules/juce_core/maths/juce_MathsFunctions.h"

class SerialPortConfig
{
public:
	SerialPortConfig(){};
	~SerialPortConfig(){};
	enum SerialPortStopBits{STOPBITS_1, STOPBITS_1ANDHALF, STOPBITS_2};
	enum SerialPortFlowControl{FLOWCONTROL_NONE, FLOWCONTROL_HARDWARE, FLOWCONTROL_XONXOFF};
	enum SerialPortParity{SERIALPORT_PARITY_NONE, SERIALPORT_PARITY_ODD, SERIALPORT_PARITY_EVEN, SERIALPORT_PARITY_SPACE, SERIALPORT_PARITY_MARK};
	SerialPortConfig(uint32 bps, uint32 databits, SerialPortParity parity, SerialPortStopBits stopbits, SerialPortFlowControl flowcontrol)
		:bps(bps), databits(databits), parity(parity), stopbits(stopbits), flowcontrol(flowcontrol)
	{}
	uint32 bps;
	uint32 databits;
	SerialPortParity parity;
	SerialPortStopBits stopbits;
	SerialPortFlowControl flowcontrol;
};

class SerialPort
{
public:
	SerialPort()
	{
		portHandle = 0;
		portDescriptor = -1;
	}
	SerialPort(const String & portPath)
	{
		SerialPort();
		open(portPath);
	}
	SerialPort(const String & portPath, const SerialPortConfig & config)
	{
		SerialPort();
		open(portPath);
		setConfig(config);
	}
	~SerialPort()
	{
		close();
	}
	bool open(const String & portPath);
	void close();
	bool setConfig(const SerialPortConfig & config);
	bool getConfig(SerialPortConfig & config);
	String getPortPath(){return portPath;}
	static StringPairArray getSerialPortPaths();
	bool exists();
	juce_UseDebuggingNewOperator
private:
	friend class SerialPortInputStream;
	friend class SerialPortOutputStream;
	void * portHandle;
	int portDescriptor;
	String portPath;
};

class SerialPortInputStream : public InputStream, public ChangeBroadcaster, private Thread
{
public:
    SerialPortInputStream(SerialPort * port)
    :port(port),bufferedbytes(0), notify(NOTIFY_OFF), notifyChar(0), Thread("SerialInThread")
	{
		startThread();
	}
	~SerialPortInputStream()
	{
		signalThreadShouldExit();
		waitForThreadToExit(500);
	}
	enum notifyflag{NOTIFY_OFF=0, NOTIFY_ON_CHAR, NOTIFY_ALWAYS};
	void setNotify(notifyflag notify=NOTIFY_ON_CHAR, char c=0)
	{
		notifyChar = c;
		this->notify = notify;
	}
	bool canReadString()
	{
		const ScopedLock l(bufferCriticalSection);
		int iNdx=0;
		while(iNdx<bufferedbytes)
			if(buffer[iNdx++]==0)return true;
		return false;
	}
	bool canReadLine()
	{
		const ScopedLock l(bufferCriticalSection);
		int iNdx=0;
		while(iNdx<bufferedbytes)
			if( (buffer[iNdx++]=='\n') /*|| (buffer[iNdx++]=='\r')*/)
				return true;
		return false;
	}
	virtual void run();
	virtual int read(void *destBuffer, int maxBytesToRead);
	virtual String readNextLine() //have to override this, because InputStream::readNextLine isn't compatible with SerialPorts (uses setPos)
	{
		String s;
		char c;
		s.preallocateBytes(32);
		while(read(&c, 1) && (c!='\n'))
			s.append(String::charToString(c), 1);
		s = s.trim();
		return s;
	}
	virtual int64 getTotalLength()
	{
		const ScopedLock l(bufferCriticalSection);
		return bufferedbytes;
	};
	virtual bool isExhausted()
	{
		const ScopedLock l(bufferCriticalSection);
		return bufferedbytes?false:true;
	};
	virtual int64 getPosition(){return -1;}
	virtual bool setPosition(int64 newPosition){return false;}
private:
	SerialPort * port;
	int bufferedbytes;
	MemoryBlock buffer;
	CriticalSection bufferCriticalSection;
	notifyflag notify;
	char notifyChar;
};

class SerialPortOutputStream : public OutputStream, private Thread
{
public:
    SerialPortOutputStream(SerialPort * port)
    :port(port),bufferedbytes(0), Thread("SerialOutThread")
	{
		startThread();
	}
	~SerialPortOutputStream()
	{
		signalThreadShouldExit();
		waitForThreadToExit(500);
	}
	virtual void run();
	virtual void flush(){}
	virtual bool setPosition(int64 newPosition){return false;}
	virtual int64 getPosition(){return -1;}
	virtual bool write(const void *dataToWrite, size_t howManyBytes);
private:
	SerialPort * port;
	int bufferedbytes;
	MemoryBlock buffer;
	CriticalSection bufferCriticalSection;
	WaitableEvent triggerWrite;
	static const uint32 writeBufferSize=128;
};
#endif //_SERIALPORT_H_
