
#include  "../LIB/STD_Types.h"

#include "../HAL/EEPROM/EEPROM_interface.h"
#include "../HAL/LCD/LCD_interface.h"
#include "../HAL/KeyPade/KeyPade_interface.h"
#include "../HAL/LED/LED_interface.h"
#include "../HAL/Servo/Servo_interface.h"
#include "../HAL/Bluetooth/Bluetooth_interface.h"
#include "../HAL/BUZZER/BUZZER_interface.h"
#include <avr/delay.h>
#include <string.h>
#define SLAVE1 0x12



u32 PASSWORD = 0;
u8 NAME[20] ;


u8  byte= 0 ,address = 0;
u8 data ;
void Get_Password()
{
	byte = 0 ;
	PASSWORD = 0 ;
	u8 data ;
	address++ ;
	while(data != '='&& data !=0x0D)
	{
		//data = Keypad_getkey();
		data = Bluetooth_RecieveData();
		if(data != -1 && data != '=' && data !=0x0D)
		{
			HLCD_SendData('*');
			data-=48 ;
			EEPROM_SendByte(data ,address);
			PASSWORD+=data ;
			PASSWORD*=10;
			address++ ;
		}
	}
	PASSWORD/=10 ;
	EEPROM_SendByte(0xFF ,address);
}

void Get_name()
{
	address = 0 ;
	byte = 0 ;
	PASSWORD = 0 ;
	u8 index=0 ;
	while(data != '='&& data !=0x0D)
	{

		//data = Keypad_getkey();
		data = Bluetooth_RecieveData();
		if(data != -1 && data != '=' && data !=0x0D)
		{
			HLCD_SendData(data);
			EEPROM_SendByte(data ,address);
			NAME[index] = data ;
			address++ ;
			index++ ;
		}
	}
	NAME[index] = '\0' ;
	EEPROM_SendByte(0xFF ,address);
}
int main()
{

	u8 count=3 ,flage = 0;
	u32 input_Pass =0;
	u8 input_name[20];
	u8 index=0 ;

	HLCD_voidinit();
	Keypad_init();
	Servo_Init();
	EEPROM_Init();
	Bluetooth_Init();
	BUZZER_voidInit(BUZZER1);
	LED_voidInit(LED1);
    LED_voidInit(LED2);

	Servo_SetAngle(SERVO1 ,0);
	HLCD_GOTO_XY(1,1);
	HLCD_PrintString(" Wellcome");
	_delay_ms(1000);
	HLCD_voidCommand(LCD_Clear_Screen);


	//EEPROM_SendByte(0xFF ,address);
	EEPROM_ReadByte(&byte , address);
	if(byte == 0xFF)
	{


		HLCD_PrintString("for first time");
		_delay_ms(1500);
		HLCD_voidCommand(LCD_Clear_Screen);
		HLCD_PrintString("Enter name");
		HLCD_GOTO_XY(2,1);
		Get_name();
		HLCD_voidCommand(LCD_Clear_Screen);
		_delay_ms(50);
		HLCD_PrintString("Enter password");
		HLCD_GOTO_XY(2,1);
		Get_Password();
	}
	else
	{
		while(byte != 0xFF)
		{
			NAME[index] = byte ;
			address++ ;
			EEPROM_ReadByte(&byte ,address);
			index++ ;
		}

		address++ ;
		EEPROM_ReadByte(&byte ,address);
		while(byte != 0xFF)
		{
			PASSWORD+=byte ;
			PASSWORD*=10;
			address++ ;
			EEPROM_ReadByte(&byte ,address);
		}
		PASSWORD/=10 ;
	}

	while(1)
	{
		data = 0 ;
		input_Pass = 0 ;
		flage = 0;
		count= 3 ;
		index =  0 ;
		HLCD_voidCommand(LCD_Clear_Screen);
		HLCD_PrintString(" Enter User name");
		HLCD_GOTO_XY(2,1);
		while(data != '=' && data !=0x0D  )
		{
			//data = Keypad_getkey();
			data = Bluetooth_RecieveData();
			if(data != -1 && data != '='&&data !=0x0D )
			{
				HLCD_SendData(data);
				input_name[index] = data ;
				index++ ;
			}
		}
		input_name[index] = '\0' ;

		if(!strcmp(input_name ,NAME))
		{
			HLCD_voidCommand(LCD_Clear_Screen);
			HLCD_PrintString(" Enter Password");
			while(count--)
			{
				data = 0 ;
				HLCD_GOTO_XY(2,1);
				while(data != '=' && data !=0x0D  )
				{
					//data = Keypad_getkey();
					data = Bluetooth_RecieveData();
					if(data != -1 && data != '='&&data !=0x0D )
					{
						HLCD_SendData('*');
						input_Pass += data-48 ;
						input_Pass*=10 ;
					}
				}
				input_Pass/=10 ;
				HLCD_voidCommand(LCD_Clear_Screen);
				if(input_Pass == PASSWORD)
				{
					flage  = 1 ;
					HLCD_PrintString(" Correct PASS");
					Servo_SetAngle(SERVO1 ,90);
                    LED_voidSetLEDHigh(LED2);
					_delay_ms(2000);
                    LED_voidSetLEDLow(LED2);
					break ;
				}
				else
				{
					HLCD_PrintString(" Incorrect PASS");
					if(count)
					{
						_delay_ms(1500);
						HLCD_voidCommand(LCD_Clear_Screen);
						HLCD_PrintString(" Try again");
					}
				}
				data = 0 ;
				input_Pass = 0 ;
			}

			if(flage)
			{
				HLCD_voidCommand(LCD_Clear_Screen);
				Servo_SetAngle(SERVO1 ,0);
				HLCD_voidCommand(LCD_Clear_Screen);
				HLCD_PrintString(" Change Password");
				HLCD_GOTO_XY(2,1);
				HLCD_PrintString(" 1-Y or 2-N : ");
				data = 0 ;
				while(1)
				{
					//data = Keypad_getkey();
					data = Bluetooth_RecieveData();
					if(data == '1')
					{
						HLCD_SendData('1');
						_delay_ms(500);
						HLCD_voidCommand(LCD_Clear_Screen);
						HLCD_PrintString("Enter new name");
						HLCD_GOTO_XY(2,1);
						Get_name();
						HLCD_voidCommand(LCD_Clear_Screen);
						HLCD_PrintString("Enter new password");
						HLCD_GOTO_XY(2,1);
						Get_Password();
						break ;
					}
					else if(data == '2')
					{
						HLCD_SendData('2');
						break ;
					}

				}
			}
			else
			{
				BUZZER_voidSetBuzzerHigh(BUZZER1);
				LED_voidSetLEDHigh(LED1);
				_delay_ms(3000);
				BUZZER_voidSetBuzzerLow(BUZZER1);
				LED_voidSetLEDLow(LED1);
			}
		}
		else
		{
			HLCD_voidCommand(LCD_Clear_Screen);
			HLCD_PrintString("Incorrect Name");
			_delay_ms(2000);
		}
		HLCD_voidCommand(LCD_Clear_Screen);
		Servo_SetAngle(SERVO1 ,0);
	}
	return 0 ;

}
