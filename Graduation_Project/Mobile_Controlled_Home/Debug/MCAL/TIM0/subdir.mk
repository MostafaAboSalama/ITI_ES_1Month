################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/TIM0/TIM0_program.c 

OBJS += \
./MCAL/TIM0/TIM0_program.o 

C_DEPS += \
./MCAL/TIM0/TIM0_program.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/TIM0/%.o: ../MCAL/TIM0/%.c MCAL/TIM0/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gdwarf-2 -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


