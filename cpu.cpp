#include <string>
#include <iomanip>
#include "cpu.hpp"
#include "bus.hpp"

CPU::CPU(){

}

CPU::~CPU(){

}

void CPU::PrintRegisters(){
    printf("X: %X\nY: %X\nAccumulator: %X\nProgram Counter: %X\n", x, y, a, pc);
}

uint8_t CPU::Read(uint32_t addr){
    return bus->CPURead(addr);
}

void CPU::Write(uint8_t val, uint32_t addr){
    bus->CPUWrite(val, addr);
}

void CPU::Fetch(){
    opcode = Read(pc);
    pc++;
}

void CPU::RunInstruction(){
    switch (opcode)
    {
    case 0x01: LDX();
        break;
    case 0x02: LDY();
        break;
    case 0x03: LDA();
        break;
    case 0x04: STX();
        break;
    case 0x05: STY();
        break;
    case 0x06: ADD();
        break;
    case 0x07: SUB();
        break;
    case 0x08: JMP();
        break;
    case 0x09: JMC();
        break;
    case 0x0A: ICX();
        break;
    case 0x0B: ICY();
        break;
    case 0x0C: ICA();
        break;
    case 0x0D: INX();
        break;
    case 0x0E: INY();
        break;
    case 0x0F: INA();
        break;
    case 0x10: 
        break;
    default:
        break;
    }
}

void CPU::LDX(){
    x = Read(pc);
    pc++;
}

void CPU::LDY(){
    y = Read(pc);
    pc++;
}

void CPU::LDA(){
    a = Read(pc);
    pc++;
}

void CPU::STX(){
    temp = Read(pc);
    Write(x, bus->ram.HEAP_OFFSET+temp);
    pc++;
}

void CPU::STY(){
    temp = Read(pc);
    Write(y, bus->ram.HEAP_OFFSET+temp);
    pc++;
}

void CPU::STA(){
    temp = Read(pc);
    Write(a, bus->ram.HEAP_OFFSET+temp);
    pc++;
}

void CPU::ADD(){
    std::cout << "ADDING" << std::endl;
    temp = Read(pc);
    switch(temp){
        case 0x00: a += x;
            break;
        case 0x01: a += y;
            break;
    }
    pc++;
}

void CPU::SUB(){
    temp = Read(pc);
    switch(temp){
        case 0x00: a -= x;
            break;
        case 0x01: a -= y;
            break;
    }
    pc++;
}

void CPU::JMP(){
    temp = Read(pc);
    pc = temp;
}

void CPU::JMC(){
    temp = Read(pc);
    if(a){
        pc = temp;
    }
    pc++;
}

void CPU::ICX(){
    x++;
}

void CPU::ICY(){
    y++;
}

void CPU::ICA(){
    a++;
}

void CPU::INX(){
    std::string input;
    std::stringstream ss;

    getline(std::cin, input);

    ss << input;
    ss >> std::hex >> x;
}

void CPU::INY(){
    std::string input;
    std::stringstream ss;

    getline(std::cin, input);

    ss << input;
    ss >> std::hex >> y;
}

void CPU::INA(){
    std::string input;
    std::stringstream ss;

    getline(std::cin, input);

    ss << input;
    ss >> std::hex >> a;
}

void CPU::PRX(){
    std::cout << x;
}

void CPU::PRY(){
    std::cout << y;
}

void CPU::PRA(){
    std::cout << a;
}