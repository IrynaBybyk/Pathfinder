#include "libmx.h"

int mx_strlen(const char *s) {
    if(!s) {
        return 0;
    }
    int i = 0;
    while(*s != '\0') {
        i++;
        s++;
    }
    return i;
}

