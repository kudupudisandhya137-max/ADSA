#include <stdio.h>
#include <stdlib.h>

#define SIZE 11

/* Node structure for linked list */
struct Node {
    int data;
    struct Node *next;
};

/* Hash table (array of pointers) */
struct Node *hashTable[SIZE];

/* Function to initialize hash table */
void initHashTable() {
    int i;
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = NULL;
    }
}

/* Hash function */
int hashFunction(int key) {
    return key % SIZE;
}

/* Insert function */
void insert(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];

    /* Check for duplicate key */
    while (temp != NULL) {
        if (temp->data == key) {
            printf("--------Duplicate key! Insertion not allowed----------\n");
            return;
        }
        temp = temp->next;
    }

    /* Create new node */
    struct Node *newNode = (struct Node *)malloc(sizeof(struct Node));
    if (newNode == NULL) {
        printf("-----------Memory allocation failed----------\n");
        return;
    }

    newNode->data = key;
    newNode->next = hashTable[index];
    hashTable[index] = newNode;

    printf("----------Key %d inserted successfully-----------\n", key);
}

/* Search function */
void search(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];

    while (temp != NULL) {
        if (temp->data == key) {
            printf("-----------Key %d found at index %d---------\n", key, index);
            return;
        }
        temp = temp->next;
    }

    printf("--------Key %d not found----------\n", key);
}

/* Delete function */
void deleteKey(int key) {
    int index = hashFunction(key);
    struct Node *temp = hashTable[index];
    struct Node *prev = NULL;

    if (temp == NULL) {
        printf("-------Key %d not found-------\n", key);
        return;
    }

    /* If key is at head */
    if (temp->data == key) {
        hashTable[index] = temp->next;
        free(temp);
        printf("----------Key %d deleted successfully----------\n", key);
        return;
    }

    /* Search in chain */
    while (temp != NULL && temp->data != key) {
        prev = temp;
        temp = temp->next;
    }

    if (temp == NULL) {
        printf("----------Key %d not found---------\n", key);
        return;
    }

    prev->next = temp->next;
    free(temp);
    printf("----------Key %d deleted successfully------------\n", key);
}

/* Display function */
void display() {
    int i;
    printf("\nHash Table Contents:\n");

    for (i = 0; i < SIZE; i++) {
        printf("Index %d : ", i);
        struct Node *temp = hashTable[i];

        if (temp == NULL) {
            printf("NULL");
        }

        while (temp != NULL) {
            printf("%d -> ", temp->data);
            temp = temp->next;
        }
        printf("\n");
    }
}

/* Main function */
int main() {
    int choice, key;

    initHashTable();

    while (1) {
        printf("\n====== OPEN HASHING (SEPARATE CHAINING) ======\n");
        printf("1. Insert\n");
        printf("2. Search\n");
        printf("3. Delete\n");
        printf("4. Display\n");
        printf("5. Exit\n");
        printf("Enter your choice: ");
        scanf("%d", &choice);

        switch (choice) {
            case 1:
                printf("Enter key to insert: ");
                scanf("%d", &key);
                insert(key);
                break;

            case 2:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 3:
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting program...\n");
                exit(0);

            default:
                printf("Invalid choice! Try again.\n");
        }
    }

    return 0;
}
