################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../adc.c \
../buzzer.c \
../dc_motor.c \
../gpio.c \
../heater.c \
../keypad.c \
../lcd.c \
../led.c \
../main.c \
../pwm.c \
../temperature_sensor.c 

OBJS += \
./adc.o \
./buzzer.o \
./dc_motor.o \
./gpio.o \
./heater.o \
./keypad.o \
./lcd.o \
./led.o \
./main.o \
./pwm.o \
./temperature_sensor.o 

C_DEPS += \
./adc.d \
./buzzer.d \
./dc_motor.d \
./gpio.d \
./heater.d \
./keypad.d \
./lcd.d \
./led.d \
./main.d \
./pwm.d \
./temperature_sensor.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=16000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


