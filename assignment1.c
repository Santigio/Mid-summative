
/* CREDIT: inorder to solve this, I research and lookup other sample codes from Google to get 
understanding to be able to solve it.   */



#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <ctype.h>
#include <unistd.h>
#include <sys/types.h>

// let's maximum words be 500
#define MAX_WORDS 500



int main()
{

    printf("counting unique wrdCounts in the fle ...\n\n");

    // pointer file
    FILE *file;
    int i, len, specialWrds, specialWrd;

    pid_t wait();

    //List of words
    char wrdCount[50];
    char wrdCounts[MAX_WORDS][50];

    // store unique unique word count
    int k[MAX_WORDS];

    // open the file
    file = fopen("file.txt", "r");

    if (file == NULL)
    {

        printf("Error reading file!\n");

        exit(0);
    }

    // while loop logic to keep program running 
    while (fscanf(file, "%s", wrdCount) != EOF)
    {

        // remove punctuation from our unique word
        len = strlen(wrdCount);
        if (punctwrd(wrdCount[len - 1]))
            wrdCount[len - 1] = '\0';

        specialWrd = 1;

        // count unique wrdCounts --
        for (i = 0; i < specialWrds && specialWrd; i++)
        {
            if (strcmp(wrdCounts[i], wrdCount) == 0)
                specialWrd = 0;
        }

        // when find unique word, add to list
        if (specialWrd)
        {
            strcpy(wrdCounts[specialWrds], wrdCount);
            k[specialWrds]++;

            specialWrds++;
        }
        else
        {
            k[i - 1]++;
        }
    }
    // close file
    fclose(file);

    // this function create file process
    int pid = fork();
    int x = getpid();

    if (pid == 0)
    {
        // child process
        printf("\nChild Calculating first batch of word count\n Child pid : %d and parent pid : %d \n\n", getpid(), getppid());
        
        for (i = 0; i < (specialWrds / 2); i++)
        {

            printf("'%s ': %d\n", wrdCounts[i], k[i]);
        }
        // this 'wait function' wait momentarily  
        wait();
    }
    else if (pid > 0)
    {
        // parent process
        printf("\nOur parent calculate the second badge of unique words Counts\nParent process pid: %d\n\n", getpid());
        // calculate second batch of wrdCounts
        for (i = (specialWrds / 2) + 1; i < specialWrds; i++)
        {

            printf("'%s ': %d\n", wrdCounts[i], k[i]);
        }
    }
    else
    {
        printf("Null child was created");
    }

    return 0;
}