################################################################################
# Automatically-generated file. Do not edit!
################################################################################

# Add inputs and outputs from these tool invocations to the build variables 
CPP_SRCS += \
../source/approximateEntropyTest.cpp \
../source/baseCryptoRandomStream.cpp \
../source/baseRandomTest.cpp \
../source/blockFrequencyTest.cpp \
../source/cumulativeSumForwardTest.cpp \
../source/cumulativeSumReverseTest.cpp \
../source/defaultCryptoRandomStream.cpp \
../source/discreteFourierTransformTest.cpp \
../source/frequencyTest.cpp \
../source/longestRunOfOnesTest.cpp \
../source/mathematicalFunctions.cpp \
../source/randomTestSuite.cpp \
../source/rankTest.cpp \
../source/runsTest.cpp \
../source/serialTest.cpp \
../source/universalTest.cpp 

OBJS += \
./source/approximateEntropyTest.o \
./source/baseCryptoRandomStream.o \
./source/baseRandomTest.o \
./source/blockFrequencyTest.o \
./source/cumulativeSumForwardTest.o \
./source/cumulativeSumReverseTest.o \
./source/defaultCryptoRandomStream.o \
./source/discreteFourierTransformTest.o \
./source/frequencyTest.o \
./source/longestRunOfOnesTest.o \
./source/mathematicalFunctions.o \
./source/randomTestSuite.o \
./source/rankTest.o \
./source/runsTest.o \
./source/serialTest.o \
./source/universalTest.o 

CPP_DEPS += \
./source/approximateEntropyTest.d \
./source/baseCryptoRandomStream.d \
./source/baseRandomTest.d \
./source/blockFrequencyTest.d \
./source/cumulativeSumForwardTest.d \
./source/cumulativeSumReverseTest.d \
./source/defaultCryptoRandomStream.d \
./source/discreteFourierTransformTest.d \
./source/frequencyTest.d \
./source/longestRunOfOnesTest.d \
./source/mathematicalFunctions.d \
./source/randomTestSuite.d \
./source/rankTest.d \
./source/runsTest.d \
./source/serialTest.d \
./source/universalTest.d 


# Each subdirectory must supply rules for building sources it contributes
source/%.o: ../source/%.cpp
	@echo 'Building file: $<'
	@echo 'Invoking: GCC C++ Compiler'
	g++ -I"/home/DiceLock-Work/Development-Work/CPP/DiceChecker-x/DiceChecker-x/header" -O0 -g3 -Wall -c -fmessage-length=0 -MMD -MP -MF"$(@:%.o=%.d)" -MT"$(@:%.o=%.d)" -o "$@" "$<"
	@echo 'Finished building: $<'
	@echo ' '


