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
void printArray(const int a[], int size); //Print an array of integers
int* cloneArray(const int a[], int size); //print a clone of the array printed above stored using DMA
void swap(int* a, int* b); // swapping the two elements of an array
void invertArray(int a[], int size); //invert an array without creating a new array

int main(void)
{
	int a[] = {1,2,3,4,5,6,7,8,9};
	int m = sizeof(a) / sizeof(a[0]); //number of elements in the integer array
	printf("Input     :[");
	printArray(a, m);

	int* clone = cloneArray(a, m);
	printf("\nClone     :[");
	printArray(clone, m);

	invertArray(clone, m);
	printf("\nInverted  :[");
	printArray(clone, m);
	
	free(clone); //free dynamically allocated memory
	return 0;
}

//Print an array of integers
void printArray(const int a[], int size)
{
	for (int i = 0; i < size; i++)
	{
		printf("%2d,", a[i]);
	}
	printf("\b\a]");
}

//print a clone of the array printed above stored using DMA
int* cloneArray(const int a[], int size)
{
	int* clone = (int*)malloc(size * sizeof(int)); //dynamic memory allocation to store the clone array

	//end the program if memory allocation fails
	if (clone == NULL) 
	{
		exit(EXIT_FAILURE);
	}

	// initializing the memory with the values in the original array
	for (int i = 0; i < size; i++)
	{
		clone[i] = a[i];
	}
	
	return clone;
}

// swapping the two elements of an array
void swap(int* a, int* b)
{
	int swap = *a;
	*a = *b;
	*b = swap;
}

//invert an array without creating a new array
void invertArray( int a[], int size)
{
	for (int i = 0; i < size/2 ; i++) //size/2 because on 4 iterations are needed to completely swap the elements, middle element stay as it is
	{
		swap(&a[i], &a[size - (i+1)]);
	}
}
