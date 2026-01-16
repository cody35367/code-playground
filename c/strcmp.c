#include <string.h>
#include <stdio.h>

int main() {
    printf("%d\n", strncmp("1234", "1234567", 9));
    printf("%d\n", strncmp("1234", "1234567", 7));
    printf("%d\n", strncmp("1234", "1234567", 4));
    printf("%ld %d\n", strlen("1234"), strncmp("1234", "1234567", strlen("1234")));
}