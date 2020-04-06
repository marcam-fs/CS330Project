/*
 Programmer Name: Maria Azam
 File Name: marcamOS.cpp
 
 Purpose:

 Revision History:
    Monday, March 23, 2020: File created.
*/

#include "marcamOS.h"

//Declare i, the command count, as a global variable
int getCommand(string input[])
{
    int i = 0;
    
    string command;
    bool commandEntered = 0;

    do
    {
        //Repeatedly print shell name
        cout << "[marcamOS]%" << i;

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
    } while (command.length() == 0);

    return command.length();
    
}

bool checkForCommand(string command)
{
    if (command.length() > 0)
        return true;

    return false;
}