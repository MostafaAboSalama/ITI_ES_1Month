/*
 * KeyPade_private.h
 *
 *  Created on: Jul 29, 2024
 *      Author: Elmag
 */

#ifndef KEYPADE_KEYPADE_PRIVATE_H_
#define KEYPADE_KEYPADE_PRIVATE_H_

#define KeyPade_PORT PORTB

#define R1 PIN0
#define R2 PIN1
#define R3 PIN2
#define R4 PIN3
#define C1 PIN4
#define C2 PIN5
#define C3 PIN6
#define C4 PIN7

int static Key_padRow[] = {R1, R2, R3,R4 };
int static Key_padCol[] = {C1, C2, C3,C4 };

u8 static digit[4][4]=
{
		{'7','8','9','+'},
		{'4','5','6','-'},
		{'1','2','3','*'},
		{'#','0','=','/'}
};


#endif /* KEYPADE_KEYPADE_PRIVATE_H_ */
