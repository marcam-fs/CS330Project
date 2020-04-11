/*
 Programmer Name: Maria Azam
 File Name: marcamOS.cpp
 
 Purpose:

 Revision History:
    Monday, March 23, 2020: File created.
*/

#include "marcamOS.h"

//Declare i, the command count, as a global variable
int getCommand(string input[], int &i)
{
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

bool processCommand(string input[], int tokenCount)
{
    //If the user wishes to terminate the shell,
    if (input[0] == "shutdown" || input[0] == "restart" || input[0] == "logout")
    {
        //If user enters an argument along w/ the termination command, print a message & return true to continue processing commands
        if (tokenCount > 1)
        {
            cout << "This command requires no arguments" << endl;
            return true;
        }
        
        //Otherwise, print a termination message & return false
        cout << endl << "marcamOS shell terminating..." << endl;
        return false;
    }
    //If no termination command was entered, return true to continue processing commands
    else
    {
        //Fork to create a child and parent
        pid_t forkReturn = fork();
        int status;

        //Child process
        if (forkReturn == 0)
        {
            //Capture cString in a char** variable
            char ** argv;
            argv = convertToCString(input, tokenCount);

            //If the user issues a write command
            if (!strcmp(argv[0], "writefile"))
            {
                //If 1 file has not been specified, print error message
                if (tokenCount == 1 || tokenCount > 2)
                    cout << "Please specify a single file to be written to." << endl;
                //Othwerwise, write to the file
                else
                    writeToFile(argv, tokenCount);
                
            }
            //Otherwise, execute user-input command using execvp()
            else
            {
                execvp(argv[0], argv);

                //If error occurs, print message
                perror("Execvp() Error");
            }
            //Exit child process
            exit(1);
        }
        //Parent process
        else if (forkReturn > 0)
        {
            //Wait for child
            wait(&status);
        }
        //Error case
        else
        {
            perror("Fork Error");
            exit(1);
        }
        
        return true;
    }
}

char ** convertToCString(string input[], int tokenCount)
{
    //Declare an argument vector to be used w/ execvp
    char ** words;
    words = (char **)malloc(sizeof(char *) * (tokenCount + 1));

    //Duplicate each element in 'input' & store in new argument vector
    for (int i = 0; i < tokenCount; i++)
        words[i] = strdup(input[i].c_str());

    //Initialize last word to NULL
    words[tokenCount] = NULL;

    return words;
}

void writeToFile(char ** argv, int tokenCount)
{
    int outFile;
    string filename = argv[1];
    string input;

    if (filename.find(".") == string::npos)
    {
        cout << "Please specify a proper file extension." << endl;
        exit(1);
    }

    //Create a pipe
    int fdes[2];
    if (pipe(fdes) == -1)
    {
        perror("Pipe Error");
        exit(2);
    }
  
    pid_t forkReturn = fork();
    int status;
    
    //Error case
    if (forkReturn == -1)
    {
        perror("Fork Error");
        exit(3);
    }
    //Child process
    else if (forkReturn == 0)
    {
        //Close write end of pipe
        close(fdes[1]);

        //Open or create file to write to
        outFile = open(filename.c_str(), O_WRONLY | O_CREAT, S_IRUSR | S_IWUSR);

        //Display instructions
        cout << "Write to the file. Once done, type 'STOP'." << endl;

        //Redirect standard output to be written to the file
        dup2(outFile, fileno(stdout));
        close(fdes[0]);
        close(fdes[1]);

        //Continue reading user input & writing to file, until user enters 'STOP'
        while (getline(cin, input))
        {
            if (input == "STOP")
                exit(4);
            cout << input << endl;
        }
    }
    //Parent process
    else
    {
        //Wait for child
        wait(&status);
    }
    
}