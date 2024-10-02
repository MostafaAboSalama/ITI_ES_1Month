/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<	SSD_interface.h	  >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *	Author : Mostafa Abd-Allah AboSalama
 *	Layer  : HAL 
 *	SWC    : SSD
 *
*/

#ifndef SSD_INTERFACE_H_
#define SSD_INTERFACE_H_


#define SSD_COMM_CAT	0
#define SSD_COMM_AND	1


#define SSD_PORTA 0
#define SSD_PORTB 1
#define SSD_PORTC 2
#define SSD_PORTD 3
		
#define SSD_PIN0 0
#define SSD_PIN1 1
#define SSD_PIN2 2
#define SSD_PIN3 3
#define SSD_PIN4 4
#define SSD_PIN5 5
#define SSD_PIN6 6
#define SSD_PIN7 7


typedef struct
{
	u8 Type;
	u8 DataPort;
	u8 EnPort;
	u8 EnPin;
	
}SSD_Type;



void SSD_voidInit(SSD_Type SSD_Configuration);

void SSD_voidSendNumber(SSD_Type SSD_Configuration, u8 Copy_u8Number);

void SSD_voidEnable(SSD_Type SSD_Configuration);

void SSD_voidDisable(SSD_Type SSD_Configuration);





#endif /* SSD_INTERFACE_H_ */
