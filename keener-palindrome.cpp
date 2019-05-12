// Emily Keener
// Lab - Palindrome
// Write a function to check if the user typed in a palindrome
// bool isPalindrome to return if word is palindrome

#include "stdafx.h"
#include <iostream>
#include <cstring>
#include <string>

// Function prototype
bool IsPalindrome(char *input);

using namespace System;

int main()
{
    char input[100]; // word up to 100 chars
	char buffer; // store Enter key

	printf("This program will check if a word you enter is a palindrome\n");

	// Prompt for word
	printf("Enter a word:\n");
	scanf("%s", &input);
	// store Enter key
	scanf("%c", &buffer);

	// Print if word is a Palindrome or not
	printf(IsPalindrome(input) ? "\nYour word is a palindrome\n" : "\nYour word is not a palindrome\n");
	// This checks for 1 if true or 0 if false and prints corrisponding statement

	system("pause");
    return 0;
}

bool IsPalindrome(char *input)
{
	bool palin; // return variable
	char temp[100]; // temporary string up to 100 chars
	int size = strlen(input); // store size of word

	int j = size-1; // store size-1 to reverse word in temp
	for(int i = 0; i < size;i++)
	{
			temp[j] = input[i]; // store word in temp, reversed
			j--;
	}

	/* compare arrays for testing
	for(int i=0;i<size;i++)
	{
		printf("%c",input[i]);
	}
	printf("\n");
	for(int i=0;i<size;i++)
	{
		printf("%c",temp[i]);
	}
	*/

	// Check if arrays match (palindrome)
	for(int i=0;i<size;i++)
	{
		if(input[i]==temp[i])
			palin = true;
		else
			palin = false;
	}

	return palin;
}

/*
This program will check if a word you enter is a palindrome
Enter a word:
red

Your word is not a palindrome
Press any key to continue . . .
*/

/*
This program will check if a word you enter is a palindrome
Enter a word:
racecar

Your word is a palindrome
Press any key to continue . . .
*/