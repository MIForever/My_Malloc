#include "../include/funcs.h"

void* my_calloc(size_t nmemb, size_t size) {
    size_t total_size = nmemb * size;

    void* ptr = my_malloc(total_size);

    if (ptr != NULL) {
        memset(ptr, 0, total_size);
    }

    return ptr;
}
