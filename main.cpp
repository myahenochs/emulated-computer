#include <iostream>
#include <cstdint>
#include <string>
#include <iomanip>
#include "ram.hpp"
#include "cpu.hpp"
#include "bus.hpp"

int DecToHex(int p_intValue);

int main(){

    Bus bus;
    bool start = false;
    std::string input;
    int hex = 0x00;
    int inc = 0;

    while(!start){
        std::stringstream ss;

        getline(std::cin, input);

        ss << input;
        ss >> std::hex >> hex;

        if(hex != 0x00 && inc <= bus.ram.MAX_ADDR){
            bus.ram.Write(hex, inc);
        }
        else{
            start = true;
        }

        inc++;
    }

    do{
        bus.cpu.Fetch();
        bus.cpu.RunInstruction();
    }while(bus.cpu.opcode);

    bus.cpu.PrintRegisters();
    bus.ram.Print();

    return 0;
}
