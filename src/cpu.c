#include <stdlib.h>
#include <string.h>
#include <stdio.h>
#include "cpu.h"
#include "instructions.h"

void beps_ExecuteCPU(BepsCPU *cpu) {
	char opcode = cpu->instruction & 0x1f;
	
	switch (opcode) {
		// ADDI
		case 0x01:
			instruction_ADDI(cpu);
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