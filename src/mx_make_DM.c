#include "header.h"

static void init_dist_matrix(t_App *app);
static void use_Floyd_Warshall(t_App *app);

void mx_make_cost_matrix(t_App *app) {
    init_dist_matrix(app);
    use_Floyd_Warshall(app);
}

static void init_dist_matrix(t_App *app) {
    app->dist_M = malloc(app->SIZE * app->SIZE * sizeof(int));
    for (int i = 0; i < app->SIZE; i++)
        for (int j = 0; j < app->SIZE; j++) {
            app->dist_M[i * app->SIZE + j] = app->AM[i * app->SIZE + j];
        }
}

static void use_Floyd_Warshall(t_App *app) {
    int size = app->SIZE;
    int *dist = app->dist_M;
    int ik = 0;
    int kj = 0;
    int ij = 0;
                

    for (int k = 0; k < size; k++) {
    // pick all vertices as source one by one
        for (int i = 0; i < size; i++) {
        // pick all vertices as destination for the 
        // above picked sourse
            for (int j = 0; j < size; j++) {
                ik = i * size + k;
                kj = k * size + j;
                ij = i * size + j;
                if (dist[ik] + dist[kj] < dist[ij])
                    dist[ij] = dist[ik] + dist[kj];
             }
        }
    }
}



