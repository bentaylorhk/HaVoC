// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include <iostream>
#include <spdlog/spdlog.h>

#include "cpu/cpu.h"

int main() {
    // Setting up the logger level.
    spdlog::set_level(spdlog::level::trace);

    // read in rom

    // setup registers and memory

    // fetch execute cycle

    // cleanup

    Cpu cpu;
    cpu.fetch();
    return 0;
}