#include <stdio.h>
#include <stdint.h>
#include "instructions.h"

uint32_t get_register(BepsCPU *cpu, uint8_t reg) {
	return cpu->REG[reg];
}

void set_register(BepsCPU *cpu, uint8_t reg, uint32_t value) {
	// Set value to 0 if register is 0
	cpu->REG[reg] = value * (reg != 0);
}

void instruction_ADDI(BepsCPU *cpu) {
	uint8_t outputReg = (cpu->instruction >> 6) & 0x1f;
	uint8_t inputReg = (cpu->instruction >> 11) & 0x1f;
	uint16_t value = (cpu->instruction >> 16) & 0xffff;

	set_register(cpu, outputReg, get_register(cpu, inputReg) + value);
	printf("0x%08X: ADDI %d, %d, %d\n", cpu->instruction, outputReg, inputReg, value);
}
