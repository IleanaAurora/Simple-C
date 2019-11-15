#include <stdio.h>
#include <stdlib.h>
#include <time.h>

#define N 100

int Find_k_Largest(int *A, int size, int k);
int smallest(int *A, int size);
	
int main()
{
	int A[N];
	int res, i, k;
	
	srand(time(NULL));
	for (i=0; i<N; i++)
		A[i] = rand()%200-100;
		
	for (i=0; i<N; i++)
		printf("A[%d] = %d\n", i, A[i]);
	
	printf("Enter an integer to indicate which smallest array element to search for:	\n", k);
	scanf("%d", &k);

	res = Find_k_Largest(A, N, k);
	
	printf("The chosen smallest array element is %d\n", A[res]);
}

	int Find_k_Largest(int *A, int size, int k)
	{
		int i;
		for (i=0; i<k; i++)
		{
			int s = smallest(A, N);
			if((k-i) == 1)
				{return s;}
			A[s]= 100;
		}
	}

	int smallest(int *A, int size)
	{
	int min = 0;
	int i;
	
	for (i=0; i<size; i++)
		if (A[i] < A[min])
			min=i;
	return min;
	}
