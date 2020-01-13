#include "header.h"

void mx_line(char *arg1, char *arg2,t_App *app, int i) {
    free(arg1);
    free(arg2);
    app->invalid_line_number = i + 1;
    mx_cast_error_message(Line_isnt_valid, app);
}

    
