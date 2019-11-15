#include <stdio.h>
#include <stdlib.h>
 
void DiagDom(int *A, int size);
 
int main()
{
    int N, i, j;
	
	printf("Enter a size for the matrix:	\n", N);
	scanf("%d", &N);
	
    int *A = (int *)malloc(N * N * sizeof(int));
	
    for (i = 0; i <  N; i++)
	{
      for (j = 0; j < N; j++)
	  {
		  printf("Enter a value for the position A[%d][%d]:  ", i, j);
		  scanf("%d", (A+i*N+j));
	  }
	}
    for (i = 0; i <  N; i++)
      for (j = 0; j < N; j++)
		  printf("A[%d][%d]=%d\n  ", i, j, *(A+i*N+j));
 
	DiagDom(A, N);
 
	free(A);
	
   return 0;
}

void DiagDom(int *A, int N)
{
	int i, j, sum=0, total=0, DD=1; 
	for (i = 0; i <  N; i++)
	{
      for (j = 0; j < N; j++)
	  {
		  if(i==j)
			  total = abs(*(A+i*N+j));
		  else
			  sum += abs(*(A+i*N+j));
		  if((N-j) == 1)
		  {
			  if(total >= sum)
				  printf("%d >= %d\n", total, sum);
			  else
			  {
				  printf("%d !>= %d\n", total, sum);
				  DD=0;
			  }
		  }
	  }
	  sum=0;
	  total=0;
	}
	if (DD == 0)
		printf("The matrix is not diagonally-dominant.\n");
	else
		printf("The matrix is diagonally-dominant.\n");
}