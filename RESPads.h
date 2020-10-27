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
 
#ifndef RESPads_h
#define RESPads_h

#include "Arduino.h"
#include "RESPad.h"

class RESPads {

private:
  RESPad _pads[64];
  boolean _started;
  int _nPads;
  void _start();
  
public:
  RESPads();
  void add(uint8_t latch, uint8_t clock, uint8_t datin);
  void update();
};

#endif