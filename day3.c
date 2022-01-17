#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <math.h>
#include <assert.h>

#define BIT_LEN 5

void copyArray(char* arr1[], char* arr2[], int length)
{
    for(int i = 0; i<length; i++){
        arr2[i] = arr1[i];
    }
}

void count(char* arr[], char string[], int primary, int counter){
    char buffer[20];
    for(int column = 0; column < BIT_LEN; column++){
        int i = 0;
        int o = 0;
        for(int bit = 0; bit < counter; bit++){
            if (arr[bit][column] == '1'){
                i++;
            } else if(arr[bit][column] == '0'){
                o++;
            }
            //printf("%d\n", bits[bit][column]);
        }
        printf("there are %d 0s and %d 1s in column %d\n", o, i, column+1);

        char str[1];
        char inverted[1];

        sprintf(str, "%d", (i >= o));
        sprintf(inverted, "%d", (i < o));

        if (primary == 1){
            strcat(string, str);
        } else {
            strcat(string, inverted);
        }

        printf("%s\n", str);
    }
    //printf("%s\n", str);
    //strcat(string, buffer);
}

// loop through list to find numbers. returns 0 if there is a number
int checkAns(char* arr[], int counter){
    // find answers
    int i;

    for(int row = 0; row < counter; row++){
        if (strcmp(arr[row], "no") != 0){
            printf("yes");
            i++;
        }
    }

    return i;
}

int main()
{
    int counter = 0;

    char** bits = malloc(2500*sizeof(char*));
    char** secondary = malloc(2500*sizeof(char*));

    char* buffer = malloc(20*sizeof(char));

    // used for bit criteria
    char gamma[20] = "";
    char epsilon[20] = "";

    char oxygen[BIT_LEN+1];
    char co2[BIT_LEN+1];

    // input
    while (1){
        fgets(buffer, 19, stdin);
        if (strcmp(buffer, "break\n") == 0){
            break;
        }
        bits[counter] = strdup(buffer);
        counter++;
    }

    copyArray(bits, secondary, 2500);

    // gamma and epsilon counting
    count(bits, gamma, 1, counter);
    count(bits, epsilon, 0, counter);

    printf("gamma: %s  epsilon: %s\n", gamma, epsilon);

    // weed out bits that don't meet criteria
    for(int column = 0; column < BIT_LEN; column++){
        for(int row = 0; row < counter; row++){
            if (atoi(&bits[row][column]) != atoi(&epsilon[column])){
                bits[row] = "no";
            }
            if (atoi(&secondary[row][column]) != atoi(&gamma[column])){
                secondary[row] = "no";
            }
        }
        if (checkAns(bits, counter) == 1){
            printf("found answer");
            break;
        }
        strcpy(gamma, "");
        strcpy(epsilon, "");
        count(bits, gamma, 1, counter);
        count(bits, epsilon, 0, counter);
    }

    // get final answers
    for(int row = 0; row < counter; row++){
        if (strcmp(bits[row], "no") != 0){
            strcpy(oxygen, bits[row]);
        }
        if (strcmp(secondary[row], "no") != 0){
            printf(secondary[row]);
            strcpy(co2, secondary[row]);
        }
    }

    printf("oxygen: %d  co2: %s", atoi(oxygen), co2);

    return 0;
}
