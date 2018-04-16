#include <stdio.h>
#include <string.h>

void print_upto_space(const char *s)
{
    do {
        putc(*s, stdout);
    } while (*s++ != ' ');
}

void reverse_print(const char *s)
{
    const char *p = strchr(s, ' ');
    if (p == NULL) { 
        printf("%s ", s);
    } else {
        reverse_print(p + 1);
        print_upto_space(s);
    }
}
