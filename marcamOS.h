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
#include <errno.h>
#include <sys/wait.h>
//#include <fstream>
#include <sys/stat.h>
#include <fcntl.h>
using namespace std;

const int MAX_ARGUMENTS = 30;

/*
 Function Name: getCommand

 Purpose: To receive a user-input command from the keyboard.
 Parameter(s):
    <1> input: The user-input command.
    <2> i: An integer keeping track of how many commands the user has entered.
 Precondition: N/A
 Returns: Number of arguments in user-input command.
 Side Effect: N/A
*/
int getCommand(string input[], int &i);

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
 Precondition: 'input' must be intialized
 Returns: True or false, corresponding to whether or not to continue processing user commands, respectively.
 Side Effect: N/A
*/
bool processCommand(string input[], int tokenCount);

/*
 Function Name: processCommand

 Purpose: To conver the user-input command into a cString so that it can be used in an execvp() sys call.
 Parameter(s):
    <1> input: The user-input command as a tokenized array of strings.
    <2> tokenCount: Number of arguments entered by user.
 Precondition: 'input' must be initialized
 Returns: cString of all arguments in the user-input command.
 Side Effect: N/A
*/
char ** convertToCString(string input[], int tokenCount);

/*
 Function Name: writeToFile

 Purpose: To write to a file using sockets.
 Parameter(s):
    <1> argv: The user-input command as a cString
    <2> tokenCount: Number of arguments entered by user.
 Precondition: 'input' must be initialized & 'argv' must be initialized. 'argv[0]' must be "write"
 Returns: N/A
 Side Effect: N/A
 */
void writeToFile(char ** argv, int tokenCount);