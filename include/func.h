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

#endif
