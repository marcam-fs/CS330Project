/*
 Programmer Name: Maria Azam
 Student Number: 200402217
 Course Number: CS 330

 File Name: main.cpp
 Purpose: 

 Revision History: This file was created on Tuesday, March 31, 2020.
 */

#include "marcamOS.cpp"

const int MAX_ARGUMENTS = 30;
int main()
{
    cout << "Welcome to marcamOS, a commmand line operating system!" << endl;

    char ** cInput;
    string input[MAX_ARGUMENTS];
    int numOfArg;

    numOfArg = getCommand(input);

    /*int i = 0;

    //Welcome user to this OS
    printf("Welcome to marcamOS, a command line operating system!\n");

    string command;
    bool commandEntered = 0;

    do
    {
        //Repeatedly print shell name
       cout << "[marcamOS]%" << i << "  ";

        //Receive user input
        getline(cin, command);

        //Check if this is a command
        commandEntered = checkForCommand(command);

        //If a command was entered, break (stop receiving input)
        if (commandEntered)
        {
            i++;
            break;
        }
    } while (command.length() == 0);*/

    return 0;
}