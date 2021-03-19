#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "cpu.h"
#include "memory.h"

int run_vm(const char *filePath) {
	FILE *file;
	BepsCPU *cpu;
	BepsRAM *ram;
	char header[5];
	size_t file_size;
	uint32_t i = 0;

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

	// Create CPU
	cpu = beps_CreateCPU();

	// Run instructions
	while (1) {
		cpu->instruction = ram->ram[i];
		beps_ExecuteCPU(cpu);

		i += 4;
		if (i >= ram->ram_size) {
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