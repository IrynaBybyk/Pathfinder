#include "header.h"

static void check_emty_line(char *str, t_App *app);

char *mx_read_file(char *argv[], t_App *app) {
    int fd = 0;
    char *str = NULL;

    app->file_name = argv[1];
    fd = open(argv[1], O_RDONLY);
    if (fd < 0){
        close(fd);
        mx_cast_error_message(File_Doesnt_Exist, app);
    }
    close(fd);
    app->file_to_str = mx_file_to_str(argv[1]);
    str = app->file_to_str;
    if (mx_strlen(str) == 0) {
        mx_cast_error_message(File_Is_Empty, app);
    }
    check_emty_line(str,app);
    return str;
}

static void check_emty_line(char *str, t_App *app) {
    int j  = 0;
    
    if (str[0] == '\n')
         mx_cast_error_message(Line1_isnt_valid, app);
    for (int i = 0; str[i] != '\0'; i++) {
        if (str[i] == '\n')
            j++;
        if (str[i] == '\n' && str[i + 1] == '\n') {
        app->k = j + 1;
            break;
        }
    }
}




