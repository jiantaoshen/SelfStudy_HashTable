#include <stdio.h>
#include <stdlib.h>

#define SIZE 100

//Hash table struct(Linked list)
typedef struct Node {
    int key;
    int value;
    struct Node* next;
} Node;

Node* table[SIZE];

void init() {
    for (int i = 0; i < SIZE; i++) {
        table[i] = NULL;
    }
}

//Hash function
int hash(int key) {
    return key % SIZE;
}

//Hash insert
void insert(int key, int value) {
    int index = hash(key);

    Node* newNode = (Node*)malloc(sizeof(Node));
    newNode->key = key;
    newNode->value = value;
    newNode->next = table[index];

    table[index] = newNode;
}


Node* search(int key) {
    int index = hash(key);

    Node* current = table[index];

    while (current != NULL) {
        if (current->key == key) {
            return current;
        }

        current = current->next;
    }

    return NULL;
}

void delete(int key) {
    int index = hash(key);

    Node* current = table[index];
    Node* prev = NULL;

    while (current != NULL) {
        if (current->key == key) {
            if (prev == NULL) {
                table[index] = current->next;
            } else {
                prev->next = current->next;
            }
            free(current);
            return;
        }
        prev = current;
        current = current->next;
    }
}

//free hash table
void free_table() {
    for (int i = 0; i < SIZE; i++) {
        Node* current = table[i];

        while (current != NULL) {
            Node* temp = current;
            current = current->next;
            free(temp);
        }

        table[i] = NULL;
    }
}

//leetcode: two sum 
int* twoSum(int* nums, int numsSize, int target, int* returnSize) {
    for (int i = 0; i < numsSize; i++) {
        int complement = target - nums[i];
        
        //my search cannot handle negative numbers
        if(complement >= 0)
        {
            Node* item = search(complement);

            if (item) {
                int* result = malloc(sizeof(int) * 2);
                result[0] = item->value;
                result[1] = i;
                *returnSize = 2;
                free_table();
                return result;
            } 
        }

        insert(nums[i], i);
    }
    
    *returnSize = 0;
    free_table();
    // Return an empty array if no solution is found
    return NULL;  // Allocate 0 bytes
}

int main()
{
    init();

    int nums[] = {3,9,4,6,0};
    int numsSize = sizeof(nums) / sizeof(nums[0]);
    int target = 6;
    int returnSize = 2;

    int* result = malloc(sizeof(int) * 2);
    
    result = twoSum(nums, numsSize, target, &returnSize);

    if (result != NULL){
        printf("[%d,%d]\n", result[0], result[1]);
    }
    else{
        printf("No answer. \n");
    }

    return 0;
}