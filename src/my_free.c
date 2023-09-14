#include "../include/funcs.h"

void remove_block(mem_block* parent, mem_block* node) {
    if (node->left == NULL && node->right == NULL) {
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = NULL;
            } else {
                parent->right = NULL;
            }
        } else {
            root = NULL;
        }
    } else if (node->left != NULL && node->right == NULL) {
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = node->left;
            } else {
                parent->right = node->left;
            }
        } else {
            root = node->left;
        }
    } else if (node->left == NULL && node->right != NULL) {
        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = node->right;
            } else {
                parent->right = node->right;
            }
        } else {
            root = node->right;
        }
    } else {
        mem_block* successor = node->right;
        mem_block* successor_parent = node;
        while (successor->left != NULL) {
            successor_parent = successor;
            successor = successor->left;
        }

        if (successor_parent == node) {
            successor_parent->right = successor->right;
        } else {
            successor_parent->left = successor->right;
        }

        successor->left = node->left;
        successor->right = node->right;

        if (parent != NULL) {
            if (parent->left == node) {
                parent->left = successor;
            } else {
                parent->right = successor;
            }
        } else {
            root = successor;
        }
    }

    munmap(node, sizeof(mem_block) + node->size);
}

void my_free(void* ptr) {
    if (ptr == NULL) {
        return;
    }

    mem_block* node_to_free = (mem_block*)ptr - 1;
    mem_block* parent = NULL;
    mem_block* current = root;

    while (current != NULL && current != node_to_free) {
        parent = current;
        if (node_to_free < current) {
            current = current->left;
        } else {
            current = current->right;
        }
    }

    if (current != NULL) {
        remove_block(parent, current);
    }
}