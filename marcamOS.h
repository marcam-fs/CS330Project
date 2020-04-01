/*
 Programmer Name: Maria Azam
 File Name: Monster.cpp
 
 Revision History:
    Tuesday, March 31, 2020: File created.
*/

#pragma once

#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>

/*
 Function Name: getCommand

 Purpose: To receive a user-input command from the keyboard.
 Parameter(s):
    <1> input: The user-input command.
 Precondition: N/A
 Returns: Number of arguments in user-input command.
 Side Effect: N/A
*/
int getCommand(string input[]);

/*
 Function Name: checkForCommand

 Purpose: To check whether the user has entered a command.
 Parameter(s):
    <1> command: The user-input command
 Precondition: N/A
 Returns: True or false
 Side Effect: N/A
*/
bool checkForCommand(string command);