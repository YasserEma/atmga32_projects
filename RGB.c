   #define F_CPU 8000000UL
#include "LCD.h" 
#include "MOTOR.h"
#include "STANDARD.h"
#include "MEMORY_Map.h"
#include "util.h"
 
#define trig  PIND_4
#include "DIO_interface.h"
#include "ADC.h" 
#include "Sensors.h"
#include "Interrupt.h"  
#include "Timer.h"
#include "Timers_Services.h"
#include <util/delay.h>	
#include "UART.h"
#include "UART_Servises.h"
#include "SPI.h"
#include "RGB.h"
 
  
int main(void)
{  
	
	  DIO_Init();
	  LCD_Init();
	  //UART_Init(); 
	   LCD_SetCursor(0,0);
	LCD_WriteString(" RGB ");
	  Globle_Interubt_Enable();
	 TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	  TIMER0_OC0Mode(OC0_NON_INVERTING);
	  TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER2_SCALER_8);
	  TIMER2_OC2Mode(OC2_NON_INVERTING);
	  ICR1=255;
	  Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8); 
	  Timer1_OCRA1Mode(OCRA_NON_INVERTING);	
	  LCD_SetCursor(0,0);
	  LCD_WriteString(" RGB ");
	    
// 	  Timer1_OCA_InterruptEnable();	  
// 	  TIMER0_OC_InterruptEnable();
// 	  TIMER2_OC_InterruptEnable(); 
      for (u8 i=0;i<10;i++)
	  {
		   RGB_Colour(i);
		   _delay_ms(1000);
	  }
	 
	   
 
	 
	while(1)
	{ 
		   for (u8 i=0;i<10;i++)
		   {
			     RGB_Colour(i);
		   _delay_ms(1000);
		   }         	
		 
	}
}   		