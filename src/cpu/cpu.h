#pragma once

#include <cstdint>

class Cpu {
    // Registers
    uint16_t pc;
    uint8_t ac;
    uint8_t x;
    uint8_t y;
    uint8_t sr;
    uint8_t sp;

    public:
        void fetch();
        void execute();

    //private:
    //  std::shared_ptr<spdlog::logger> logger;

};