# CS330Project
CS 330 - Operating Systems: Project

NAME 
Maria Azam

STUDENT NUMBER
200402217

TOPIC
Description: A simple emulation of a shell, featuring the use of a pipe to write to a file; this improves user experience,
    because files can be written to simply by typing in the terminal, instead of using the echo command and ">" characters.

Challenges:
    Sunday, April 05, 2020: Previously, I had my code for receiving user commands and checking if they were valid commands in 
        main.cpp. This was done to make sure the base of the program was running properly. Today, I separated this code between 
        main.cpp and marcamOS.cpp. I am able to compile both files, but am encountering a "duplicate symbol" error when linking 
        them. I realized this was due to a simple mistake in my '#include' statements.

    Friday, April 10, 2020: I am implementing the 'writeToFile' function today and am having trouble with pipe redirection. I am
        trying to write from standard input to a file.

        Writing to a file via a pipe now works. However, writing to a file that has already been written to wipes the previously
        written contents. Need to find a way to point to the last line of the file. Solved using an if-else statement and
        specifying permissions in open() system call.

REPRODUCTION
In order to reproduce the project, please do the following:
    - Download the following files into a single directory
        main.cpp
        marcamOS.h
        marcamOS.cpp.
    - Once done, open a terminal and change into this directory. 
    - Compile the C++ files
        g++ -c main.cpp
        g++ -c marcamOS.cpp
    - Link the files and create an object file
        g++ main.cpp marcamOS.cpp -o marcamOS
    - Run the program and execute any regular command
        ./marcamOS
    - If at any point you need help, enter "help"
    - To exit the program, type "logout", "restart", or "shutdown".
