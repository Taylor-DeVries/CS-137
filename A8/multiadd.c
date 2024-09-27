#include <assert.h>
#include <stdlib.h>
#include <stdbool.h>
#include <stdio.h>

void sortArr(long long int arr[], int len)
{
    long long int max = arr[0];

    // finds max value in arr
    for (int i = 0; i < len; i++)
    {
        if (arr[i] > max)
        {
            max = arr[i];
        }
    }

    // creates an array to hold the occurances of each element in arr
    long long int *count = (long long int *)malloc((max + 1) * sizeof(long long int));
    for (int j = 0; j <= max; j++)
    {
        count[j] = 0;
    }
    // counts the occurances
    for (int k = 0; k < len; k++)
    {
        count[arr[k]]++;
    }

    long long int *sortedArr = (long long int *)malloc(len * sizeof(long long int));
    int index = 0;

    for (int i = 0; i <= max; i++)
    {
        while (count[i] > 0)
        {
            sortedArr[index] = i;
            ++index;
            --count[i];
        }
    }

    // copies the sorted array back to the arr[]
    for (int j = 0; j < len; j++)
    {
        arr[j] = sortedArr[j];
    }

    free(count);
    free(sortedArr);
}

long long int multiadd(long long int a[], int n)
{
    if(n==1){
        return a[0];
    }else {
        sortArr(a, n);
    }
    int pos = 0;

    while (n > 1)
    {
        // multiplys
        for (int i = 0; i <= (n - 2); i += 2)
        {
            a[pos] = (a[i] * a[i + 1]);
            ++pos;
        }
        n = n / 2;
        pos = 0;

        if (n == 1)
        {
            break;
        }

        //adds
        for (int j = 0; j < (n - 1); j += 2)
        {
            a[pos] = (a[j] + a[j + 1]);
            ++pos;
        }
        n = n / 2;
        pos = 0;
    }

    return a[0];
}

// int main(void){
//     long long int a[8] = {1,4,3,6,5,3,2,8};
//     assert(748 == multiadd(a,8));
//     long long int b[16] = {0};
//     assert(0 == multiadd(b,16));
//     long long int c[16] = {1,6,5,8,6,7,5,4,8,9,10,2,12,14,1,1};
//     assert(27498 == multiadd(c,16));
//     long long int d[4] = {1,0,2,4};
//     assert(8 == multiadd(d,4));

//     return 0;
// }