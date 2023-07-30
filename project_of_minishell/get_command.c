#include "main.h"

// Function to extract the command until a space or new line is encountered
char *get_command(char *input_string)
{    
    // Static variable declaration to store the command extracted
    static char command[25] = {'\0'};
    int i = 0;

    // Loop through the input string
    while (1)
    {
        // Break the loop if a space or the end of the input string is encountered
        if (*input_string == ' ' || *input_string == '\0')
        {
            break;
        }

        // Store the character in the command buffer and move to the next character
        command[i++] = *input_string;
        input_string++;
    }

    // Append NULL character at the end to terminate the command string
    command[i] = '\0';

    // Return the extracted command
    return command;
}
