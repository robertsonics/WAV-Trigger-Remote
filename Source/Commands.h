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
	GET_VERSION = 0x01,
    GET_SYS_INFO,
	PLAY_TRACK_SOLO,
	PLAY_TRACK_POLY,
	PAUSE_TRACK,
	STOP_TRACK,
	LOOP_TRACK_ON_OFF
};

enum {
	VERSION_STRING = 0x81,
	SYSTEM_INFO
};


#endif  // COMMANDS_H_INCLUDED
