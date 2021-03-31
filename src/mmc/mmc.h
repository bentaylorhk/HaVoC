// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#pragma once

#include <cstdint>
#include <string>

const int RAM_SIZE = 0x800;
const uint8_t NES_SIGNATURE[4] = { 0x4E, 0x45, 0x53, 0x1A };

class NesFileException : public std::exception {
public:
    NesFileException(const char *msg) : std::exception(msg) {

    }
};

class Mmc {
public:
    Mmc();
    Mmc(FILE *nesFile);
    ~Mmc();

private:
    FILE *nesFile;

    uint8_t ram[RAM_SIZE] = { 0 };

    uint8_t *prgRom;
    uint8_t *chrRom;

    uint8_t prgRomSize;
    uint8_t chrRomSize;
        
    void parseNesFile();
    void parseHeader();

    void readFileBytes(uint8_t* byteBuffer, size_t count);
};



