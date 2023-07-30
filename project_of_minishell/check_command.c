#include "main.h"

// Function to determine the type of command: internal, external, or no command
int check_command_type(char *command)
{

    // Array to store the list of external commands
    char *external_commands[155] = {NULL};

    // List of built-in commands
    char *builtins[] = {"echo", "printf", "read", "cd", "pwd", "pushd", "popd", "dirs", "let", "eval", "set", "unset", "export", "declare", "typecast", "readonly", "getopts", "source", "exit", "exec", "shopt", "caller", "true", "type", "hash", "bind", "help", NULL};

    // Check if the command is "echo" (special case for handling variables)
    if (!strcmp(command, "echo"))
    {
        return SPECIAL_VARIABLES;
    }

    // Check if the command is an ENTER key
    if (strcmp(command, "\0") == 0)
    {
        return ENTER;
    }

    // Check if the command is a built-in command
    for (int i = 0; builtins[i] != NULL; i++)
    {
        if (strcmp(command, builtins[i]) == 0)
        {
            return BUILDIN;
        }
    }

    // Extract the list of external commands
    extract_external_commands(external_commands);

    // Check if the command is an external command
    for (int i = 0; external_commands[i] != NULL; i++)
    {
        if (strcmp(command, external_commands[i]) == 0)
        {
            return EXTERNAL;
        }
    }
}
