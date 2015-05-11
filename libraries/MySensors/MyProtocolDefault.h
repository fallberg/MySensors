/**
 * The MySensors Arduino library handles the wireless radio link and protocol
 * between your home built sensors/actuators and HA controller of choice.
 * The sensors forms a self healing radio network with optional repeaters. Each
 * repeater and gateway builds a routing tables in EEPROM which keeps track of the
 * network topology allowing messages to be routed to nodes.
 *
 * Created by Henrik Ekblad <henrik.ekblad@mysensors.org>
 * Copyright (C) 2013-2015 Sensnology AB
 * Full contributor list: https://github.com/mysensors/Arduino/graphs/contributors
 *
 * Documentation: http://www.mysensors.org
 * Support Forum: http://forum.mysensors.org
 *
 * This program is free software; you can redistribute it and/or
 * modify it under the terms of the GNU General Public License
 * version 2 as published by the Free Software Foundation.
 */

#ifndef MyProtocolDefault_h
#define MyProtocolDefault_h

#include "MyConfig.h"
#include "MyProtocol.h"
#include "MyTransport.h"

#define MAX_FORMAT_BUFFER_LENGTH 120 // Max buffersize when formatting messages


class MyProtocolDefault : public MyProtocol
{ 
public:
	MyProtocolDefault();
	bool parse(MyMessage &message, char *inputString);
	char *format(MyMessage &message);
private:
	char fmtBuffer[MAX_FORMAT_BUFFER_LENGTH];
	char convBuffer[MAX_PAYLOAD*2+1];

	uint8_t h2i(char c);
};
#endif
