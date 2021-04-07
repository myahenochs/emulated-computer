#pragma once

#include <iostream>
#include <cstdint>
#include <array>

class RAM{

    public:

        const int SIZE;
        static const uint32_t MAX_ADDR = 0xFF;
        static const int OUTPUT_LINE = 16;
        static const int HEAP_OFFSET = 0x00;

    public:

        RAM(int initSize=256);
        ~RAM();

        uint8_t Read(uint32_t addr);
        void Write(uint8_t val, uint32_t addr);
        void Print();
        void ConnectToBus();

    private:

        uint8_t *ram;
};