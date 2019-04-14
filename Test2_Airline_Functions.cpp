// Author: Emily Keener
// Test 2
// Flight company needs a program to show a menu of 3 flights, their number, day, and time.
// Each Flight holds up to 15 passengers
// Use a function to display menu and another to check if there are seats available. 

#include "stdafx.h"
#include <iostream>
using namespace System;

// Function prototypes
void company(); // Prints company header
void schedule(int flights[]); // Prints updated schedule
int getFlight(int f); // Get user flight input
int menu(int f, int flights[]); // Menu which includes schedule() and getFlight() calls
int checkFlight(int f, int flights[], int counter, int passengers[]); // Checks if flight is full / available

// Begin Main()
int main()
{
	// Set console to black text / white background
    system("color f0");

	//int flights[3] = {12,15,5}; // test flights
	int flights[] = {0,0,0};
	int passengers[45]; // stores passenger choices in order for report #2
	int f; // user input for flight number
	bool quit = false; // quits menu loop
	char exit; // user input to quit program
	int counter = 0; // number of passengers entered

	while(quit == false) // quit condition to end program
	{
		f = menu(f, flights); // updates user input variable
		counter = checkFlight(f, flights, counter, passengers); // checks if flight is available or full

		bool validate = false; // validates Quit input
		// Quit program check
		while(validate == false)
		{
			printf("Would you like to exit? [Y/N]\n");
			scanf("%c%c", &exit);
			if(exit == 'y' || exit == 'Y')
			{
				validate = true;
				quit = true;
			}
			else if(exit == 'n' || exit == 'N')
			{
				validate = true;
			}
			else{
				printf("Please enter Y for Yes or N for No.\n");
				validate = false;
			}
		}
	}
} // end Main

// Begin company()
void company() // Prints Company header
{
	system("cls"); // clear screen
	printf("-----------------------------------------------------------\n");
	printf("\t* F A S T   F L I G H T   A I R L I N E S * \n");
	printf("-----------------------------------------------------------\n");
} //end company()

// Begin schedule()
void schedule(int flights[]) // Prints updated schedule
{
	printf("\t\tF L I G H T   S C H E D U L E\n");
		printf("-----------------------------------------------------------\n");
		printf("     N U M B E R     D A Y     T I M E     S E A T S\n"); // extra column to show seats available
		printf("     1\t             Mon       6:00 AM");
		if(flights[0]==15)
			printf("     FULL");
		else
			printf("     %d", 15-flights[0]);
		printf("\n     2\t             Wed      12:00 PM");
		if(flights[1]==15)
			printf("     FULL");
		else
			printf("     %d", 15-flights[1]);
		printf("\n     3\t             Fri       6:00 PM");
		if(flights[2]==15)
			printf("     FULL");
		else
			printf("     %d", 15-flights[2]);
}// end schedule()

// Begin getFlight()
int getFlight(int f) // Get user flight input
{
	bool validate = false;
	while(validate == false)
	{
		printf("\n\nChoose a flight: ");
		scanf("%d%c", &f);
		if((f>0) && (f<4))
		{
			printf("You selected flight %d\n", f);
			validate = true;
		}
		else
		{
			printf("Please enter a valid flight number (1-3)");
			validate = false;
		}
	}
	return f;
} // end getFlight()

// Begin menu()
int menu(int f, int flights[]) // Menu function
{
	company();
	schedule(flights);
	f = getFlight(f);
	return f;
} // end menu()

// Begin checkFlight()
int checkFlight(int f, int flights[], int counter, int passengers[]) // validates number of passengers
{
	company(); // Print company header
	if(flights[(f-1)]<15) // flight can only hold 15 passengers
	{
		char input; // input variable to check if user would like to reserve a seat on chosen flight
		bool validate = false;
		while(validate == false)
		{
			printf("Seat %d is availible. Would you like to reserve this seat? [Y/N]\n", (flights[(f-1)])+1);
			scanf("%c%c",&input);
			if(input == 'y' || input == 'Y') // user wants to reserve flight
			{
				validate = true;
				passengers[counter] = f; // updates passengers[] which stores flight choices in order
				flights[(f-1)]++; // increases total number of passengers on chosen flight
				printf("You have reserved seat %d on Flight %d.\n", flights[(f-1)],f); // prints choice

				printf("Please choose a report style: \n\t[1] Report by Flight choice     [2] Report by Passenger number\n Report: ");
				scanf("%d%c", &input);
				switch(input)
				{
				case 1:
					printf("Flight Choice\t Passenger Number\n");
					for(int i=0;i<counter+1;i++)
					{
						if(passengers[i] == 1)
						{
							printf("Flight %d\t %d\n",1, i+1);
						}
					}
					for(int i=0;i<counter+1;i++)
					{
						if(passengers[i] == 2)
						{
							printf("Flight %d\t %d\n",2, i+1);
						}
					}
					for(int i=0;i<counter+1;i++)
					{
						if(passengers[i] == 3)
						{
							printf("Flight %d\t %d\n",3, i+1);
						}
					}
					break;
				case 2: 
					printf("Passenger Number\t Flight Choice\n");
					for(int i=0;i<counter+1;i++)
					{
						printf("%d\t\t\t Flight %d\n",i+1, passengers[i]);
					}
					break;
				// catch invalid input
				default: printf("Please enter 1 or 2 only.\n"); break;
				}
				counter++;
			}
			else if((input == 'n') || (input == 'N'))
			{
				validate = true;
			}
			else
			{
				printf("Please enter Y for Yes or N for No.\n");
				validate = false;
			}
		}
	}
	else
	{
		printf("This flight is full\n");
	}
	return counter;
} // end checkFlight()
