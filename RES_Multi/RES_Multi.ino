  /*
Reading a NES Controller
 
 Original code by:
 Sebastian Tomczak
 21 July 2007
 Adelaide, Australia
 
 Modified by:
 Joshua de Haan
 21 June 2009
 Landgraaf, The Netherlands
 
 Modified by:
 Benjamin Gaulon
 December 2010
 Dublin, Ireland

 Modified by:
 Jerome Saint-Clair aka 01010101
 April 2013
 Brunoy, France

 */

/* USE THE RESPad library */
#include <RESPads.h>;

RESPads resPads;

/* SETUP */
void setup() {
  
  Serial.begin(9600);
  // Create pads by specifying latch, clock and datin
  resPads.add(3,2,4); // Pad 1 
  resPads.add(9,8,10); // Pad 2
  resPads.add(6,5,7); // Pad 3
}

/* PROGRAM */
void loop() {
  resPads.update();
} 


