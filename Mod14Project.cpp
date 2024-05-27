/*Author: Francisco Bumanglag
Project: Charge Account Validation
Assignment: Module 14 Project 11
Course: C++ Santa Ana College
Class: CMPR120 Dr. Tahir Aziz
Date: May 22, 2024*/


#include <iostream>     //input-output stream header
#include <string>       //string manipulation header
#include <algorithm>    //algorithms header for operations on ranges
#include <conio.h>      //console input/output header (non-standard)
#include <cstdlib>      //standard library definitions header
using namespace std;

//function declarations
void displayArray(int[], int);          //dispaly array with length
void changeValue(int[], int);           //change value in array
void searchRecords(int[], int, int);    //search records in array
void bubbleSort(int[], int);            //sorty array using bubblesort
bool validateAccount(int[], int, int);  //validate account number in array

int main()
{
    const int size = 18;  //size constant with value 18
    //array of account numbers initialized
    int accountNumbers[size] = { 5658845, 4520125, 7895122, 8777541, 8451277, 1302850,
                                8080152, 4562555, 5552012, 5050552, 7825877, 1250255,
                                1005231, 6545231, 3852085, 7576651, 7881200, 4581002 };
    int selection = 0;  //selection variable initialized to zero

    while (true) 
    {
        system("cls");  //clears console screen
        //display main menu options
        cout << "\t\t\tMAIN MENU" << endl;
        cout << "\t\t\t================" << endl;
        cout << endl;
        cout << "\t\t\t1. DISPLAY AN ARRAY" << endl;
        cout << "\t\t\t2. VALIDATE A CHARGE ACCOUNT NUMBER" << endl;
        cout << "\t\t\t3. SEARCH AN ARRAY" << endl;
        cout << "\t\t\t4. SORT AN ARRAY" << endl;
        cout << "\t\t\t5. QUIT. CLOSE PROGRAM" << endl;

        cout << "\n\n\t\t\t Please choose your selection: ";
        cin >> selection;

        if (selection == 1)  //display array for selection #1
        {
            displayArray(accountNumbers, size);
        }
        else if (selection == 2) // display array for selection #2
        {
            //validates if the account number entered is valid or invalid 
            int input;
            cout << "Enter the charge account number to validate: ";
            cin >> input;
            if (validateAccount(accountNumbers, size, input))
            {
                cout << "The number is valid." << endl;
            }
            else
            {
                cout << "The number is invalid." << endl;
            }
        }
        else if (selection == 3)  // display array for selection #3
        {
            //prompts user for account numbers, searches
            int searchNum;
            cout << "Enter the account number to search : ";
            cin >> searchNum;
            searchRecords(accountNumbers, size, searchNum);
        }
        else if (selection == 4)  // display array for selection #3
        {
            bubbleSort(accountNumbers, size);  //sorts array using bubble sort
        }
        else
        {
            exit(1);  //exit the program
        }
    }
    return 0;  //program exits 
}

//function --clears screen, displays array elements, waits for user input
void displayArray(int arr[], int size)
{
    system("cls");
    cout << "Array Elements:" << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << "\n\n\nPress any Key to continue...";
    _getch();
}

//function--clears screen, prompts for new values, updates, waits
void changeValue(int arr[], int size)
{
    system("cls");
    cout << endl << "In the changeValue function. " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << "Enter ID : ";
        cin >> arr[i];
    }
    cout << "Values were updated" << endl;
    cout << "\n\n\nPress any Key to Continue....";
    _getch();
}
//function--searches array for specified number, displays result, waits
void searchRecords(int arr[], int size, int searchNum)
{
    bool found = false;
    for (int i = 0; i < size; i++)
    {
        if (arr[i] == searchNum)
        {
            cout << "Number found at index: " << i << endl;
            found = true;
            break;
        }
    }
    if (!found)
    {
        cout << "Number not found in the array." << endl;
    }
    cout << "\n\n\nPress any key to continue...";
    _getch();
}

//function--clears screen, displays unsorted array, sorts, displays sorted, waits
void bubbleSort(int arr[], int size)
{
    system("cls");
    cout << "Unsorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    sort(arr, arr + size);

    cout << "Sorted array: " << endl;
    for (int i = 0; i < size; i++)
    {
        cout << arr[i] << " ";
    }
    cout << endl;
    cout << "\n\n\nPress any key to continue...";
    _getch();
}

//function--checks if account number exists in array
bool validateAccount(int arr[], int size, int number)
{
    for (int i = 0; i < size; ++i)
    {
        if (arr[i] == number)
        {
            return true;
        }
    }
    return false;

}
