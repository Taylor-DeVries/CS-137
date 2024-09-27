#include <stdio.h>

void printarr(int a[], int len){
    for (int i=0; i<len-1; i++)
       printf("%d ", a[i]);
    printf("%d\n", a[len-1]);
}

void doubleselectionsort(int a[], int len){
 for (int i = 0; i < len / 2; i++) {
        int min = i;
        int max = i;

        for (int j = i + 1; j < len - i; j++) {
            if (a[j] < a[min]) {
                min = j;
            } else if (a[j] > a[max]) {
                max = j;
            }
        }

        //swaps the minimum element with the first element
        int temp = a[i];
        a[i] = a[min];
        a[min] = temp;

        //chekcs if the maximum element was at the first position, its position is now min index
        if (max == i) {
            max = min;
        }

        //swaps the maximum element with the last element
        temp = a[len - i - 1];
        a[len - i - 1] = a[max];
        a[max] = temp;

        printarr(a,len);
    }
}

// int main(void) {
   
//     int a[7] = {4, 4, 4, 0, 0, -10, -10};
//     doubleselectionsort(a,7);
//     int a2[5] = {6, 11, 2, -4, -1};
//     doubleselectionsort(a2,5);
//     int a3[10] = {1, 8, 5, 4, 6, 2, 5, 6, 2, 9};
//     doubleselectionsort(a3,10);
    
//     return 0;
// }
