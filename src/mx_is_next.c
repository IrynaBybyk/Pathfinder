#include "header.h"

bool mx_is_next(t_App *app, t_stack *st, int *cur) {
    int j = mx_get_from_stack(st);
    int i = st->path[0];
    int size = app->SIZE;
    int starting_vertex = *cur + 1;
    int *DM = app->dist_M;

    for (int k = starting_vertex; k < app->SIZE; k++) {
        if (j != k) {
            if (DM[i * size +j] - app->AM[j * size + k] == DM[i * size + k]) {
                *cur = k;
                return true;
            }
        }
    }
    return false;
}




