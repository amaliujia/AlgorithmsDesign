#include "linear_heap.h"

void vec_copy_inplase(VECTOR *new_vec, VECTOR *old_vec) {
  size_t i;

  /*  two vectors must have same dimensions */
  assert(new_vec->len == old_vec->len);

  for(i = 0; i < new_vec->len; i++) {
    (old_vec->vec)[i] = (new_vec->vec)[i];
  }
}

void vec_init(VECTOR *pvec, int n) {
  size_t i;

  pvec->len = n;
  pvec->vec = (NUMBER *)malloc(sizeof(NUMBER) * n);
  /* initialize vector to zeros - 2/7/97 */
  for (i = 0; i < n; i++) {
    pvec->vec[i] = 0.0;
  }
}

heap *heap_alloc(int k, int n) {
  heap *ret;
  int i;

  assert(k > 0);

  ret = (heap *)malloc(sizeof(heap));
  assert(ret != NULL);

  ret->heap_size = k;
  ret->cur_size = 0;
  ret->heap_array = (NUMBER *)malloc(sizeof(NUMBER) * k);

  ret->heap_vector_array = (VECTOR *)malloc(sizeof(VECTOR) * k);

  for (i = 0; i < k; i++) {
    vec_init(&(ret->heap_vector_array[i]), n);
  }
  return ret;
}

void heap_dealloc(heap *hp) {
  assert(hp != NULL);

  free(hp->heap_vector_array);
  free(hp->heap_array);
  free(hp);
}

int heap_max_index(heap *hp) {
  int ret, i;
  NUMBER cur_max;
  assert(hp != NULL);

  ret = -1;
  cur_max = -1;
  for (i = 0; i < hp->cur_size; i++) {
    if (hp->heap_array[i] > cur_max) {
      cur_max = hp->heap_array[i];
      ret = i;
    }
  }

  return ret;
}

NUMBER heap_max_dis(heap *hp) {
  int ret;
  assert(hp != NULL);

  ret = heap_max_index(hp);
  if (ret == -1 || hp->cur_size < hp->heap_size) {
    return INT_MAX;
  }

  return hp->heap_array[ret];
}

/*  If under capacity, directly insert new val and vec.
    If over capacity, replace the largest one to main max_heap.
*/
bool heap_insert(heap *hp, NUMBER new_val, VECTOR *new_vec) {
  assert(hp != NULL);
  assert(hp->cur_size <= hp->heap_size);

  if(hp->cur_size == hp->heap_size) {
    int ret = heap_max_index(hp);
    assert(ret != -1);
    hp->heap_array[ret] = new_val;
    vec_copy_inplase(new_vec, &(hp->heap_vector_array[ret]));
    return true;
  } else {
    hp->heap_array[hp->cur_size] = new_val;
    vec_copy_inplase(new_vec, &(hp->heap_vector_array[hp->cur_size]));
    hp->cur_size++;
  }

  return true;
}

void heap_print(heap *hp) {
  size_t i;
  assert(hp != NULL);

  if (hp->cur_size < hp->heap_size) {
    printf("only %d nodes found\n", hp->cur_size);
  }

  for (i = 0; i < hp->cur_size; i++) {
    vecprint(&(hp->heap_vector_array[i]));
  }
}

void heap_debug_print(heap *hp) {
  size_t i;
  assert(hp != NULL);

  for (i = 0; i < hp->heap_size; i++) {
    vecprint(&(hp->heap_vector_array[i]));
  }
}
