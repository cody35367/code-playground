#include <stdint.h>
#include <stdio.h>

#define ARRAY_SIZE 12
typedef uint8_t MyCustom_t[ARRAY_SIZE];

int main () {
    printf("Size %zu\n", sizeof(MyCustom_t));
    MyCustom_t a = {0};
    a[0] = 2;
    a[ARRAY_SIZE - 1] = 8;
    for (int i = 0; i < ARRAY_SIZE; i++) {
        printf("[%d] = %d\n", i, a[i]);
    }
}