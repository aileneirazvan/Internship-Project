################################################################################
# Automatically-generated file. Do not edit!
################################################################################

-include ../makefile.init

RM := rm -rf

# All of the sources participating in the build are defined here
-include sources.mk
-include src/subdir.mk
-include emlib/subdir.mk
-include Drivers/subdir.mk
-include CMSIS/EFM32ZG/subdir.mk
-include BSP/subdir.mk
-include subdir.mk
-include objects.mk

ifneq ($(MAKECMDGOALS),clean)
ifneq ($(strip $(C_DEPS)),)
-include $(C_DEPS)
endif
endif

-include ../makefile.defs

# Add inputs and outputs from these tool invocations to the build variables 

# All Target
all: Copy\ of\ Copy\ of\ STK3200_touch_3.axf

# Tool invocations
Copy\ of\ Copy\ of\ STK3200_touch_3.axf: $(OBJS) $(USER_OBJS)
	@echo 'Building target: $@'
	@echo 'Invoking: GNU ARM C Linker'
	arm-none-eabi-gcc -g3 -gdwarf-2 -mcpu=cortex-m0plus -mthumb -T "Copy of Copy of STK3200_touch_3.ld" -Xlinker --gc-sections -Xlinker -Map="Copy of Copy of STK3200_touch_3.map" --specs=nano.specs -o "Copy of Copy of STK3200_touch_3.axf" "./BSP/bsp_bcc.o" "./BSP/bsp_stk.o" "./BSP/bsp_stk_leds.o" "./CMSIS/EFM32ZG/startup_efm32zg.o" "./CMSIS/EFM32ZG/system_efm32zg.o" "./Drivers/display.o" "./Drivers/displayls013b7dh03.o" "./Drivers/displaypalemlib.o" "./Drivers/dmactrl.o" "./Drivers/retargetio.o" "./Drivers/retargettextdisplay.o" "./Drivers/textdisplay.o" "./Drivers/udelay.o" "./emlib/em_acmp.o" "./emlib/em_adc.o" "./emlib/em_assert.o" "./emlib/em_cmu.o" "./emlib/em_core.o" "./emlib/em_dma.o" "./emlib/em_ebi.o" "./emlib/em_emu.o" "./emlib/em_gpio.o" "./emlib/em_leuart.o" "./emlib/em_prs.o" "./emlib/em_rtc.o" "./emlib/em_system.o" "./emlib/em_timer.o" "./emlib/em_usart.o" "./src/capsense_touch3.o" "./src/main.o" "./src/menu.o" "./src/problema1.o" "./src/problema2.o" "./src/problema3.o" -Wl,--start-group -lgcc -lc -lnosys -Wl,--end-group
	@echo 'Finished building target: $@'
	@echo ' '

	@echo 'Building hex file: Copy of Copy of STK3200_touch_3.hex'
	arm-none-eabi-objcopy -O ihex "Copy of Copy of STK3200_touch_3.axf" "Copy of Copy of STK3200_touch_3.hex"
	@echo ' '

	@echo 'Building bin file: Copy of Copy of STK3200_touch_3.bin'
	arm-none-eabi-objcopy -O binary "Copy of Copy of STK3200_touch_3.axf" "Copy of Copy of STK3200_touch_3.bin"
	@echo ' '

	@echo 'Building s37 file: Copy of Copy of STK3200_touch_3.s37'
	arm-none-eabi-objcopy -O srec "Copy of Copy of STK3200_touch_3.axf" "Copy of Copy of STK3200_touch_3.s37"
	@echo ' '

	@echo 'Running size tool'
	arm-none-eabi-size "Copy of Copy of STK3200_touch_3.axf" -A
	@echo ' '

# Other Targets
clean:
	-$(RM) $(EXECUTABLES)$(OBJS)$(C_DEPS) "Copy of Copy of STK3200_touch_3.axf"
	-@echo ' '

.PHONY: all clean dependents
.SECONDARY:

-include ../makefile.targets
