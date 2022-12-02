/*
 * GestureProject.c
 *
 * Created: 25-01-2017 13:11:28
 *  Author: LAKSHYA (lachchu)
 */ 


#include <avr/io.h>
#define F_CPU 8000000UL
#include <util/delay.h>
/*Includes delay.h header file which defines two functions, _delay_ms (millisecond delay) and _delay_us (microsecond delay)*/

//#define LCD_DATA_PORT (PORTB)
///*Defines a macro for the lcd.h header File. LCD_DATA_PORT is the microcontroller PORT Register to which the data pins of the LCD are connected. Default PORT Register for data pins in lcd.h header file is PORTA*/
//
//#define LCD_CONT_PORT (PORTD)
///*Defines a macro for the lcd.h header File. LCD_CONT_PORT is the microcontroller PORT Register to which the control pins of the LCD are connected. Default PORT Register for control pins in lcd.h header file is PORTB*/
//
//#define LCD_RS 	(PD0)
///*Defines a macro for the lcd.h header file. LCD_RS is the microcontroller Port pin to which the RS pin of the LCD is connected. Default Port pin for RS pin in lcd.h header file is PB0*/
//
//#define LCD_RW 	(PD1)
///*Defines a macro for the lcd.h header file. LCD_RW is the microcontroller Port pin to which the RW pin of the LCD is connected. Default Port pin for RW pin in lcd.h header file is PB1*/
//
//#define LCD_EN 	(PD2)
///*Defines a macro for the lcd.h header file. LCD_EN is the microcontroller Port pin to which the EN pin of the LCD is connected. Default Port pin for EN pin in lcd.h header file is PB2*/

#include "lcd.h"
/*Includes lcd.h header file which defines different functions for all Alphanumeric LCD(8-Bit Interfacing Method). LCD header file version is 1.1*/

#include "adc.h"
/*Includes adc.h header file which defines different functions for Analog to Digital Converter. ADC header file version is 1.1*/

#include "adxl335.h"
/*Includes adxl335.h header file which defines different functions for ADXL335 Accelerometer Sensor. ADXL335 header file version is 1.1*/

#define	X_MIN 	( (unsigned int) 310 )
/*Defines the lower threshold for the x-axis value of adxl335*/

#define	X_MAX 	( (unsigned int) 390 )
/*Defines the upper threshold for the x-axis value of adxl335*/

#define Y_MIN	( (unsigned int) 310 )
/*Defines the lower threshold for the y-axis value of adxl335*/

#define Y_MAX 	( (unsigned int) 390 )
/*Defines the upper threshold for the y-axis value of adxl335*/


int main(void)
{

	DDRB=0xff;
	/*All the 8 pins of PortB are declared output (data pins of LCD are connected)*/

	DDRD=0x07;
	/*PD0, PD1 and PD2 pins of PortD are declared output (control pins of LCD are connected)*/

	DDRC=0x0f;
	/*PC0,PC1,PC2 and PC3 pins of PortC are declared output ( i/p1,i/p2,i/p3,i/p4 pins of DC Motor Driver are connected )*/

	uint8_t x_axis,y_axis;
	/*Variable declarations*/

	adc_init();
	/*ADC initialization*/

	lcd_init();
	/*LCD initialization*/

	lcd_string_write("ABLab Solutions");
	/*String display in 1st row of LCD*/

	lcd_command_write(0xc0);
	/*Cursor moves to 2nd row 1st column of LCD*/

	lcd_string_write("www.ablab.in");
	/*String display in 2nd row of LCD*/

	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
	_delay_ms(500);
	/*Display stays for 2 second*/

	lcd_command_write(0x01);
	/*Clear screen*/

	lcd_string_write("Tilt your Hand:");
	/*String display in 1st row of LCD*/

	lcd_command_write(0xc0);
	/*Cursor moves to 2nd row 1st column of LCD*/

	/*Start of infinite loop*/
	while(1)
	{

		x_axis=read_adxl335_x_value(0);
		/*Reading x-axis value of Accelerometer Sensor*/

		y_axis=read_adxl335_x_value(1);
		/*Reading y-axis value of Accelerometer Sensor*/

		lcd_command_write(0xc0);
		/*Cursor moves to 2nd row 1st column of LCD*/

		/*Checking the tilt of the Hand(sensor) to move the robot in different direction*/
		if(x_axis > X_MAX)
		{

			PORTC=0x0A;
			/*Robot will move forward direction*/

			lcd_string_write("Moving Forward ");
			/*String display in 2nd row of LCD*/

		}
		else if(x_axis < X_MIN)
		{

			PORTC=0x05;
			/*Robot will move in backward direction*/

			lcd_string_write("Moving Backward");
			/*String display in 2nd row of LCD*/

		}
		else if (y_axis > Y_MAX)
		{

			PORTC=0x08;
			/*Robot will move in right direction*/

			lcd_string_write("Moving Right ");
			/*String display in 2nd row of LCD*/

		}
		else if(y_axis < Y_MIN)
		{

			PORTC=0x02;
			/*Robot will move in left direction*/

			lcd_string_write("Moving Left ");
			/*String display in 2nd row of LCD*/

		}
		else
		{

			PORTC=0x0F;
			/*Robot will stop*/

			lcd_string_write("Stopped ");
			/*String display in 2nd row of LCD*/

		}

	}

}