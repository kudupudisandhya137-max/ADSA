#include<stdio.h>
#include<stdlib.h>

#define MAX 50

void swap(int *, int *);
void minHeapifyUp(int);
void minHeapifyDown(int);
void insertMinHeap(int);
void deleteMinHeap();
void displayMinHeap();

int minHeap[MAX];
int minSize = 0;

void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

void insertMinHeap(int value)
{
    minHeap[minSize] = value;
    minHeapifyUp(minSize);
    minSize++;
}

void minHeapifyUp(int i)
{
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i])
    {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void deleteMinHeap()
{
    if (minSize == 0)
    {
        printf("Min Heap is empty\n");
        return;
    }

    printf("Deleted element: %d\n", minHeap[0]);
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
}

void minHeapifyDown(int i)
{
    int smallest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < minSize && minHeap[left] < minHeap[smallest])
        smallest = left;

    if (right < minSize && minHeap[right] < minHeap[smallest])
        smallest = right;

    if (smallest != i)
    {
        swap(&minHeap[i], &minHeap[smallest]);
        minHeapifyDown(smallest);
    }
}

void displayMinHeap()
{
    int i;
    printf("Min Heap: ");
    for (i = 0; i < minSize; i++)
        printf("%d  ", minHeap[i]);
    printf("\n");
}

int main()
{
    int choice, value;

    do
    {
        printf("\n---Heap operations---\n");
        printf("1. Insert into Min Heap\n");
        printf("2. Delete from Min Heap\n");
        printf("3. Display Min Heap\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value to insert: ");
                scanf("%d", &value);
                insertMinHeap(value);
                break;

            case 2:
                deleteMinHeap();
                break;

            case 3:
                displayMinHeap();
                break;

            case 0:
                exit(0);

            default:
                printf("Invalid choice\n");
        }
    } while (choice != 0);

    return 0;
}

