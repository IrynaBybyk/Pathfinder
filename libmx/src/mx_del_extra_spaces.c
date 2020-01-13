#include "libmx.h"

static _Bool mx_isspace(char c);

char *mx_del_extra_spaces(const char *str) {
    if(str == NULL)
          return NULL;
    char *dur = mx_strnew(mx_strlen(str));
    int k = 0;
  
    for(int i = 0; str[i] != '\0'; i++) {
        if(mx_isspace(str[i]) && !mx_isspace(str[i - 1])){
            dur[k] = ' ';
            k++;
        }
        else if (!mx_isspace(str[i])) {
            dur[k] = str[i];
            k++;
        }
    }
    char *result = mx_strtrim(dur);
    mx_strdel(&dur);
    
    return result;
}

static _Bool mx_isspace(char c) {
return c == '\t'
    || c == '\n'
    || c == '\v'
    || c == '\f'
    || c == '\r'
    || c == ' ';
}


