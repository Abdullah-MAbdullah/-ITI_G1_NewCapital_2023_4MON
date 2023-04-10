/*********************************************
 * Author:          Abdullah M. Abdullah
 * Creation Data:   10 APR, 2023
 * Version:         v1.0
 * Compiler:        GNU GCC
 ********************************************/
/*********************************************
 * Version      Date                  Author                  Description
 * v1.0         10 APR, 2023    Abdullah M. Abdullah          Initial Creation
 *********************************************/
#include "../LIB/BIT_MATH.h"
#include "../LIB/STD_TYPES.h"
#include <util/delay.h>
#include "../MCAL/DIO/DIO_interface.h"
#include "../MCAL/TIMER/TIMER_interface.h"

int main(void)
{
	u16 Local_u16Counter;
	/*Set The OC0 Pin To Be Output*/
	DIO_voidSetPinDirection(DIO_PORTB, PIN3, OUTPUT);
	/*Initialize The Timer*/
	TIMER0_voidInit();

	while(1)
	{
		/*Set The Compare Match Value from 0 to 255*/
		for(Local_u16Counter = 0; Local_u16Counter <= 255; Local_u16Counter++)
		{
			TIMER0_voidSetOCMatchValue(Local_u16Counter);
			_delay_ms(10);
		}

		/*Set The Compare Match Value from 255 to 0*/
		for(Local_u16Counter = 0; Local_u16Counter <= 255; Local_u16Counter++)
		{
			TIMER0_voidSetOCMatchValue(255 - Local_u16Counter);
			_delay_ms(10);
		}
	}
}




