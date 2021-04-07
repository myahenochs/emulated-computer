#pragma once

#include <iostream>
#include <cstdint>
#include <map>

class Bus;

class CPU{

    public:

        uint8_t x = 0x00;
        uint8_t y = 0x00;
        uint8_t a = 0x00;
        uint32_t pc = 0x0000;
        uint8_t opcode = 0x00;
        uint8_t temp = 0x00;

        Bus *bus;

        // enum Instruction{ADD, SUB, LDX, LDY, STX, STY};
        // const std::map<uint8_t, Instruction> OpCodes;

        void Fetch();
        void RunInstruction();

    public:

        CPU();
        ~CPU();

        void PrintRegisters();

        uint8_t Read(uint32_t addr);
        void Write(uint8_t val, uint32_t addr);

        void ConnectToBus(Bus *n){bus=n;}

        void LDX();
        void LDY();
        void LDA();
        void ADD();
        void SUB();
        void STX();
        void STY();
        void STA();
        void JMP();
        void JMC();
        void ICX();
        void ICY();
        void ICA();
        void INX();
        void INY();
        void INA();
        void PRX();
        void PRY();
        void PRA();

};