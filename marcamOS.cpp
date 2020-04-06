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
    int i = 1;
    string command;
    bool commandEntered = 0;
    int tokenCount;

    do
    {
        //Repeatedly print shell name
        cout << "marcamOS[" << i << "]% ";

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

    //Tokenize the user-input command, storing it in the 'input' array of strings & capture the return value
    tokenCount = tokenizeInput(input, command);
    
    //Return the number of tokens in the command
    return tokenCount;
}

bool checkForCommand(string command)
{
    if (command.length() > 0)
        return true;

    return false;
}

//This function adopts the same structure as TokenizeCommandLine in HALmod.cpp (provided in CS 330 Lab 3)
int tokenizeInput(string input[], string command)
{
    char * token[MAX_ARGUMENTS];
    char * workCommand = new char[command.length() + 1];
    int tokenCount;

    //Initialize input array to empty strings
    for (int i = 0; i < MAX_ARGUMENTS; i++)
    {
        input[i] = "";
    }

    //Copy the user-input command into the cstring workCommand
    strcpy(workCommand, command.c_str());

    //Convert user-input command from string to tokens, using space as the delimeter character
    int i = 0;
    if ((token[i] = strtok(workCommand, " ")) != NULL)
    {
        i++;

        while ((token[i] = strtok(NULL, " ")) != NULL)
            i++;
    }
    tokenCount = i;

    //Initialize each element of the 'input' array to a single token from the user-input command
    for (int i = 0; i < tokenCount; i++)
    {
        input[i] = token[i];
    }

    //Delete the dynamically allocated workCommand pointer
    delete [] workCommand;

    //Return number of tokens in user-input command
    return tokenCount;
}