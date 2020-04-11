/*
 Programmer Name: Maria Azam

 File Name: main.cpp
 Created: Tuesday, March 31, 2020.
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