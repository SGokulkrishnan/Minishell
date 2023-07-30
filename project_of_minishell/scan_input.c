#include "main.h"

pid_t pid;

// Function to scan user input and execute commands
void scan_input(char *prompt, char *input_string)
{   
    char *command = "\0";
    int command_type, status;

    while (1)
    {  
        // Clear the memory for the input string
        memset(input_string, '\0', 25);

        // Display the prompt
        printf(ANSI_COLOUR_GREEN "[%s]$ " ANSI_COLOUR_RESET, prompt);

        // Clear the output buffer
        fflush(stdout);

        // Read the input from the user until a newline character is encountered
        scanf("%[^\n]s", input_string);

        // Clear the input buffer
        getchar();
        
        // Check if the command is to customize the prompt (PS1=...)
        if (!strncmp("PS1=", input_string, 4))
        {
            // Customize the prompt if a valid value is provided after "PS1="
            if (input_string[4] != ' ')
            {
                strcpy(prompt, &input_string[4]);

                // Clear the input string and continue to the next iteration of the loop
                memset(input_string, '\0', 25);
                continue;
            }
            printf("%s: command not found\n", &input_string[5]);
        }
        
        // Get the first command from the input string
        command = get_command(input_string);

        // Extract the type of command (external, internal, or special variables)
        command_type = check_command_type(command);

        // If the command is an external command
        if (command_type == EXTERNAL)
        {            
            // Create a child process
            pid = fork();

            if (pid == -1)
            {
                perror("fork ");
                exit(1);
            }
            else if (pid == 0) // Child process
            {
                // Execute the external command using the system() function
                int ret_status = system(input_string);

                // Exit the child process with the appropriate exit status
                if (ret_status == 0)
                {
                    exit(0);
                }
                else
                {
                    exit(1);
                }
            }
            else
            {
                // Parent process
                // Wait for the child process to complete
                wait(&status);
                
                // Display the termination status of the child process
                if (WIFEXITED(status))
                    printf("Child with PID: %d terminated normally with exit status %d\n", pid, WIFEXITED(status));
                else
                    printf("Child with PID: %d terminated abnormally\n", pid);
            }
        }
        else if (command_type == SPECIAL_VARIABLES)
        {
            // Execute the echo function to handle special variables
            echo(input_string, status);
        }
        else
        {
            // Command not found (neither external nor special variables)
            printf("%s: command not found\n", input_string);
        }

        // Clear the input string before processing the next iteration
        memset(input_string, '\0', 25);

        // Execute internal commands (e.g., cd, exit, pwd)
        execute_internal_command(input_string);
    }
}
