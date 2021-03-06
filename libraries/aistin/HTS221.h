/*
	HTS221.h - HTS221 library for Aistin ATMega
	
	This program is free software under the MIT License (MIT)

	Copyright 2015 iProtoXi Oy

	Permission is hereby granted, free of charge, to any person obtaining a copy
	of this software and associated documentation files (the "Software"), to deal
	in the Software without restriction, including without limitation the rights
	to use, copy, modify, merge, publish, distribute, sublicense, and/or sell
	copies of the Software, and to permit persons to whom the Software is
	furnished to do so, subject to the following conditions:

	The above copyright notice and this permission notice shall be included in all
	copies or substantial portions of the Software.

	THE SOFTWARE IS PROVIDED "AS IS", WITHOUT WARRANTY OF ANY KIND, EXPRESS OR
	IMPLIED, INCLUDING BUT NOT LIMITED TO THE WARRANTIES OF MERCHANTABILITY,
	FITNESS FOR A PARTICULAR PURPOSE AND NONINFRINGEMENT. IN NO EVENT SHALL THE
	AUTHORS OR COPYRIGHT HOLDERS BE LIABLE FOR ANY CLAIM, DAMAGES OR OTHER
	LIABILITY, WHETHER IN AN ACTION OF CONTRACT, TORT OR OTHERWISE, ARISING FROM,
	OUT OF OR IN CONNECTION WITH THE SOFTWARE OR THE USE OR OTHER DEALINGS IN THE
	SOFTWARE.
*/
#include "aistin.h"
#include <stdint.h>

#ifndef HTS221_h
#define HTS221_h

class HTS221 {
private:
	float RHf, RHc;
	float CTf, CTc;
public:
	static uint8_t sensorAddress;
	uint8_t init(void);
	void readCalibration(void);
	int16_t readHumidityRaw(void);
	float readHumidity(void);
	uint16_t readTemperatureRaw(void);
	float readTemperature(void);
	uint8_t readReg(uint8_t);
	void readReg(uint8_t, uint8_t *, uint8_t);
	uint8_t writeReg(uint8_t, uint8_t);
	uint8_t writeReg(uint8_t, uint8_t *, size_t);
	};
	
#endif