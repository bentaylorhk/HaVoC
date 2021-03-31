// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#define SPDLOG_ACTIVE_LEVEL SPDLOG_LEVEL_TRACE

#include <errno.h>
#include <stdio.h>
#include <string.h>
#include <spdlog/spdlog.h>


#include "cpu/cpu.h"
#include "mmc/mmc.h"

// Constants
const int STRERROR_MAX_LENGTH = 95;

// Components.
Cpu cpu;
Mmc mmc;

int main(int argc, char *argv[]) {
    // Setting up the logger level.
    spdlog::set_level(spdlog::level::trace);

    // Parsing the command line args.
    if (argc != 2) {
        spdlog::error("You gave {} args, please only give a .nes file.", argc - 1);
        return 1;
    }

    // Opening the .nes file.
    FILE *nesFile;
    const char *fileName = argv[1];
    errno_t err = fopen_s(&nesFile, fileName, "rb");

    // If the file can't be opened.
    if (err != 0) {
        char buffer[STRERROR_MAX_LENGTH];
        strerror_s(buffer, sizeof(buffer), err);
        spdlog::error("Cannot open file {}: {}", fileName, buffer);
        return EXIT_FAILURE;
    }

    // Parsing the opened .nes file. ADD TRY AND CATCHs
    try {
        mmc = Mmc(nesFile);
    }
    catch (NesFileException &e) {
        spdlog::error("NesFileException: {}", e.what());
        return EXIT_FAILURE;
    }

    // Ensuring it's closed.
    fclose(nesFile);
    
    // setup registers and memory

    // fetch execute cycle

    // cleanup

    Cpu cpu;
    cpu.fetch();
    return EXIT_SUCCESS;
}