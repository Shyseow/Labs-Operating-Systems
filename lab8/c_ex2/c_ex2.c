#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "command.h"

#define COMMAND_LINE_SIZE 2024

void remove_newline_ch(char *s)
{
	int nl = strlen(s) - 1;
	if(s[nl] == '\n')
		s[nl] = '\0';
}

int main(int argc, char *argv[])
{
	while(1)
    {
        int commandNum;
        char commandLine[1000000];
        char *tokens[10000];
        Command commands[MAX_NUM_COMMANDS];
        int tokenNum;

        printf("$ ");
        fgets(commandLine, 1000000, stdin);

        remove_newline_ch(commandLine);

        if (strcmp(commandLine, "exit") == 0)
            break;
        
        tokenNum = tokenise(commandLine, tokens);
        if (tokenNum == -1)
            printf("Error: Input has exceeded the limit.\n");
        else 
        {
            commandNum = separateCommands(tokens, commands, tokenNum);
            if(commandNum == -1)
                printf("Error: The first command cannot be a separator\n");
            else if (commandNum == -2)
                printf("Error: Last command cannot end with a pipe.\n");
            else if (commandNum == -3)
                printf("Error: Consecutive separator detected.\n");
            else
            {
                int i;
                printf("There is a total of %d commands.\n", tokenNum);

                i = 0;
                while (i<commandNum)
                {
                    int j = commands[i].first;
                    int counter = 0;

                    while (j <= commands[i].last)
                    {
                        printf("Token %d: %s\n", counter+1, tokens[j]);
                        j++;
                        counter++;
                    }
                    i++;
                }
            }

        }
    }
    exit(0);
}
