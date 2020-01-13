#include "header.h"

void mx_initialize(int argc, char *argv[], t_App *app) {
    app->city = NULL; // in heap
    app->AM = NULL;   // in heap
    app->parsed_lines_array = NULL; // in heap
    app->file_to_str = NULL; // in heap

    if (argc != 2) {
        mx_cast_error_message(Invalid_Number_Of_Commandline, app);
    } 
    char *str = mx_read_file(argv, app);
    app->parsed_lines_array = mx_strsplit(str, '\n');
    char **str_parsed = app->parsed_lines_array;
    app->SIZE = mx_my_atoi(str_parsed[0]);
    mx_check_file(app, str_parsed);
} 



