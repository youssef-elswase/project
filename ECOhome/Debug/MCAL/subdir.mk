################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../MCAL/ADC_prog.c \
../MCAL/DIO_program.c \
../MCAL/EEPROM_prog.c \
../MCAL/TIMER_program.c \
../MCAL/TWI_prog.c 

OBJS += \
./MCAL/ADC_prog.o \
./MCAL/DIO_program.o \
./MCAL/EEPROM_prog.o \
./MCAL/TIMER_program.o \
./MCAL/TWI_prog.o 

C_DEPS += \
./MCAL/ADC_prog.d \
./MCAL/DIO_program.d \
./MCAL/EEPROM_prog.d \
./MCAL/TIMER_program.d \
./MCAL/TWI_prog.d 


# Each subdirectory must supply rules for building sources it contributes
MCAL/%.o: ../MCAL/%.c MCAL/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


