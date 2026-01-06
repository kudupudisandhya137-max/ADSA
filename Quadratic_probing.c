#include <stdio.h>
#include <limits.h>

#define SIZE 10
#define EMPTY INT_MIN
#define DELETED (INT_MIN + 1)

int hashTable[SIZE];

/* Initialize hash table */
void initTable() {
	int i;
    for (i = 0; i < SIZE; i++) {
        hashTable[i] = EMPTY;
    }
}

/* Hash function (modulo) */
int hashFunction(int key) {
    return key % SIZE;
}

/* Insert operation using Quadratic Probing */
void insert(int key) {
    int index = hashFunction(key),i;

    for (i = 0; i < SIZE; i++) {
        int probeIndex = (index + i * i) % SIZE;

        if (hashTable[probeIndex] == EMPTY ||
            hashTable[probeIndex] == DELETED) {
            hashTable[probeIndex] = key;
            printf("Inserted %d at index %d\n", key, probeIndex);
            return;
        }
    }

    printf("Hash table is FULL. Insertion failed.\n");
}

/* Search operation */
void search(int key) {
    int index = hashFunction(key),i;

    for (i = 0; i < SIZE; i++) {
        int probeIndex = (index + i * i) % SIZE;

        if (hashTable[probeIndex] == EMPTY) {
            break;
        }

        if (hashTable[probeIndex] == key) {
            printf("Key %d found at index %d\n", key, probeIndex);
            return;
        }
    }

    printf("Key %d not found\n", key);
}

/* Delete operation */
void deleteKey(int key) {
    int index = hashFunction(key),i;

    for (i = 0; i < SIZE; i++) {
        int probeIndex = (index + i * i) % SIZE;

        if (hashTable[probeIndex] == EMPTY) {
            break;
        }

        if (hashTable[probeIndex] == key) {
            hashTable[probeIndex] = DELETED;
            printf("Key %d deleted from index %d\n", key, probeIndex);
            return;
        }
    }

    printf("Key %d not found. Deletion failed.\n", key);
}

/* Display hash table */
void display() {
	int i;
    printf("\nHash Table:\n");
    for (i = 0; i < SIZE; i++) {
        if (hashTable[i] == EMPTY)
            printf("[%d] : EMPTY\n", i);
        else if (hashTable[i] == DELETED)
            printf("[%d] : DELETED\n", i);
        else
            printf("[%d] : %d\n", i, hashTable[i]);
    }
}

/* Main function */
int main() {
    int choice, key;

    initTable();

    while (1) {
        printf("\n--- QUADRATIC PROBING HASH TABLE ---\n");
        printf("1. Insert\n");
        printf("2. Delete\n");
        printf("3. Search\n");
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
                printf("Enter key to delete: ");
                scanf("%d", &key);
                deleteKey(key);
                break;

            case 3:
                printf("Enter key to search: ");
                scanf("%d", &key);
                search(key);
                break;

            case 4:
                display();
                break;

            case 5:
                printf("Exiting...\n");
                return 0;

            default:
                printf("Invalid choice. Try again.\n");
        }
    }
}

