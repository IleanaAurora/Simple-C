#include <stdio.h>
#include <stdlib.h>
#include <sys/file.h>
#include <string.h>

void reverse(char *A, int size);

int main(int argc, char *argv[])
{
	int fds, fdd, size, n, i, c, s, m;
	char buf[100];
	
	if(argc != 3)
	{
		printf("Please provide an input and output file.\n");
		exit(1);
	}
	
	if(strcmp(argv[1], argv[2]) == 0)
	{
		printf("The source and destination files must be distinct.");
		exit(2);
	}
	
	fds = open(argv[1], O_RDONLY);
	if(fds == -1)
	{
		printf("The file %s could not be opened for reading.\n", argv[1]);
		exit(3);
	}

	fdd = open(argv[2], O_RDWR|O_CREAT|O_TRUNC, 0644);
	if(fdd == -1)
	{
		printf("The file %s could not be opened for writing.\n", argv[2]);
		exit(4);
	}
	
	size = lseek(fds, 0, SEEK_END);
	lseek(fds, 0, SEEK_SET);
	
	n = read(fds, buf, 100);
	c = n;
	reverse(buf, n);
	while(n>0)
	{
		for(i=0; i<n; i++)
			if(buf[i] == 32)
				buf[i] += 63;
		m = size - c;
		s = lseek(fdd, m, SEEK_SET);
			if(s == -1)
			{
				printf("Could not find the correct file location.\n");
				exit(1);
			}
		write(fdd, buf, n);
		n = read(fds, buf, 100);
		if(n > 0)
		{
			c += n;
			reverse(buf, n);
		}
	}
	
	write(1,"Done!", sizeof("Done!"));
	
	close(fds);
	close(fdd);
	
	return 0;
}

void reverse(char *A, int size)
{
	int i=0, j=size-1;
	char temp;
	
	while(i < j)
	{
		temp = A[i];
		A[i] = A[j];
		A[j] = temp;
		i++;
		j--;
	}
}