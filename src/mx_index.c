#include "header.h"

void mx_index(t_App *app, char *arg1, char *arg2, int *arg3) {
    int i = 0;
    int j = 0;

    i = mx_index_in_city(arg1, app);
    j = mx_index_in_city(arg2, app);
    mx_push_am(app, arg3, i, j);
}
