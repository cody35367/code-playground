#include <stdio.h>
#include <string.h>

void crlf_to_lf(char *s)
{
    char *r = s;  // read
    char *w = s;  // write

    while (*r) {
        if (r[0] == '\r' && r[1] == '\n') {
            *w++ = '\n';
            r += 2;
        } else {
            *w++ = *r++;
        }
    }
    *w = '\0';
}

void replace_cr_lf_dump(char *s) {
    while (*s) {
        if (*s == '\r') {
            *s = 'r';
        } else if (*s == '\n') {
            *s = 'n';
        }
        s++;
    }
}

int main() {
    char str1[]="123\r\n456\r\n7890";
    char str2[100];
    strcpy(str2, str1);
    replace_cr_lf_dump(str2);
    printf("%s\n", str2);
    printf("%s\n", str1);
    crlf_to_lf(str1);
    printf("%s\n", str1);
    replace_cr_lf_dump(str1);
    printf("%s\n", str1);
}