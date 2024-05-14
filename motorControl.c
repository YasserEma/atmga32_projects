
  #include "LCD.h"
 #include "MOTOR.h"
 #include "STANDARD.h"
 #include "MEMORY_Map.h"
 #include "util.h"
 #include "DIO_interface.h"
 #include "KEYPAD.h"



 int main(void)
 {
	 
	 // a < a
	 DIO_Init();
	 LCD_Init();
	 KEYPAD_Init();
	 
	 
	 
	 u8 x =0x11;
	 LCD_WriteString(" wellcom Dr Ali");
	 _delay_ms(2000);
	 MOTOR_STOP();
	 u8 flag =0;
	 u8 key ;

	 while (1)
	 {    LCD_SetCursor(0,0) ;
		 LCD_WriteString("1- auto system ");
		 LCD_SetCursor(1,0) ;
		 LCD_WriteString("2- manual system");
		 flag =KEYPAD_Read();
		 if (flag=='1')
		 {
			 LCD_CLEAR ();
			 LCD_SetCursor(0,1) ;
			 LCD_WriteString(" 1:CCW      2:CW ");
			 LCD_SetCursor(1,1) ;
			 LCD_WriteString("3:STOP_MOTOR ");
			 while(flag=='1')
			 {
				 key=KEYPAD_Read();
				 if ( key =='1' )
				 {   LCD_CLEAR ();
					 MOTOR_CCW();
					 LCD_SetCursor(1,1) ;
					 LCD_WriteString(" MOTOR_CCW");
					 _delay_ms(200);
					 
				 }
				 else if ( key =='2' )
				 {
					 LCD_CLEAR ();
					 MOTOR_CW();
					 LCD_SetCursor(1,1) ;
					 LCD_WriteString(" MOTOR_CW");
					 _delay_ms(200);
					 
				 }
				 
				 else if ( key =='3' )
				 {	 LCD_CLEAR ();
					 LCD_SetCursor(1,1) ;
					 LCD_WriteString(" MOTOR_STOP");
					 MOTOR_STOP();
				 }
				 else if ( key =='0' )
				 {
					 MOTOR_STOP;
					 break;
				 }
				 else
				 {
					 
					 
				 }
			 }
			 
		 }
		 
		 
		 if (flag=='2')
		 {
			 
			 while(flag=='2')
			 {   LCD_CLEAR ();
				 LCD_SetCursor(0,1) ;
				 LCD_WriteString(" 1:CCW    2:CW ");
				 LCD_SetCursor(1,1) ;
				 LCD_WriteString("3:REVERCE_AUTO ");
				 _delay_ms(1000);
				 key=KEYPAD_Read();
				 if ( key =='1' )
				 {
					 LCD_CLEAR ();
					 MOTOR_CCW();
					 LCD_SetCursor(1,1) ;
					 LCD_WriteString(" MOTOR_CCW");
					 _delay_ms(1000);
					 MOTOR_STOP();
					 
					  _delay_ms(100);
				 }
				 else if ( key =='2' )
				 {   LCD_CLEAR ();
					 MOTOR_CW();
					 LCD_SetCursor(1,1) ;
					 LCD_WriteString(" MOTOR_CW");
					 _delay_ms(1000);
					 MOTOR_STOP();
					 
					  _delay_ms(100);
				 }
				 
				 
				 else if ( key =='3' )
				 { LCD_CLEAR ();
					 LCD_SetCursor(1,1) ;
					 LCD_WriteString(" MOTOR_Reverce");
					 MOTOR_CW();
					 _delay_ms(2000);
					 MOTOR_STOP();
					 _delay_ms(100);
					 MOTOR_CCW();
					 _delay_ms(2000);
					 
					 MOTOR_STOP();
					 _delay_ms(100);
					 
					 
					 
					 
				 }
				 else if ( key =='0' )
				 {
					 MOTOR_STOP;
					 break;
				 }
				 else
				 {
					 
					 
				 }
			 }
		 }
	 }
 }