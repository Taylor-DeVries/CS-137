#include <stdio.h>
#include "functions.h"

void square(int w){
    for(int i = 1; i < (w*w) +1; i++){
        if(i% (w) != 0){
           printf("%d ", i);
        }else{
            printf("%d\n", i);
        }
    }
}

void spiral(int w){
    int x = 0;                                //counter number

    for(int k = 0 ; k < (w/2); k++){
        for(int i=0; i < (w - (2*k)); i++){
            printf("%d ", ++x);
        }
        for(int i=0; i < (w - ((2*k) +1)); i++){
            x+=w;
            printf("%d ", x);
        }
        for(int i=0; i < (w - ((2*k) +1)); i++){
            printf("%d ", --x);
        }
        for(int i=0; i < (w - ((2*k) + 2)); i++){
            x-=w;
            printf("%d ", x);
        }
    }
    if(w%2 !=0){
        x+=1;
        printf("%d ", x);
    }

    printf("\n");
}

void rotation(int w){
    int x = 0;                                  //current number

    for(int k=0; k < w/2; k++){
        for(int r=0; r < w - (2*k) -1; r++ ){

            printf("%d ", ++x);

            x += (w -(2*k) -(1+r)) + (w*r);

            printf("%d ", x);

            x += (w*(w - (2*k)  -(1+r))) -r;

            printf("%d ", x);

            x -= (w- (2*k) -(1+r)) + (w*r);

            printf("%d ", x);

            if(r == w - (2*k) -2){
                break;
            }
            x -= (w*(w - (2*k) -(1+r))) -r;
        }
    }
    if(w % 2 != 0){
        printf("%d ", ++x);
    }

    printf("\n");
    
}

// int main (void){
//     int n;

//     scanf("%d", &n);

//     square(n);

//     spiral(n);

//     rotation(n);

//     return 0;
// }
