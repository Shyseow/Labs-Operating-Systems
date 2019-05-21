#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include "token.h"

#define COMMAND_LINE_SIZE 2024

void remove_newline_ch(char *s)
{
	int nl = strlen(s) - 1;
	if(s[nl] == '\n')
		s[nl] = '\0';
}

int main(int argc, char *argv[])
{
	char *inputline;
	char *tkn[MAX_NUM_TOKENS];
	int i, tokenNo;

	inputline = malloc(sizeof(char) * 1024);
	

	while (1) {
		// display a prompt such as "%", "$", or whatever you like, to the terminal output;
		printf("$ ");
		// then input one line of text from the user;
		fgets(inputline, COMMAND_LINE_SIZE, stdin);
		remove_newline_ch(inputline);
		tokenNo = tokenise(inputline, tkn);
		
		if (tokenNo == -1)
		{
			printf("Error: Input has exceeded the limit.\n");
		}
		else
		{
		// then prints out the input line to the terminal output if the input line is not "exit".
			i = 0;
			while (i < tokenNo)
			{	
				if (strcmp(tkn[i],"exit")== 0)
					{
						return 0;
					}
				else
				{
					printf("token[%d]: %s\n", i, tkn[i]);
					++i;
				}
			}
		}
	}
	
	free(inputline);
	exit(0);
}
