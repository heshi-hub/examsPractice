/*
*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Heshini Jayaweera
 * Project: WS2022/23 Series expansions
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 ******************************************************************************************************
 */
#define _USE_MATH_DEFINES
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <math.h>

void clearInputBuffer(void);//Clear input buffer
double sine(double alpha, int i); //returns the approximation of sine(alpha) value (i.e not with the principal x value
double principalValue(double alpha);//returns the alpha with the principal value

int main(void)
{
	while (1)
	{
		double x = 0.0;
		double alpha = 0.0;
		int k = 0;
		char keyPressed = 0;

		printf("Series expansion for sin(x * PI) with k < 0 terms.\n");
		printf("Please enter <x>,<k>: ");
		while (scanf("%lf, %d", &x, &k) != 2 || k <= 0)
			printf("Invalid input.Retry: ");
		clearInputBuffer();

		alpha = x * M_PI;

		printf("Approximations of sin(%.2f * pi):\n", x);
		for (int i = 1; i <= k; i++)
		{
			printf("  k = %2d: sin(x * PI) = %lf\n", i, sine(alpha,i) * alpha);

		}
		printf("Principal value: %.2f * pi\n", principalValue(alpha) / M_PI); //divide by pi to get the new x value

		printf("Enter <q> to quit, any other key to continue. ");
		scanf("%c", &keyPressed);
		clearInputBuffer();

		if (keyPressed == 'q' || keyPressed == 'Q')
			break;
		putchar('\n');
	}
	
	return 0;
}

//Clear input buffer
void clearInputBuffer(void)
{
	while (getchar() != '\n')
		continue;
}

//returns the approximation of sine(alpha) value (i.e not with the principal x value
double sine(double alpha, int k)
{
	double sinX = 1.0;
	int i = 1;
	while (i <= k)
	{
		sinX *= 1 - (pow(alpha, 2) / (pow((double)i, 2) * pow(M_PI, 2)));
		i++;
	}
	return sinX;
}

//returns the alpha with the principal value
double principalValue(double alpha)
{
	const double PI_2 = 2 * M_PI;

	if (alpha >= PI_2)
	{
		alpha -= PI_2;
	}

	if (alpha < 0)
	{
		alpha += PI_2;
	}

	return alpha;
}
