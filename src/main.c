#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"
#include "memory.h"

// Loads an instruction to the cpu from the stack pointer
void load_instruction(BepsCPU *cpu, BepsRAM *ram) {
	uint32_t sp = cpu->REG[29];									// Get register
	memcpy(&cpu->instruction, ram->ram + sp, sizeof(uint32_t));	// Copy 4 uint8_t bytes to 1 uint32_t
}

int run_vm(const char *filePath) {
	FILE *file;
	BepsCPU *cpu;
	BepsRAM *ram;
	char header[5];
	size_t file_size;

	// Read file
	file = fopen(filePath, "rb");
	if (file == NULL) {
		fprintf(stderr, "Failed to open file.\n");
		return 1;
	}

	fseek(file, 0, SEEK_END);
	file_size = ftell(file) - 5;	// File size - header size (5)
	fseek(file, 0, SEEK_SET);

	fread(header, 5, 1, file);
	if (memcmp(header, "BEPS\x01", 5) != 0) {
		fprintf(stderr, "Invalid file\n");
		fclose(file);
		return 1;
	}

	// Create ram and load file
	ram = beps_CreateRAM(file_size);
	fread(ram->ram, file_size, 1, file);
	printf("Created RAM with size 0x%X\n", ram->ram_size);

	// Create CPU
	cpu = beps_CreateCPU();

	// Run instructions
	while (1) {
		load_instruction(cpu, ram);	// Fetch
		beps_ExecuteCPU(cpu);		// Execute

		// Increment stack pointer by 4 and check if out of bounds
		cpu->REG[29] += 4;
		if (cpu->REG[29] >= ram->ram_size ) {
			break;
		}
	}

	// Clean
	beps_FreeCPU(cpu);
	beps_FreeRAM(ram);
	return 0;
}

int main(int argc, char const *argv[]) {
	if (argc < 2) {
		fprintf(stderr, "%s <file>\n", argv[0]);
		return 1;
	}
	
	return run_vm(argv[1]);
}