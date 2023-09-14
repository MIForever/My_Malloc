#ifndef FUNCS_H
#define FUNCS_H

#include "structs.h"

void* my_malloc(size_t size);
void* my_calloc(size_t nmemb, size_t size);
void* my_realloc(void* ptr, size_t size);
mem_block* find_block(mem_block* node, size_t size);
void remove_block(mem_block* parent, mem_block* node);
void my_free(void* ptr);
size_t hash_func(size_t size);


#endif