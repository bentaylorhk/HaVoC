// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#include <iostream>
#include <spdlog/spdlog.h>

#include "cpu/cpu.h"

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_DEBUG

int main() {
    // Setting up the logger level.
    spdlog::set_level(spdlog::level::trace);

    // read in rom

    // setup registers and memory

    // fetch execute cycle

    // cleanup
    printf("Hello World");
    Cpu cpu;
    cpu.fetch();
    return 0;
}