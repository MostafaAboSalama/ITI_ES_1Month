/*
 *<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<<    STD_TYPES.h    >>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>>
 *
 *  Author : Mostafa AboSalama
 *  Layer  : LIB
 *
 */ 


#ifndef STD_TYPES_H_
#define STD_TYPES_H_

#define NULL (void*)(0x00)

typedef unsigned char           u8 ;
typedef unsigned short int      u16;
typedef unsigned long int       u32;
typedef unsigned long long int  u64;
typedef signed char	            s8 ;
typedef signed short int        s16;
typedef signed long int         s32;
typedef signed long long int    s64;
typedef float                   f32;
typedef double                  f64;
typedef enum
	{
		false,
		true,
	}bool;



	
#endif // STD_TYPES_H_ 
