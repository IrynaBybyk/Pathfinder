#ifndef HEADER_H
#define HEADER_H

#include "libmx.h"

// ................Path finder

typedef struct s_App {
    int SIZE;
    char **city; //in heap
    int *AM;     //in heap
    int *dist_M; //in heap
    char **parsed_lines_array; //in heap
    char *file_to_str;         //in heap
    int invalid_line_number;
    char *file_name;
    int k;
} t_App;

    typedef struct {
        int *path;
        int size;
        int max_size;
    } t_stack;
   
typedef enum Err {
    Invalid_Number_Of_Commandline,
    File_Doesnt_Exist,
    File_Is_Empty,
    Line1_isnt_valid,
    Line_isnt_valid,
    Invalid_Number_of_Islands,
    Line_error_slash

} e_Error;

void mx_printerr(const char *s);
bool mx_isdigit(int c);
bool mx_isalpha(int c);
void mx_cast_error_message(e_Error err, t_App *app);
void mx_print_path_info(t_App *app, t_stack *st);
int mx_my_atoi(char *s);
void initialize(int argc, char *argv[], t_App *app);
bool mx_is_valid_name(char *s);
char *mx_read_file(char *argv[], t_App *app);
void mx_init_AM(t_App *app);
void mx_make_cost_matrix(t_App *app);
void mx_restore_all_paths(t_App *app);
void mx_allpaths_and_print(t_App *app);
void mx_init_stack(t_stack **st, t_App *app, int i, int j);
bool mx_is_next(t_App *app, t_stack *st, int *cur);
void mx_free_all(t_App *app);
int mx_get_from_stack(t_stack *st);
void mx_init_city(t_App *app);
void mx_print_line(void);
void mx_check_file(t_App *app, char **str_parsed);
int mx_index_in_city(char *elem, t_App *app);
bool mx_parse_line(char *line, char **arg1, char **arg2, int *arg3);
void mx_push_in_city(char *elem, t_App *app);
void mx_initialize(int argc, char *argv[], t_App *app);
void mx_push(char *arg1, char *arg2, t_App *app);
void mx_push_am(t_App *app, int *arg3, int i, int j);
void mx_index(t_App *app,char *arg1, char *arg2, int *arg3);
void mx_line(char *arg1, char *arg2,t_App *app, int i);

#endif
