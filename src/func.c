#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/func.h"

float *get_top_info(topology_t topo){

    float *topo_info = malloc(5*sizeof(float));
    topo_info[0] = (int) pow(topo.k, topo.n);

    topo_info[1] = 0;
    topo_info[2] = 0;
    topo_info[3] = 0;
    topo_info[4] = 0;

    switch(topo.t){
        case 0:
            topo_info[1] = topo.n * (topo.k - 1);
            topo_info[2] = ((float)topo.n * (float)topo.k) / 3;
            topo_info[3] = pow(topo.k, topo.n-1);
            topo_info[4] = 0;
            break;
	case 1:
            topo_info[1] = topo.n * ((float)topo.k / 2);
            topo_info[2] = ((float)topo.n * (float)topo.k) / 4;
            topo_info[3] = 2 * pow(topo.k, topo.n-1);
            topo_info[4] = 0;
            break;
	case 2:
            topo_info[1] = topo.n;
            topo_info[2] = (float)topo.n / 2;
            topo_info[3] = topo_info[0] / 2;
            topo_info[4] = 0;
            break;
        default:
            break;
    }

    return topo_info;
}

void print_top_info(topology_t topo){

    float *t_info = get_top_info(topo);

    printf("\033[1;34m");   // color blue
    switch(topo.t){
        case 0:
            printf("\n	    Topologia: %d dimentsioko maila, %0.f nodo (%d^%d)\n", topo.n,t_info[0],topo.k,topo.n);
            break;
	case 1:
            printf("\n	    Topologia: %d dimentsioko torua, %0.f nodo (%d^%d)\n", topo.n,t_info[0],topo.k,topo.n);
            break;
	case 2:
            printf("\n	    Topologia: %d dimentsioko hiperkuboa, %0.f nodo (%d^%d)\n", topo.n,t_info[0],topo.k,topo.n);
            break;
        default:
	    fprintf(stderr, "[ERR] incorrect topology\n");
	    exit(-1);
            break;
    }

    printf("	    Distantzia maximoa:     %.0f\n", t_info[1]);
    printf("	    Batez besteko dist.:    %.2f\n", t_info[2]);
    printf("	    Erdibiketa:             %.0f lotura\n", t_info[3]);

    printf("\033[0m");
    free(t_info);
}
