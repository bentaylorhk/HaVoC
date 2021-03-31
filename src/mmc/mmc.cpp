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

    // If the header specifies a trainer is present.
    if (bTrainer) {
        trainer = new uint8_t[512];
        readFileBytes(trainer, 512);
    }

    // Setting up the ROMs to the size found in the header.
    prgRom = new uint8_t[prgRomSizeBytes];
    readFileBytes(prgRom, prgRomSizeBytes);

    chrRom = new uint8_t[chrRomSizeBytes];
    readFileBytes(chrRom, chrRomSizeBytes);
}

void Mmc::parseHeader() {
    // Checking the first 4 bytes are NES + MS_DOS EOF.
    uint8_t inspectBytes[4];
    readFileBytes(inspectBytes, 4);
    for (int i = 0; i < 4; i++) {
        spdlog::trace("'NES' Header Byte: {:02X}", inspectBytes[i]);
        if (inspectBytes[i] != NES_SIGNATURE[i]) {
            throw NesFileException("Invalid .nes file header bytes");
        }
    }

    // Getting the PRG ROM size.
    readFileBytes(&prgRomSize, 1);
    prgRomSizeBytes = (uint32_t)prgRomSize * 0x4000;
    if (prgRomSize < 0x01 || prgRomSize > 0x40) {
        throw NesFileException("Invalid PRG ROM size in .nes header");
    }
    spdlog::trace("PRG ROM Size: {} Bytes", prgRomSizeBytes);

    // Getting the CHR ROM size, or if it uses CHR RAM.
    readFileBytes(&chrRomSize, 1);
    chrRomSizeBytes = (uint32_t)chrRomSize * 0x2000;
    if (chrRomSize > 0x40) {
        throw NesFileException("Invalid CHR ROM size in .nes header");
    }
    else if (chrRom == 0) {
        // TODO: Start CHRRAM here or always do so, and should some
        // safety be done for accessing the chrROM? Could have a
        // chr enabbled bool and check that in the read CHR method.
    }
    else {
        spdlog::trace("CHR ROM Size: {} Bytes", chrRomSizeBytes);
    }

    // Single byte reading buffer.
    uint8_t buffer[1];

    // Getting the 7th byte, that includes the low nibble for the
    // mapper and oter info.
    readFileBytes(buffer, 1);
    mapper = (buffer[0] & HIGH_NIBBLE) >> 4;
    
    bVerticalMirroring = buffer[0] & FIRST_BIT_MASK;
    bBattery = buffer[0] & SECOND_BIT_MASK;
    bTrainer = buffer[0] & THIRD_BIT_MASK;
    bFourScreenVram = buffer[0] & FOURTH_BIT_MASK;

    // Getting the 8th byte, only including the higher mapper nibble.
    // TODO: Implement Lower Nibble.
    readFileBytes(buffer, 1);
    mapper |= buffer[0] & HIGH_NIBBLE;
    // TODO: Implement Mapper (needed for games beyone Super Mario Bros.

    // TODO: Implement PRG RAM Size.
    readFileBytes(buffer, 1);
    spdlog::trace("9th Header Byte: {:02X}", buffer[0]);

    // TODO: Implement TV system.
    readFileBytes(buffer, 1);
    spdlog::trace("10th Header Byte: {:02X}", buffer[0]);

    // TODO: Implement PRG RAM Presence.
    readFileBytes(buffer, 1);
    spdlog::trace("11th Header Byte: {:02X}", buffer[0]);

    // Tracing the unused padding to see if it includes the ripper's name.
    char ripperName[6];
    ripperName[5] = '\0';
    readFileBytes((uint8_t *)ripperName, 5);

    // If the padding isn't unused, first byte shouldn't be 0.
    if (ripperName[0]) {
        spdlog::trace("Ripper Name: {}", ripperName);
    }
}

void Mmc::readFileBytes(uint8_t *byteBuffer, size_t count) {
    fread(byteBuffer, sizeof(uint8_t), count, nesFile);
}

uint8_t readByte(uint16_t address) {
    return 0;
}