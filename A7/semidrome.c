#include <stdbool.h> 
#include <string.h>
#include <assert.h>

bool palindrome(char *s, int pos1, int pos2) {
    if (pos1 >= pos2 || strlen(s) == 1) {
        return false;
    }
    while (pos1 < pos2) {
        if (s[pos1] != s[pos2]) {
            return false;
        }
        pos1 += 1; 
        pos2 -= 1;
    }
    return true;
}

bool check(char *s, int start) {

    int size = strlen(s) - 1;

    for (int i = start; i <= size; i++) {

        if (palindrome(s, start, i)) {
            if (check(s, i + 1)) {
                return true;
            }
        } else if (size-i == 0 && !palindrome(s, start, size)) {
            return false;
        } else if (size-i == 0 && palindrome(s, start, size)) {
            return true;
        }

    }
}

bool is_semidrome(char *s) {
    return check(s, 0);
}


// int main(void){

//     assert(is_semidrome("popeye"));
// 	assert(is_semidrome("racecar"));
// 	assert(!is_semidrome("aab"));
// 	assert(!is_semidrome("aabbc"));
// 	assert(is_semidrome("aa"));
// 	assert(is_semidrome("abaabacaba"));
// 	assert(!is_semidrome(""));
	
//     return 0;
// }

