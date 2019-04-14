// Author: Emily Keener
// Test 2
// Flight company needs a program to show a menu of 3 flights, their number, day, and time.
// Each Flight holds up to 15 passengers
// Use a function to display menu and another to check if there are seats available. 

#include "stdafx.h"
#include <iostream>
using namespace System;

// Function prototypes
void printCompanyHeader();
void printUpdatedSchedule(int flights[]);
int getUserFlightInput(int userInputForFlightNumber);
int printMenuAndGetUserFlightNumberSelection(int userInputForFlightNumber, int flights[]); // Menu which includes schedule() and getFlight() calls
int checkIfFlightIsFullOrAvailable(int userSelectedFlightNumber, int flights[], int numberOfPassengersEntered, int passengers[]); // Checks if flight is full / available

// Begin Main()
int main()
{
    // Set console to black text / white background
    system("color f0");
    
    //int flights[3] = {12,15,5}; // test flights
    int flights[] = {0,0,0};
    int passengersChoicesInOrderForReport2[45];
    int userInputForFlightNumber = -1;
    bool shouldQuitMenuLoop = false;
    char userInputToQuitProgram;
    int numberOfPassengersEntered = 0;
    
    while(shouldQuitMenuLoop == false) // quit condition to end program
    {
        userInputForFlightNumber = printMenuAndGetUserFlightNumberSelection(userInputForFlightNumber, flights); // updates user input variable
        numberOfPassengersEntered = checkIfFlightIsFullOrAvailable(userInputForFlightNumber, flights, numberOfPassengersEntered, passengersChoicesInOrderForReport2); // checks if flight is available or full
        
        bool userActuallyWantsQuit = false; // validates Quit input
                                            // Quit program check
        while(userActuallyWantsQuit == false)
        {
            printf("Would you like to exit? [Y/N]\n");
            scanf("%c", &userInputToQuitProgram);
            if(userInputToQuitProgram == 'y' || userInputToQuitProgram == 'Y')
            {
                userActuallyWantsQuit = true;
                shouldQuitMenuLoop = true;
            }
            else if(userInputToQuitProgram == 'n' || userInputToQuitProgram == 'N')
            {
                userActuallyWantsQuit = true;
            }
            else{
                printf("Please enter Y for Yes or N for No.\n");
                userActuallyWantsQuit = false;
            }
        }
    }
} // end Main

// Begin printCompanyHeader()
void printCompanyHeader() // Prints Company header
{
    system("cls"); // clear screen
    printf("-----------------------------------------------------------\n");
    printf("        * F A S T   F L I G H T   A I R L I N E S * \n");
    printf("-----------------------------------------------------------\n");
} //end printCompanyHeader()

// Begin schedule()
void printUpdatedSchedule(int flights[]) // Prints updated schedule
{
    printf("                F L I G H T   S C H E D U L E\n");
    printf("-----------------------------------------------------------\n");
    printf("     N U M B E R     D A Y     T I M E     S E A T S\n"); // extra column to show seats available
    printf("     1                     Mon       6:00 AM");
    if(flights[0]==15)
        printf("     FULL");
    else
        printf("     %d", 15-flights[0]);
    printf("\n     2                     Wed      12:00 PM");
    if(flights[1]==15)
        printf("     FULL");
    else
        printf("     %d", 15-flights[1]);
    printf("\n     3                     Fri       6:00 PM");
    if(flights[2]==15)
        printf("     FULL");
    else
        printf("     %d", 15-flights[2]);
}// end schedule()

// Begin getUserFlightInput()
int getUserFlightInput(int userInputForFlightNumber) // Get user flight input
{
    bool validate = false;
    while(validate == false)
    {
        printf("\n\nChoose a flight: ");
        scanf("%d", &userInputForFlightNumber);
        if((userInputForFlightNumber>0) && (userInputForFlightNumber<4))
        {
            printf("You selected flight %d\n", userInputForFlightNumber);
            validate = true;
        }
        else
        {
            printf("Please enter a valid flight number (1-3)");
            validate = false;
        }
    }
    return userInputForFlightNumber;
} // end getFlight()

// Begin printMenuAndGetUserFlightNumberSelection()
int printMenuAndGetUserFlightNumberSelection(int userInputForFlightNumber, int flights[]) // Menu function
{
    printCompanyHeader();
    printUpdatedSchedule(flights);
    userInputForFlightNumber = getUserFlightInput(userInputForFlightNumber);
    return userInputForFlightNumber;
} // end 2printMenuAndGetUserFlightNumberSelection()

// Begin checkIfFlightIsFullOrAvailable()
int checkIfFlightIsFullOrAvailable(int userInputForFlightNumber, int flights[], int numberOfPassengersEntered, int passengers[]) // validates number of passengers
{
    printCompanyHeader();
    if(flights[(userInputForFlightNumber-1)]<15) // flight can only hold 15 passengers
    {
        char input; // input variable to check if user would like to reserve a seat on chosen flight
        bool shouldContinueTakingInput = false;
        while(shouldContinueTakingInput == false)
        {
            printf("Seat %d is availible. Would you like to reserve this seat? [Y/N]\n", (flights[(userInputForFlightNumber-1)])+1);
            scanf("%c",&input);
            if(input == 'y' || input == 'Y') // user wants to reserve flight
            {
                shouldContinueTakingInput = true;
                passengers[numberOfPassengersEntered] = userInputForFlightNumber; // updates passengers[] which stores flight choices in order
                flights[(userInputForFlightNumber-1)]++; // increases total number of passengers on chosen flight
                printf("You have reserved seat %d on Flight %d.\n", flights[(userInputForFlightNumber-1)],userInputForFlightNumber); // prints choice
                
                printf("Please choose a report style: \n\t[1] Report by Flight choice     [2] Report by Passenger number\n Report: ");
                scanf("%c", &input);
                switch(input)
                {
                    case 1:
                        printf("Flight Choice\t Passenger Number\n");
                        for(int i=0;i<numberOfPassengersEntered+1;i++)
                        {
                            if(passengers[i] == 1)
                            {
                                printf("Flight %d\t %d\n",1, i+1);
                            }
                        }
                        for(int i=0;i<numberOfPassengersEntered+1;i++)
                        {
                            if(passengers[i] == 2)
                            {
                                printf("Flight %d\t %d\n",2, i+1);
                            }
                        }
                        for(int i=0;i<numberOfPassengersEntered+1;i++)
                        {
                            if(passengers[i] == 3)
                            {
                                printf("Flight %d\t %d\n",3, i+1);
                            }
                        }
                        break;
                    case 2:
                        printf("Passenger Number\t Flight Choice\n");
                        for(int i=0;i<numberOfPassengersEntered+1;i++)
                        {
                            printf("%d\t\t\t Flight %d\n",i+1, passengers[i]);
                        }
                        break;
                        // catch invalid input
                    default: printf("Please enter 1 or 2 only.\n"); break;
                }
                numberOfPassengersEntered++;
            }
            else if((input == 'n') || (input == 'N'))
            {
                shouldContinueTakingInput = true;
            }
            else
            {
                printf("Please enter Y for Yes or N for No.\n");
                shouldContinueTakingInput = false;
            }
        }
    }
    else
    {
        printf("This flight is full\n");
    }
    return numberOfPassengersEntered;
} // end checkIfFlightIsFullOrAvailable()
