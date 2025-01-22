/*
 ============================================================================
 Name        : temperature_sensor.h
 Author      : Menna Tullah Medhat
 Description : Use the course-provided RTD temperature sensor driver to measure the room's temperature. The
sensor should be connected to ADC channel 0.
 Date        : 10/6/2024
 ============================================================================
 */

#ifndef TEMPERATURE_SENSOR_H_
#define TEMPERATURE_SENSOR_H_
#include "std_types.h"
/*
#define temp_PORT  PORTC_ID
#define temp_PIN   PIN3_ID
*/

#define SENSOR_CHANNEL_ID         7
#define SENSOR_MAX_VOLT_VALUE     1.5
#define SENSOR_MAX_TEMPERATURE    150


/*

 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.

uint8 LM35_getTemperature(void);

*/
uint8 LM35_getTemperature(void);



#endif /* TEMPERATURE_SENSOR_H_ */
