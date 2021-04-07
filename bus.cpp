#include "bus.hpp"

Bus::Bus(){
    cpu.ConnectToBus(this);
}

Bus::~Bus(){

}

void Bus::LoadRAM(){
    
}

uint8_t Bus::CPURead(uint32_t addr){
    return ram.Read(addr);
}

void Bus::CPUWrite(uint8_t val, uint32_t addr){
    ram.Write(val, addr);
}