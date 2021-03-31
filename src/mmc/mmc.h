// HaVoC Emulator Project
// Benjamin Michael Taylor
// 2021

#pragma once

#include <cstdint>
#include <string>

const uint8_t HIGH_NIBBLE = 0xF0;
const uint8_t LOW_NIBBLE = 0x0F;

const uint8_t FIRST_BIT_MASK = 0b00000001;
const uint8_t SECOND_BIT_MASK = 0b00000010;
const uint8_t THIRD_BIT_MASK = 0b00000100;
const uint8_t FOURTH_BIT_MASK = 0b00001000;
const uint8_t FIFTH_BIT_MASK = 0b00010000;
const uint8_t SIXTH_BIT_MASK = 0b00100000;
const uint8_t SEVENTH_BIT_MASK = 0b01000000;
const uint8_t EIGHTH_BIT_MASK = 0b10000000;

const uint32_t RAM_SIZE = 0x800;

const uint8_t NES_SIGNATURE[4] = { 0x4E, 0x45, 0x53, 0x1A };

class NesFileException : public std::exception {
public:
    NesFileException(const char *msg) : std::exception(msg) {}
};

class Mmc {
public:
    Mmc();
    Mmc(FILE *nesFile);
    ~Mmc();

    uint8_t readByte(uint16_t address);

private:
    FILE *nesFile;

    uint8_t ram[RAM_SIZE] = { 0 };

    uint8_t *trainer;

    uint8_t *prgRom;
    uint8_t *chrRom;

    uint8_t prgRomSize;
    uint8_t chrRomSize;

    uint32_t prgRomSizeBytes;
    uint32_t chrRomSizeBytes;

    uint8_t mapper;

    bool bVerticalMirroring;
    bool bBattery;
    bool bTrainer;
    bool bFourScreenVram;
        
    void parseNesFile();
    void parseHeader();

    void readFileBytes(uint8_t* byteBuffer, size_t count);
};



