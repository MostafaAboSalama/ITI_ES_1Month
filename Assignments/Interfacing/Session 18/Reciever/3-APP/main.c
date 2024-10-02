#define F_CPU 8000000
#include <util/delay.h>
#include "../2-HAL/01_LED/LED_interface.h"
#include "../4-LIB/BIT_MATH.H"
#include "../4-LIB/STD_TYPES.H"
#include "../1-MCAL/3_GIE/GIE_interface.h"
#include "../1-MCAL/1_EXTI/EXTI_interface.h"
#include "../1-MCAL/2_TIMER/TMR1_interface.h"
#include "../2-HAL/05_LCD/LCD_interface.h"

LED_Type led1 = {LED_PORTD, LED_PIN5, ACTIVE_HIGH};

u16 risingEdgeTime = 0;
u16 fallingEdgeTime = 0;
u16 ofTime = 0;
u16 onTime = 0;
f32 dutyCycle = 0;

void ICU_LED()
{
    static u8 edgeFlag = 0;

    if (edgeFlag == 0)
    {
        risingEdgeTime = TMR1_u16ICU_Read();
        TMR1_voidICU_SetEdge(ICU_FALLING_EDGE);
        edgeFlag = 1;
    }
    else if (edgeFlag == 1)
    {
        fallingEdgeTime = TMR1_u16ICU_Read();
        ofTime = fallingEdgeTime - risingEdgeTime;
        TMR1_voidICU_SetEdge(ICU_RISING_EDGE);
        edgeFlag = 2;
    }
    else if (edgeFlag == 2)
    {
        onTime = TMR1_u16ICU_Read() - fallingEdgeTime;
         dutyCycle = (onTime * 100.0) / (onTime + ofTime);

        // Display Period and Duty Cycle on LCD

        edgeFlag = 0;
    }

    LED_voidToggle(led1);
}

int main()
{
    LED_voidInit(led1);
    LCD_voidInit();
    TMR1_voidICU_Init();
    TMR1_voidICU_SetEdge(ICU_RISING_EDGE);
    TMR1_voidSetCallBack(ICU_LED);
    GIE_voidEnable();

    while(1)
    {
    	LCD_voidSendCommand(LCD_CLEAR);
    	        LCD_voidSendString("Period: ");
    	        LCD_voidSendNumber(onTime+ofTime);
    	        LCD_voidSendString(" us");
    	        _delay_ms(1000);
    	        LCD_voidSendCommand(LCD_CLEAR);
    	        LCD_voidSendString("DC: ");
    	        LCD_voidSendNumber(dutyCycle);
    	        LCD_voidSendString(" %");
    	        _delay_ms(1000);
    }
    return 0;
}
