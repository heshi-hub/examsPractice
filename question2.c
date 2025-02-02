/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Heshini Jayaweera
 * Project: Array operations
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

 /* Include files */
#include <stdio.h>
#include <stdlib.h>

/* Function prototypes (provided by examiner) */
void printArray(const int a[], int size);
int* cloneArray(const int a[], int size);
void swap(int* a, int* b);
void invertArray(int a[], int size);

int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int m = sizeof(a) / sizeof(a[0]);

	printf("Input     :[");
	printArray(a, m);

	int* clone = cloneArray(a, m);
	printf("\nClone     :[");
	printArray(clone, m);
	/*for (int i = 0; i < m; i++)
	{
		printf("%2d,", clone[i]);
	}
	printf("\b]");*/

	invertArray(clone, m);
	printf("\nInverted  :[");
	printArray(clone, m);
	/*for (int i = 0; i < m; i++)
	{
		printf("%2d,", clone[i]);
	}
	printf("\b]");*/

	free(clone);
	return 0;
}

void printArray(const int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%2d,", a[i]);
	}
	printf("\b\a]");
}

int* cloneArray(const int a[], int size)
{
	int* clone = (int*)malloc(size * sizeof(int));
	if (clone == NULL)
	{
		exit(EXIT_FAILURE);
	}

	for (int i = 0; i < size; i++)
	{
		clone[i] = a[i];
	}
	
	return clone;
}

void swap(int* a, int* b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

void invertArray( int a[], int size)
{
	for (int i = 0; i < size/2 ; i++)
	{
		swap(&a[i], &a[size - (i+1)]);
	}
}
