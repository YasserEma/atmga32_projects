#include "LCD.h"

#include "MOTOR.h"
#include "STANDARD.h"
#include "MEMORY_Map.h"
#include "util.h"
#include "DIO_interface.h"

 u8  Segment_print( u8  num)
{   char arr [10]={0x3f,0x06,0x5b,0x4f,0x66,0x6d,0x7d,0x07,0x7f,0x6f};

	u8 num2 = ( num/10);
	DIO_WritePin(PINC_7,HIGH);
	 PORTA=PORTA<<1;
	 PORTA=  arr[  num%10] ;
	DIO_WritePin(PINC_6,LOW);	 
	_delay_ms(10);
	 DIO_WritePin(PINC_6,HIGH);
	 PORTA=PORTA<<1;
	 PORTA = arr[num2];
    DIO_WritePin(PINC_7,LOW); 
    _delay_ms(10);
	  
}
int main(void)
{  DIO_Init();
 u8 i =30;
 u8 flag =0;
 u8 flag2=0;
 
  
	while(1)
	{ 
		flag=flag%2;
		flag2=flag2%2;
		if (!DIO_ReadPin(PIND_4))
		{
			flag2++;
			while(!DIO_ReadPin(PIND_4));
		}
		if (!flag2)
		{
				if (!DIO_ReadPin(PIND_2))
			{
				 flag++;
				 while(!DIO_ReadPin(PIND_2));
			}
			if (!DIO_ReadPin(PIND_3))
			{
				 i=30;
				 while(!DIO_ReadPin(PIND_3));
			}
		 if (flag==0)
		    {
				for (u8 j =0;j<25;j++ )
			{
			
			 Segment_print(i);
			
			}
			if (i==0)
			{
				Segment_print(0);
				DIO_WritePin(PINC_5,HIGH);
				i=1;
			}
			i--;
			}
		else  
			{
			   Segment_print(i);	
			}
		}
		else if (flag2)
		{
			if (!DIO_ReadPin(PIND_2))
			{
				 i++;
				 	 
					 Segment_print(i);
					 
				 
				  if (i==99)
				  {
					  Segment_print(99);
					  //	 DIO_WritePin(PINC_5,HIGH);
					  i=98;
				  }
				 
			}
			if (!DIO_ReadPin(PIND_3))
			{
				 i--;
				 Segment_print(i);	 
				 
				 if (i==0)
				 {
					 Segment_print(0);
				 
					 i=1;
				 }
				 
				
			}
		}
	}		 
}	