#include "main.h"

// Function to process the "echo" command with special variables
void echo(char *input_string, int status)
{
    char *ptr;
    ptr = strtok(input_string, " ");

    // Loop through each token in the input string
    while (ptr != NULL)
    {
        if (ptr == NULL)
        {
            break;
        }
        else if (strcmp(ptr, "$?") == 0)
        {
            // Print the exit status of the last executed command
            printf("%d\n", status);
        }
        else if (strcmp(ptr, "$$") == 0)
        {
            // Print the current process ID (PID)
            printf("%d\n", getpid());
        }
        else if (strcmp(ptr, "$SHELL") == 0)
        {
            // Print the current working directory using the "pwd" command
            system("pwd");
        }

        // Get the next token
        ptr = strtok(NULL, " ");
    }
}
