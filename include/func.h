#ifndef func_h
#define func_h

typedef struct topology{
    int n;	// dim_kop 
    int k;	// Nodo kop
    int t;	// topology type (0->katea, 1->eraztun, 2->hiperkubo)
}topology_t;

/**
 * 0: Node kopurua
 * 1: D_max
 * 2: D_bb
 * 3: Erdibiketa
 * 4: Inj_max_rand
 */
float *get_top_info(topology_t topo);
void print_top_info(topology_t topo);

int *get_coord(int node, topology_t topo);
void print_coord(int* coord, int n);
 
int *get_be(int node_s, int node_f, topology_t topo);
void print_be(int* be, int n);

int get_n_dis(int *be, int n);

int get_node(int *coord, topology_t topo);
void print_pathNodes(int *c_nodes, int *be, topology_t topo);
long fact(int n);
#endif
