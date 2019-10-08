################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
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
LAB1CAPTURE.lss \

FLASH_IMAGE += \
LAB1CAPTURE.hex \

EEPROM_IMAGE += \
LAB1CAPTURE.eep \

SIZEDUMMY += \
sizedummy \


# All Target
all: LAB1CAPTURE.elf secondary-outputs

# Tool invocations
LAB1CAPTURE.elf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: AVR C Linker'
	avr-gcc -Wl,-Map,LAB1CAPTURE.map -mmcu=atmega32 -o "LAB1CAPTURE.elf" $(OBJS) $(USER_OBJS) $(LIBS)
	@echo 'Finished building target: $@'
	@echo ' '

LAB1CAPTURE.lss: LAB1CAPTURE.elf
	@echo 'Invoking: AVR Create Extended Listing'
	-avr-objdump -h -S LAB1CAPTURE.elf  >"LAB1CAPTURE.lss"
	@echo 'Finished building: $@'
	@echo ' '

LAB1CAPTURE.hex: LAB1CAPTURE.elf
	@echo 'Create Flash image (ihex format)'
	-avr-objcopy -R .eeprom -R .fuse -R .lock -R .signature -O ihex LAB1CAPTURE.elf  "LAB1CAPTURE.hex"
	@echo 'Finished building: $@'
	@echo ' '

LAB1CAPTURE.eep: LAB1CAPTURE.elf
	@echo 'Create eeprom image (ihex format)'
	-avr-objcopy -j .eeprom --no-change-warnings --change-section-lma .eeprom=0 -O ihex LAB1CAPTURE.elf  "LAB1CAPTURE.eep"
	@echo 'Finished building: $@'
	@echo ' '

sizedummy: LAB1CAPTURE.elf
	@echo 'Invoking: Print Size'
	-avr-size --format=avr --mcu=atmega32 LAB1CAPTURE.elf
	@echo 'Finished building: $@'
	@echo ' '

# Other Targets
clean:
	-$(RM) $(FLASH_IMAGE)$(ELFS)$(OBJS)$(ASM_DEPS)$(EEPROM_IMAGE)$(S_DEPS)$(SIZEDUMMY)$(S_UPPER_DEPS)$(LSS)$(C_DEPS) LAB1CAPTURE.elf
	-@echo ' '

secondary-outputs: $(LSS) $(FLASH_IMAGE) $(EEPROM_IMAGE) $(SIZEDUMMY)

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
