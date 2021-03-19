#include <stdlib.h>
#include <stdio.h>
#include <string.h>
#include "memory.h"

BepsRAM *beps_CreateRAM(uint32_t ram_size) {
	BepsRAM *ram = malloc(sizeof(BepsRAM));
	ram->ram = malloc(ram_size);
	ram->ram_size = ram_size;

	if (ram->ram == NULL) {
		fprintf(stderr, "Failed to alloc RAM\n");
		free(ram);
		return NULL;
	}

	return ram;
}

void beps_ResetRAM(BepsRAM *ram) {
	memset(ram->ram, 0, ram->ram_size);
}

void beps_FreeRAM(BepsRAM *ram) {
	free(ram->ram);
	free(ram);
}
