#ifndef BEPSVM_CPU
#define BEPSVM_CPU

#include <stdint.h>

// Instruction opcodes
#define INSTRUCTION_ADDI 	0x01
#define INSTRUCTION_SYSCALL	0x1f

typedef struct {
	uint32_t REG[32];
	uint32_t instruction;
} BepsCPU;


// Get a value from given register
uint32_t cpu_GetReg(BepsCPU *cpu, uint8_t reg);

// Set a value from given register
void cpu_SetReg(BepsCPU *cpu, uint8_t reg, uint32_t value);

// Execute a instruction on the CPU
void beps_ExecuteCPU(BepsCPU *cpu);

// Creates a new CPU and resets it
BepsCPU *beps_CreateCPU();

// Resets all CPU values to default
void beps_ResetCPU(BepsCPU *cpu);

// Destroys a CPU
void beps_FreeCPU(BepsCPU *cpu);

#endif