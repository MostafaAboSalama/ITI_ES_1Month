################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include 3-APP/subdir.mk
-include 2-HAL/08_SERVO/subdir.mk
-include 2-HAL/07_STEPPER/subdir.mk
-include 2-HAL/06_KPD/subdir.mk
-include 2-HAL/05_LCD/subdir.mk
-include 2-HAL/04_SSD/subdir.mk
-include 2-HAL/03_SW/subdir.mk
-include 2-HAL/02_BUZ/subdir.mk
-include 2-HAL/01_LED/subdir.mk
-include 1-MCAL/3_GIE/subdir.mk
-include 1-MCAL/2_TIMER/subdir.mk
-include 1-MCAL/1_EXTI/subdir.mk
-include 1-MCAL/0_DIO/subdir.mk
-include 1-MCAL/05_SPI/subdir.mk
-include 1-MCAL/04_UART/subdir.mk
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

OPTIONAL_TOOL_DEPS := \
$(wildcard ../makefile.defs) \
$(wildcard ../makefile.init) \
$(wildcard ../makefile.targets) \


BUILD_ARTIFACT_NAME := SERVO
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SERVO.lss \

FLASH_IMAGE += \
SERVO.hex \

EEPROM_IMAGE += \
SERVO.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: SERVO.elf secondary-outputs

# Tool invocations
SERVO.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SERVO.map -mmcu=atmega16 -o "SERVO.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SERVO.lss: SERVO.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SERVO.elf  >"SERVO.lss"
	@echo 'Finished building: $@'
	@echo ' '

SERVO.hex: SERVO.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SERVO.elf  "SERVO.hex"
	@echo 'Finished building: $@'
	@echo ' '

SERVO.eep: SERVO.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SERVO.elf  "SERVO.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SERVO.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SERVO.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SERVO.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
