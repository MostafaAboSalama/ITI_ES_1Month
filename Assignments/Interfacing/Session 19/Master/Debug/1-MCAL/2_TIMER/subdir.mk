################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../1-MCAL/2_TIMER/TMR1_program.c \
../1-MCAL/2_TIMER/TMR2_program.c 

OBJS += \
./1-MCAL/2_TIMER/TMR1_program.o \
./1-MCAL/2_TIMER/TMR2_program.o 

C_DEPS += \
./1-MCAL/2_TIMER/TMR1_program.d \
./1-MCAL/2_TIMER/TMR2_program.d 


# Each subdirectory must supply rules for building sources it contributes
1-MCAL/2_TIMER/%.o: ../1-MCAL/2_TIMER/%.c 1-MCAL/2_TIMER/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g3 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega16 -DF_CPU=1000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


