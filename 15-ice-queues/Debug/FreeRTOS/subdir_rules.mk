################################################################################
# Automatically-generated file. Do not edit!
################################################################################

SHELL = cmd.exe

# Each subdirectory must supply rules for building sources it contributes
FreeRTOS/croutine.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/croutine.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/event_groups.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/event_groups.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/heap_4.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/MemMang/heap_4.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/list.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/list.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/queue.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/queue.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/stream_buffer.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/stream_buffer.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/tasks.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/tasks.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '

FreeRTOS/timers.obj: I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/timers.c $(GEN_OPTS) | $(GEN_FILES) $(GEN_MISC_FILES)
	@echo 'Building file: "$<"'
	@echo 'Invoking: Arm Compiler'
	"C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/bin/armcl" -mv7M4 --code_state=16 --float_support=FPv4SPD16 -me --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/ccs_base/arm/include/CMSIS" --include_path="C:/ProgramData/App-V/883E8076-D99D-4911-93C4-940332A6BE1F/BFE39798-EFFD-4CAF-929B-E5A85FC35347/Root/ccs/tools/compiler/ti-cgt-arm_20.2.4.LTS/include" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/portable/CCS/ARM_CM4F" --include_path="I:/ECE353/code-FreeRTOS/FreeRTOSv202212.01/FreeRTOS/Source/include" --include_path="I:/ECE353/15-ice-queues" --advice:power=all --define=__MSP432P401R__ --define=ccs -g --gcc --diag_warning=225 --diag_wrap=off --display_error_number --abi=eabi --preproc_with_compile --preproc_dependency="FreeRTOS/$(basename $(<F)).d_raw" --obj_directory="FreeRTOS" $(GEN_OPTS__FLAG) "$<"
	@echo 'Finished building: "$<"'
	@echo ' '


