#include <stdio.h>
#include <stdint.h>
#include "instructions.h"
#include "syscalls.h"

void instruction_ADDI(BepsCPU *cpu) {
	uint8_t outputReg = (cpu->instruction >> 6) & 0x1f;
	uint8_t inputReg = (cpu->instruction >> 11) & 0x1f;
	uint16_t value = (cpu->instruction >> 16) & 0xffff;
	printf("0x%08X: ADDI %d, %d, %d\n", cpu->instruction, outputReg, inputReg, value);

	cpu_SetReg(cpu, outputReg, cpu_GetReg(cpu, inputReg) + value);
}

void instruction_SYSCALL(BepsCPU *cpu) {
	uint8_t inputReg = (cpu->instruction >> 6) & 0x1f;
	uint32_t syscallCode = cpu_GetReg(cpu, inputReg);
	printf("0x%08X: SYSCALL %d\n", cpu->instruction, inputReg);

	syscall_Execute(cpu, syscallCode);
}

