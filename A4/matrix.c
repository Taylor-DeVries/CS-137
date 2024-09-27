#include <stdio.h>
#include <stdbool.h>
#include <assert.h>

void arrprint(int a[], int n){
    for (int i = 0; i<n-1 ;i++){
        printf("%d ",a[i]);
    }
    printf("%d\n", a[n-1]);
}

void matrixprint(int n, int m[][n]){
    for (int i = 0; i<n ;i++){
        for (int j=0; j<n-1; j++){
               printf("%d ",m[i][j]);
        }
        printf("%d\n", m[i][n-1]);
    }
}

//convert 2D array nxn into 1D array of size nxn
void convert(int n, int mat[n][n], int a[]){
    int pos = 0;

    for(int i=0; i < n ; i++){
        for(int j=0; j < n ; j++){
            a[pos] = mat[i][j];
            ++pos;
        }
    }

}

//returns true if mat is a magic square matrix.
// mat is a magic square if the sums of the numbers in each row, 
// each column, and both main diagonals are the same
// the function also prints the magic constant (the magic sum of each row, column, and diagonal).
// use "The magic constant is: %d\n"  for printing the magic constant
bool ismagicsquare(int n, int mat[n][n]){
    int temp =0;
    int sumRows = 0, sumColumns = 0, sumDiagFwd = 0, sumDiagRev = 0;

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            sumRows = sumRows + mat[i][j];
        }
        if(i == 0){
            temp = sumRows;
        }
        if(temp != sumRows){
            return false;
        }
        if(i < n-1){
            sumRows = 0;
        }        
        
    }

    for(int i=0; i<n ; i++){
        for(int j=0; j<n ; j++){
            sumColumns = sumColumns + mat[j][i];
        }
        if(temp != sumColumns){
            return false;
        }
        if(i < n-1){
            sumColumns = 0;
        }
    }

    for(int i=0; i<n ; i++){
        sumDiagFwd = sumDiagFwd + mat[i][i];
    }

    int j = 0;
    for(int i=(n-1); i>=0 ; i--){
        sumDiagRev = sumDiagRev + mat[i][j];
        j++;
    }

    if( sumRows == sumColumns && sumRows == sumDiagFwd && sumRows == sumDiagRev){
        printf("The magic constant is: %d\n", sumRows);
        return true;
    }else{
        return false;
    }
}


// int main(void){
//     int mat[5][5] = {{1,2,3,4,5}, {2,3,4,5,6},{3,4,5,6,7},{4,5,6,7,8},{5,6,7,8,9}};
//     matrixprint(5,mat);
//     int arr[25];
//     convert(5,mat,arr);
//     arrprint(arr,25);
//     ismagicsquare(5,mat);

//     // tests for magic square

//     assert(!ismagicsquare(5,mat));
//     int mat3[3][3] = {{4,9,2},{3,5,7},{8,1,6}};
//     assert(ismagicsquare(3,mat3));
//     int mat4[4][4] = {{1,1,1,1},{1,1,1,1},{1,1,1,1},{1,1,1,1}};
//     assert(ismagicsquare(4,mat4));

//     // int mat[1][1] = {1};
//     // matrixprint(1,mat);
//     // int arr[1];
//     // convert(1,mat,arr);
//     // arrprint(arr,1);
    
// }

