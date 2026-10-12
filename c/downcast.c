#include <stdio.h>
#include <stdint.h>

int main() {
    uint32_t u32 = 0x12345678;
    uint16_t u16 = u32;
    printf("0x%08x 0x%04x\n", u32, u16);
    u16 = 0xFFFF;
    u16++;
    printf("0x%04x\n", u16);
}