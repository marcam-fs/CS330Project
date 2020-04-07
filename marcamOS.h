/*
 Programmer Name: Maria Azam
 File Name: Monster.cpp
 
 Revision History:
    Tuesday, March 31, 2020: File created.
*/

#pragma once

#include <cstdlib>
#include <stdio.h>
#include <sys/types.h>
#include <unistd.h>
#include <string>
#include <iostream>
#include <cstring>
using namespace std;

const int MAX_ARGUMENTS = 30;

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

/*
 Function Name: tokenizeInput

 Purpose: To separate the user-input command from a string into tokens.
 Parameter(s):
    <1> command: The user-input command
    <2> input: An array of strings to later hold the tokenized command.
 Precondition: N/A
 Returns: Number of arguments (tokens) in user-input command.
 Side Effect: N/A
*/
int tokenizeInput(string input[], string command);

/*
 Function Name: processCommand

 Purpose: To decide whether to continue processing user commands or terminate the shell.
 Parameter(s):
    <1> input: The user-input command as a tokenized array of strings.
    <2> tokenCount: Number of arguments entered by user.
 Precondition: N/A
 Returns: True or false, corresponding to whether or not to continue processing user commands, respectively.
 Side Effect: N/A
*/
bool processCommand(string input[], int tokenCount);