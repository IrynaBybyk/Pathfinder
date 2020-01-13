#include "libmx.h"

static int mx_strncmp(const char *s1, const char *s2, int len ) {
     int i = 0;
     while (s1[i] == s2[i] && s1[i] && s2[i] && i < len) {
         i++;
     }
     if(i == len)
          return 0;
     return s1[i] - s2[i];
}

int mx_get_substr_index(const char *str, const char *sub) {
    int i = 0;
    int index = 0;
    if(str == NULL || sub == NULL)
         return -2;
    if(!*str) 
        return 0;

    while(str[i] != '\0') {
if(mx_strncmp(str, sub, mx_strlen(sub)) == 0)
        return index;
    index++;
    str++;
    }
    return -1;
}

