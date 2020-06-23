#include<stdio.h>
#include<string.h>
#include<stdlib.h>
#define MAX_SIZE_STRING 500
int checker(char input[],char check[], int len)
{
    int i,result=1;
    for(i=0; i < len; i++) {
        
        if(input[i] != check[i]) {
            result=0;
            break;
        }
    }
    return result;
}
int main() {
    char *str = (char *) malloc(sizeof(char) * MAX_SIZE_STRING);
    char *strModified = (char *) malloc(sizeof(char) * MAX_SIZE_STRING);
    fgets(str, MAX_SIZE_STRING, stdin); 
    char * token = strtok(str, " ");
    strcpy(strModified, "");
    while( token != NULL ) {
        char * max =  (char *) malloc(sizeof(char) * MAX_SIZE_STRING);
        strcpy(max, token);
        if(checker(max, "stupid", 6)) {
            strcpy(max, "the great");
        } else if(checker(max, "ugly", 4)) {
            strcpy(max, "vibrant");
        } else if(checker(max, "pathetic", 8)) {
            strcpy(max, "shiny");
        } else if(checker(max, "Alas", 4)) {
            strcpy(max, "Wow");
        }
        strcat(strModified, strcat(max, " "));
        token = strtok(NULL, " ");
    }
    printf("%s\n", strModified);
    return 0;
}