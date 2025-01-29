/*****************************************************************************************************
 * Provided file for lab exam.
 *****************************************************************************************************
 * Author: Heshini Jayweera
 * Project: Strings
 * Copyright: 2023, Marc Hensel
 * Version: 2023.09.18
 * License: CC BY-NC-SA 4.0, see https://creativecommons.org/licenses/by-nc-sa/4.0/deed.en
 *****************************************************************************************************/

#define _CRT_SECURE_NO_DEPRECATE	// Else MSVC++ prevents using functions with potential buffer overflow
#include <stdio.h>
#include <stdlib.h>
//#include <string.h>

 /* Function prototypes (provided by examiner) */
char* invertString(const char* name); //invert the string by using DMA to store the invereted string
int countChar(const char* name, char count); // returns the number of occurences of a character

int main(void)
{
	char name[] = "Welcome to IE-SO1!";
	char letter = 'e';
	char* x;

	printf("Original : %s\n", name);

	x = invertString(name);
	printf("Inverted : ");
	for (int i = 0; x[i] != '\0'; i++) //loop to print the inverted string character by character
	{
		printf("%c", x[i]);
	}
	free(x);// free memory
	
	printf("\nCount '%c' : %d", letter, countChar(name,letter));

	getchar();
	return 0;
}

//invert the string by using DMA to store the invereted string
char* invertString(const char* string)
{
	int size = 19;
	char* ptr = (char*)calloc(size , sizeof(char));//Dynamic alloacation of memory to store the inverted string

	if (ptr == NULL)//checking whether memory allocation is successful
		exit(EXIT_FAILURE);

	for (int i = 0; string[i] != '\0'; i++)
	{
		ptr[i] = string[(size - 2) - i];
	}
	ptr[size - 1] = '\0';//stores the null terminator in the DMA
	return ptr;
}

// returns the number of occurences of a character
int countChar(const char* string, char letter)
{
	int count = 0;
	for (int i = 0; string[i] != '\0'; i++)
	{
		if (string[i] == letter)
		{
			count++;
		}
	}
	return count;
}
