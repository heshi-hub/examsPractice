/*
*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Heshini Jayaweera
 * Project: WS2023/24
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 ******************************************************************************************************
 */

#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>
#include <time.h>

typedef struct {
	int x;
	int y;
}point2D;

//Function prototypes
int keyboardInputNumberPoints(void);//get the user inputs for N, number of points
point2D* generateRandomPoints(int numberPoints);//
void printPoints(point2D* points, int numberPoints);
point2D getCenterOfGravity(point2D* points, int numberPoints);

int main(void)
{
	int numPoints = keyboardInputNumberPoints();
	point2D* coordinates = generateRandomPoints(numPoints);
	printPoints(coordinates, numPoints);

	point2D m = getCenterOfGravity(coordinates, numPoints);
	printf("\nCenter of gravity: cog = (%d,%d)", m.x, m.y);

	free(coordinates);
	return 0;
}

//get the user inputs for N, number of points
int keyboardInputNumberPoints(void)
{
	int n = 0;
	int userInput = 0;

	while (1)
	{
		printf("Enter number of 2D points to generate: ");
		userInput = scanf("%d", &n);
		while (getchar() != '\n')//Clear input buffer
			continue;
		 
		if (userInput != 1)
			printf("Invalid Input. Try again.\n\n");
		else if (n < 0)
		{
			printf("Number of points must be positive. Try again.\n\n");
		}
		else if (userInput == 1)
		{
			printf("Number entered: %d\n", n);
			break;
		}
	}
	
	return n;
}

point2D* generateRandomPoints(int numberPoints)
{
	point2D* points;
	if ((points = (point2D*)malloc(numberPoints * sizeof(point2D))) == NULL)
		exit(EXIT_FAILURE);

	srand((unsigned)time(NULL));

	for (int y = 0; y < numberPoints; y++)
	{
		points[y].x = rand() % 10;
		points[y].y = rand() % 10;
	}

	return points;
}

void printPoints(point2D* points, int numberPoints)
{
	for (int k = 0; k < numberPoints; k++)
	{
		printf("P%d = (%d , %d)\n", k+1 , points[k].x,points[k].y);
	}
}

point2D getCenterOfGravity(point2D* points, int numberPoints)
{
	int sumX = 0;
	int sumY = 0;
	point2D mean;

	for (int i = 0; i < numberPoints; i++)
	{
		sumX += points[i].x;
		sumY += points[i].y;
	}

	mean.x = (sumX + (int)0.5) / numberPoints;
	mean.y = (sumY + (int)0.5) / numberPoints;

	return mean;
}
