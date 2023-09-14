#include "../include/funcs.h"

void* my_realloc(void* ptr, size_t size) {
    if (ptr == NULL) {
        return my_malloc(size);
    }

    if (size == 0) {
        my_free(ptr);
        return NULL;
    }

    mem_block* node_to_realloc = (mem_block*)ptr - 1;

    if (node_to_realloc->size >= size) {
        return ptr;
    }

    void* new_ptr = my_malloc(size);

    if (new_ptr != NULL) {
        memcpy(new_ptr, ptr, node_to_realloc->size);
        my_free(ptr);
    }

    return new_ptr;
}