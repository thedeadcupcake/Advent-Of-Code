#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <assert.h>

int getnum(char line[])
{
    char *token;
    char *search = " ";

    token = strtok(line, search);
    token = strtok(NULL, search);

    return atoi(token);
}

char* getcmd(char line[])
{
    char *search = " ";
    char *token;

    token = strtok(line, search);

    return strdup(token);
}

int main(void)
{
    // data goes into here
    char** cmds = malloc(2500*sizeof(char*));
    int nums[2500];

    // submarine position
    int depth = 0;
    int hPos = 0;

    int aim = 0;

    char* buffer = malloc(20*sizeof(char));

    // counts the number of commands
    int counter = 0;

    // puts input stuff into array and counts them
    while (1){
        fgets(buffer, 19, stdin);
        if (strcmp(buffer, "break\n") == 0){
            break;
        }
        nums[counter] = getnum(buffer);
        cmds[counter] = getcmd(buffer);

        // printf("%s %d\n", cmds[counter], nums[counter]);

        counter++;
    }

    //  moving the sub
    for(int i = 0; i < counter; i++){
        if (strcmp(cmds[i], "forward") == 0){
            hPos+=nums[i];
            depth+=(nums[i]*aim);
        } else if (strcmp(cmds[i], "up") == 0){
            //depth-=nums[i];
            aim-=nums[i];
        } else if (strcmp(cmds[i], "down") == 0){
            //depth+=nums[i];
            aim+=nums[i];
        }
    }

    printf("depth: %d  hPos: %d aim: %d\n", depth, hPos, aim);
    printf("answer: %d", (depth*hPos));

    return 0;
}
