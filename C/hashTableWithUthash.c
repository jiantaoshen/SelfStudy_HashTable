#include <stdio.h>
#include <stdlib.h>
#include "uthash.h"

// Hash table item
typedef struct {
    int key;            // number from array
    int value;          // index
    UT_hash_handle hh;  // makes this struct hashable
} Node;

Node *table = NULL; // uthash table (no fixed size!)

// Insert
void insert(int key, int value) {
    Node *item = malloc(sizeof(Node));
    item->key = key;
    item->value = value;
    HASH_ADD_INT(table, key, item);
}

// Search
Node* search(int key) {
    Node *item;
    HASH_FIND_INT(table, &key, item);
    return item;
}

// Delete all (cleanup)
void free_table() {
    Node *current, *tmp;
    HASH_ITER(hh, table, current, tmp) {
        HASH_DEL(table, current);
        free(current);
    }
}

// LeetCode: Two Sum
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];

        Node* item = search(complement);

        if (item) {
            int* result = malloc(sizeof(int) * 2);
            result[0] = item->value;
            result[1] = i;
            *returnSize = 2;
            free_table();
            return result;
        }

        insert(nums[i], i);
    }

    *returnSize = 0;
    free_table();
    return NULL;
}

int main() {
    int nums[] = {3, 9, 4, 6, 0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 6;
    int returnSize = 0;

    int* result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL) {
        printf("[%d,%d]\n", result[0], result[1]);
        free(result);
    } else {
        printf("No answer.\n");
    }

    return 0;
}