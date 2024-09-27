#include <stdio.h>
#include <math.h>

int main(void){
    int curr,max,min,fails;
    double mean = 0.0;
    double SD = 0.0;
    int currpos = 0;
    int grades[101] = {0};

    while(scanf("%d", &curr)){
        if(currpos == 0){
            max = curr;
            min = curr;
            fails = 0;
        }else if( curr >= max){
            max = curr;
        }else if ( curr <= min){
            min = curr;
        }
        
        if(curr < 50){
            ++fails;
        }

        grades[curr]++;
        ++currpos;
        }    

    
    for(int i=0; i<101; i++){
        mean = mean + (grades[i] * i);
    }

    mean = mean / currpos;

    for(int i=0; i<101; i++){
        for(int j=0; j < grades[i]; j++){
            SD = SD + pow(i - mean, 2);
        }
    }

    SD = sqrt(SD / (currpos - 1));

    printf("The maximal grade is: %d\n", max);
    printf("The number of students who received the maximal grade is %d\n", grades[max]);
    printf("The minimal grade is: %d\n", min);
    printf("The number of students who received the minimal grade is %d\n", grades[min]);
    printf("The course mean is: %0.3f\n", mean);
    printf("The standard deviation is: %0.3f\n", SD);
    printf("The number of students who failed the course is: %d\n", fails);

    return 0;
}