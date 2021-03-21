#ifndef BEPSVM_SYSCALLS
#define BEPSVM_SYSCALLS

#include <stdint.h>
#include "cpu.h"

// Syscall table
#define SYSCALL_EXIT 0x01

// Executes a syscall with given code
void syscall_Execute(BepsCPU *cpu, uint32_t code);

#endif