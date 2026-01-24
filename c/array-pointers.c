#include <stdio.h>

int main() {
    int a[10] = {0};
    printf("0x%p 0x%p\n", (void *)a, (void *)&a);
    if ((void *)a == (void *)&a) {
        printf("The pointers equal\n");
    }
}