#include <stdio.h>
#include <assert.h>
#include <stdlib.h>
#include <string.h>


char* merge(char* s1, char* s2) {
    int len1 = strlen(s1);
    int len2 = strlen(s2);

    char* result = (char*)malloc((len1 + len2 + 2)*sizeof(char));
    strcpy(result,"");

    int i = 0, j = 0;

    while (i < len1 || j < len2) {

        if (i < len1) {
            while(s1[i] != ' ' && s1[i] != '\0'){
                result = realloc(result, strlen(result) +2);
                strncat(result, &s1[i], 1);
                i++;
            }
            result = realloc(result, strlen(result) +2);
            strcat(result, " ");
            i++;            
        }
        if (j < len2) {
            while(s2[j] != ' ' && s2[j] != '\0'){
                result = realloc(result, strlen(result) +2);
                strncat(result, &s2[j], 1);
                j++;
            }
            result = realloc(result, strlen(result) +2);
            strcat(result, " ");
            j++;            
        }       
    }

    result[strlen(result) -1] = '\0';
    return result;

}

// int main(void){
        
//     char s1[] = "The brown jumps the dog";
//     char s2[] = "quick fox over lazy";
//     char *s = merge(s1, s2);
//     assert(!strcmp(s, "The quick brown fox jumps over the lazy dog"));
//     free(s);
    
//     char s3[] = "the brown";
//     char s4[] = "quick fox is sleeping today";  
//     s = merge(s3,s4);
//     assert(!strcmp(s, "the quick brown fox is sleeping today"));
//     free(s);
    
//     char* s5 = "happy to you";
//     char* s6 = "birthday";  
//     s = merge(s5,s6);
//     assert(!strcmp(s, "happy birthday to you"));
//     free(s);

//     return 0;
// }
