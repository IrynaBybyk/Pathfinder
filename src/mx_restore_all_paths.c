#include "header.h"

static int pop_from_stack(t_stack *st);
static void restore_path_Helper(t_App *app, t_stack *st);
static void restore_allpaths_from_to(t_App *app, int i, int j);
static void push_in_stack(t_stack *st, int elem);

void mx_restore_all_paths(t_App *app) {
    for (int i = 0; i < app-> SIZE; i++) {
         for (int j = i + 1; j < app->SIZE; j++)
             restore_allpaths_from_to(app, i, j);
    }
}

static void push_in_stack(t_stack *st, int elem) {
    if (st->size < st->max_size) {
        st->size++;
        st->path[st->size] = elem;
    }
}

static int pop_from_stack(t_stack *st) {
    if (st->size > 1) {
        st->size--;
        return st->path[st->size + 1];
    }
    return st->path[1];  //всегда первый елемент
}

static void restore_path_Helper(t_App *app, t_stack *st) {
    int cur = -1;
    // bace case
    if (mx_get_from_stack(st) == st->path[0]) { 
        mx_print_path_info(app, st);
        return;
    }
    else { // recursive case
        //int cur = -1; 
        while (mx_is_next(app, st, &cur)) {
            // choose
            push_in_stack(st, cur);
            // explore
            restore_path_Helper(app, st);
            // un-choose
            pop_from_stack(st);
        }
    }
}

static void restore_allpaths_from_to(t_App *app, int i, int j) {
    t_stack *st = NULL;
    
    mx_init_stack(&st, app, i, j);
    restore_path_Helper(app, st);
    free(st->path);
    free(st);
}

 

