#include "libmx.h"

char *mx_itoa(int number) {
    int sing = 1;
    int tens = 1;
    int chars = 2;
    if(number < 0)
        sing = -1;

    for(int i = number; i / 10 != 0; i/= 10, chars++)
        tens *= 10;
    char *res = mx_strnew(chars);
    chars = 0;

    if(sing == -1) {
        res[chars] = '-';
        chars++;
    }
    for (int i = number; tens != 0; i %= tens, tens /= 10, chars++)
        res[chars] = i / tens * sing + '0';
    return res;
}


