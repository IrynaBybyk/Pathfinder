#include "header.h"
 
bool mx_is_valid_name(char *s) {
    if (mx_strlen(s) == 0)
        return false;
    for (int i = 0; s[i] != '\0'; i++)
        if (!mx_isalpha(s[i])) return false;
    return true;
}


