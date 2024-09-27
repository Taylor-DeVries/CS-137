#include <stdio.h>
#include <math.h>
#include <assert.h>

// #define PI acos(-1)

// double f1(double x){
// 	return x*x;
// }

// double f2(double x){
// 	return cos(x);
// }

// double f3(double x){
// 	return sqrt(x);
// }

double trapezoidal(double (*f)(double), double a, double b, double epsilon, int n){
  	double totala = 0.0;
    double totalb = 0.0; 
    double width = (b-a) / n; //changed 2 to be n
    int keepTrack = 1;

    // while(difference >= epsilon){
    //     for(double i=a; i <= (b-width); i += width){
    //         totala += (((*f)(i) + (*f)(i+width)) / 2.0) * width;
    //     }

    //     difference = fabs(totalb - totala);
    //     totalb = totala;
    //     totala = 0.0;
    //     n *= 2;

    //     width /= 2.0 ;
    // }

    while(keepTrack){

        totalb = totala;
        totala = 0.0;
        n *= 2;

        width /= 2.0 ;

        for(int N = 0; N < n; N++){
            totala += (((*f)(a+width*N) + (*f)(a+width*(N+1))) / 2.0) * width;
        }
        if(fabs(totalb-totala) < epsilon){
            keepTrack = 0;
        }
    }    

    return totala;
}

// int main(void){
//   	assert(fabs(trapezoidal(f1, 5, 10, 0.00001, 2) - 291.667) <= 0.001);
// 	assert(fabs(trapezoidal(f2, PI / 2, 3, 0.00001, 5) - -0.858879) <= 0.000001);
// 	assert(fabs(trapezoidal(f3, 1, 4, 0.00001, 2) - 4.666) <= 0.001);
	
//   	return 0;
// }