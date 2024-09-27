#include <stdio.h>
int main (void){
    int num,denom;                   //initalizes int variables for num and demon

    scanf("%d %d", &num, &denom);    //sets the int values to what is typed on the keybaord accordingly

    //checking to see if the quotient will be positive; if its not, the qoutient will round down to get further from zero, but if its positive it will round up to get futher from zero
    if ( (num > 0 && denom > 0) || (num < 0 && denom < 0) ){
        //checks if there is a remainder
        if ( (num% denom) != 0){
            printf("%d\n", ((num/denom) + 1));                  //prints the quotient rounded up
        }//end if
        else{
            printf("%d\n", num/denom );                         //prints the quotient
        }//end else
    }//end if
    else{
        //checks if there is a remainder
        if ( (num% denom) != 0){
            printf("%d\n", ((num/denom) - 1));                  //prints the quotient rounded down
        }//end if
        else{
            printf("%d\n", num/denom );                         //prints the quotient
        }//end else
    }//end else

    return 0;              
}//end main