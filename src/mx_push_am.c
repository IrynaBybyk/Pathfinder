#include "header.h"

void mx_push_am(t_App *app, int *arg3, int i, int j) {
    app->AM[i * app->SIZE + j] = *arg3;
    app->AM[j * app->SIZE + i] = *arg3;
}
        
