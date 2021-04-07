#include "ram.hpp"

RAM::RAM(int initSize): SIZE(initSize){
    ram = new uint8_t[SIZE];
    for(int i = 0; i < SIZE; i++){
        ram[i] = 0x00;
    }
}

RAM::~RAM(){
    delete[] ram;
}

uint8_t RAM::Read(uint32_t addr){
    if (addr >= 0x0000 && addr <= MAX_ADDR){
        return ram[addr];
    }
    return 0x00;
}

void RAM::Write(uint8_t val, uint32_t addr){
    if (addr >= 0x0000 && addr <= MAX_ADDR){
        ram[addr] = val;
    }
}

void RAM::Print(){
    for(int i = 1; i < SIZE+1; i++){
        if(ram[i-1]<0x10){
            printf("0");
        }
        printf("%X", ram[i-1]);
        if(i){
            if(i%4 == 0){
                printf(" ");
            }
            if(i%OUTPUT_LINE == 0){
                printf("\n");
            }
        }
    }
}