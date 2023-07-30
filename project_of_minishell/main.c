#include "main.h"

// Global variable to store the process ID (PID)
int pid = -1;

// Signal handler function
void sig_handler(int signum)
{
    if (pid > 0)
        printf("\nGot signal %d\n", signum);
    exit(1);
}

int main()
{
    // Register signal handlers for SIGINT (Ctrl+C) and SIGTSTP (Ctrl+Z)
    signal(SIGINT, sig_handler);
    signal(SIGTSTP, sig_handler);

    // Clear the screen
    system("clear");

    // Variable declaration
    // Array to store the user input
    char input_string[25];

    // Array to store the prompt
    char prompt[25] = "minishell@gokul";

    // Scan the input from the user
    scan_input(prompt, input_string);

    return 0;
}
