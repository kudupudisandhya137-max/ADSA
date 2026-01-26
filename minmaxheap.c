#include <stdio.h>
#include <stdlib.h>

#define MAX 50

/* ---------- COMMON ---------- */
void swap(int *a, int *b)
{
    int temp = *a;
    *a = *b;
    *b = temp;
}

/* ---------- MAX HEAP ---------- */
int maxHeap[MAX];
int maxSize = 0;

void maxHeapifyUp(int i)
{
    while (i > 0 && maxHeap[(i - 1) / 2] < maxHeap[i])
    {
        swap(&maxHeap[i], &maxHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
}

void maxHeapifyDown(int i)
{
    int largest = i;
    int left = 2 * i + 1;
    int right = 2 * i + 2;

    if (left < maxSize && maxHeap[left] > maxHeap[largest])
        largest = left;
    if (right < maxSize && maxHeap[right] > maxHeap[largest])
        largest = right;

    if (largest != i)
    {
        swap(&maxHeap[i], &maxHeap[largest]);
        maxHeapifyDown(largest);
    }
}

void insertMaxHeap(int value)
{
    maxHeap[maxSize] = value;
    maxHeapifyUp(maxSize);
    maxSize++;
}

void deleteMaxHeap()
{
    if (maxSize == 0)
    {
        printf("Max Heap is empty\n");
        return;
    }

    printf("Deleted from Max Heap: %d\n", maxHeap[0]);
    maxHeap[0] = maxHeap[--maxSize];
    maxHeapifyDown(0);
}

void displayMaxHeap()
{
    int i;
    printf("Max Heap: ");
    for (i = 0; i < maxSize; i++)
        printf("%d ", maxHeap[i]);
    printf("\n");
}

/* ---------- MIN HEAP ---------- */
int minHeap[MAX];
int minSize = 0;

void minHeapifyUp(int i)
{
    while (i > 0 && minHeap[(i - 1) / 2] > minHeap[i])
    {
        swap(&minHeap[i], &minHeap[(i - 1) / 2]);
        i = (i - 1) / 2;
    }
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

void insertMinHeap(int value)
{
    minHeap[minSize] = value;
    minHeapifyUp(minSize);
    minSize++;
}

void deleteMinHeap()
{
    if (minSize == 0)
    {
        printf("Min Heap is empty\n");
        return;
    }

    printf("Deleted from Min Heap: %d\n", minHeap[0]);
    minHeap[0] = minHeap[--minSize];
    minHeapifyDown(0);
}

void displayMinHeap()
{
    int i;
    printf("Min Heap: ");
    for (i = 0; i < minSize; i++)
        printf("%d ", minHeap[i]);
    printf("\n");
}

/* ---------- MAIN ---------- */
int main()
{
    int choice, value;

    do
    {
        printf("\n--- HEAP OPERATIONS ---\n");
        printf("1. Insert into Max Heap\n");
        printf("2. Delete from Max Heap\n");
        printf("3. Display Max Heap\n");
        printf("4. Insert into Min Heap\n");
        printf("5. Delete from Min Heap\n");
        printf("6. Display Min Heap\n");
        printf("0. Exit\n");
        printf("Enter choice: ");
        scanf("%d", &choice);

        switch (choice)
        {
            case 1:
                printf("Enter value: ");
                scanf("%d", &value);
                insertMaxHeap(value);
                break;

            case 2:
                deleteMaxHeap();
                break;

            case 3:
                displayMaxHeap();
                break;

            case 4:
                printf("Enter value: ");
                scanf("%d", &value);
                insertMinHeap(value);
                break;

            case 5:
                deleteMinHeap();
                break;

            case 6:
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

