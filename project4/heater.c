

#include "gpio.h"
#include "std_types.h"
#include "heater.h"

/*Initializes heater and
  Turn off the heater*/
void Heater_init(void)
{
	GPIO_setupPinDirection(HEATERPORT_ID, HEATERPIN_ID, PIN_OUTPUT);

	GPIO_writePin(HEATERPORT_ID , HEATERPIN_ID, LOGIC_LOW);

}

/*Turns on heater.*/
void Heater_on()
{

	GPIO_writePin(HEATERPORT_ID , HEATERPIN_ID, LOGIC_HIGH);
}

/*Turns off the heater*/
void Heater_off()
{
	GPIO_writePin(HEATERPORT_ID , HEATERPIN_ID, LOGIC_LOW);
}





