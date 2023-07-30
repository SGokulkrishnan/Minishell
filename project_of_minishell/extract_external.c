#include "main.h"

// Function to extract external commands from a file and store them in an array
void extract_external_commands(char **external_commands)
{
    // Variable declaration
    char ch;
    char buffer[25] = {'\0'};
    int i = 0, j = 0;

    // Open the file containing external commands
    int fd = open("external_commands.txt", O_RDONLY);

    if (fd == -1)
    {
        printf("Error opening the file.");
        exit(1);
    }

    // Read the commands from the file
    while (read(fd, &ch, 1) > 0)
    {
        if (ch != '\n')
        {
            buffer[i++] = ch;
        }
        else
        {
            // Allocate memory to store the command
            external_commands[j] = calloc(strlen(buffer) + 1, sizeof(char));

            // Copy the contents of the buffer to the array
            strcpy(external_commands[j++], buffer);

            // Reset the buffer and index for the next command
            i = 0;
            memset(buffer, '\0', 25);
        }
    }

    // Append NULL character at the end to mark the end of the array
    external_commands[j] = NULL;

    // Close the file
    close(fd);
}
