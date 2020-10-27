/*
 * RESPad 
 *
 * Reading a NES Controller Arduino library by Jerome Saint-Clair
 *
 * Original code by:
 * Sebastian Tomczak
 * 21 July 2007
 * Adelaide, Australia
 * 
 * Modified by:
 * Joshua de Haan
 * 21 June 2009
 * Landgraaf, The Netherlands
 * 
 * Modified by:
 * Benjamin Gaulon
 * December 2010
 * Dublin, Ireland
 *
 * Modified by:
 * Jerome Saint-Clair
 * April 2013
 * Brunoy, France
 *
 */
 
#include "Arduino.h"
#include "RESPad.h"
#include "RESPads.h"

RESPads::RESPads() {
 _nPads = 0;
};

void RESPads::_start() {
	Serial.begin(9600);
	_started = true;
}

void RESPads::add(uint8_t latch, uint8_t clock, uint8_t datin) {
	if (!_started) {
		_start();
	}
	if (_nPads < 64) {
		_pads[_nPads] = RESPad(latch, clock, datin);
		_nPads++;
	}
}

void RESPads::update() {
	for (int i=0; i<_nPads; i++) {
		_pads[i].update();
	}
	Serial.println();
}
