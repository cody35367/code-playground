#include <stdio.h>
#include <stdint.h>

int main() {
    uint16_t val1 = 65530;
    uint16_t val2 = 5;
    uint16_t val3 = val2 - val1;
    printf("%u\n", val3);
}