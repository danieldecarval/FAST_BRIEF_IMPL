################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
C_SRCS += \
../src/brief.c \
../src/fast.c \
../src/fast_10.c \
../src/fast_11.c \
../src/fast_12.c \
../src/fast_9.c \
../src/main.c \
../src/nonmax.c 

OBJS += \
./src/brief.o \
./src/fast.o \
./src/fast_10.o \
./src/fast_11.o \
./src/fast_12.o \
./src/fast_9.o \
./src/main.o \
./src/nonmax.o 

C_DEPS += \
./src/brief.d \
./src/fast.d \
./src/fast_10.d \
./src/fast_11.d \
./src/fast_12.d \
./src/fast_9.d \
./src/main.d \
./src/nonmax.d 


# Each subdirectory must supply rules for building sources it contributes
src/%.o: ../src/%.c
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C Compiler'
	gcc -I/usr/local/include/opencv -I/usr/local/include/opencv2 -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


