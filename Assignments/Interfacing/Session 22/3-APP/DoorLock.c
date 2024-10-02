/*
 * DoorLock.c
 *
 *  Created on: Jul 26, 2024
 *      Author: AboSalama
 */
#define F_CPU 8000000
#include <util/delay.h>

#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"
#include "../2-HAL/06_KPD/KPD_interface.h"
#include "../2-HAL/09_EEPROM/EEPROM_interface.h"
#include "../2-HAL/08_SERVO/SERVO_interface.h"

u32 GetPasswordFromEEPROM(void);
u8 CheckPassword(u32 RealPassword);
void ChangePassword(void);

int main()
{
    LCD_voidInit();
    SERVO_voidInit();
    SERVO_voidSetAngle(SERVO1, -90);
    KPD_voidInit();
    EEPROM_voidInit(10000);

    // Set the password for the first time
   /* EEPROM_voidWrite(11, 9);
    _delay_ms(100);
    EEPROM_voidWrite(11, 10);
    _delay_ms(100);*/

    // Read the stored password
    u32 RealPassword = GetPasswordFromEEPROM();

    // Welcome message
    LCD_voidSendString("Welcome");
    _delay_ms(2000);
    LCD_voidSendCommand(LCD_CLEAR);

    // Check the password
    if (CheckPassword(RealPassword))
    {
        LCD_voidSendString("Access Granted");
        SERVO_voidSetAngle(SERVO1, 90);
        _delay_ms(1000);
        LCD_voidSendCommand(LCD_CLEAR);
        LCD_voidSendString("1-Change PW 2-No :");

        u8 change;
        do
        {
            change = KPD_u8GetPressed();
        } while (change == NOT_PRESSED);

        if (change == '1')
        {
        	_delay_ms(200);
            ChangePassword();
        }
        else
        {
            LCD_voidSendCommand(LCD_CLEAR);
            LCD_voidSendString("ENJOY!");
        }
    }
    else
    {
        LCD_voidSendCommand(LCD_CLEAR);
        LCD_voidSendString("No more tries");
    }

    return 0;
}

// Function to read the password from EEPROM
u32 GetPasswordFromEEPROM(void)
{
    _delay_ms(100);
    u8 data1 = EEPROM_u8Read(9);
    _delay_ms(100);
    u8 data2 = EEPROM_u8Read(10);
    return (data1 * 100) + data2;
}

// Function to check the entered password
u8 CheckPassword(u32 RealPassword)
{
    u8 pressed, cnt, tries = 3;
    u32 EnteredPassword;
    while (tries > 0)
    {
        cnt = 0;
        EnteredPassword = 0;
        LCD_voidSendString("Enter password :");
        LCD_voidSetPosition(2, 8);
        while (cnt < 4)
        {
            pressed = KPD_u8GetPressed();
            if (pressed != NOT_PRESSED)
            {
                LCD_voidSendData('*');
                EnteredPassword = (EnteredPassword * 10) + (pressed - '0');
                cnt++;
                _delay_ms(200);
            }
        }

        LCD_voidSendCommand(LCD_CLEAR);
        if (EnteredPassword == RealPassword)
        {
            return 1;
        }
        else
        {
            tries--;
            LCD_voidSendString("Access Denied");
            LCD_voidSetPosition(2, 1);
            LCD_voidSendString("Tries left : ");
            LCD_voidSendData(tries + '0'); // Convert tries to character
            _delay_ms(1500);
            LCD_voidSendCommand(LCD_CLEAR);
        }
    }
    return 0;
}

// Function to change the password and store it in EEPROM
void ChangePassword(void)
{
    u8 pressed, cnt;
    u32 NewPassword = 0;

    LCD_voidSendCommand(LCD_CLEAR);
    LCD_voidSendString("Enter new PW:");
    LCD_voidSetPosition(2, 8);

    cnt = 0;
    while (cnt < 4)
    {
        pressed = KPD_u8GetPressed();
        if (pressed != NOT_PRESSED)
        {
            LCD_voidSendData('*');
            NewPassword = (NewPassword * 10) + (pressed - '0');
            cnt++;
            _delay_ms(200);
        }
    }

    // Split the new password into two bytes and store them in EEPROM
    u8 data1 = NewPassword / 100;
    u8 data2 = NewPassword % 100;
    EEPROM_voidWrite(data1, 9);
    _delay_ms(100);
    EEPROM_voidWrite(data2, 10);
    _delay_ms(100);

    LCD_voidSendCommand(LCD_CLEAR);
    LCD_voidSendString("PW Changed!");
}
