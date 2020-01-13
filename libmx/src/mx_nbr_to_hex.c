#include "libmx.h"

char *mx_nbr_to_hex(unsigned long nbr) {
    char *hex;
    if(nbr != 0){
        int len = 0;
        for(unsigned long c = nbr; c > 0; c /= 16)
            len ++;
        hex = malloc(len + 1);
        if(!hex) return NULL;

    hex[len] = '\0';

    for(int i = 0; nbr > 0; nbr /= 16, i++, len --) {
        if(nbr % 16 >= 0 && nbr % 16 <= 9)
             hex[len - 1] = nbr % 16 + '0';
        else if (nbr % 16 >= 10 && nbr % 16 <= 15)
             hex[len - 1] = nbr % 16 + 'a' - 10;
    }
    } else {
        hex = malloc(2);
        hex[0] = '0';
        hex[1] = '\0';
    }
    return hex;
}


