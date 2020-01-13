#include "libmx.h"

static _Bool mx_isspace(char c);

char *mx_strtrim(const char *str) {
    if( str == NULL) return NULL;
    int start = 0;
    while(mx_isspace(str[start]))
        start++;
    int end = mx_strlen(str) - 1;
    if(end == -1)
        return mx_strnew(0);
    while (mx_isspace(str[end]))
        end--;
    char *newstr = mx_strnew(end - start + 1);
    if (newstr != NULL)
        mx_strncpy(newstr, &str[start], end - start + 1);
    return newstr;
}

static _Bool mx_isspace(char c) {
    return c == '\t'
    || c == '\n'
    || c == '\v'
    || c == '\f'
    || c == '\r'
    || c == ' ';
}



