/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Marc Hensel, http://www.haw-hamburg.de/marc-hensel
 * Project: https://github.com/MarcOnTheMoon/coding_learners_c/
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.18
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdlib.h>

 /* Function prototypes (provided by examiner) */
void clearInputBuffer();
void sortDescending(int* a, int* b); //Sorting two integers to get the greatest and swap if required
int greatestCommonDivisor(int, int); //finding the gcd of two integers using Euclidean algorithm
int getNumberOfDivisors(int m);
int* newArrayOfDivisors(int m);

int main(void)
{
	int m = 0;
	int n = 0;
	int* divisors = 0;

	printf("Enter two positive integer values (comma-seperated): ");
	while (scanf("%d, %d", &m, &n) != 2 || m <= 0 || n <= 0)
	{
		printf("Invalid input. Retry: ");
		clearInputBuffer();
	}
	clearInputBuffer();

	printf("Divisors of %d: ", m);
	divisors = newArrayOfDivisors(m);
	for (int i = 0; i < getNumberOfDivisors(m); i++)
	{
		printf("%d ", divisors[i]);
	}
	putchar('\n');
	free(divisors);

	printf("Greatest commom divisor: gcd(%d,%d) = %d", m, n, greatestCommonDivisor(m, n));
	
	return 0;
}

void clearInputBuffer()
{
	while (getchar() != '\n')
		continue;
}

//Sorting two integers to get the greatest and swap if required
void sortDescending(int* a, int* b)
{
	if (*b > *a)
	{
		int change = *a;
		*a = *b;
		*b = change;
	}
}

//finding the gcd of two integers using Euclidean algorithm
int greatestCommonDivisor(int m, int n)
{
	int remainder = 0;
	do
	{
		sortDescending(&m, &n);
		m = remainder = m % n;
	}while (remainder != 0);

	return n;
}

int getNumberOfDivisors(int m)
{
	int divisor = 1;

	for (int k = 2; k <= m / 2; k++)
	{
		if (m % k == 0)
			divisor += 1;
	}

	return divisor;
}

int* newArrayOfDivisors(int m)
{
	int numDivisor = getNumberOfDivisors(m);
	int* divisors = (int*)malloc(numDivisor * sizeof(int));
	if (divisors == NULL)
		exit(EXIT_FAILURE);
	
	for (int i = 1, count = 0; i <= m/2; i++)
	{
		if (m % i == 0)
			divisors[count++] = i;
	}
	return divisors;
}
