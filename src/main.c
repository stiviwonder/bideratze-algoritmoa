#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/func.h"


int main(int argc, char* argv[]){

    topology_t topo;
    int node_s, node_f; //node_s = start node | node_f = final node
    int *be;

    printf("\033[1;31m");   // color red
    printf("  ____  _     _                _                   __             _       _             \n");
    printf(" |  _ \\(_)   | |              | |                 / _|           | |     (_)            \n");
    printf(" | |_) |_  __| | ___ _ __ __ _| |_ _______ ______| |_ _   _ _ __ | |_ _____  ___   __ _ \n");
    printf(" |  _ <| |/ _` |/ _ \\ '__/ _` | __|_  / _ \\______|  _| | | | '_ \\| __|_  / |/ _ \\ / _` |\n");
    printf(" | |_) | | (_| |  __/ | | (_| | |_ / /  __/      | | | |_| | | | | |_ / /| | (_) | (_| |\n");
    printf(" |____/|_|\\__,_|\\___|_|  \\__,_|\\__/___\\___|      |_|  \\__,_|_| |_|\\__/___|_|\\___/ \\__,_|\n");
    printf("                                                                                        \n");
    printf("========================================================================================\n");
    printf("\033[0m");

    printf("\nKateak (0) - Eraztunak (1) - Hiperkuboa (2) > ");
    scanf("%d", &topo.t);

    switch (topo.t) {
	case 0:
	case 1:
            printf("\nDimentsio kopurua (1-10) > ");
            scanf("%d", &topo.n);
            printf("Nodo kop. dimentsioko (2-32) > ");
            scanf("%d", &topo.k);
            break;
        case 2:
            printf("\nDimentsio kopurua (1-10) > ");
            scanf("%d", &topo.n);
            topo.k = 2;
            break;
        default:
            fprintf(stderr, "[ERR] incorrect input\n");
            exit(-1);
            break;

    }

    print_top_info(topo);

    double nodo_kop = pow(topo.k, topo.n);

    printf("\nIturburu-nodoa (0-%.0f) > ", nodo_kop-1);
    scanf("%d", &node_s);
    printf("Helburu-nodoa (0-%.0f) > ", nodo_kop-1);
    scanf("%d", &node_f);

    printf("\n	%d Nodoen koordenatuak: ", node_s);
    print_coord(get_coord(node_s, topo), topo.n);
    printf("	%d Nodoen koordenatuak: ", node_f);
    print_coord(get_coord(node_f, topo), topo.n);
    
    int test = node_s ^ node_f;
    print_coord(get_coord(test, topo), topo.n);


    // be = get_be(node_s, node_f, topo);
    // print_be(be);
    
    // print_pathNodes(be, topo);




    return 0;
}
