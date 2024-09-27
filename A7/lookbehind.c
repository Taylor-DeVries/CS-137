#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>

void removeSubstring(char* str, const char* charsub, int strLength) {
    
    int subLen = strlen(charsub);

    for (int j = 0; j <= strLength - subLen; j++){
      str[j] = str[j+subLen];

      if (j == strLength){
        str[j] = '\0';
      }

    }

}

void lookBehind(const char* check, const char* s_sub, char* word) {
  //initializing all the lengths
  int checkLen = strlen(check);
  int s_subLen = strlen(s_sub);
  int wordLen = strlen(word);

    for (int i = 0; i < wordLen - s_subLen; i++) {
        //checking if the check string is in the word string, and checking if the substring is in the word string
        if (strncmp(word + i, s_sub, s_subLen) == 0 && strncmp(word + i - checkLen, check, checkLen) == 0) {

            removeSubstring(word + i, s_sub, wordLen - i); //sending to remove string to get rid of the sub string
            i -= 1; 
      }
  }//end for

}

// int main(void){

//     char word[] = "foo bar loop hoop" ;
//     lookBehind("l", "oo", word);
//     assert(0==strcmp("foo bar lp hoop", word));
//   lookBehind("o", "o", word);
//     assert(0==strcmp("fo bar lp hop", word));

//     char word3[] = "CS137137" ;
//     lookBehind("CS", "137", word3);
//     assert(0==strcmp("CS", word3));
//     char word3b[] = "CS137 137" ;
//     lookBehind("CS", "137", word3b);
//     assert(0==strcmp("CS 137", word3b));

//     char word4[] = "111111" ;
//     lookBehind("1", "1", word4);
//     assert(0==strcmp("1", word4));

//     char word5[] = "wow" ;
//     lookBehind("", "w", word5);
//     assert(0==strcmp("o", word5));

//     return 0;
// }
