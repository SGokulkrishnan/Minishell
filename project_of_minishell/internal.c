#include "main.h"

// Function to execute internal commands
void execute_internal_command(char *input_string)
{
    // Check if the command is "cd" (change the directory)
    if (strncmp("cd", input_string, 2) == 0)
    {
        // Implement the cd command with multiple spaces
        int i, count = 0;
        for (i = 2; input_string[i] == ' '; i++)
        {
            count++;
        }
        chdir(&input_string[2 + count]);
    }    

    // Check if the command is "exit" (terminate the program)
    else if (strncmp("exit", input_string, 4) == 0)
    {
        exit(0);
    }

    // Check if the command is "pwd" (print the current location)
    else if (strncmp("pwd", input_string, 3) == 0)
    {
        system("pwd");
    }   
}
