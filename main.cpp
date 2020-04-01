/*
 Programmer Name: Maria Azam
 Student Number: 200402217
 Course Number: CS 330

 File Name: main.cpp
 Purpose: 

 Revision History: This file was created on Tuesday, March 31, 2020.
 */

//#include "marcamOS.cpp"
#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

bool checkForCommand(string command)
{
    if (command.length() > 0)
        return true;

    return false;
}

int i = 0;

int main()
{
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
    } while (command.length() == 0);

    return 0;
}