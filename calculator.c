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
