#include "header.h"

bool mx_parse_line(char *line, char **arg1, char **arg2, int *arg3) {
    int dash_idx = mx_get_char_index(line, '-');
    int coma_idx = mx_get_char_index(line, ',');
    int len = mx_strlen(line);
    char *number = NULL;

    if (dash_idx == -1  && coma_idx == -1 && len == 0 
        && dash_idx > coma_idx) {
        return false;
    }
    *arg1 = mx_strndup(line, dash_idx);
    *arg2 = mx_strndup(line + dash_idx + 1, coma_idx - dash_idx - 1);
    number = mx_strndup(line + coma_idx + 1, len - coma_idx - 1);
    if (!mx_is_valid_name(*arg1) || !mx_is_valid_name(*arg2))
       return false;
    *arg3 = mx_my_atoi(number);
    if (*arg3 == -1 || *arg3 == 0) {
        return false;
    }
    free(number);
    return true;
}


