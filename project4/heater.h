

#include "gpio.h"
#include "std_types.h"

#define HEATERPORT_ID   PORTD_ID
#define HEATERPIN_ID    PIN6_ID
#define LOGIC           POSITIVE_LOGIC
#define NEGATIVE_LOGIC  0
#define POSITIVE_LOGIC  1

#ifndef HEATER_H_
#define HEATER_H_

/*Initializes heater and
  Turn off the heater*/
void Heater_init(void);

/*Turns on heater.*/
void Heater_on();

/*Turns off the heater*/
void Heater_off();


#endif /* HEATER_H_ */
