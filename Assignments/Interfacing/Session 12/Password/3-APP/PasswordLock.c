/*
 * PasswordLock.c
 *
 *  Created on: Jul 26, 2024
 *      Author: user
 */
#define F_CPU 8000000
#include <avr/io.h>
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"
#include "../2-HAL/06_KPD/KPD_interface.h"

#include "../4-LIB/BIT_MATH.h"
#include "../4-LIB/STD_TYPES.h"

#define DELAY_TIME 1000
#define PASSWORD 1234
#define NOT_PRESSED 0xFF // Ensure NOT_PRESSED is defined

int main(void)
{
    KPD_voidInit();
    LCD_voidInit();
    LED_Type CorrectGreen = {LED_PORTB, LED_PIN1, ACTIVE_HIGH};
    LED_Type WrongRed = {LED_PORTB, LED_PIN0, ACTIVE_HIGH};
    LED_voidInit(CorrectGreen);
    LED_voidInit(WrongRed);
    LCD_voidSendString("Welcome");
    _delay_ms(2000);
    LCD_voidSendCommand(LCD_CLEAR);
    LCD_voidSendString("Enter password :");
    LCD_voidSetCursorPosition(2,8);
    u8 pressed, cnt, tries = 3;
    u32 password;
    while(1)
    {
        cnt = 0;
        password = 0;
        while(tries > 0)
        {
            while(cnt < 4)
            {
                pressed = KPD_u8GetPressed();
                if(pressed != NOT_PRESSED)
                {
                    LCD_voidSendData('*');
                    password = (password * 10) + (pressed - '0');
                    cnt++;
                }
            }

            LCD_voidSendCommand(LCD_CLEAR);
            if(password == PASSWORD)
            {
                LCD_voidSendString("Correct");
                LED_voidON(CorrectGreen);
                break;
            }
            else
            {
                tries--;
                LED_voidON(WrongRed);
                LCD_voidSendString("Wrong");
                LCD_voidSetCursorPosition(2,1);
                LCD_voidSendString("Tries left : ");
                LCD_voidSendData(tries + '0'); // Convert tries to character
                _delay_ms(DELAY_TIME);
                LED_voidToggle(WrongRed);
                LCD_voidSendCommand(LCD_CLEAR);
                LCD_voidSendString("Enter password :");
                LCD_voidSetCursorPosition(2,8);
                cnt = 0;
                password = 0;
            }
        }

        if(tries == 0)
        {
            LCD_voidSendCommand(LCD_CLEAR);
            LCD_voidSendString("No more tries");
            break;
        }
    }
    return 0;
}
