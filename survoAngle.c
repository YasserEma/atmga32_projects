/****************************** Survo ***************/

  
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
 
 volatile int c =0;
 static  u16 t1, t2,tim ;
 u8 flag=0;
 u16 Survo_Angle (u8 angle )
 {
	 u16 duty ;
	 duty =((angle*(long)1900)/180)+500;
	 return duty; 
 }
int main(void)
{  
	u16   fre;
	u16   duty;
	 
	  DIO_Init();
	  LCD_Init();
	  KEYPAD_Init();
	 
	  Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8); 
	  Timer1_OCRA1Mode(OCRA_NON_INVERTING);	  
	   LCD_SetCursor(0,0);
	   LCD_WriteString("Inter Angel");
	   	ICR1 = 20000; 
	  Globle_Interubt_Enable();
	u8 in=0,key='o', i=0,flag =0;
	 
	while(1)
	{ 
		if(flag ==0)
		{
			LCD_CLEAR();
		    LCD_SetCursor(0,0);
			 in =0;
		    LCD_WriteString("  Inter Angel");
		while(flag ==0)
		{   key=KEYPAD_Read();
			if (key=='I')
			{
			i=0;
			flag=1;
			}
			else if (key=='o')
			{
				continue;
			}
			else if (key ==' ')
			{
				key=0;
			}
		else 
		{
		LCD_SetCursor(1,i++);
			LCD_WriteChar(key);	
		    in=in*10+(key-'0');
		if (in >=180)
		    {
			    in =180; 
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
	 
	press= ADC_ReadVolt(CH_7);
	LCD_SetCursor(0,0);
	if (x>=2500)  {
	 	press= ADC_ReadVolt(CH_7);
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
								continue;
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
		    }
		}
		}
		}
		LCD_SetCursor(1,5);
		LCD_WriteNumber(Survo_Angle (in ));
		_delay_ms(2000);
		OCR1A=Survo_Angle (in ); 
	   
		flag=0;		
	}   
 
}
