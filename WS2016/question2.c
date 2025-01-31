/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Heshini Jayaweera
 * Project: https://github.com/MarcOnTheMoon/coding_learners_c/
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.18
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/
#define _CRT_NO_SECURE_DEPRECATE
#include <stdio.h>
#include <math.h>
#define DIM 2

 /* Function prototypes */
void scaleVector2D(double a[DIM], double k); // changing the original vector after scaling
void printVector2D(const double *vector ); // Printing the vector
double vectorLength(const double* a1); // Returning the length of the vector after calculation
double dotProduct2D(const double* a1, const double* a2); //returning the dot product 

/* Main function */
int main(void)
{
	double a1[DIM] = { 3., 4. };
	double a2[DIM] = { -2., 6. };

	/* Print vectors to the console */
	printf("Vectors:\na1 = ");
	printVector2D(a1);
	printf("\na2 = ");
	printVector2D(a2);
	printf("\n\n");

	/* Vector length */
	printf("Vector length:\n|a1| = %.1f\n\n", vectorLength(a1));

	/* Scale vector */
	printf("Scale a2 with 0.5:\na2 = ");
	scaleVector2D(a2, 0.5);
	printVector2D(a2);
	printf("\n\n");

	/* Vector product */
	printf("Dot product:\n<a1, a2> = %.1f\n\n", dotProduct2D(a1, a2));

	getchar();
	return 0;
}

// changing the original vector after scaling
void scaleVector2D(double a[DIM], double k)
{
	*a *= k;
	*(a + 1) *= k;
}

// Printing the vector
void printVector2D(const double* vector)
{
	printf("(%.1f, %.1f)", *vector, *(vector + 1));
}

// Returning the length of the vector after calculation
double vectorLength(const double* a1)
{
	double length = 0.;
	length = sqrt(pow(*a1, 2) + pow(*(a1 + 1), 2));
	return length;
}

//returning the dot product 
double dotProduct2D(const double* a1, const double* a2)
{
	double dotProduct = 0.0;
	dotProduct = (*a1) * (*a2) + (*(a1 + 1)) * (*(a2 + 1));
	return dotProduct;
}
