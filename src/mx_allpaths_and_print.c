#include "header.h"

void mx_allpaths_and_print(t_App *app) {
    mx_make_cost_matrix(app);
    mx_restore_all_paths(app);
}


