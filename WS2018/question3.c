/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Heshini Jayaweera
 * Project: User input and bit operations
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.19
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

 /* Include files */
#define _CRT_SECURE_NO_DEPRECATE
#include <stdio.h>
#include <stdlib.h>

int main(void)
{
	const int maxN = 16;
	int n;

	printf("Calculation of 2^n with n in [0,16]:\n");

	while (1)
	{
		printf("Enter n: ");

		//if user input is not an integer program terminates
		if (scanf("%d", &n) != 1) 
			break;

		//Clear keyboard input buffer
		while (getchar() != '\n')
			continue;

		if (n < 0 || n > maxN)
		{
			printf("Incorrect input: Not in [0,16]\n");
		}
		else
		{
			printf("2^%d = %d\n", n, 1 << n);
		}
	}
	
	printf("Press any key to quit. ");
	return 0;
}


