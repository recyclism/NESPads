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

#ifndef RESPad_h
#define RESPad_h

#include "Arduino.h"

class RESPad {

private:
  int _clock;
  int _latch;
  int _datin;
  char _data[8];

public:
  RESPad();
  RESPad(uint8_t latch, uint8_t clock, uint8_t datin);
  void update();
  void readData();
  void sendData();
};

#endif