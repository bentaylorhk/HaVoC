// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#include "cpu.h"

#include <cstdint>
#include <stdio.h>
#include <spdlog/spdlog.h>

// Constructor.
Cpu::Cpu() {
    pc = 0;
    ac = 0;
    x = 0;
    y = 0;
    sr = 0;
    sp = 0;
}

// Destructor.
Cpu::~Cpu() {

}

void Cpu::fetch() {
    
}

void Cpu::execute() {
}
