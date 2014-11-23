// **************************************************************************
//     Filename: COMMANDS.H
// Date Created: 8/23/2013
//      Version: 0.01
//
//
//  COPYRIGHT (c) Robertsonics 2013. All Rights Reserved
//
// **************************************************************************

#ifndef COMMANDS_H_INCLUDED
#define COMMANDS_H_INCLUDED


enum {
	TRACK_CONTROL_PLAY_SOLO,
	TRACK_CONTROL_PLAY_POLY,
	TRACK_CONTROL_PAUSE,
	TRACK_CONTROL_RESUME,
	TRACK_CONTROL_STOP,
	TRACK_CONTROL_LOOP_ON,
	TRACK_CONTROL_LOOP_OFF
};


enum {
	GET_VERSION = 0x01,
    GET_SYS_INFO,
	CONTROL_TRACK,
	STOP_ALL,
	VOLUME,
	TRIGGER_SET,
	GET_STATUS,
	TRACK_VOLUME,
	AMP_POWER,
	TRACK_FADE,
	RESUME_ALL_SYNC,
	SAMPLERATE_OFFSET
};

enum {
	VERSION_STRING = 0x81,
	SYSTEM_INFO,
	CMD_STATUS
};


#endif  // COMMANDS_H_INCLUDED
