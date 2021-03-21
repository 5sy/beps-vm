#include <stdio.h>
#include <stdlib.h>
#include "syscalls.h"

// Argument registers
#define A0 4
#define A1 5
#define A2 6
#define A3 7

void syscall_Execute(BepsCPU *cpu, uint32_t code) {
	switch (code) {
		case SYSCALL_EXIT:
			exit(cpu_GetReg(cpu, A0));
			break;
		default:
			printf("Unknown SYSCALL code 0x%X\n", code);
			break;
	}
}
