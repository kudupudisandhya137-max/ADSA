#include<stdio.h>
#define MAX 50

void swap(int *,int *);
void maxHeapifyUp(int);
void maxHeapifyDown(int);
void insertMaxHeap(int);
void deleteMaxHeap();
void displayMaxHeap();

int maxHeap[MAX];
int maxSize=0;

void swap(int *a,int *b) 
{
	int temp=*a;
	*a = *b;
	*b = temp;
}

void insertMaxHeap(int value) 
{
	maxHeap[maxSize] = value;
	maxHeapifyUp(maxSize);
	maxSize++;
}

void maxHeapifyUp(int i)
{   
	while(i>0 && maxHeap[(i-1) / 2] < maxHeap[i])
	{
		swap (&maxHeap[i], &maxHeap[(i-1) / 2]);
		i=(i-1) / 2;
	}
}

void deleteMaxHeap()
{
	if(maxSize == 0)
	{
		printf("Max Heap is empty\n");
		return;
	}
	printf("Deleted element: %d\n", maxHeap[0]);
	maxHeap[0] = maxHeap[--maxSize];
	maxHeapifyDown(0);
}

void maxHeapifyDown(int i)
{
	int largest = i;
	int left = 2 * i + 1;
	int right = 2 * i + 2;
	if(left < maxSize && maxHeap[left] > maxHeap[largest])
	    largest = left;
	if(right < maxSize && maxHeap[right] > maxHeap[largest])
	    largest = right;
	if(largest != i)
	{
		swap(&maxHeap[i], &maxHeap[largest]);
		maxHeapifyDown(largest);
	}
}

void displayMaxHeap()
{   int i;
	printf("Max Heap: ");
	for(i=0;i< maxSize ; i++)
	    printf("%d  ", maxHeap[i]);
	printf("\n");
}

int main()
{
	int choice , value;
	do
	{
		printf("\n---Heap operations---\n");
		printf("1. Insert into Max Heap\n");
		printf("2. Delete from Max Heap\n");
		printf("3. Display Max Heap\n");
		printf("0. Exit\n");
		printf("Enter choice: ");
		scanf("%d",&choice);
		switch(choice)
		{
			case 1:
				printf("Enter value to insert: ");
              scanf("%d",&value);

				insertMaxHeap(value);
				break;
			case 2:
				deleteMaxHeap();
				break;
			case 3:
				displayMaxHeap();
				break;
			case 0:
				exit(0);
				break;
			default:
				printf("Invalid choice");
		}
		
	}while(choice!=0);
	return 0;
} 
