#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct Book
{
	char title[100];
	char author[100];
	int pages;
	int year;
};

void Display(struct Book *b, int size, int s);
void TitleSelectionSort(struct Book *b, int size);
void AuthorSelectionSort(struct Book *b, int size);
void PagesSelectionSort(struct Book *b, int size);
void YearSelectionSort(struct Book *b, int size);
void Swap(struct Book *b, int min, int i);
void PrintBook(struct Book *b);

int main(int argc, char *argv[])
{
	FILE *fpr;
	
	int n,i,s,d=0;
	char junk[2];
	char buf[100];
	
	fpr = fopen("books.db", "r");
	
	fgets(buf, 100, (FILE *)fpr);
	n = atoi(buf);
	
	struct Book *book = (struct Book *) malloc(n * sizeof(struct Book));
	
	for (i=0; i<n; i++)
	{
		fgets(buf, 100, (FILE *)fpr);		
		strcpy(book[i].title, buf);
		
		fgets(buf, 100, (FILE *)fpr);		
		strcpy(book[i].author, buf);
		
		fgets(buf, 100, (FILE *)fpr);
		book[i].pages = atoi(buf);
		
		fgets(buf, 100, (FILE *)fpr);
		book[i].year = atoi(buf);
	}
	
	while (d==0)
	{
		printf("How would you like the books database to be displayed? ('1'-Sort by title, '2'-Sort by author, '3'-Sort by number of pages, '4'-Sort by publication date\n");
		scanf("%d", &s);
		gets(junk);
		
		Display(book,n,s);
		
		printf("Would you like to display the books database again? ('0'-yes, '1'-quit)\n");
		scanf("%d", &d);
		gets(junk);
	}
	free(book);
}

void Display(struct Book *b, int size, int s)
{
	int i;
	if(s==1)
		TitleSelectionSort(b,size);
	if(s==2)
		AuthorSelectionSort(b,size);
	if(s==3)
		PagesSelectionSort(b,size);
	if(s==4)
		YearSelectionSort(b,size);
	for (i=0; i<size; i++)
		PrintBook(&b[i]);
}

void TitleSelectionSort(struct Book *b, int size)
{
	int min, i, j;
    for (i = 0; i < (size-1); i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (strcmp(b[j].title, b[min].title) < 0)
		  {
            min = j;
		  }
		if(min != i)
			Swap(b,min,i);
    }
	printf("Array after title selection sort:\n");
}

void AuthorSelectionSort(struct Book *b, int size)
{
	int min, i, j;
    for (i = 0; i < (size-1); i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (strcmp(b[j].author, b[min].author) < 0)
            min = j;
		if(min != i)
			Swap(b,min,i);
    }
	printf("Array after author selection sort:\n");
}

void PagesSelectionSort(struct Book *b, int size)
{
	int min, i, j;
    for (i = 0; i < (size-1); i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (b[j].pages < b[min].pages)
            min = j;
		if(min != i)
			Swap(b,min,i);
    }
	printf("Array after page count selection sort:\n");
}

void YearSelectionSort(struct Book *b, int size)
{
	int min, i, j;
    for (i = 0; i < (size-1); i++)
    {
        min = i;
        for (j = i+1; j < size; j++)
          if (b[j].year < b[min].year)
            min = j;
		if(min != i)
			Swap(b,min,i);
    }
	printf("Array after publication date selection sort:\n");
}

void Swap(struct Book *b, int min, int i)
{
	struct Book ttemp, atemp;
	int ptemp, ytemp;
	
	strcpy(ttemp.title, b[min].title);
	strcpy(b[min].title, b[i].title);
	strcpy(b[i].title, ttemp.title);

	strcpy(atemp.title, b[min].author);
	strcpy(b[min].author, b[i].author);
	strcpy(b[i].author, atemp.title);
	
	ptemp = b[min].pages;
	b[min].pages = b[i].pages;
	b[i].pages = ptemp;
	
	ytemp = b[min].year;
	b[min].year = b[i].year;
	b[i].year = ytemp;
}

void PrintBook(struct Book *b)
{
	printf("Title: %s Author: %s Number of pages: %d\n Publication Date: %d\n\n", b->title, b->author, b->pages, b->year);
}