#include "../include/funcs.h"

mem_block* root = NULL;

size_t hash_func(size_t size) {
    return size % HASH_TABLE_SIZE;
}

mem_block* find_block(mem_block* node, size_t size) {
    if (node == NULL) {
        return NULL;
    }

    if (node->size >= size) {
        return node;
    } else if (size < node->size) {
        return find_block(node->left, size);
    } else {
        return find_block(node->right, size);
    }
}

void* my_malloc(size_t size) {
    mem_block* block = find_block(root, size);

    if (block != NULL) {
        return block->user_ptr;
    }

    mem_block* new_block = mmap(NULL, sizeof(mem_block) + size, PROT_READ | PROT_WRITE, MAP_ANON | MAP_PRIVATE, -1, 0);
    if (new_block == MAP_FAILED) {
        return NULL;
    }

    new_block->size = size;
    new_block->user_ptr = new_block + 1;
    new_block->left = NULL;
    new_block->right = NULL;

    if (root == NULL) {
        root = new_block;
    } else {
        mem_block* parent = NULL;
        mem_block* current = root;

        while (current != NULL) {
            parent = current;
            if (size < current->size) {
                current = current->left;
            } else {
                current = current->right;
            }
        }

        if (size < parent->size) {
            parent->left = new_block;
        } else {
            parent->right = new_block;
        }
    }

    return new_block->user_ptr;
}