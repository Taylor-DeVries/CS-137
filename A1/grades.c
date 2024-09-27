#include <stdio.h>
int main(void){
    int Q,A,M;                                                   //initailizes variables for assesments

    scanf("%d %d %d", &Q, &A, &M);                               //reads in from keyboard and sets variables for quizzes, assignments, and midterm respectivly

    int result1 = ((37.5 - (0.3*M))/0.45);                       //calcs the min grade required for the condition of the midterm and final >= 37.5
    int result2 = ((50 - (0.05*Q) - (0.2*A) - (0.3*M))/0.45);    //calcs the min grade required for the average of each assesment being >= 50

    //checking to see which result is the higher grade required for the final exam
    if (result1 > result2){
        printf("%d\n", result1);      //prints the min grade required for final exam
    }//end if
    else {
        printf("%d\n", result2);      //prints the min grade required for final exam
    }//end else

    return 0;
}//end main