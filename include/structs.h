#ifndef STRUCTS_H
#define STRUCTS_H

#include <stdio.h>
#include <sys/mman.h>
#include <stddef.h>
#include <string.h>

typedef struct mem_block {
    struct mem_block* left;
    struct mem_block* right;
    size_t size;
    void* user_ptr;
} mem_block;

extern mem_block* root;

#define HASH_TABLE_SIZE 256

#endif