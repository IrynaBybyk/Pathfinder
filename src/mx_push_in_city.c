#include "header.h"

void mx_push_in_city(char *elem, t_App *app) {
    char **city = app->city;
    int i;
    
    for (i = 0; i < app->SIZE; i++) {
        if (city[i] == NULL)
            break;
        if (mx_strcmp(city[i], elem) == 0)
            return;
    }
    if (i < app->SIZE)
        city[i] = mx_strdup(elem);
    else { 
        mx_cast_error_message(Invalid_Number_of_Islands, app);
    }
}


