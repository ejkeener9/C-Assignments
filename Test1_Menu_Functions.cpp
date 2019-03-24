// Author: Emily Keener
// Test 1
// Write 4 programs (several were from previous labs) and use a menu to select each program.
// Make the menu loop and place programs in their own functions

// Pre-Processing
#include "stdafx.h"
#include <iostream>
using namespace System;

// Function prototypes
int compare(); // Asks user for 2 integers. Outputs the larger number or if they are equal.
int compareToString(); // compare() prompt
char * compareProcessing(int x, int y, char number[20]); // compare() processing
int evenOdd(); // Reads an integer and outputs if it is even or odd.
int evenOddToString(); // evenOdd() prompt
int evenOddProcessing(int x); // evenOdd() processing
int intChar(); // Reads an integer and outputs the character equivalent.
int intCharToString(); // intChar() prompt
int squareCube(); // Calculates and outputs the square and cube of 0 - 10
int squareCubeToString(); // squareCube prompt
int squareCubeProcessing(int num); // squareCube() processing

// Begin main()
int main(array<System::String ^> ^args)
{
	// Set console to black text / white background
    system("color f0");

	// Menu input
	int input;

	// Menu loop
	while(input != 0) // Quit is case 0
	{
		system("cls"); // Clears the screen on program load

		// Prompt
		printf("\tSelect an item from the menu: \n\n");
		printf("\tMENU \n\t1 Compare two numbers \n\t2 Even or Odd \n\t3 Integer to character \n\t4 Square and Cube 0-10 \n\t0 Quit\n\t");
		scanf("%d", &input);

		// Select statement for menu
		switch(input)
		{
			case 1 : compare(); break; // Compares 2 numbers for larger / equivalent
			case 2 : evenOdd();break; // Checks if a number is even or odd
			case 3 : intChar(); break; // Outputs the character with the entered integer value
			case 4 : squareCube(); break; // Outputs 0 - 10 and the square / cube of each
			case 0 : printf("\t"); break; // Quits the menu
			default : printf("\tPlease enter a menu item (0-4)\n\t"); // Validation
			system("pause");
		} // End switch
	} // End while
	system("pause");
    return 0;
} // End main()

// compare() prompt - asks user to to input 2 numbers
int compareToString()
{
	printf("\tThis program compares 2 numbers and will output the larger number (or if they are equal).\n");
	printf("\tEnter 2 numbers:\n\t");
	return 0;
} // End compareToString()

// compare function - Asks user for 2 integers. Outputs the larger number or if they are equal.
int compare()
{
	system("cls"); // Clears the screen on program load
	int x, y;
	char number[20];
	compareToString();
	scanf("%d",&x);
	printf("\t");
	scanf("%d", &y);
	printf("\tPrintf called compareProcessing() and passed user integers to it\n\t");
	printf("\t%s\n\t", compareProcessing(x,y, number));
	system("pause");
	return 0;
} // End compare()

// compare() processing - returns which number is larger
char * compareProcessing(int x, int y, char number[20])
{    
	printf("This function will return a String with the result\n");
	// Single selection forms of the if statement
	if(x>y)
	{
		sprintf(number, "%d is larger", x);
		return number;
	}
	if(y>x)
	{
		sprintf(number, "%d is larger", y);
		return number;
	}
	if(x==y)
	{
		return "These numbers are equal";
	}
} // End compareProcessing()

// evenOdd() prompt - asks user to enter a number
int evenOddToString()
{
	printf("\tThis program will check if a number is even or odd.\n");
	printf("\tEnter an integer: \n\t");
	return 0;
} // End evenOddToString()

// evenOdd function - Reads an integer and outputs if it is even or odd.
int evenOdd()
{
	system("cls"); // Clears the screen on program load
	int x;
	evenOddToString();
	scanf("%d",&x);
	printf("\tUser int will now be passed to evenOddProcessing()\n\t");
	evenOddProcessing(x);
	system("pause");
	return 0;
} // End evenOdd()

// evenOdd Processing - return if number is even / odd
int evenOddProcessing(int x)
{
	printf("User int was passed\n");
	if(x%2==0)
	{
		printf("\t%d is even.\n\n\t",x);
	}
	else
	{
		printf("\t%d is odd.\n\n\t",x);
	}
	return 0;
} // End evenOddProcessing()

// intChar prompt - ask user to enter an integer (to char)
int intCharToString()
{
	printf("\tThis program will show the ASCII character equivalent of an integer.\n");
	printf("\tEnter a number: \n\t");
	return 0;
} // End intCharToString()

// intChar function - Reads an integer and outputs the character equivalent.
int intChar()
{
	system("cls"); // Clears the screen on program load
	int x;
	intCharToString();
	scanf("%d",&x);
	printf("\tThe character equivalent is %c\n\n\t", x);
	system("pause");
	return 0;
} // End intChar()

// squareCube prompt - ask user to input a number (output 10+ / square / cube)
int squareCubeToString()
{
	int x;
	printf("\tThis program will output 10 more than a number of your choosing. Then it will show the square and cube of each.\n\tEnter a number\n\n\t");
	scanf("%d", &x);
	printf("\n\t int was stored in x");
	return x;
} // End squareCubeToString()

// squareCube - Calculates and outputs the square and cube of 0 - 10
int squareCube()
{
	system("cls"); // Clears the screen on program load
	squareCubeProcessing(squareCubeToString());
	system("pause");
    return 0;
} // End squareCube()

// squareCube processing - output square / cube results
int squareCubeProcessing(int x)
{
	printf("\n\tUser int was passed\n\n");
	int num = x;
	printf("\tNumber \tSquare \t Cube\n");
	while(num <= x + 10)
	{
		printf("\t%d\t%d\t%d\n",num,num*num,num*num*num);
		num++;
	}
	printf("\n\t");
	return 0;
} // End squareCubeProcessing()
