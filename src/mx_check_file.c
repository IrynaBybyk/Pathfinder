#include "header.h"

static void parse_rest_of_lines(t_App *app, char **str_parsed);
static void free_words(char *arg1, char *arg2); 

void mx_check_file(t_App *app, char **str_parsed) {
    if (app->SIZE == 9999)
        mx_cast_error_message(Invalid_Number_of_Islands, app);
    if (app->SIZE == 0 && str_parsed[1] == NULL)
        exit(0);
    if (app->SIZE == 0 && str_parsed[1] == NULL)
        mx_cast_error_message(Invalid_Number_of_Islands, app);
    if (app->SIZE == -1) {
        mx_cast_error_message(Line1_isnt_valid, app);
    }
    parse_rest_of_lines(app, str_parsed);
    if (app->city[app->SIZE - 1] == NULL) {
        mx_cast_error_message(Invalid_Number_of_Islands, app);
    }
}

static void parse_rest_of_lines(t_App *app, char **str_parsed) { 
    char *arg1 = NULL;
    char *arg2 = NULL;
    int arg3 = -1;

    mx_init_city(app);
    mx_init_AM(app);
    for ( int i = 1; str_parsed[i] != NULL; i++) {
        if (app->k != 0 && app->k <= i)
            mx_cast_error_message(Line_error_slash, app);
        if (mx_parse_line(str_parsed[i], &arg1, &arg2, &arg3)) {
            mx_push(arg1, arg2, app);
            mx_index(app,arg1,arg2,&arg3);
        }    
        else {
            mx_line(arg1, arg2, app, i);
        } 
            free_words(arg1, arg2);  
    }
    if (app->k != 0) {
        mx_cast_error_message(Line_error_slash, app);
    }
} 

static void free_words(char *arg1, char *arg2) {
    free(arg1);
    free(arg2);
}








