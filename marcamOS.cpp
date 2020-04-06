/*
 Programmer Name: Maria Azam
 File Name: marcamOS.cpp
 
 Purpose:

 Revision History:
    Monday, March 23, 2020: File created.
*/

#include "marcamOS.h"

//Declare i, the command count, as a global variable
int i = 0;

int getCommand(string input[])
{
    string command;
    bool commandEntered = 0;

    do
    {
        //Repeatedly print shell name
        printf("[marcamOS]%%i   ", i);

        //Receive user input
        getline(cin, command);

        //Check if this is a command
        commandEntered = checkForCommand(command);

        //If a command was entered, break (stop receiving input)
        if (commandEntered)
            break;
    } while (command.length == 0);
    
}

bool checkForCommand(string command)
{
    if (command.length() > 0)
        return true;

    return false;
}