
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
