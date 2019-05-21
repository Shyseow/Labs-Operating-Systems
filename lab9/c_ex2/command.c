// file:		command.c for Week 9 
// purpose;		to separate a list of tokens into a sequence of commands.
// assumptions:		any two successive commands in the list of tokens are separated 
//			by one of the following command separators:
//				"|"  - pipe to the next command
//				"&"  - shell does not wait for the proceeding command to terminate
//				";"  - shell waits for the proceeding command to terminate

#include <string.h>
#include <stdlib.h>
#include <stdio.h>
#include "command.h"

// return 1 if the token is a command separator
// return 0 otherwise
//
int separator(char *token)
{
    int i=0;
    char *commandSeparators[] = {pipeSep, conSep, seqSep, NULL};

    while (commandSeparators[i] != NULL) {
        if (strcmp(commandSeparators[i], token) == 0) {
            return 1; 
        } 
        ++i;
    }
    
    return 0;
}

// fill one command structure with the details
//
void fillCommandStructure(Command *cp, int first, int last, char *sep)
{
     cp->first = first; 
     cp->last = last - 1;
     cp->sep = sep; 
}

int separateCommands(char *token[], Command command[], int nTokens)
{
    // check the first token
    if (separator(token[0]) == 1)
        return -1;

    // if last token is a pipe
    if(strcmp(token[nTokens -1], pipeSep) == 0)
        return -2;

    // check last token, add ";" if necessary 
    if (strcmp(token[nTokens-1], seqSep) != 0) {
        token[nTokens] = seqSep;
        nTokens++;
    }
          
    int first=0;   // points to the first tokens of a command
    int last;      // points to the last  tokens of a command
    char *sep;     // command separator at the end of a command
    int c = 0;     // command index
    int i;

    for (i=0; i<nTokens; ++i) {
        last = i;
        if (separator(token[i])) {
            sep = token[i];
            if (first==last)  // two consecutive separators
                return -3;
            fillCommandStructure(&(command[c]), first, last, sep);
            c++;
        }
        
    }

     // check the last token of the last command  
    if (strcmp(token[last], pipeSep) == 0) { // last token is pipe separator
        return -3; 
    } 

     // calculate the number of commands
     int nCommands = c;

    for (i=0; i<nCommands; i++) {
        searchRedirection(token, &(command[i]));
        buildCommandArgumentArray(token, &(command[i]));
    }
 
    return nCommands; 
}

int tokenise (char line[], char *token[])
{
    char *temp;
    int i=0;

    temp = strtok(line, tokenSeparators); 
    //token sperator is define at header file as " \t\n"

    while (temp != NULL && i < MAX_NUM_TOKENS) 
    {
        token[i] = temp;
        temp = strtok(NULL, tokenSeparators); 
        //strtok(NULL,..) means continue take in token from first string that is passed in strtok
        // unitl reach token separator
        i++;
    }

    if (i == MAX_NUM_TOKENS && temp != NULL) 
    {
     return -1;
    }
    else if (i == 0)
    {
      return -2;  
    }
    else
    {
      return i;
        // return max number of token to show did not exceed max token and carry on prg
    }
}

void searchRedirection(char *token[], Command *cp)
{
    int i; 
    for (i=cp->first; i<=cp->last; ++i) {
        if (strcmp(token[i], "<") == 0) {   // standard input redirection
            cp->stdin_file = token[i+1];
            ++i;
        } else if (strcmp(token[i], ">") == 0) { // standard output redirection
            cp->stdout_file = token[i+1];
            ++i;
        }
    }
}

void buildCommandArgumentArray(char *token[], Command *cp)
{
    int n = (cp->last - cp->first + 1)    // the numner of tokens in the command
          + 1;                             // the element in argv must be a NULL

     // re-allocate memory for argument vector
     cp->argv = (char **) realloc(cp->argv, sizeof(char *) * n);   
     if (cp->argv == NULL) {
         perror("realloc");
         exit(1);
     }

     // build the argument vector
     int i;
     int k = 0; 
     for (i=cp->first; i<= cp->last; ++i ) {
         if (strcmp(token[i], ">") == 0 || strcmp(token[i], "<") == 0) 
             ++i;    // skip off the std in/out redirection
         else {
             cp->argv[k] = token[i];
             ++k;
         }
     }
     cp->argv[k] = NULL;
}
