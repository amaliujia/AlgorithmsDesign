#ifndef __LINEAR_HEAP_H
#define __LINEAR_HEAP_H

#include <assert.h>
#include "dfn.h"
#include "vector.h"

/* this should be a max heap by default */
typedef struct linear_heap {
    int heap_size;
    int cur_size;
    NUMBER *heap_array;
    VECTOR *heap_vector_array;
}heap;


/* memory management */
heap *heap_alloc(int k, int n);
void heap_dealloc(heap* hp);

/* heap operations */
NUMBER heap_max_dis(heap *hp);
int heap_max_index(heap *hp);
bool heap_insert(heap *hp, NUMBER new_val, VECTOR *new_vec);
void vec_copy_inplase(VECTOR *new_vec, VECTOR *old_vec);

void heap_print(heap *hp);

#endif /*  __LINEAR_HEAP_H */
