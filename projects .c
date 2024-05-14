 
	
	/************** project 1 ***************/
		
		
	 //Stop Watch Program 
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
	
	/*
 * LOVE_2.c
 *
 * Created: 04/12/2022 04:01:47 م
 * Author : Yasser Emad
 */ 
            faculity project 
#include "LCD.h"
 
#include "MOTOR.h"
int main(void)
{
	 
   	// a < a
  	DEFAULT();
   	LCD_Init();
	 
	 DDRD=0x00;
	 PORTD=0xFF;
	// PIND=0x00
	 DDRB=0xff;
	 PORTB=0xff; 
      u8 x =0x11;
	  LCD_WriteString(" wellcom Dr Ali");
   				MOTOR_STOP();

   	while (1)
   	{
		   
	   if ( !read (PIND,2) )
	   	    {   PORTB=!(0b11111111);

		  MOTOR_CCW();
		  LCD_WriteString("MOTOR_CCW");
		   _delay_ms(1000);
		   LCD_CLEAR();
		   MOTOR_STOP();
	   }
	   if ( !read (PIND,3) )
	   { PORTB=0b11110000;
		   MOTOR_CW();
		   LCD_WriteString("MOTOR_CW");
		   _delay_ms(1000);
		   LCD_CLEAR();
		   MOTOR_STOP();
	   }
	    if ( !read (PIND,4) )
	    {   PORTB=0b11111111;
			MOTOR_STOP();
		    LCD_WriteString("MOTOR_STOP");
		    _delay_ms(1000);
			LCD_CLEAR();
		    
	    }
		if ( !read (PIND,5) )
		{   PORTB=0b11111111;
			LCD_WriteString("MOTOR_AUTO_4 sec");
			
			MOTOR_CW();
			_delay_ms(10000);
			MOTOR_STOP();
			_delay_ms(10000);
			MOTOR_CCW();
			_delay_ms(10000);
			
			MOTOR_STOP();
			_delay_ms(10000);
            LCD_CLEAR();
		}
	 // DIO_WRITE_PORT(PB,0xff);
	   
	 //  MOTOR_STOP();
		  
	   }
   	
}

  


CALCLATOR 
 
	
	/*
 * LOVE_2.c
 *
 * Created: 01/11/2022 05:10:20 م
 * Author : Yasser Emad
 */ 

 
 

#include "MOTOR.h"
#include "MEMORY_Map.h"
#include "STANDARD.h"
#include "util.h"
#include "DIO_Interface.h"
#include "KEYPAD.h"
#include "LCD.h"



int main(void)
{  DIO_Init();
   LCD_Init();
   
	KEYPAD_Init();
   
  
	 u8 num1=0,num2=0 ,result; 
	 u8 flag=0,num =0,i=0, prosess,key; 
	   
   	while (1)
   	{key=KEYPAD_Read();
		 
	 if (key !='o')
	 {
        
		 if (key>='0'&key<='9')
		 {   
	
			 LCD_WriteChar(key);
			 
			 if (!flag)
			 {
				  num1=num1*10+(key-'0');
				  flag=0;
				  
			 }
			 else 
			 {
				 num2=num2*10+(key-'0');
				 flag=1;
			 }
			 
		 
		 }
		 else if (key=='=')
		  {
			  LCD_SetCursor  (1,0) ;
			  if (prosess=='+')
			  {
				  result=num1+num2;
 			  }
			 else if (prosess=='*')
			  {
				  result=num1*num2;
 			  }
			   else if (prosess=='-')
			   {
				   result=num1-num2;
				  
			   }
			    else if (prosess=='/')
			    {
				    result=num1/num2;
 			    }
				else
				{
					LCD_WriteString ("not avail");
				}
			  LCD_WriteNumber(result);
			  num1=0;
			  num2=0;
			  result=0;
			  flag=0;
			 
		  } 
		  else if (key=='%')
		  {
			  LCD_CLEAR ();
			  flag=0;
		  }
		 
		 else 
		 {   LCD_WriteChar (key);
 			 
			 flag=1;
			 prosess=key;
			 
		 }		 
		 }
		 
	 } 
   	
}





 


calculator pro wait edit 

	/*
 * LOVE_2.c
 *
 * Created: 04/11/2022 04:01:47 م
 * Author : Yasser Emad
 */ 
 
 #include "util.h"
#include "DIO_Interface.h"
#include "KEYPAD.h"
#include "LCD.h"



int main(void)
{  DIO_Init();
   LCD_Init();
   
	KEYPAD_Init();
   
  
	 s16 num1=0,num2=0 ; 
	 s16 result=0;
	 u8 flag=0,num=0, prosess,key,flag2=0; 
	   
   	while (1)
   	{key=KEYPAD_Read();
		 
	 if (key !='o')
	 { 
        
		 if (key>='0'&key<='9')
		 {   
	
			 LCD_WriteChar(key);
			 
			 if (!flag)
			 {				
				  num1=num1*10+(key-'0');
				  flag=0;				  
			 }
			 else 
			 {
				 num2=num2*10+(key-'0');
				 flag=1;
			 }
			 
			 
		 
		 }
		 else if ((key=='=')&&(flag2==0))
		  {
			 
			  LCD_SetCursor  (1,0) ;
			  if (prosess=='+')
			  {
				  result=num1+num2;
 			  }
			   else if (prosess=='*')
			   {
				  result=num1*num2;
 			   }
			   else if (prosess=='-')
			   {
				   result=num1-num2;
				  
			   }
			    else if (prosess=='/')
			    {   if (num2)
					{
				    result=num1/num2;
					}
					else 
					{
						LCD_WriteString ("not valid ");
						break;
					}
					
					
 			    }
				 
				else
				{
					LCD_WriteString ("not avail");
			}  
			LCD_SetCursor(1,0);
			LCD_WriteString("       ") ;
			
		    	LCD_SetCursor(1,0);
			  LCD_WriteNumber(result);
			  num1=0;
			  num2=0;			  
			  flag=0;
			  flag2=1;
			  LCD_SetCursor(0,0);
			 
			 
			   
			 
		  } 
		   else if ((key=='=')&&(flag2==1))
		   {  
			   
			num1=result;
			 
			LCD_CLEAR();
			
			LCD_WriteNumber(result);  
			 	   
		   }
		  else if (key=='%')
		  {
			  LCD_CLEAR ();
			  flag=0;
			  flag2=0; 
		  }
		 else 
		 {   LCD_WriteChar (key); 			 
			 flag=1;
			 flag2=0;
			 prosess=key;			 
		 }	
		 
		  }
		 
		
		 
      }
	}	

#include "MOTOR.h"
#include "MEMORY_Map.h"
#include "STANDARD.h"

	
	
	
//////////////////////////////////////	converting system ////////////////////////////////////

	 
	 
		// بسم الله الرحمن الرحيم 
		
		
		 /*
 * LOVE_2.c
 *
 * Created: 04/11/2022 04:01:47 م
 * Author : Yasser Emad
 */ 

 
 
#include "LCD.h"
 
#include "MOTOR.h"
 #include "STANDARD.h"
 #include "MEMORY_Map.h"
 #include "util.h"
 #include "DIO_interface.h"



int main(void)
{
	 
   	// a < a
  	DIO_Init();
   	LCD_Init();
    KEYPAD_Init();
	
	u8 flag ;
    
	u8 key='0' ; 
	
   	while (1)
   	{ u8 number=0;
	  long number1=0;
	//
    LCD_WriteString ("1 B-->D"); 
    LCD_SetCursor(0,8);
	LCD_WriteString (" 2 D-->B"); 
	LCD_SetCursor(1,0);
	LCD_WriteString ("3 H-->D");
	LCD_SetCursor(1,8);
	LCD_WriteString (" 4 D-->H"); 
		flag =KEYPAD_Read();
	if (flag=='1')  
	{    LCD_CLEAR();
		
		 LCD_SetCursor(1,0);
	     LCD_WriteString("bin :");
		  LCD_SetCursor(0,0) ;
		 LCD_WriteString("DES :");
		while(flag=='1')
			 { 
			     key =KEYPAD_Read();
			    
				if (key>='0'&key<='9')
				{
				 LCD_WriteChar(key);
				 
				number=number*10+(key-'0');
					}		 
				 else if (key=='=') 
				 {      
					    LCD_SetCursor(1,5);	
					    LCD_PrintPinary(number);
 				 }
				  else if (key=='%')
				   {
					   flag='0';
					   LCD_CLEAR();
				   }
				  else 
				  {
				  }
							 
			 }
			 
	}
		 if (flag=='2')
		 { 
        LCD_CLEAR();
        
        LCD_SetCursor(1,0);
        LCD_WriteString("bin:");
        LCD_SetCursor(0,0) ;
        LCD_WriteString("DES:");
        while(flag=='2')
        {
	        key =KEYPAD_Read();
	        
	        if (key=='0'|key=='1')
	        {
		        LCD_WriteChar(key);
		        
		        number1=number1*10+(key-'0');
	        }
	        else if (key=='=')
	        {
		        LCD_SetCursor(1,4);
		        LCD_PrintDes(number1);
	        }
	        else if (key=='%')
	        {
		        flag='0';
		        LCD_CLEAR();
	        }
	        else
	        {
	        }
	        
        }
        
		 }
		while(flag=='3')
		 {  
			 
		 }
		  while(flag=='4')
		  {  
		  }
		  
	}
      	
}

  			   
final faculity project

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
 		
			 
 
	
	
	
	 
			
		/**********************/
	
	 
#include "LCD.h"

#include "MOTOR.h"
#include "STANDARD.h"
#include "MEMORY_Map.h"
#include "util.h"
#include "DIO_interface.h"



int main(void)
{
	
	// a < a
	DIO_Init();
	LCD_Init();
	KEYPAD_Init();
	
	u8 flag ;
	u8 flag2;
	u8 flag3=0 ;
	
	u8 key='0' ;
	LCD_WriteString ("Hello To Conv ");
	LCD_SetCursor(1,0);
	LCD_WriteString ("By Yasser");
	_delay_ms(1000);
	LCD_CLEAR();
	u8 num1=0;
	u8 num2=0; 
    long num3=0;
   
	while (1)
	{ u8 number=0;
      u8 key=0 ;
		long number1=0;
		 
		//
		LCD_WriteString ( " 1-Des");
		LCD_SetCursor(0,8);
		LCD_WriteString (" 2- Bin");
		LCD_SetCursor(1,5);
		LCD_WriteString ("3- Hex    ");
		 
		 
		flag =KEYPAD_Read();
		 
 if (flag=='1')
	{ //des
				LCD_CLEAR();
 while(flag=='1'){
					
					LCD_SetCursor(0,7);
					LCD_WriteString (" To");
					LCD_SetCursor(1,0);
					LCD_WriteString (" 1- Bin ");
					LCD_SetCursor(1,7);  
					LCD_WriteString ("   2- hex");
					flag2=KEYPAD_Read();
			 if (flag2=='1')
			 {   LCD_CLEAR();				 
				 LCD_SetCursor(1,0);
				 LCD_WriteString("bin :");
				 LCD_SetCursor(0,0) ;
				 LCD_WriteString("DES :");
				 u8 i =5;
				 while(flag2=='1')
				 {
					 key =KEYPAD_Read();
					 
					 if (key>='0'&key<='9')
					 {  						  
						 LCD_SetCursor(0,i++);
						 LCD_WriteChar(key);						 
						 number=number*10+(key-'0'); 
						 LCD_SetCursor(1,5);
						 LCD_DesToBin(number);
					 }
					 else if (key=='F')
					 {
						 if (flag3 ==0)
						 {
							 LCD_SetCursor(0,5);
							 LCD_WriteString("         ");
							 LCD_SetCursor(1,5);
							 LCD_WriteString("         ");
							 i=5;
							 number=0;
						 }
						 else if  (flag3 ==1)
						 {
							 flag2='0';
							 flag='0';
							 LCD_CLEAR();
						 }
						 flag3++;
					 }
					 
				}
			 }
		else if (flag2=='2')//des to hex 
				 {   LCD_CLEAR();
					 LCD_SetCursor(1,0);
					 LCD_WriteString("Hex:");
					 LCD_SetCursor(0,0) ;
					 LCD_WriteString("DES :");
					 u8 x =5;
					 while(flag2=='2')
					 {
						 key =KEYPAD_Read();
						 
						 if (key>='0'&key<='9')
						 {
							 LCD_SetCursor(0,x++);
							 LCD_WriteChar(key);
							 number=number*10+(key-'0');
							 LCD_SetCursor(1,4);
							 LCD_DesToHex(number);
							 flag3=0;
						 }
						 else if (key=='F')
						 {
							 if (flag3 ==0)
							 {
						     LCD_SetCursor(0,5);
							 LCD_WriteString("         ");
							 LCD_SetCursor(1,5);
							 LCD_WriteString("         ");
							 x =5;
							 number=0;
							 }	
					        else if  (flag3 ==1)
							{  
								 flag2='0';
								 flag='0';
								 LCD_CLEAR();
							}							
							flag3++;
						}
					 }
						
			   }		 
		}
	}
		  else if (flag=='2')
				{
					//bin
					LCD_CLEAR();
					while(flag=='2'){
						
						LCD_SetCursor(0,7);
						LCD_WriteString (" To");
						LCD_SetCursor(1,0);
						LCD_WriteString (" 1- Des ");
						LCD_SetCursor(1,7);
						LCD_WriteString ("   2- hex");
						flag2=KEYPAD_Read();
						if (flag2=='1')//bin to des 
						{  
						    LCD_CLEAR();
							LCD_SetCursor(1,0);
							LCD_WriteString("DES :");
							LCD_SetCursor(0,0) ;
							LCD_WriteString("Bin :");
							u8 i =5;
							while(flag2=='1')
							{
								key =KEYPAD_Read();
								
								if (key=='0'||key=='1')
								{
									LCD_SetCursor(0,i++);
									LCD_WriteChar(key);
									num3=num3*10+(key-'0');
									LCD_SetCursor(1,5);
									 u8 n=LCD_BinToDes(num3);
									LCD_WriteNumber(n);
								}
								 else if (key=='F')
								 {
									 if (flag3 == 0)
									 {
										 LCD_SetCursor(0,5);
										 LCD_WriteString("         ");
										 LCD_SetCursor(1,5);
										 LCD_WriteString("         ");
										 i =5;
										 number=0;
									 }
									 else if  (flag3 ==1)
									 {
										 flag2='0';
										 flag='0';
										 LCD_CLEAR();
									 }
									 flag3++;
								 }								
							}  		
				}
				if (flag2=='2')//bin to des
				{
					LCD_CLEAR();
					LCD_SetCursor(1,0);
					LCD_WriteString("Hex :");
					LCD_SetCursor(0,0) ;
					LCD_WriteString("Bin :");
					u8 i =5;
					while(flag2=='2')
					{
						key =KEYPAD_Read();
						
						if (key=='0'||key=='1')
						{
							LCD_SetCursor(0,i++);
							LCD_WriteChar(key);
							num3=num3*10+(key-'0');
							LCD_SetCursor(1,5);
							LCD_BinToHex(num3);
						}
							 else if (key=='F')
							 {
								 if (flag3 ==0)
								 {
									 LCD_SetCursor(0,5);
									 LCD_WriteString("         ");
									 LCD_SetCursor(1,5);
									 LCD_WriteString("         ");
									 i =5;
									 number=0;
								 }
								 else if  (flag3 ==1)
								 {
									 flag2='0';
									 flag='0';
									 LCD_CLEAR();
								 }
								 flag3++;
							 }					
					}					
				}
					}
				}
		  else if (flag=='3')
				{
					//HEX
					LCD_CLEAR();
					while(flag=='3'){						
						LCD_SetCursor(0,7);
						LCD_WriteString (" To");
						LCD_SetCursor(1,0);
						LCD_WriteString (" 1- Des ");
						LCD_SetCursor(1,7);
						LCD_WriteString ("   2- Bin");
						flag2=KEYPAD_Read();
						if (flag2=='1')//hex to bin
						{
							LCD_CLEAR();
							LCD_SetCursor(1,0);
							LCD_WriteString("Des:");
							LCD_SetCursor(0,0) ;
							LCD_WriteString("Hex :");
							u8 i =5,j=5,k=0;
							while(flag2=='1')
							{
								key =KEYPAD_Read();
								
								if (key>='0'&&key<='f')
								{
									LCD_SetCursor(0,i++);
									LCD_WriteChar(key);
									
									LCD_SetCursor(1,5);
								    u8 n1=	LCD_HexToDes(key);
								    u8 n2 ;
									if (k==1)
									{
										  n2=	LCD_HexToDes(key); 
										  n2=n2<<4;
									}  
									u8 num =n1|n2;
									LCD_WriteNumber(num);
									k++;
								}
								
							}
							
						}
						if (flag2=='2')//hex to bin
						{
							LCD_CLEAR();
							LCD_SetCursor(1,0);
							LCD_WriteString("Bin:");
							LCD_SetCursor(0,0) ;
							LCD_WriteString("Hex :");
							u8 i =5,j=5;
							while(flag2=='2')
							{
								key =KEYPAD_Read();
								
								 if (key>='0'&&key<='f')
								 {
									LCD_SetCursor(0,i++);
									LCD_WriteChar(key);
									 
									LCD_SetCursor(1,j);
									LCD_HexToBin(key);
									j=j+4;
									
								 }
								
							}
							
						}
						 
					}
					
				}
		  
		  else 
				{
			
				}
		}	 		 
	}
 	
		
last pro 


 //Stop Watch Program 
#include "LCD.h"

#include "MOTOR.h"
#include "STANDARD.h"
#include "MEMORY_Map.h"
#include "util.h"
#include "DIO_interface.h"
#include "ADC.h" 
#include "Sensors.h"
#include "Interrupt.h" 
 

  
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
 
int main(void)
{ DIO_Init();
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
		 	LCD_SetCursor(0,0);
		  if (x>=50)  {
			   ADC_StartConversion(CH_7) ;
			  press= ADC_ReadVolt(CH_7);
			  if (press<80){
				  
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
					  DIO_WritePin(PINC_5,HIGH);
					  DIO_WritePin(PINC_3, HIGH);
					  DIO_WritePin(PINC_4,LOW);
					  DIO_WritePin(PINC_2,LOW);
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
									  LCD_WriteString("          ");
									  _delay_ms(3000);
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
									  _delay_ms(3000);
									  flag=2;
									  i=0;
								  }
								  
							  }
							  else
							  {
								  LCD_SetCursor(1,i+5);
								  LCD_WriteChar(key);
								  i++;
							  }
						  }
					  }
				  }
			  } 
			  }	
		   	  else	
			 {		    DIO_WritePin(PINC_2,LOW);
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

	 
 
else
	{    
		press=PREASURE_READ();		   
		if (press>=450 )
		{   			 
			LCD_SetCursor(0,0);			
			LCD_WriteString("fire          ");
			LCD_SetCursor(1,0);
		    LCD_WriteString("pass:             ");
			i=0;
			
           while (press >=450 & readpass==0 )	
		   { 
			 key=KEYPAD_Read();
			 if(key!='o')
			  {  			 
				    arr[i]=key;			 				  
				    if( key=='=')
				   {
					  readpass= password(arr);
					  if (readpass)
					  {   LCD_CLEAR(); 
						  LCD_WriteString ("right         ");
						  _delay_ms(3000);
						  
						  
					  }
					  else
					  {
						  LCD_CLEAR();
						  LCD_WriteString (" wrong         ");
						  _delay_ms(3000);
						 
					  }
				     } 
					 else 
					 {
					  LCD_SetCursor(1,i+5);
					  LCD_WriteChar(key);					  
					  i++;
		              }
					 
			   }
	            
				  			 	
			 
			 DIO_WritePin(PINC_2,LOW);	
			 DIO_WritePin(PINC_0,HIGH);
			 DIO_WritePin(PINC_5,HIGH); 
			  	
		      }
				 }
	else{
	    ;				
		}
		 
	
	  
 
} 
	}
		}
	 
	 
/*ISR(TIMER0_OVF_vect)
{       FILTER_TEMP(); 
		x =READ_Temp_Filter();
		
	static u16 c =0;
	if (c==3906| c==1953)
	{
		if (c==3906)
		{
		DIO_WritePin(PINC_3,DIO_ReadPin(PINC_3)^1);
		DIO_WritePin(PINC_4,DIO_ReadPin(PINC_4)^1);
		c=0;	
			
		}
		else
		{
			DIO_WritePin(PINC_4,DIO_ReadPin(PINC_4)^1);
		} 
		
	}		 
	 c++;
}
ISR(TIMER0_OVF_vect)
{
	static u16 c =0;
	
	if (c==0)
	{   
		DIO_WritePin(PINC_3,HIGH);
		TCNT0=175;
        c=1;
	}
	if ( c==1)
	{
		DIO_WritePin(PINC_3,LOW);
		 TCNT0=246;
         c=0;
	}
	
	 
} 
/* 
					}*/
					
					 
	


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

 ????????????????????? LAST SMART SYSTEM FOR FIRE ????????????????????
 
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


  
  ???????????????????????????? RGB ??????????????????
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
		   
	  
	  
	  
	  
	  ?????????????????????? Smart home final lock ???????????/
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
 static u8 receive =0;
 u8 flag2=0;
 volatile u16 time1, time2 ,flag3_ulterasonic=0 ;
 
 ISR (UART_RX_vect)
 {
	 
	  receive=UART_ReceiveData_NoBlock();
	  flag2=1;
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
	 LCD_Init();
	 ADC_Init(VREF_AVCC,ADC_SCALER_64);
	  KEYPAD_Init();
	    UART_Init();	 
	   
	   UART_RX_InterruptEnable ();
	  //  Globle_Interubt_Enable();
   	ADC_StartConversion(CH_0) ;
	 Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	 Timer1_OCRA1Mode(OCRA_NON_INVERTING);	 	 
	  u16 volt ;
	 ICR1 = 20000;
	 
	 Globle_Interubt_Enable();
	 
	 //TIMER0_OC_InterruptEnable();
	 u8 counter1,read_eeprom ,key ='o',flag=0,readpass=0,i =0  ;
	 u16 lazer_read=0;
	 u8 arr[10],setpass[10];
	 static u8 LOCK =3;
	 const u8 Data=0x01;
	 const u8 Data2='\0';
	 const u16 loc=0x20;
	 // const u8 setpassSize;
	 LCD_SetCursor(0,1);
	 
	 OCR1A=	Survo_Angle (0);
	 LCD_SetCursor(0,1);
	 LCD_WriteString (" Set Pass  ") ;
	 read_eeprom=EEPROM_ui8ReadByteFromAddress(loc);
	 
	 while (read_eeprom==255 )
	 {    LCD_SetCursor(0,1);	 
		 key=KEYPAD_Read();
		 if(key!='o')
		 {
			 setpass[i]=key;
			 if( key=='=')
			 {
				 LCD_SetCursor(0,0);
				 LCD_WriteString("  OK           ");
				 LCD_SetCursor(1,0);
				 LCD_WriteString("          ");
				 _delay_ms(500);
				 
				 const u8 setpassSize=i;
				 EEPROM_vWriteBlockToAddress(loc+1, setpass,setpassSize);
				 EEPROM_vWriteByteToAddress(loc+setpassSize+1 ,Data2);
				 
				 
				 EEPROM_vWriteByteToAddress(loc ,Data);
				 read_eeprom=EEPROM_ui8ReadByteFromAddress(loc);
				 i=0;
				 key='o';
				 
				 break;;
			 }
			 else
			 {
				 LCD_SetCursor(1,i+5);
				 LCD_WriteChar(key);
				 _delay_ms(1000);
				 LCD_SetCursor(1,i+5);
				 LCD_WriteChar('*');
				 i++;
			 }
		 }
	 }
	 
	 
	 
	 
	 while(1)
	 {
		 
		  	 
		 if (read_eeprom==1&&flag2==0 )
		 {
			 
			 
		         LCD_CLEAR();
		         LCD_SetCursor(0,0);
				 LCD_WriteString(" Enter Password ");
				  while (read_eeprom==1&&flag2==0 )
			  {  
				   OCR1A=	Survo_Angle (0);
				  	key=KEYPAD_Read();
				 if(key!='o'&&flag2==0)
				 {
					 arr[i]=key;
					 if( key=='='&&flag2==0)
					 { 	   EEPROM_vReadBlockFromAddress(loc+1,setpass,5);
						 
						 arr[i]='\0';
						 readpass= compareTwoString(arr ,setpass );
						 if (!readpass)
						 {   LCD_CLEAR();
							 LCD_SetCursor(0,0);
							 LCD_WriteString(" Right           ");
							 LCD_SetCursor(1,0);
							 LCD_WriteString(" Open               ");
							  DIO_WritePin(PINC_1,HIGH) ;
							 OCR1A=	 Survo_Angle (90 );						  
							 _delay_ms(5000);
							 DIO_WritePin(PIND_3,HIGH);
							 _delay_ms(5000);	
							 volt= ADC_ReadVolt(CH_0);						   
							 while(volt<=4000) //????عدل اكبر من 
							 {   DIO_WritePin(PINC_1,HIGH) ;
								 Globle_Interubt_Disable();
								 volt= ADC_ReadVolt(CH_0);
								 Globle_Interubt_Enable();
								 OCR1A=	 Survo_Angle (90 );
								    LCD_SetCursor(1,0);
								    
								 LCD_WriteNumber(volt);
								 _delay_ms(100);
							 } DIO_WritePin(PINC_1,LOW) ;
							 flag=2;
							 i=0;
							 OCR1A=	Survo_Angle (0);
							 DIO_WritePin(PIND_3,LOW);
							 LCD_SetCursor(1,0);
							 LCD_WriteString("Close               ");
							 _delay_ms(3000);
							 break;
						 }
						 else
						 {   LCD_CLEAR();
							  DIO_WritePin(PINC_2,HIGH) ;
							 
							 
							 OCR1A=	Survo_Angle (0);
							 LCD_SetCursor(0,0);
							 LCD_WriteString("  wrong               ");
							 LCD_SetCursor(0,8);
							 LCD_WriteString(" try =");
							 LCD_SetCursor(0,13);
							 LCD_WriteNumber(LOCK);
							 _delay_ms(1000);
							  DIO_WritePin(PINC_2,LOW) ;
							 if(!LOCK)
							 {  LCD_CLEAR();
								 LCD_SetCursor(0,0);
								 LCD_WriteString(" Lock wait 20sec  ");
								 LOCK=3;
								 for(u8 j=0;j<10;j++)
								 {
									 DIO_WritePin(PINC_2,HIGH) ;
									 _delay_ms(1000);
									 DIO_WritePin(PINC_2,LOW) ;
									 _delay_ms(1000);
								 }
								 
								 break;
								 
							 }
							 i=0;
							 LOCK--;
							 
						 }
						 
					 }
					
					 else
					 {     OCR1A=	Survo_Angle (0);
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
		 if (flag2==1 )
		  {    if (receive=='a')
			  {
				 
							LCD_CLEAR();
							LCD_SetCursor(0,0);
							LCD_WriteString(" Right           ");
							LCD_SetCursor(1,0);
							LCD_WriteString(" Open               ");
							DIO_WritePin(PINC_1,HIGH) ;
							OCR1A=	 Survo_Angle (90 );
							_delay_ms(5000);
							DIO_WritePin(PIND_3,HIGH);
							_delay_ms(5000);	
							 volt= ADC_ReadVolt(CH_0);							
							while(volt<=4000) 
							{   DIO_WritePin(PINC_1,HIGH) ;
								//Globle_Interubt_Disable();
								volt= ADC_ReadVolt(CH_0);
								//Globle_Interubt_Enable();
								OCR1A=	 Survo_Angle (90 );
								LCD_SetCursor(1,0);								
								LCD_WriteNumber(volt);
								_delay_ms(1000);
							}
							 DIO_WritePin(PINC_1,LOW) ;
							flag=2;
							i=0;
							OCR1A=	Survo_Angle (0);
							 DIO_WritePin(PIND_3,LOW);
							LCD_SetCursor(1,0);
							LCD_WriteString("Close               ");
							_delay_ms(1000);
							flag2=0; 
							 	
				}
			 
			  else
			  {    LCD_CLEAR();
				   LCD_SetCursor(0,0);
				   LCD_WriteString(" ERROR           ");
				   	flag2=0;
			  }
	    	}		
         }
	 }	    
				 
					 
				      
				     
			       
			  
			 
	 ?????????????????????? Smart home final fire and control System ???????????/		  
	    
 
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
#include "UART.h"
#include "UART_Servises.h"
#include "RGB.h"
#include <util/delay.h>
static u8 receive =0;
u8 volatile flag2=0;
ISR (UART_RX_vect)
{
	receive=UART_ReceiveData_NoBlock();
	flag2=1;
}
ISR (UART_TX_vect)
{
	receive=UART_ReceiveData_NoBlock();
	flag2=1;
}
 

int main(void)
{
	DIO_Init();
	LCD_Init ();
	// EXI_Init();
	ADC_Init(VREF_AVCC,ADC_SCALER_64);
	KEYPAD_Init();
	ADC_StartConversion(CH_0) ;
    UART_Init();
     UART_RX_InterruptEnable ();
	  TIMER0_Init(TIMER0_FASTPWM_MODE,TIMER0_SCALER_8);
	  TIMER0_OC0Mode(OC0_NON_INVERTING);
	  TIMER2_Init(TIMER2_FASTPWM_MODE,TIMER2_SCALER_8);
	  TIMER2_OC2Mode(OC2_NON_INVERTING);
	  ICR1=255;
	  Timer1_Init(TIMER1_FASTPWM_ICR_TOP_MODE,TIMER1_SCALER_8);
	  Timer1_OCRA1Mode(OCRA_NON_INVERTING);
	 Globle_Interubt_Enable();

	u16 x , press;
    u8 flag=0; 
	LCD_CLEAR();
	while(1)

	{
		if (!flag2)
		{
			FILTER_TEMP();
		x =ADC_ReadVolt(CH_0);		
		press= ADC_ReadVolt(CH_7);
		LCD_SetCursor(0,0);
		if (x>=500)  {
			press= ADC_ReadVolt(CH_7);
			if (press<3500){
				LCD_CLEAR();
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
			else    {
			        LCD_CLEAR();
					LCD_SetCursor(0,0);
					LCD_WriteString(" fire");
					LCD_SetCursor(0,7);
					LCD_WriteString("pre : ");
					LCD_SetCursor(0,11);
					LCD_WriteNumber(press);	
					LCD_SetCursor(1,7);					 
					LCD_WriteString("Temp:");
					LCD_SetCursor(1,11);
					LCD_WriteNumber(x);
					_delay_ms(500);
					DIO_WritePin(PINC_0, HIGH);
					DIO_WritePin(PINC_1,LOW);
					DIO_WritePin(PINC_3, HIGH);
					DIO_WritePin(PINC_4,LOW);
					DIO_WritePin(PINC_2,LOW);
					DIO_WritePin(PINC_5,HIGH);
				 
			    	}
			}
		 
		else
		{   LCD_CLEAR();
			if (flag==1)
			{
				 DIO_WritePin(PINC_2,LOW);
				 DIO_WritePin(PINC_0 ,LOW);
				 DIO_WritePin(PINC_5,LOW);
				 DIO_WritePin(PINC_1,LOW);
				 DIO_WritePin(PINC_3,HIGH);
				 DIO_WritePin(PINC_4,LOW);
			}
			else if (flag==2)
			{
				   DIO_WritePin(PINC_2,LOW);
				   DIO_WritePin(PINC_0, LOW);
				   DIO_WritePin(PINC_5,LOW);
				   DIO_WritePin(PINC_1, LOW);
				   DIO_WritePin(PINC_3,LOW);
				   DIO_WritePin(PINC_4,HIGH);
			}
			else
			{
				   DIO_WritePin(PINC_2,LOW);
				   DIO_WritePin(PINC_0, LOW);
				   DIO_WritePin(PINC_5,LOW);
				   DIO_WritePin(PINC_1, LOW);
				   DIO_WritePin(PINC_3,LOW);
				   DIO_WritePin(PINC_4,LOW);
			}
		 
			LCD_SetCursor(0,0);
			LCD_WriteString(" Stable");
			LCD_SetCursor(1,0);
			LCD_WriteString("  Temp:      ");
			LCD_SetCursor(1,7);
			LCD_WriteNumber(x);
			_delay_ms(500);
			
		 }	
	   }
	else  
	 {   
		  if (receive=='a')
		  {
			  UART_SentData('a');
			  LCD_SetCursor(0,0);
			  LCD_WriteString(" open_On    ");
			    _delay_ms(1000);
			    flag2=0;
		  }
		  else if (receive=='M')
		  {
			  
			  LCD_CLEAR();
			  LCD_SetCursor(0,0);
			  LCD_WriteString(" Motor_On    ");
			  LCD_SetCursor(1,0);
			  
			  DIO_WritePin(PINC_3,HIGH) ;
			  _delay_ms(2000);
			  flag=1;
		      flag2=0;
	      }
		  else if (receive=='m')
		  {
			    LCD_CLEAR();
			    LCD_SetCursor(0,0);
			    LCD_WriteString(" Motor_Off ");
			    LCD_SetCursor(1,0);
			   
			    DIO_WritePin(PINC_3,LOW) ;
				_delay_ms(2000);
				 flag2=0;	
                 flag=0;				 
		  }
		   else if (receive=='F')
		   {
			   LCD_CLEAR();
			   LCD_SetCursor(0,0);
			   LCD_WriteString(" Fan_On ");
			   LCD_SetCursor(1,0);
			    
			   DIO_WritePin(PINC_4,HIGH) ;
			   _delay_ms(2000);
			   flag=2;
			   flag2=0;
		   }
		    else if (receive=='f')
		      {
			      LCD_CLEAR();
			      LCD_SetCursor(0,0);
			      LCD_WriteString(" Fan_Off ");
			      LCD_SetCursor(1,0);
			     
			      DIO_WritePin(PINC_4,LOW) ;
			      _delay_ms(2000);
				  flag=0;
			      flag2=0;
		      }
			    else if (receive=='1')
			    {
				    LCD_CLEAR();
				    LCD_SetCursor(0,0);
				    LCD_WriteString(" RED_COLOUR ");
				     RGB_Colour(red);
				    _delay_ms(2000);
				    flag2=0;
			    }
			    else if (receive=='2')
			    {
				     LCD_CLEAR();
				     LCD_SetCursor(0,0);
				     LCD_WriteString(" GREEN_COLOUR ");
				     RGB_Colour(green);
				     _delay_ms(2000);
				     flag2=0;
			    }
			    else if (receive=='3')
			    {
				    LCD_CLEAR();
				    LCD_SetCursor(0,0);
				    LCD_WriteString(" Blue_COLOUR ");
				    RGB_Colour(blue);
				    _delay_ms(2000);
				    flag2=0;
			    }
				else if (receive=='0')
				{
					LCD_CLEAR();
					LCD_SetCursor(0,0);
					LCD_WriteString(" White_COLOUR ");
					RGB_Colour(white);
					_delay_ms(2000);
					flag2=0;
				}
				 else if (receive=='4')
				 {
					 LCD_CLEAR();
					 LCD_SetCursor(0,0);
					 LCD_WriteString(" brown_COLOUR ");
					 RGB_Colour(brown);
					 _delay_ms(2000);
					 flag2=0;
				 }
				 else if (receive=='5')
				 {
					 LCD_CLEAR();
					 LCD_SetCursor(0,0);
					 LCD_WriteString(" black_COLOUR ");
					 RGB_Colour(black);
					 _delay_ms(2000);
					 flag2=0;
				 }
				 else if (receive=='6')
				 {
					 LCD_CLEAR();
					 LCD_SetCursor(0,0);
					 LCD_WriteString(" pink_COLOUR ");
					 RGB_Colour(pink);
					 _delay_ms(2000);
					 flag2=0;
				 }
				 else if (receive=='7')
				 {
					 LCD_CLEAR();
					 LCD_SetCursor(0,0);
					 LCD_WriteString(" purple_COLOUR ");
					 RGB_Colour(purple);
					 _delay_ms(2000);
					 flag2=0;
				 }
				else
				{
					flag2=0;
				}
		
		
	}
 }
}
 
		
		
	 
 

		
	 
 

 
 