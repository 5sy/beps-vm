#ifndef BEPSVM_MEMORY
#define BEPSVM_MEMORY

typedef struct {
	uint8_t *ram;
	uint32_t ram_size;
} BepsRAM;

// Creates new RAM with given size
BepsRAM *beps_CreateRAM(uint32_t ram_size);

// Clears all RAM to 0
void beps_ResetRAM(BepsRAM *ram);

// Frees all memory
void beps_FreeRAM(BepsRAM *ram);

#endif