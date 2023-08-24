#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#define MAX_INPUT_LENGTH 1024 
/*
 * Function to process the input command only
 * finctions are good
 */

void processCommand(char *command)
{
   /* Remove newline character at the end)*/
   command[strcspn(command, "\n")] = '\0';
   /* Check if the line is a comment (starts with '#')*/
   if (command[0] == '#') {
        /* Comment line, do nothing)*/
        return;
    }

    system(command);
}

int main() {
    char input[MAX_INPUT_LENGTH];
    while (1) {
        printf("Shell> ");
        if (fgets(input, sizeof(input), stdin) == NULL) {
              break;
        }
        processCommand(input);
    }
    return 0;
}
