#include <stdio.h>
#include <assert.h>
#include <stdbool.h>

int checkDig(int num){

    if(num == 0){
        return 0;
    }

    return 1 + checkDig(num/10);
}

int power(int x, int y){
    if(y==0){
        return 1;
    }

    return x*power(x,y-1);
}

int calcNum(int num, int numDig){
    if(num == 0){
        return 0;
    }

    int digit = num%10;
    int digitToPow = power(digit, numDig);

    return digitToPow + calcNum(num/10, numDig);
}

bool narcissist(int n){
    if(calcNum(n, checkDig(n)) == n){
        return true;
    }
    return false;
}

// int main (void){
//     int n = 301;

//     printf("%d\n", narcissist(n));
//     printf("%d \n", checkDig(n));
//     int numDigits = checkDig(n);
//     printf("%d", calcNum(n, numDigits));

//  assert(narcissist(1));
//  assert(narcissist(9));
//  assert(narcissist(153));
//  assert(narcissist(370));
//  assert(narcissist(92727));
//  assert(narcissist(548834));
//  assert(!narcissist(10));
//  assert(!narcissist(92));
//  assert(!narcissist(1535));
//  assert(!narcissist(1234));
//  assert(!narcissist(92726));
//  assert(!narcissist(93083));

//  return 0;
 
// }