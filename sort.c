#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 10

void InsertionSort(int *A, int size);
void SelectionSort(int *A, int size);
void Init(void (* func) (int*, int), int *A, int size);

int main()
{
	int A[N];
	Init(InsertionSort, A, N);
	Init(SelectionSort, A, N);
}

void Init(void (* func) (int*, int), int *A, int size)
{
	int i;
	srand(time(NULL));
	for (i=0; i<size; i++)
		A[i] = rand()%90+10;
	printf("Original array:\n");
	for (i=0; i<size; i++)
		printf("A[%d] = %d\n", i, A[i]);
	printf("\n");
	return func(A, size);
}

void InsertionSort(int *A, int size)
{
   int i, j, k;
   for (i = 1; i < size; i++)
   {
       k = *(A+i);
       j = i-1;
       while (j >= 0 && *(A+j) > k)
       {
           *(A+j+1) = *(A+j);
           j = j-1;
       }
       *(A+j+1) = k;
   }
   printf("Array after insertion sort:\n");
	for (i=0; i<size; i++)
		printf("A[%d] = %d\n", i, A[i]);
	printf("\n");
}

void SelectionSort(int *A, int size)
{
	int min, temp, i, j;
    for (i = 0; i < (size-1); i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (*(A+j) < *(A+min))
            min = j;
		int temp = *(A+min);
		*(A+min) = *(A+i);
		*(A+i) = temp;
    }
	printf("Array after selection sort:\n");
	for (i=0; i<size; i++)
		printf("A[%d] = %d\n", i, A[i]);
	printf("\n");
}