################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../CLCD_project.c \
../DIO_project.c \
../KEY_project.c \
../SSD_project.c \
../main.c 

OBJS += \
./CLCD_project.o \
./DIO_project.o \
./KEY_project.o \
./SSD_project.o \
./main.o 

C_DEPS += \
./CLCD_project.d \
./DIO_project.d \
./KEY_project.d \
./SSD_project.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


