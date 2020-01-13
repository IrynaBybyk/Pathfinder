#include "libmx.h"

void *mx_memrchr(const void *s, int c, size_t n){
    unsigned char *src = (unsigned char *) s;
    unsigned char chr = (unsigned char) c;
    for(size_t i = n - 1; i >= 0; i--) {
        if(src[i] == chr)
            return src + i;
    }
    return NULL;
}

