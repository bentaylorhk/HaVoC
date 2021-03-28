// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#include <iostream>

// Registers
uint16_t pc;
uint8_t ac;
uint8_t x;
uint8_t y;
uint8_t sr;
uint8_t sp;

// Internal Working RAM
uint8_t ram[0x800];

void initialiseMemory() {
    // allocate ram
    // setup stack pointer
}

void fetch() {

}

void execute() {

}

int main() {
    // read in rom

    // setup registers and memory

    // fetch execute cycle

    // cleanup
    printf("Hello World");
    return 0;
}