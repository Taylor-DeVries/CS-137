#include <stdio.h>
#include <assert.h>

int jump_stair_v1(int n){
    if (n<=1){
        return 1;
    }

    return (jump_stair_v1(n-1) + jump_stair_v1(n-2));
}

int jump_stair_v2(int n){
   
    if(n < 0){
        return 0;
    }
    if(n<=1){
        return 1;
    }
    if(n == 2 || n == 4){
        return 2;
    }

    return (jump_stair_v2(n-3)+jump_stair_v2(n-6));
}

int jump_stair_v3(int n){
    if( n < 6){
        return 0;
    }
    if( n == 6 || n == 9){
        return 1;
    }

    return (jump_stair_v3(n-6) + jump_stair_v3(n-9));
}

// int main(void){
//     int x = 7;

//     printf("%d\n", jump_stair_v2(x));
//     printf("%d\n", jump_stair_v2(x));
//     printf("%d\n", jump_stair_v3(x));

//     assert(1==jump_stair_v1(1));
//     assert(1==jump_stair_v2(1));
//     assert(0==jump_stair_v3(1));
//     assert(2==jump_stair_v1(2));
//     assert(2==jump_stair_v2(2));
//     assert(0==jump_stair_v3(2));
//     assert(13==jump_stair_v1(6));
//     assert(2==jump_stair_v2(6));
//     assert(1==jump_stair_v3(6));
//     assert(21==jump_stair_v1(7));
//     assert(3==jump_stair_v2(7));
//     assert(0==jump_stair_v3(7));
//     assert(55==jump_stair_v1(9));
//     assert(3==jump_stair_v2(9));
//     assert(1==jump_stair_v3(9));

//  return 0;
// }
