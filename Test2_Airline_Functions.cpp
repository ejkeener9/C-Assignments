// Author: Emily Keener
// Work in Progress!
// Test 2
// Flight company needs a program to show a menu of 3 flights, their number, day, and time.
// Use a function to display menu and another to check if there are seats available. 

#include "stdafx.h"
#include <iostream>

using namespace System;

// Function prototypes
void company();
void schedule(int flights[]);
int getFlight(int f);
int menu(int f, int flights[]);
void checkFlight(int f, int flights[], int counter, int passengers[], int r);

int main()
{
	// Set console to black text / white background
    system("color f0");

	// int flights[3] = {12,15,5}; // test flights
	int flights[3] = {0,0,0};
	int passengers[30];
	int f, r; // user input for flight # and report type
	bool quit = false; // quits menu loop
	char exit; // user input to quit program
	int counter = 0; // number of passengers entered

	//checkFlight(menu());
	while(quit == false)
	{
		f = menu(f, flights);
		checkFlight(f, flights, counter, passengers,r);
		printf("Would you like to exit? [Y/N]\n");
		scanf("%c%c", &exit);
		if(exit == 'y' || exit == 'Y')
		{
			quit = true;
		}
	}
	//system("pause");
}

void company()
{
	system("cls"); // clear screen
	printf("-----------------------------------------------------------\n");
	printf("\t* F A S T   F L I G H T   A I R L I N E S * \n");
	printf("-----------------------------------------------------------\n");
}

void schedule(int flights[])
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
}

int getFlight(int f)
{
	printf("\n\n\tChoose a flight: ");
	scanf("%d%c", &f);
	printf("You selected flight %d\n", f);
	return f;
}

int menu(int f, int flights[])
{
	company();
	schedule(flights);
	f = getFlight(f);
	return f;
}


void checkFlight(int f, int flights[], int counter, int passengers[], int r)
{
	company();
	if(flights[(f-1)]<15)
	{
		char reserve;
		printf("Seat %d is availible. Would you like to reserve this seat? [Y/N]\n", (flights[(f-1)])+1);
		scanf("%c%c",&reserve);
		if(reserve == 'y' || reserve == 'Y')
		{
			passengers[counter] = f;
			flights[(f-1)]++;
			printf("You have reserved seat %d on Flight %d.\n", flights[(f-1)],f);
			printf("Please choose a report style: \n\t[1] Report by Flight choice     [2] Report by Passenger number\n Report: ");
			scanf("%d%c", &r);
			switch(r)
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
			}
			counter++;
		}
	}
	else
	{
		printf("This flight is full\n");
	}
	return;
}
