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
ButtonWith7Seg.lss \

FLASH_IMAGE += \
ButtonWith7Seg.hex \

EEPROM_IMAGE += \
ButtonWith7Seg.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: ButtonWith7Seg.elf secondary-outputs

# Tool invocations
ButtonWith7Seg.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,ButtonWith7Seg.map -mmcu=atmega32 -o "ButtonWith7Seg.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

ButtonWith7Seg.lss: ButtonWith7Seg.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S ButtonWith7Seg.elf  >"ButtonWith7Seg.lss"
	@echo 'Finished building: $@'
	@echo ' '

ButtonWith7Seg.hex: ButtonWith7Seg.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex ButtonWith7Seg.elf  "ButtonWith7Seg.hex"
	@echo 'Finished building: $@'
	@echo ' '

ButtonWith7Seg.eep: ButtonWith7Seg.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex ButtonWith7Seg.elf  "ButtonWith7Seg.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: ButtonWith7Seg.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 ButtonWith7Seg.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) ButtonWith7Seg.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
