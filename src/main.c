#include <stdio.h>
#include <stdlib.h>
#include <math.h>
#include "../include/func.h"


int main(int argc, char* argv[]){

    topology_t topo;
    int node_s, node_f; //node_s = start node | node_f = final node
    int *be;
    int dis;
    long bide_kop;


    printf("\033[1;31m");   // color red
    printf("      ____  _     _           _        _               \n");
    printf("     |  _ \\(_)   | |         | |      | |              \n");
    printf("     | |_) |_  __| | ___ _ __| |_ __ _| |_ _______     \n");
    printf("     |  _ <| |/ _` |/ _ \\ '__| __/ _` | __|_  / _ \\    \n");
    printf("     | |_) | | (_| |  __/ |  | || (_| | |_ / /  __/    \n");
    printf("     |____/|_|\\__,_|\\___|_|_ _\\__\\__,_|\\__/___\\___|    \n");
    printf("       | |                (_) |                        \n");
    printf("   __ _| | __ _  ___  _ __ _| |_ _ __ ___   ___   __ _ \n");
    printf("  / _` | |/ _` |/ _ \\| '__| | __| '_ ` _ \\ / _ \\ / _` |\n");
    printf(" | (_| | | (_| | (_) | |  | | |_| | | | | | (_) | (_| |\n");
    printf("  \\__,_|_|\\__, |\\___/|_|  |_|\\__|_| |_| |_|\\___/ \\__,_|\n");
    printf("           __/ |                                       \n");
    printf("          |___/                                        \n");
    printf("\n");
    printf("========================================================\n");
    printf("\033[0m");

    printf("\n\033[1;32m > Sarearen definizioa\n\033[0m"); // color green
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

    while (1){
	printf("\n\033[1;32m > Nondik nora (-1 amaitzeko)\n\033[0m"); // color green
	double nodo_kop = pow(topo.k, topo.n);

	printf("\nIturburu-nodoa (0-%.0f) > ", nodo_kop-1);
	scanf("%d", &node_s);
	if (node_s == -1)
	    exit(-1);
	printf("Helburu-nodoa (0-%.0f) > ", nodo_kop-1);
	scanf("%d", &node_f);
	if (node_f == -1)
	    exit(-1);

	printf("\033[1;34m");   // color blue
	printf("\n	Nodoen koordenatuak:     ");
	int *c_nodes = get_coord(node_s, topo);
	print_coord(c_nodes, topo.n);
	printf(" (%d Nodoa)\n", node_s);
	printf("	Nodoen koordenatuak:     ");
	print_coord(get_coord(node_f, topo), topo.n);
	printf(" (%d Nodoa)\n", node_f);

	be = get_be(node_s, node_f, topo);
	printf("	Bideratze-erregistroa:   ");
	print_be(be, topo.n);

	dis = get_n_dis(be, topo.n);
	bide_kop = fact((long)dis);
	printf("	Nodoen arteko distantzia: %d\n", dis);
	if (dis <= 12)
	    printf("        Bide alternatibe kopurua: %ld\n", bide_kop); 
	else
	    printf("        Bide alternatibe kopurua: --    (dis <= 12 denean)\n"); 
	printf("	Tarteko nodoak (DOR):\n");
	print_pathNodes(c_nodes, be, topo);

	printf("\n");
	//printf("	Bide desberdinen kopurua: ");
	printf("\033[0m");
    }
    return 0;
}
