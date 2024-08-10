################################################################################
# Automatically-generated file. Do not edit!
# Toolchain: GNU Tools for STM32 (11.3.rel1)
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../Core/Src/button.c \
../Core/Src/buzzer.c \
../Core/Src/gpio.c \
../Core/Src/led_rgb.c \
../Core/Src/line_sensor.c \
../Core/Src/main.c \
../Core/Src/motor.c \
../Core/Src/stm32l0xx_it.c \
../Core/Src/syscalls.c \
../Core/Src/sysmem.c \
../Core/Src/system_stm32l0xx.c \
../Core/Src/timer.c \
../Core/Src/ultrasonic.c \
../Core/Src/usart.c 

OBJS += \
./Core/Src/button.o \
./Core/Src/buzzer.o \
./Core/Src/gpio.o \
./Core/Src/led_rgb.o \
./Core/Src/line_sensor.o \
./Core/Src/main.o \
./Core/Src/motor.o \
./Core/Src/stm32l0xx_it.o \
./Core/Src/syscalls.o \
./Core/Src/sysmem.o \
./Core/Src/system_stm32l0xx.o \
./Core/Src/timer.o \
./Core/Src/ultrasonic.o \
./Core/Src/usart.o 

C_DEPS += \
./Core/Src/button.d \
./Core/Src/buzzer.d \
./Core/Src/gpio.d \
./Core/Src/led_rgb.d \
./Core/Src/line_sensor.d \
./Core/Src/main.d \
./Core/Src/motor.d \
./Core/Src/stm32l0xx_it.d \
./Core/Src/syscalls.d \
./Core/Src/sysmem.d \
./Core/Src/system_stm32l0xx.d \
./Core/Src/timer.d \
./Core/Src/ultrasonic.d \
./Core/Src/usart.d 


# Each subdirectory must supply rules for building sources it contributes
Core/Src/%.o Core/Src/%.su Core/Src/%.cyclo: ../Core/Src/%.c Core/Src/subdir.mk
	arm-none-eabi-gcc "$<" -mcpu=cortex-m0plus -std=gnu11 -g3 -DDEBUG -DSTM32L053xx -DUSE_FULL_LL_DRIVER -DHSE_VALUE=8000000 -DHSE_STARTUP_TIMEOUT=100 -DLSE_STARTUP_TIMEOUT=5000 -DLSE_VALUE=32768 -DMSI_VALUE=2097000 -DHSI_VALUE=16000000 -DLSI_VALUE=37000 -DVDD_VALUE=3300 -DPREFETCH_ENABLE=0 -DINSTRUCTION_CACHE_ENABLE=1 -DDATA_CACHE_ENABLE=1 -c -I../Core/Inc -I../Drivers/STM32L0xx_HAL_Driver/Inc -I../Drivers/CMSIS/Device/ST/STM32L0xx/Include -I../Drivers/CMSIS/Include -O0 -ffunction-sections -fdata-sections -Wall -fstack-usage -fcyclomatic-complexity -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" --specs=nano.specs -mfloat-abi=soft -mthumb -o "$@"

clean: clean-Core-2f-Src

clean-Core-2f-Src:
	-$(RM) ./Core/Src/button.cyclo ./Core/Src/button.d ./Core/Src/button.o ./Core/Src/button.su ./Core/Src/buzzer.cyclo ./Core/Src/buzzer.d ./Core/Src/buzzer.o ./Core/Src/buzzer.su ./Core/Src/gpio.cyclo ./Core/Src/gpio.d ./Core/Src/gpio.o ./Core/Src/gpio.su ./Core/Src/led_rgb.cyclo ./Core/Src/led_rgb.d ./Core/Src/led_rgb.o ./Core/Src/led_rgb.su ./Core/Src/line_sensor.cyclo ./Core/Src/line_sensor.d ./Core/Src/line_sensor.o ./Core/Src/line_sensor.su ./Core/Src/main.cyclo ./Core/Src/main.d ./Core/Src/main.o ./Core/Src/main.su ./Core/Src/motor.cyclo ./Core/Src/motor.d ./Core/Src/motor.o ./Core/Src/motor.su ./Core/Src/stm32l0xx_it.cyclo ./Core/Src/stm32l0xx_it.d ./Core/Src/stm32l0xx_it.o ./Core/Src/stm32l0xx_it.su ./Core/Src/syscalls.cyclo ./Core/Src/syscalls.d ./Core/Src/syscalls.o ./Core/Src/syscalls.su ./Core/Src/sysmem.cyclo ./Core/Src/sysmem.d ./Core/Src/sysmem.o ./Core/Src/sysmem.su ./Core/Src/system_stm32l0xx.cyclo ./Core/Src/system_stm32l0xx.d ./Core/Src/system_stm32l0xx.o ./Core/Src/system_stm32l0xx.su ./Core/Src/timer.cyclo ./Core/Src/timer.d ./Core/Src/timer.o ./Core/Src/timer.su ./Core/Src/ultrasonic.cyclo ./Core/Src/ultrasonic.d ./Core/Src/ultrasonic.o ./Core/Src/ultrasonic.su ./Core/Src/usart.cyclo ./Core/Src/usart.d ./Core/Src/usart.o ./Core/Src/usart.su

.PHONY: clean-Core-2f-Src

