#pragma once

#include <iostream>
#include <cstdint>
#include <random>
#include "cpu.hpp"
#include "ram.hpp"

class Bus {

    public:

        Bus();
        ~Bus();

        void LoadRAM();

        uint8_t CPURead(uint32_t addr);
        void CPUWrite(uint8_t val, uint32_t addr);

        CPU cpu;
        RAM ram;
};