// Author: Emily Keener
// Test 2
// Flight company needs a program to show a menu of 3 flights, their number, day, and time.
// Each Flight holds up to 15 passengers
// Use a function to display menu and another to check if there are seats available. 

#include "stdafx.h"
#include <iostream>
using namespace System;


/// Each flight can only hold 15 passengers
static const int flightMaxPassengerCount = 15;
/// The smallest valid flight number
static const int minFlightNumber = 1;
/// The largest valid flight number
static const int maxFlightNumber = 3;



struct OneUserInputForEnteringPassengers {
    int numberOfPassengersEntered;
    bool shouldContinueTakingUserInput;
};
typedef OneUserInputForEnteringPassengers OneUserInputForEnteringPassengers;



// Function prototypes
void printCompanyHeader();
void printUpdatedSchedule(const int flights[]);

int getUserFlightInput(const int userInputForFlightNumber);
const int getFlightNumberFromUser();
bool isFlightNumberValid(const int flightNumber);
int printMenuAndGetUserFlightNumberSelection(const int userInputForFlightNumber, const int flights[]); // Menu which includes schedule() and getFlight() calls
int checkIfFlightIsFullOrAvailable(const int userSelectedFlightNumber, const int flights[], const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]); // Checks if flight is full / available

const int takeAllUserInputForEnteringPassengers(const int userInputForFlightNumber, int inoutFlights[], const int numberOfPassengersEnteredSoFar, int inoutAllUserInputsForFlightNumbers[]);
const OneUserInputForEnteringPassengers takeOneUserInputForEnteringPassengers(const int userInputForFlightNumber, int inoutFlights[], const int numberOfPassengersEnteredSoFar, int inoutAllUserInputsForFlightNumbers[]);

char askUserForChosenAvailableSeat(const int seatNumber);
char askUserForChosenReportType(const int seatNumber, const int flightNumber);
void printReportBasedOnUserChoice(const int userReportChoice, const int numberOfPassengersEnteredSoFar, const int allUserInputsForFlightNumbers[]);

void printReportByFlightChoice(const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]);
void printReportByOneFlightChoice(const int flightNumber, const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]);
void conditionallyPrintOnePassengerForReportByFlightChoice(const int flightNumber, const int passengerNumber, const int userInputForFlightNumber, const int targetUserInput);
void printOnePassengerForReportByFlightChoice(const int flightNumber, const int passengerNumber);

void printReportByPassengerNumber(const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]);
void printOneFlightForReportByPassengerNumber(const int passengerNumber, const int userChosenFlightNumber);

void quit();
bool userInputIndicatesYes(const char input);
bool userInputIndicatesNo(const char input);



// Begin Main()
int main()
{
    // Set console to black text / white background
    system("color f0");
    
    //int flights[3] = {12,15,5}; // test flights
    int flights[] = {0,0,0};
    int passengersChoicesInOrderForReport2[45];
    bzero(&passengersChoicesInOrderForReport2, sizeof(passengersChoicesInOrderForReport2));
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
            if (userInputIndicatesYes(userInputToQuitProgram))
            {
                userActuallyWantsQuit = true;
                shouldQuitMenuLoop = true;
            }
            else if (userInputIndicatesNo(userInputToQuitProgram))
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
void printUpdatedSchedule(const int flights[]) // Prints updated schedule
{
    printf("                F L I G H T   S C H E D U L E\n");
    printf("-----------------------------------------------------------\n");
    printf("     N U M B E R     D A Y     T I M E     S E A T S\n"); // extra column to show seats available
    printf("     1                     Mon       6:00 AM");
    if(flights[0]==15) {
        printf("     FULL");
    }
    else {
        printf("     %d", 15-flights[0]);
    }
    printf("\n     2                     Wed      12:00 PM");
    if(flights[1]==15) {
        printf("     FULL");
    }
    else {
        printf("     %d", 15-flights[1]);
    }
    printf("\n     3                     Fri       6:00 PM");
    if(flights[2]==15) {
        printf("     FULL");
    }
    else {
        printf("     %d", 15-flights[2]);
    }
}// end schedule()


// Begin getUserFlightInput()
int getUserFlightInput(const int userInputForFlightNumber) // Get user flight input
{
    bool validate = false;
    while(validate == false)
    {
        const int userInputForFlightNumber = getFlightNumberFromUser();
        if(isFlightNumberValid(userInputForFlightNumber))
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


bool isFlightNumberValid(const int flightNumber) {
    return (flightNumber >= minFlightNumber)
        && (flightNumber <= maxFlightNumber);
}


const int getFlightNumberFromUser() {
    int userInputForFlightNumber = -1;
    printf("\n\nChoose a flight: ");
    scanf("%d", &userInputForFlightNumber);
    return userInputForFlightNumber;
}


// Begin printMenuAndGetUserFlightNumberSelection()
int printMenuAndGetUserFlightNumberSelection(const int userInputForFlightNumber, const int flights[]) // Menu function
{
    printCompanyHeader();
    printUpdatedSchedule(flights);
    return getUserFlightInput(userInputForFlightNumber);
} // end 2printMenuAndGetUserFlightNumberSelection()


// Begin checkIfFlightIsFullOrAvailable()
int checkIfFlightIsFullOrAvailable(const int userInputForFlightNumber, int inoutFlights[], const int numberOfPassengersEnteredSoFar, int inoutAllUserInputsForFlightNumbers[]) // validates number of passengers
{
    printCompanyHeader();
    if(inoutFlights[(userInputForFlightNumber-1)] < flightMaxPassengerCount)
    {
        return takeAllUserInputForEnteringPassengers(userInputForFlightNumber, inoutFlights, numberOfPassengersEnteredSoFar, inoutAllUserInputsForFlightNumbers);
    }
    else
    {
        printf("This flight is full\n");
        return numberOfPassengersEnteredSoFar;
    }
} // end checkIfFlightIsFullOrAvailable()


const int takeAllUserInputForEnteringPassengers(const int userInputForFlightNumber, int inoutFlights[], const int numberOfPassengersEnteredSoFar, int inoutAllUserInputsForFlightNumbers[]) {
    OneUserInputForEnteringPassengers runningResult = {
        numberOfPassengersEnteredSoFar,
        false
    };
    
    while(runningResult.shouldContinueTakingUserInput == false)
    {
        runningResult = takeOneUserInputForEnteringPassengers(userInputForFlightNumber, inoutFlights, numberOfPassengersEnteredSoFar, inoutAllUserInputsForFlightNumbers);
    }
    
    return runningResult.numberOfPassengersEntered;
}


const OneUserInputForEnteringPassengers takeOneUserInputForEnteringPassengers(const int userInputForFlightNumber, int inoutFlights[], const int numberOfPassengersEnteredSoFar, int inoutAllUserInputsForFlightNumbers[]) {
    OneUserInputForEnteringPassengers result = {
        numberOfPassengersEnteredSoFar,
        false
    };
    
    char userInput = askUserForChosenAvailableSeat((inoutFlights[(userInputForFlightNumber-1)])+1);
    
    if (userInputIndicatesYes(userInput)) // user wants to reserve flight
    {
        result.shouldContinueTakingUserInput = true;
        inoutAllUserInputsForFlightNumbers[result.numberOfPassengersEntered] = userInputForFlightNumber; // updates passengers[] which stores flight choices in order
        const int newSeatNumber = ++inoutFlights[(userInputForFlightNumber-1)]; // increases total number of passengers on chosen flight
        userInput = askUserForChosenReportType(newSeatNumber, userInputForFlightNumber);
        printReportBasedOnUserChoice(userInput, result.numberOfPassengersEntered, inoutAllUserInputsForFlightNumbers);
        result.numberOfPassengersEntered++;
    }
    else if (userInputIndicatesNo(userInput))
    {
        result.shouldContinueTakingUserInput = true;
    }
    else
    {
        printf("Please enter Y for Yes or N for No.\n");
        result.shouldContinueTakingUserInput = false;
    }
    
    return result;
}


char askUserForChosenAvailableSeat(const int seatNumber) {
    char input = 0;
    printf("Seat %d is availible. Would you like to reserve this seat? [Y/N]\n", seatNumber);
    const int numberOfInputsScanned = scanf("%c", &input);
    if (EOF == numberOfInputsScanned) {
        // User chose to input nothing, usually meaning they are done using our program
        quit();
    }
    return input;
}



// MARK: - Reports

char askUserForChosenReportType(const int seatNumber, const int flightNumber) {
    char input = 0;
    printf("You have reserved seat %d on Flight %d.\n", seatNumber, flightNumber);
    
    printf("Please choose a report style: \n\t[1] Report by Flight choice     [2] Report by Passenger number\n Report: ");
    const int numberOfInputsScanned = scanf("%c", &input);
    if (EOF == numberOfInputsScanned) {
        // User chose to input nothing, usually meaning they are done using our program
        quit();
    }
    return input;
}


void printReportBasedOnUserChoice(const int userReportChoice, const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]) {
    switch(userReportChoice)
    {
        case 1:
            printReportByFlightChoice(numberOfPassengersEntered, allUserInputsForFlightNumbers);
            break;
            
        case 2:
            printReportByPassengerNumber(numberOfPassengersEntered, allUserInputsForFlightNumbers);
            break;
            
        default:
            // catch invalid input
            printf("Please enter 1 or 2 only.\n");
            break;
    }
}


// MARK: Report by Flight Choice

void printReportByFlightChoice(const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]) {
    printf("Flight Choice\t Passenger Number\n");
    printReportByOneFlightChoice(1, numberOfPassengersEntered, allUserInputsForFlightNumbers);
    printReportByOneFlightChoice(2, numberOfPassengersEntered, allUserInputsForFlightNumbers);
    printReportByOneFlightChoice(3, numberOfPassengersEntered, allUserInputsForFlightNumbers);
}


void printReportByOneFlightChoice(const int flightNumber, const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]) {
    for(int eachPassenger = 0;
        eachPassenger < numberOfPassengersEntered + 1;
        eachPassenger++) {
        conditionallyPrintOnePassengerForReportByFlightChoice(flightNumber, eachPassenger+1, allUserInputsForFlightNumbers[eachPassenger], flightNumber);
    }
}


void conditionallyPrintOnePassengerForReportByFlightChoice(const int flightNumber, const int passengerNumber, const int allUserInputsForFlightNumbers, const int targetUserInput) {
    if (allUserInputsForFlightNumbers == targetUserInput) {
        printOnePassengerForReportByFlightChoice(flightNumber, passengerNumber);
    }
}


void printOnePassengerForReportByFlightChoice(const int flightNumber, const int passengerNumber) {
    printf("Flight %d\t %d\n", flightNumber, passengerNumber);
}


// MARK: Report by passenger number

void printReportByPassengerNumber(const int numberOfPassengersEntered, const int allUserInputsForFlightNumbers[]) {
    printf("Passenger Number\t Flight Choice\n");
    for(int eachPassenger = 0;
        eachPassenger < numberOfPassengersEntered + 1;
        eachPassenger++) {
        printOneFlightForReportByPassengerNumber(eachPassenger+1, allUserInputsForFlightNumbers[eachPassenger]);
    }
}


void printOneFlightForReportByPassengerNumber(const int passengerNumber, const int userChosenFlightNumber) {
    printf("%d\t\t\t Flight %d\n", passengerNumber, userChosenFlightNumber);
}



// MARK: - General utilities

void quit() {
    exit(0);
}


bool isUserInputEqualIgnoringCase(const char expectedInput, const char actualInput) {
    return tolower(expectedInput) == tolower(actualInput);
}


bool userInputIndicatesYes(const char input) {
    return isUserInputEqualIgnoringCase('y', input);
}


bool userInputIndicatesNo(const char input) {
    return isUserInputEqualIgnoringCase('n', input);
}
