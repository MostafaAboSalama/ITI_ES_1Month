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


BUILD_ARTIFACT_NAME := SPI_SLAVE
BUILD_ARTIFACT_EXTENSION := elf
BUILD_ARTIFACT_PREFIX :=
BUILD_ARTIFACT := $(BUILD_ARTIFACT_PREFIX)$(BUILD_ARTIFACT_NAME)$(if $(BUILD_ARTIFACT_EXTENSION),.$(BUILD_ARTIFACT_EXTENSION),)

# Add inputs and outputs from these tool invocations to the build variables 
LSS += \
SPI_SLAVE.lss \

FLASH_IMAGE += \
SPI_SLAVE.hex \

EEPROM_IMAGE += \
SPI_SLAVE.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: main-build

# Main-build Target
main-build: SPI_SLAVE.elf secondary-outputs

# Tool invocations
SPI_SLAVE.elf: $(OBJS) $(USER_OBJS) makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,SPI_SLAVE.map -mmcu=atmega16 -o "SPI_SLAVE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

SPI_SLAVE.lss: SPI_SLAVE.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S SPI_SLAVE.elf  >"SPI_SLAVE.lss"
	@echo 'Finished building: $@'
	@echo ' '

SPI_SLAVE.hex: SPI_SLAVE.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex SPI_SLAVE.elf  "SPI_SLAVE.hex"
	@echo 'Finished building: $@'
	@echo ' '

SPI_SLAVE.eep: SPI_SLAVE.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex SPI_SLAVE.elf  "SPI_SLAVE.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: SPI_SLAVE.elf makefile objects.mk $(OPTIONAL_TOOL_DEPS)
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega16 SPI_SLAVE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) SPI_SLAVE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents main-build

-include ../makefile.targets
