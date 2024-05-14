 
 #define F_CPU 8000000UL
 #include "LCD.h"

 #include "MOTOR.h"
 #include "STANDARD.h"
 #include "MEMORY_Map.h"
 #include "util.h"
 #include "DIO_interface.h"
 #include "ADC.h"
 #include "Sensors.h"
 #include "Interrupt.h"
 #include "Timer.h"
 #include "Timers_Services.h"
 #include <util/delay.h>
 
 u8 password(char p[])
 {
	 u8 i  =0;
	 u8 c =0;
	 while(p[c]!='=')
	 {
		 c++;
	 }
	 u8 arr[]={"00000"};
	 while (arr[i]==p[i]&i<=5)
	 {
		 i++;
	 }
	 if (i==5&c==5)
	 {
		 
		 return 1;
	 }
	 else
	 {
		 
		 return  0;
	 }
 }

 char compareTwoString(char a[],char b[])
 {
	 int flag=0,i=0;
	 while(a[i]!='\0' &&b[i]!='\0')
	 {
		 if(a[i]!=b[i])
		 {
			 flag=1;
			 break;
		 }
		 i++;
	 }
	 if(a[i]!='\0'||b[i]!='\0')
	 return 1;
	 if(flag==0)
	 return 0;
	 else
	 return 1;
 }


 int main(void)
 {
	 DIO_Init();
	 LCD_Init ();
	 // EXI_Init();
	 ADC_Init(VREF_AVCC,ADC_SCALER_64);
	 KEYPAD_Init();
	 ADC_StartConversion(CH_0) ;


	 u16 x ;
	 u16 press;
	 u8 i=0,key=0,flag =0,readpass=0;
	 u8 arr[5];
	 LCD_CLEAR();

	 while(1)

	 {
		 
		 FILTER_TEMP();
		 x =ADC_ReadVolt(CH_0);
    	 _delay_ms(100); 
		 press= ADC_ReadVolt(CH_7);
		 _delay_ms(100);

		 LCD_SetCursor(0,0);
		 if (x>=500)  {
			 press= ADC_ReadVolt(CH_7);
			 	 _delay_ms(100);
			 if (press<3500){
				 
				 LCD_SetCursor(0,0);
				 LCD_WriteString("  Hot    ");
				 LCD_SetCursor(1,0);
				 LCD_WriteString("  Temp:      ");
				 LCD_SetCursor(1,7);
				 LCD_WriteNumber(x);
				 _delay_ms(500);
				 
				 DIO_WritePin(PINC_0, LOW);
				 DIO_WritePin(PINC_5,LOW);
				 DIO_WritePin(PINC_2, LOW);
				 DIO_WritePin(PINC_3, LOW);
				 DIO_WritePin(PINC_4,HIGH);
				 DIO_WritePin(PINC_1,HIGH);
			 }
			 else         {
				 flag=2;
				 while (flag==2&flag!=0)
				 {
					 if (flag==0)
					 {
						 break;
					 }
					 LCD_SetCursor(0,0);
					 LCD_WriteString("  fire    ");
					 LCD_SetCursor(1,0);
					 LCD_WriteString("pass:          ");
					 DIO_WritePin(PINC_0, HIGH);
					 DIO_WritePin(PINC_1,LOW);
					 DIO_WritePin(PINC_3, HIGH);
					 DIO_WritePin(PINC_4,LOW);
					 DIO_WritePin(PINC_2,LOW);
					 DIO_WritePin(PINC_5,HIGH);
					 flag=1;
					 while (flag==1&flag!=0)
					 {
						 key=KEYPAD_Read();
						 if(key!='o'&flag!=0)
						 {
							 arr[i]=key;
							 if( key=='=')
							 {
								 readpass= password(arr);
								 if (readpass)
								 {
									 LCD_SetCursor(0,0);
									 LCD_WriteString("  right  ");
									 LCD_SetCursor(1,0);
									 LCD_WriteString("                 ");
									 _delay_ms(2000);
									 flag=0;
									 i=0;
									 break;
								 }
								 else
								 {
									 LCD_SetCursor(0,0);
									 LCD_WriteString("  wrong ");
									 LCD_SetCursor(1,0);
									 LCD_WriteString("          ");
									 _delay_ms(2000);
									 flag=2;
									 i=0;
								 }
								 
							 }
							 else
							 {
								 LCD_SetCursor(1,i+5);
								 LCD_WriteChar(key);
								 _delay_ms(500);
								 LCD_SetCursor(1,i+5);
								 LCD_WriteChar('*');
								 i++;
							 }
						 }
					 }
				 }
			 }
		 }
		 else
		 {   DIO_WritePin(PINC_2,LOW);
			 DIO_WritePin(PINC_0, LOW);
			 DIO_WritePin(PINC_5,LOW);
			 DIO_WritePin(PINC_1, LOW);
			 DIO_WritePin(PINC_3,LOW);
			 DIO_WritePin(PINC_4,LOW);
			 LCD_SetCursor(0,0);
			 LCD_WriteString(" Stable");
			 LCD_SetCursor(1,0);
			 LCD_WriteString("  Temp:      ");
			 LCD_SetCursor(1,7);
			 LCD_WriteNumber(x);
			 _delay_ms(500);
			 
		 }
		 
		 
		 
	 }
 }