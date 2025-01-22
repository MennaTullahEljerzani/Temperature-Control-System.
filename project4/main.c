#include "temperature_sensor.h"
#include "adc.h"
#include "lcd.h"
#include "buzzer.h"
#include <avr/io.h>
#include "keypad.h"
#include <util/delay.h>
#include "std_types.h"
#include "led.h"
#include "heater.h"
#include "dc_motor.h"
#include "gpio.h"

void showingHighTempKeyPressed(uint8 key, uint8 cursor);
void showingLowTempKeyPressed(uint8 key, uint8 cursor);
int main(void)
{
    uint8 key1;
    uint8 key2;
    uint8 key3;
    uint8 key4;
    uint8 highTemp;
    uint8 lowTemp;
    uint8 sensorTemp;

    /* Display a welcome message */

    /* Initialization */
    LCD_init();
   /* ADC_ConfigType ADC_Configurations = {INTERNAL_VOLT,F_CPU_128};
    	 Enable interrupts by setting I-bit
    	SREG|=(1<<7);
*/
    	/* Initialize ADC driver */
    	ADC_init();
    DcMotor_Init();
    Heater_init();
    LEDS_init();
    Buzzer_init();

    LCD_displayStringRowColumn(0 ,0,"Hello Hello");
       	 LCD_displayStringRowColumn(1 ,0,"Eng. Ziad");
       	 _delay_ms(2500);
       	 LCD_clearScreen();

       	 LCD_displayStringRowColumn(0 ,0,"Project 4");

       	       	 _delay_ms(1500);
       	       	 LCD_clearScreen();

    /* Display a welcome message */
	 LCD_displayStringRowColumn(0 ,0,"HT:");

    /* Move the cursor to the second row */
	 LCD_displayStringRowColumn(0 ,5,"LT:");
    /* Get the pressed key from the keypad */
           key1 = KEYPAD_getPressedKey();

           showingHighTempKeyPressed(key1,3);
           highTemp = key1*10;
           _delay_ms(500);
           key2 = KEYPAD_getPressedKey();

           showingHighTempKeyPressed(key2,4);
           highTemp+= key2;

           _delay_ms(500);
           key3 = KEYPAD_getPressedKey();
           showingLowTempKeyPressed(key3,8);
           lowTemp = key3*10;
           _delay_ms(500);
           key4 = KEYPAD_getPressedKey();
           showingLowTempKeyPressed(key4,9);
           lowTemp += key4;
           _delay_ms(500);


    while(1)
    {
    	if (lowTemp<highTemp){
        	sensorTemp = LM35_getTemperature();
            LCD_displayStringRowColumn(1 ,6,"T:   ");
        	LCD_moveCursor(1, 8);              /* Move Cursor to (ROW 1 , COLUMN 9) on LCD */
        	LCD_intgerToString(sensorTemp);
        if (sensorTemp >= highTemp){
        	DcMotor_Rotate(ClockWise, 255);
        	Heater_off();
        	Buzzer_off();
        	LED_on(LEDPIN1_ID);
        	LED_off(LEDPIN2_ID);
        	LED_off(LEDPIN3_ID);
        	LCD_displayStringRowColumn(1,0,"Hot ");
        }  else if (sensorTemp <= lowTemp){
        	Heater_on();
        	Buzzer_on();
        	DcMotor_Rotate(ClockWise, 0);
        	LED_off(LEDPIN1_ID);
        	LED_off(LEDPIN2_ID);
        	LED_on(LEDPIN3_ID);
        	LCD_displayStringRowColumn(1,0,"Cold ");
        }
        else {
        	DcMotor_Rotate(ClockWise, 0);
        	Heater_off();
        	Buzzer_off();
        	LED_off(LEDPIN1_ID);
        	LED_on(LEDPIN2_ID);
        	LED_off(LEDPIN3_ID);
        	LCD_displayStringRowColumn(1,0,"Norm");
        }
    	} else {
    		  key1 = KEYPAD_getPressedKey();

    		           showingHighTempKeyPressed(key1,3);
    		           highTemp = key1*10;
    		           _delay_ms(200);
    		           key2 = KEYPAD_getPressedKey();

    		           showingHighTempKeyPressed(key2,4);
    		           highTemp+= key2;

    		           _delay_ms(200);
    		           key3 = KEYPAD_getPressedKey();
    		           showingLowTempKeyPressed(key3,8);
    		           lowTemp = key3*10;
    		           _delay_ms(200);
    		           key4 = KEYPAD_getPressedKey();
    		           showingLowTempKeyPressed(key4,9);
    		           lowTemp += key4;
    	}


        /* Small delay to avoid bouncing issues */
        _delay_ms(300);
    }
}


void showingHighTempKeyPressed(uint8 key, uint8 cursor)
{
	        switch(key)
	        		{
	        		case 0:
	        			 LCD_displayStringRowColumn(0 ,cursor,"0");
	        			break;
	        		case 1:
	        			 LCD_displayStringRowColumn(0 ,cursor,"1");
	        			break;
	        		case 2:
	        			 LCD_displayStringRowColumn(0 ,cursor,"2");
	           			 break;
	        		case 3:
	        			 LCD_displayStringRowColumn(0 ,cursor,"3");
	        			break;
	        		case 4:
	        			 LCD_displayStringRowColumn(0 ,cursor,"4");
	        			break;
	        		case 5:
	        			 LCD_displayStringRowColumn(0 ,cursor,"5");
	        			break;
	        		case 6:
	        			 LCD_displayStringRowColumn(0 ,cursor,"6");
	        			break;
	        		case 7:
	        			 LCD_displayStringRowColumn(0 ,cursor,"7");
	        			break;
	        		case 8:
	        			 LCD_displayStringRowColumn(0 ,cursor,"8");
	        			break;
	        		case 9:
	        			 LCD_displayStringRowColumn(0 ,cursor,"9");
	        			break;
	        		case '*':
	        			 LCD_displayStringRowColumn(0 ,cursor,"0");
	        			break;
	        		case '#':
	        			 LCD_displayStringRowColumn(0 ,cursor,"0");
	        			break;
	        		}
}


void showingLowTempKeyPressed(uint8 key, uint8 cursor)
{
	        switch(key)
	        		{
	        		case 0:
	        			 LCD_displayStringRowColumn(0 , cursor,"0");
	        			break;
	        		case 1:
	        			 LCD_displayStringRowColumn(0 ,cursor,"1");
	        			break;
	        		case 2:
	        			 LCD_displayStringRowColumn(0 ,cursor,"2");
	           			 break;
	        		case 3:
	        			 LCD_displayStringRowColumn(0 ,cursor,"3");
	        			break;
	        		case 4:
	        			 LCD_displayStringRowColumn(0 ,cursor,"4");
	        			break;
	        		case 5:
	        			 LCD_displayStringRowColumn(0 ,cursor,"5");
	        			break;
	        		case 6:
	        			 LCD_displayStringRowColumn(0 ,cursor,"6");
	        			break;
	        		case 7:
	        			 LCD_displayStringRowColumn(0 ,cursor,"7");
	        			break;
	        		case 8:
	        			 LCD_displayStringRowColumn(0 ,cursor,"8");
	        			break;
	        		case 9:
	        			 LCD_displayStringRowColumn(0 ,cursor,"9");
	        			break;
	        		case '*':
	        			 LCD_displayStringRowColumn(0 ,cursor,"0");
	        			break;
	        		case '#':
	        			 LCD_displayStringRowColumn(0 ,cursor,"0");
	        			break;
	        		}
}
