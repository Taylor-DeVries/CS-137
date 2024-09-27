#include <assert.h>
#include <stdio.h>

int count_common(int a[], int n1, int b[], int n2){
    int common = 0;
    int j = 0;
    int i = 0;

    while(j<n1 && i<n2){
        if(a[j] == b[i]){
            if(j>0 && i>0){
                if(a[j] == a[j-1] && b[j]==b[j-1]){
                    common--;
                }
            }
            j++;
            i++;
            common++;
        }else if (a[j] < b[i]){
            j++;
        }else{
            i++;
        }
    }
    return common;
}


// int main(void){
//     int a1[4] = {1,1,1,1};
//     int b1[8] = {1,1,1,1,1,1,1,1};
//     assert(1 == count_common(a1,4,b1,8));
//     int a2[8] = {1,3,3,4,5,8,9,100};
//     int b2[7] = {4,4,8,15,20,40,100};
//     assert(3 == count_common(a2,8,b2,7));  
    
//     int a3[5] = {1,3,3,45,990};
//     int b3[3] = {45,990,990};
//     assert(2 == count_common(a3,5,b3,3));
//     int a4[4] = {0,2,3,4};
//     int b4[4] = {0,7,8,9};
//     assert(1 == count_common(a4,4,b4,4));
//     int a5[2]= {0};
//     int b5[4]= {0};
//     assert(1 == count_common(a5,1,b5,1));

//     return 0;
// }