#include <stdbool.h>
#include <string.h>
#include <stdio.h>
#include <assert.h>
#include <stdlib.h>

void lookBehind(const char* check, const char* s_sub, char* word) {
   
    int checkLen = strlen(check);
    int s_subLen = strlen(s_sub);
    bool contains = false;

    for(int i=0 ; i < strlen(word) ; i++){
        //when contains is true that means that there is elements to get rid of beind the check char, so we remove
         if(contains){
            printf("word=%s\n", word);
            char *copyStr = (char*)malloc((strlen(word)-strlen(s_sub))*(sizeof(char)));
            strcpy(copyStr,"");

            //copys all the values from word up until the point where check was found
            strncpy(copyStr,word,i);    
            printf("copy=%s\n", copyStr); 

            for(int k=1 ; k<=s_subLen ; k++){
                copyStr[i+k] = word[i+s_subLen+k];
            }
            printf("copystr=%s\n", copyStr);

            strncpy(word,copyStr,strlen(copyStr));
            printf("new word= %s\n", word);
            
            free(copyStr);
            //i = 0;
        }
        //checks if the first character of the check string is in the word,, if so, checks if the remaining are the same as check
        if(word[i] == check[0]){
            printf("%d\n", i);
            for(int j=0 ; j < checkLen ; j++){
                printf("%d\n", j);
                if(word[i+j] == check[j]){
                    contains = true;
                    printf("true\n");
                }else{
                    contains = false;
                    break;
                }
            }
            //checking if the chars in the indexs behind the check char are the s_sub we are looking to remove
            for(int k=0 ; k < s_subLen ; k++){
                printf("k=%d, i=%d\n", k,i);
                if(word[i+checkLen+k] == s_sub[k]){
                    contains = true;
                    printf("true again\n");
                }else{
                    contains = false;
                    break;
                }//end else
            }//end for
        }//end if

    }//end for

    printf("%s\n", word);

}

int main(void){
    
    char word[] = "foo bar loop hoop" ;
    lookBehind("l", "oo", word);
    assert(0==strcmp("foo bar lp hoop", word));
	lookBehind("o", "o", word);
    assert(0==strcmp("fo bar lp hop", word));
    
    char word3[] = "CS137137" ;
    lookBehind("CS", "137", word3);
    assert(0==strcmp("CS", word3));
    char word3b[] = "CS137 137" ;
    lookBehind("CS", "137", word3b);
    assert(0==strcmp("CS 137", word3b));
    
    char word4[] = "111111" ;
    lookBehind("1", "1", word4);
    assert(0==strcmp("1", word4));

    char word5[] = "wow" ;
    lookBehind("", "w", word5);
    assert(0==strcmp("o", word5));
    
    return 0;
}