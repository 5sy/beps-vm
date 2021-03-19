#ifndef BEPSVM_CPU
#define BEPSVM_CPU

#include <stdint.h>

typedef struct {
	uint32_t REG[32];
	uint32_t instruction;
} BepsCPU;

// Execute a instruction on the CPU
void beps_ExecuteCPU(BepsCPU *cpu);

// Creates a new CPU and resets it
BepsCPU *beps_CreateCPU();

// Resets all CPU values to default
void beps_ResetCPU(BepsCPU *cpu);

// Destroys a CPU
void beps_FreeCPU(BepsCPU *cpu);

#endif