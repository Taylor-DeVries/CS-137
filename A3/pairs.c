#include <stdio.h>

void numberPairs(int n){
    if(n%10 == n){
        printf("%d%d", n,n);
        return;
    }
    
    int digitCur= n%10;
    int next= n/10;

    if(digitCur == (next%10)){
        numberPairs(n/10);
    }else{
        numberPairs(n/10);
        printf("%d%d", digitCur,digitCur);
    }
    
}

// int main(void){
//     int x;

//     scanf("%d", &x);

//     numberPairs(x);
// }