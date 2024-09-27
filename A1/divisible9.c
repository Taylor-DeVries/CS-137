#include <stdio.h>
int main(void){
    int x;           //initializes int var x

    scanf("%d", &x); //reads in an int from the keyboard to store in x

    //checking if x is divisble by 9 by checking if it has a remainder
    if(x%9 == 0){
        printf("yes\n");   //if it is divisble, prints out yes
    }//end if
    else{
        printf("no\n");    //if it is not divisble, prints out no
    }//end else

    return 0;
}