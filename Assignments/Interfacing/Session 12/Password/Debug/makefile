################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 3-APP/subdir.mk
-include 2-HAL/06_KPD/subdir.mk
-include 2-HAL/05_LCD/subdir.mk
-include 2-HAL/04_SSD/subdir.mk
-include 2-HAL/03_SW/subdir.mk
-include 2-HAL/02_BUZ/subdir.mk
-include 2-HAL/01_LED/subdir.mk
-include 1-MCAL/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(ASM_DEPS)),)
-include $(ASM_DEPS)
endif
ifneq ($(strip $(S_DEPS)),)
-include $(S_DEPS)
endif
ifneq ($(strip $(S_UPPER_DEPS)),)
-include $(S_UPPER_DEPS)
endif
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
password.lss \

FLASH_IMAGE += \
password.hex \

EEPROM_IMAGE += \
password.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: password.elf secondary-outputs

# Tool invocations
password.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,password.map -mmcu=atmega32 -o "password.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

password.lss: password.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S password.elf  >"password.lss"
	@echo 'Finished building: $@'
	@echo ' '

password.hex: password.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex password.elf  "password.hex"
	@echo 'Finished building: $@'
	@echo ' '

password.eep: password.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex password.elf  "password.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: password.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 password.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) password.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
