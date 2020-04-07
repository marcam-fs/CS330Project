/*
 Programmer Name: Maria Azam
 Student Number: 200402217
 Course Number: CS 330

 File Name: main.cpp
 Purpose: 

 Revision History: This file was created on Tuesday, March 31, 2020.
 */

#include "marcamOS.h"

int main()
{
    cout << "Welcome to marcamOS, a commmand line operating system!" << endl;

    char ** cInput;
    string input[MAX_ARGUMENTS];
    int argCount;
    int i = 1;

    do 
    {
        argCount = getCommand(input, i);
    } while (processCommand(input, argCount));

    return 0;
}