#include <stdio.h>
int main(void){
    int n;           //initalizing variable to hold num of spaces

    int headPos = 3;
    int bodyPos = 2;
    int count  = 0;

    scanf("%d", &n); //reading in the number of spaces inputted by user (greater or equal to 5)

    while(headPos < n){
        while (count < headPos-bodyPos){
            printf("_");
            count++;
        }
        while(count < headPos){
            printf("X");
            count++;
        }
        if(count == headPos){
            printf("H");
            count++;
        }

        while( count < n){
            if(count%2 == 0){
                printf("_");
                count++;
            }else{
                printf(".");
                count++;

            }
        }

        printf("\n");
        if (++headPos %2 != 0){
            bodyPos++;
        }

        count =0;
    }

    return 0;
}