################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../ADC_project.c \
../CLCD_project.c \
../DIO_project.c \
../EXTI_project.c \
../GIF_project.c \
../SW_project.c \
../main.c 

OBJS += \
./ADC_project.o \
./CLCD_project.o \
./DIO_project.o \
./EXTI_project.o \
./GIF_project.o \
./SW_project.o \
./main.o 

C_DEPS += \
./ADC_project.d \
./CLCD_project.d \
./DIO_project.d \
./EXTI_project.d \
./GIF_project.d \
./SW_project.d \
./main.d 


# Each subdirectory must supply rules for building sources it contributes
%.o: ../%.c subdir.mk
	@echo 'Building file: $<'
	@echo 'Invoking: AVR Compiler'
	avr-gcc -Wall -g2 -gstabs -O0 -fpack-struct -fshort-enums -ffunction-sections -fdata-sections -std=gnu99 -funsigned-char -funsigned-bitfields -mmcu=atmega32 -DF_CPU=8000000UL -MMD -MP -MF"$(@:%.o=%.d)" -MT"$@" -c -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


