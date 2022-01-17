#include <stdio.h>
#include <stdlib.h>
#include <string.h>

int main()
{
    int nums[5000]; // array of input numbers

    int inc = 0; // value for increased

    int counter = 0;

    // puts input numbers into array and counts them
    while (1){
        scanf("%d", &nums[counter]);
        if (nums[counter] == -1){
            break;
        }
        if (counter > 1){
            if (nums[counter] > nums[counter-1]){
                inc++;
            }
        }
        counter++;
    }

    // adds up all the 3 measurement sliding windows
    for(int i = 0; i<counter-2; i++){
        nums[i] = nums[i]  + nums[i+1] + nums[i+2];
    }

    inc = 0;

    // counts again
    for(int i = 1; i<counter-2; i++){
        if (nums[i] > nums[i-1]){
            inc++;
        }
    }

    printf("%d/%d three-window measurements were larger than the last \n", inc, counter-2);

    return 0;
}
