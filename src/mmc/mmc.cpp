#include "mmc.h"
// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#include "mmc.h"

#include <string>
#include <spdlog/spdlog.h>

Mmc::Mmc() {

}

Mmc::Mmc(FILE *nesFile) {
    Mmc::nesFile = nesFile;
    parseNesFile();
}

Mmc::~Mmc() {
}

void Mmc::parseNesFile() {
    parseHeader();
}

void Mmc::parseHeader() {
    // Checking the first 4 bytes are NES + MS_DOS.
    uint8_t inspectBytes[4];
    readFileBytes(inspectBytes, 4);
    for (int i = 0; i < 4; i++) {
        spdlog::trace("NES Header Byte: {}", inspectBytes[i]);
        if (inspectBytes[i] != NES_SIGNATURE[i]) {
            throw NesFileException("Invalid .nes file header bytes");
        }
    }

    // Setting up the PRG ROM.
    readFileBytes(&prgRomSize, 1);
    if (prgRomSize < 0x01 || prgRomSize > 0x40) {
        throw NesFileException("Invalid PRG ROM size in .nes header");
    }
    prgRom = new uint8_t[(size_t) prgRomSize * 16384];

    // Initialising the CHR ROM, and CHR RAM.

}

void Mmc::readFileBytes(uint8_t *byteBuffer, size_t count) {
    fread(byteBuffer, sizeof(uint8_t), count, nesFile);
}