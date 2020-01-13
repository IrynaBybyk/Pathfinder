#include "header.h"

void mx_init_stack(t_stack **st, t_App *app, int i, int j) {
    *st = malloc(sizeof(t_stack)); //i, j, v2, v3, ..
    if ((*st) == NULL) exit(1);
    (*st)->max_size = app->SIZE;
    (*st)->path = malloc((*st)->max_size * sizeof(int) + 1);
    (*st)->path[0] = i;
    (*st)->path[1] = j;
    (*st)->size = 1;
}


