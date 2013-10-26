//win32_SerialPort.cpp
//Serial Port classes in a Juce stylee, by graffiti
//see SerialPort.h for details
//
// Updated for current Juce API 8/1/13 Marc Lindahl
//

#include "../JuceLibraryCode/JuceHeader.h"

#if WIN32

#include <windows.h>
#include <stdio.h>

//the enumneration functions require Setupapi.lib and Setupapi.dll
//- if this dependency is not wanted, undef USE_SETUPAPI, and the 
//SerialPort::getSerialPortPaths() will simply return an empty StringPairArray
#define USE_SETUPAPI
#ifdef USE_SETUPAPI
#include <setupapi.h>
#include <devguid.h>
#include <regstr.h>
// The following define is from ntddser.h in the DDK. It is
// needed for serial port enumeration.
#ifndef GUID_CLASS_COMPORT
DEFINE_GUID(GUID_CLASS_COMPORT, 0x86e0d1e0L, 0x8089, 0x11d0, 0x9c, 0xe4, \
			0x08, 0x00, 0x3e, 0x30, 0x1f, 0x73);
#endif
#endif

#include "Serial.h"

StringPairArray SerialPort::getSerialPortPaths()
{
	StringPairArray SerialPortPaths;
#ifdef USE_SETUPAPI
	HDEVINFO hDevInfo;
    SP_DEVINFO_DATA DeviceInfoData;
	DeviceInfoData.cbSize = sizeof(SP_DEVINFO_DATA);
	DWORD dwDetDataSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA) + 256;
	SP_DEVICE_INTERFACE_DETAIL_DATA *pDetData = (SP_DEVICE_INTERFACE_DETAIL_DATA*) new char[dwDetDataSize];
	pDetData->cbSize = sizeof(SP_DEVICE_INTERFACE_DETAIL_DATA);
	SP_DEVICE_INTERFACE_DATA ifcData;
	ifcData.cbSize = sizeof(SP_DEVICE_INTERFACE_DATA);
    DWORD i;
	GUID *guidDev = (GUID*) &GUID_CLASS_COMPORT;
    if(INVALID_HANDLE_VALUE == (hDevInfo = SetupDiGetClassDevs(guidDev, 0, 0, DIGCF_PRESENT | DIGCF_DEVICEINTERFACE )))
    {
		DBG("SerialPort::getSerialPortPaths :: SetupDiGetClassDevs failed");
		return SerialPortPaths;
    }
    for (i=0;SetupDiEnumDeviceInfo(hDevInfo,i,&DeviceInfoData);i++)
    {
        DWORD DataT;
        char buffer[1024];
        DWORD buffersize = 1024;
		DWORD buffersizerequired=0;		
		SetupDiEnumDeviceInterfaces(hDevInfo, NULL, guidDev, i, &ifcData);
		SetupDiGetDeviceInterfaceDetail(hDevInfo, &ifcData, pDetData, dwDetDataSize, NULL, &DeviceInfoData);
		SetupDiGetDeviceRegistryProperty(hDevInfo, &DeviceInfoData, SPDRP_FRIENDLYNAME, &DataT, (PBYTE)buffer, buffersize, &buffersizerequired);
		SerialPortPaths.set(buffer, pDetData->DevicePath);		
    }
    SetupDiDestroyDeviceInfoList(hDevInfo);
	delete[] pDetData;
#endif// USE_SETUPAPI
	return SerialPortPaths;
}
void SerialPort::close()
{
	if(portHandle)
	{
		CloseHandle(portHandle);
		portHandle = 0;
	}
}
bool SerialPort::exists()
{
	return portHandle?true:false;
}
bool SerialPort::open(const String & portPath)
{
	this->portPath = portPath;
	portHandle = CreateFile( (LPCSTR)portPath.toUTF8(), GENERIC_READ | GENERIC_WRITE, 0, NULL, OPEN_EXISTING, FILE_FLAG_OVERLAPPED, NULL);
	if(portHandle == INVALID_HANDLE_VALUE)
	{
		//DBG_PRINTF((T("(SerialPort::open) CreateFile failed with error %d.\n"), GetLastError()));
		portHandle = 0;
		return false;
	}
	COMMTIMEOUTS commTimeout;
	if(GetCommTimeouts(portHandle, &commTimeout))
	{
		commTimeout.ReadIntervalTimeout = MAXDWORD;
		commTimeout.ReadTotalTimeoutConstant = 0;
		commTimeout.ReadTotalTimeoutMultiplier = 0;
		commTimeout.WriteTotalTimeoutConstant = 0;
		commTimeout.WriteTotalTimeoutMultiplier = 0;
	}
	else
		DBG("GetCommTimeouts error");
	if(!SetCommTimeouts(portHandle, &commTimeout))
		DBG("SetCommTimeouts error");

	if(!SetCommMask(portHandle,EV_RXCHAR))
		DBG("SetCommMask error");

	return true;
}
bool SerialPort::setConfig(const SerialPortConfig & config)
{
	if(!portHandle)return false;
	DCB dcb;
	memset(&dcb, 0, sizeof(DCB));
	dcb.DCBlength = sizeof(DCB);
	dcb.fBinary = 1;
	dcb.XonLim = 2048;
	dcb.XoffLim = 512;
	dcb.BaudRate = config.bps;
	dcb.ByteSize = config.databits;
	dcb.fParity = true;
	switch(config.parity)
	{
	case SerialPortConfig::SERIALPORT_PARITY_ODD:
		dcb.Parity = ODDPARITY;
		break;
	case SerialPortConfig::SERIALPORT_PARITY_EVEN:
		dcb.Parity = EVENPARITY;
		break;
	case SerialPortConfig::SERIALPORT_PARITY_MARK:
		dcb.Parity = MARKPARITY;
		break;
	case SerialPortConfig::SERIALPORT_PARITY_SPACE:
		dcb.Parity = SPACEPARITY;
		break;
	case SerialPortConfig::SERIALPORT_PARITY_NONE:
	default:
		dcb.Parity = NOPARITY;
		dcb.fParity = false;
		break;
	}
	switch(config.stopbits)
	{
	case SerialPortConfig::STOPBITS_1:
	default:
		dcb.StopBits = ONESTOPBIT;
		break;
	case SerialPortConfig::STOPBITS_1ANDHALF:
		dcb.StopBits = ONE5STOPBITS;
		break;
	case SerialPortConfig::STOPBITS_2:
		dcb.StopBits = TWOSTOPBITS;
		break;
	}
	switch(config.flowcontrol)
	{
	case SerialPortConfig::FLOWCONTROL_XONXOFF:
		dcb.fOutxCtsFlow = 0;
		dcb.fOutxDsrFlow = 0;
		dcb.fDtrControl = DTR_CONTROL_ENABLE;
		dcb.fOutX = 1;
		dcb.fInX = 1;
		dcb.fRtsControl = RTS_CONTROL_ENABLE;
		break;
	case SerialPortConfig::FLOWCONTROL_HARDWARE:
		dcb.fOutxCtsFlow = 1;
		dcb.fOutxDsrFlow = 1;
		dcb.fDtrControl = DTR_CONTROL_HANDSHAKE;
		dcb.fOutX = 0;
		dcb.fInX = 0;
		dcb.fRtsControl = RTS_CONTROL_HANDSHAKE;
		break;
	case SerialPortConfig::FLOWCONTROL_NONE:
	default:
		dcb.fOutxCtsFlow = 0;
		dcb.fOutxDsrFlow = 0;
		dcb.fDtrControl = DTR_CONTROL_ENABLE;
		dcb.fOutX = 0;
		dcb.fInX = 0;
		dcb.fRtsControl = RTS_CONTROL_ENABLE;
		break;
	}
	return (SetCommState(portHandle, &dcb)?true:false);
}
bool SerialPort::getConfig(SerialPortConfig & config)
{
	if(!portHandle)return false;
	DCB dcb;
	if(!GetCommState(portHandle, &dcb))
		return false;
	config.bps = dcb.BaudRate;
	config.databits = dcb.ByteSize;
	switch(dcb.Parity)
	{
	case ODDPARITY:
		config.parity = SerialPortConfig::SERIALPORT_PARITY_ODD;
		break;
	case EVENPARITY:
		config.parity = SerialPortConfig::SERIALPORT_PARITY_EVEN;
		break;
	case MARKPARITY:
		config.parity = SerialPortConfig::SERIALPORT_PARITY_MARK;
		break;
	case SPACEPARITY:
		config.parity = SerialPortConfig::SERIALPORT_PARITY_SPACE;
		break;
	case NOPARITY:
	default:
		config.parity = SerialPortConfig::SERIALPORT_PARITY_NONE;
		break;
	}
	switch(dcb.StopBits)
	{
	case ONESTOPBIT:
	default:
		config.stopbits = SerialPortConfig::STOPBITS_1;
		break;
	case ONE5STOPBITS:
		config.stopbits = SerialPortConfig::STOPBITS_1ANDHALF;
		break;
	case TWOSTOPBITS:
		config.stopbits = SerialPortConfig::STOPBITS_2;
		break;
	}
	if(dcb.fOutX && dcb.fInX)
		config.flowcontrol=SerialPortConfig::FLOWCONTROL_XONXOFF;
	else if((dcb.fDtrControl == DTR_CONTROL_HANDSHAKE) && (dcb.fRtsControl == RTS_CONTROL_HANDSHAKE))
		config.flowcontrol=SerialPortConfig::FLOWCONTROL_HARDWARE;
	else
		config.flowcontrol=SerialPortConfig::FLOWCONTROL_NONE;
	return true;
}
/////////////////////////////////
// SerialPortInputStream
/////////////////////////////////
void SerialPortInputStream::run()
{
	DWORD dwEventMask=0;
	//overlapped structure for the wait
	OVERLAPPED ov;
	memset(&ov,0,sizeof(ov));
	ov.hEvent = CreateEvent( 0,true,0,0);
	//overlapped structure for the read
	OVERLAPPED ovRead;
	memset(&ovRead,0,sizeof(ovRead));
	ovRead.hEvent = CreateEvent( 0,true,0,0);
	while(port && port->portHandle && !threadShouldExit())
	{
		unsigned char c;
		DWORD bytesread=0;
		WaitCommEvent(port->portHandle,&dwEventMask, &ov);
		if(WAIT_OBJECT_0==WaitForSingleObject(ov.hEvent, 100))
		{
			DWORD dwMask;
			if (GetCommMask(port->portHandle,&dwMask) )
			{
				if ( dwMask & EV_RXCHAR )
				{
					do
					{
						ResetEvent( ovRead.hEvent  );
						ReadFile(port->portHandle,&c,1,&bytesread,&ov);
						if(bytesread==1)
						{
							const ScopedLock l(bufferCriticalSection);
							buffer.ensureSize(bufferedbytes+1);
							buffer[bufferedbytes]=c;
							bufferedbytes++;
							if(notify==NOTIFY_ALWAYS||((notify==NOTIFY_ON_CHAR) && (c == notifyChar)))
								sendChangeMessage();
						}
					}while(bytesread);	
				}
			}
			ResetEvent ( ov.hEvent );
		}
	}
	CloseHandle(ovRead.hEvent);
	CloseHandle(ov.hEvent);
}
int SerialPortInputStream::read(void *destBuffer, int maxBytesToRead)
{
	const ScopedLock l(bufferCriticalSection);
	if(maxBytesToRead>bufferedbytes)maxBytesToRead=bufferedbytes;
	memcpy(destBuffer, buffer.getData(), maxBytesToRead);
	buffer.removeSection(0,maxBytesToRead);
	bufferedbytes-=maxBytesToRead;
	return maxBytesToRead;
}
/////////////////////////////////
// SerialPortInputStream
/////////////////////////////////
void SerialPortOutputStream::run()
{
	unsigned char tempbuffer[writeBufferSize];
	OVERLAPPED ov;
	memset(&ov,0,sizeof(ov));
	ov.hEvent = CreateEvent( 0,true,0,0);
	while(port && port->portHandle && !threadShouldExit())
	{
		if(!bufferedbytes)
			triggerWrite.wait(100);
		if(bufferedbytes)
		{
			DWORD byteswritten=0;
			bufferCriticalSection.enter();
			DWORD bytestowrite=bufferedbytes>writeBufferSize?writeBufferSize:bufferedbytes;
			memcpy(tempbuffer, buffer.getData(), bytestowrite);
			bufferCriticalSection.exit();
			ResetEvent ( ov.hEvent );
			int iRet = WriteFile(port->portHandle,tempbuffer,bytestowrite,&byteswritten,&ov);
			if ( iRet == 0 )
			{
				WaitForSingleObject(ov.hEvent, INFINITE);
			}
			GetOverlappedResult(port->portHandle,&ov,&byteswritten,TRUE);
			if(byteswritten)
			{
				const ScopedLock l(bufferCriticalSection);
				buffer.removeSection(0, byteswritten);
				bufferedbytes-=byteswritten;
			}
		}
	}
	CloseHandle(ov.hEvent);
}
bool SerialPortOutputStream::write(const void *dataToWrite, size_t howManyBytes)
{
	bufferCriticalSection.enter();
	buffer.append(dataToWrite, howManyBytes);
	bufferedbytes+=howManyBytes;
	bufferCriticalSection.exit();
	triggerWrite.signal();
	return true;
}

#endif // JUCE_WIN
