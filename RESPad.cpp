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


RESPad::RESPad() {};

RESPad::RESPad(uint8_t latch, uint8_t clock, uint8_t datin) {
  _latch = latch; // set the latch pin
  _clock = clock; // set the clock pin
  _datin = datin; // set the data in pin
  pinMode(latch, OUTPUT);
  pinMode(clock, OUTPUT);
  pinMode(datin, INPUT);
}


void RESPad::update() {
	readData();
	sendData();
}

void RESPad::readData() {

  digitalWrite(_latch, LOW);
  digitalWrite(_clock, LOW);
  digitalWrite(_latch, HIGH);
  delayMicroseconds(200);
  digitalWrite(_latch, LOW);
  if (digitalRead(_datin) == 1) {
    _data[0] = '1';
  }
  else {
    _data[0] = '0';
  }
  delayMicroseconds(200);
  for (int i = 1; i <= 7; i ++) {
    digitalWrite(_clock, HIGH);
    delayMicroseconds(200);
    if (digitalRead(_datin) == 1) {
      _data[i] = '1';
    }
    else {
      _data[i] = '0';
    }
    digitalWrite(_clock, LOW);
    delayMicroseconds(200);
  }
}

void RESPad::sendData() {
  for (int i = 0; i <= 7; i++){
    Serial.print(_data[i]);
    delayMicroseconds(200);
  }

  Serial.print(" ");
  delayMicroseconds(200);    
}
