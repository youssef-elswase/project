################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../pre/CLCD_project.c \
../pre/KEY_project.c 

OBJS += \
./pre/CLCD_project.o \
./pre/KEY_project.o 

C_DEPS += \
./pre/CLCD_project.d \
./pre/KEY_project.d 


# Each subdirectory must supply rules for building sources it contributes
pre/%.o: ../pre/%.c pre/subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


