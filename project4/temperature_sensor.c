/*
 ============================================================================
 Name        : temperature_sensor.c
 Author      : Menna Tullah Medhat
 Description : Use the course-provided RTD temperature sensor driver to measure the room's temperature. The
sensor should be connected to ADC channel 0.
 Date        : 10/6/2024
 ============================================================================
 */


#include "temperature_sensor.h"
#include"gpio.h"
#include "adc.h"
 //void Temp_init(void){



/*
 * Description :
 * Function responsible for calculate the temperature from the ADC digital value.
 */

	 uint8 LM35_getTemperature(void)
	 {
		 uint8 temp_value = 0;

		 uint16 adc_value = 0;

		 /* Read ADC channel where the temperature sensor is connected */
		 adc_value = ADC_readChannel(SENSOR_CHANNEL_ID);

		 /* Calculate the temperature from the ADC value*/
		 temp_value = (uint8)(((uint32)adc_value*SENSOR_MAX_TEMPERATURE*2.56)/(1023*SENSOR_MAX_VOLT_VALUE));

		 return temp_value;
	 }

