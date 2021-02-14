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


int *get_coord(int node, topology_t topo){

    int *coord = malloc(topo.n*sizeof(int));
    int n = node, i, d = topo.n, k = topo.k;

    switch(topo.t){
	case 0:
	case 1:
	    for (i=0; i<topo.n-1; i++){
		coord[i] = n / pow(k, d-1);
		n %= (int)pow(k, d-1);
		d--;
	    }
	    coord[topo.n-1] = n; 
	    break;
	case 2:
	    i = topo.n-1;
	    while(n > 0){
		coord[i] = n % 2;
		n /= 2;
		i--;
	    }
	    break;
    }

    return coord;
}

void print_coord(int *coord, int n){
    int i;
    printf(" (");
    for (i=0; i<n-1; i++){
	    printf("%d, ", coord[i]);
    }
    printf("%d)", coord[n-1]);
}

int *get_be(int node_s, int node_f, topology_t topo){
    int *be = malloc(topo.n*sizeof(int));
    int *c_nodes = get_coord(node_s, topo);
    int *c_nodef = get_coord(node_f, topo);
    int i;

    switch(topo.t){
	case 0:
	    for (i=0; i<topo.n; i++){
		be[i] = c_nodef[i] - c_nodes[i];
	    }
	    break;
	case 1:
	    for (i=0; i<topo.n; i++){
		be[i] = c_nodef[i] - c_nodes[i];
		if (be[i] > topo.k/2){
		    be[i] -= topo.k;
		}
		else if (be[i] < -topo.k/2){
		    be[i] += topo.k;
		}
	    }
	    break;
	case 2:
	    be = get_coord(node_s ^ node_f, topo);
	    break;
    }
    return be;
}

void print_be(int *be, int n){
    int i;
    printf(" [");
    for (i=0; i<n-1; i++){
	    printf("%d, ", be[i]);
    }
    printf("%d]\n", be[n-1]);
}

int get_n_dis(int *be, int n){
    int i, d = 0;

    for (i=0; i<n; i++){
	d += abs(be[i]);
    }
    return d;
}

int get_node(int *coord, topology_t topo){
    int node = 0;
    int i, j = 1, n = topo.n-1;

    switch(topo.t){
	case 0:
	case 1:

	    i = 1;
	    node = coord[topo.n-i];
	    for (j=1; j<topo.n; j++){
		i++;
		node += coord[topo.n-i]*pow(topo.k, j);
	    }
	    break;
	case 2:
	    for (i=0; i<topo.n; i++){
		node += coord[i] * pow(2, n);
		n--;
	    }
    }
    return node;
}

void print_pathNodes(int *c_nodes, int *be, topology_t topo){
    int i, j;
    int *path_cnode = c_nodes;

    switch (topo.t){
	case 0:
	    printf("          %d > ", get_node(path_cnode, topo));
	    for (i=0; i<topo.n; i++){
		for (j=0; j<abs(be[i]); j++){
		    if (be[i] > 0)
			path_cnode[i]++;
		    else if (be[i] < 0)
			path_cnode[i]--;
		    printf(" %d > ", get_node(path_cnode, topo));
		}
		printf("\n         ");
	    }
	    break;
	case 1:
	    printf("          %d > ", get_node(path_cnode, topo));
	    for (i=0; i<topo.n; i++){
		for (j=0; j<abs(be[i]); j++){
		    if (be[i] > 0)
			path_cnode[i] = (path_cnode[i]+1) % topo.k;
		    else if (be[i] < 0)
			path_cnode[i]--;
		    if (path_cnode[i] < 0)
			path_cnode[i] = topo.k-1;
		    printf(" %d > ", get_node(path_cnode, topo));
		}
		printf("\n         ");
	    }
	    break;
	case 2:
	    printf("          %d > ", get_node(path_cnode, topo));
	    for (i=topo.n-1; i>=0; i--){
		if (be[i]){
		    path_cnode[i] = !path_cnode[i];
		    printf(" %d > ", get_node(path_cnode, topo));
		}
	    }
	    printf("\n");
	    break;
    }
}
