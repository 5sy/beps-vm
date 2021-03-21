#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

uint32_t cpu_GetReg(BepsCPU *cpu, uint8_t reg) {
	return cpu->REG[reg];
}

void cpu_SetReg(BepsCPU *cpu, uint8_t reg, uint32_t value) {
	// If register is 0, multiply value by 0, since register 0 always remains 0
	// Faster than using 'if' as no cpu branching.
	cpu->REG[reg] = value * (reg != 0);
}

void beps_ExecuteCPU(BepsCPU *cpu) {
	char opcode = cpu->instruction & 0x1f;
	switch (opcode) {
		// ADDI
		case INSTRUCTION_ADDI:
			instruction_ADDI(cpu);
			break;
		// SYSCALL
		case INSTRUCTION_SYSCALL:
			instruction_SYSCALL(cpu);
			break;
		default:
			fprintf(stderr, "Unknown opcode 0x%X\n", opcode);
			break;
	}
}

BepsCPU *beps_CreateCPU() {
	BepsCPU *cpu = malloc(sizeof(BepsCPU));
	beps_ResetCPU(cpu);
	return cpu;
}

void beps_ResetCPU(BepsCPU *cpu) {
	memset(cpu, 0, sizeof(BepsCPU));
}

void beps_FreeCPU(BepsCPU *cpu) {
	free(cpu);
}