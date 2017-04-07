#include<stdio.h>
#include<string.h>
#include<stdbool.h>
char* parse(char* s)
{
    static char* reste;
    int quote = 1;
    char delim = ',';
    int i = 0;
    if(reste==NULL && s==NULL)
        return NULL;
    if (s == NULL) 
        s = reste;
    if(*s=='"'){
        quote = 2;
        delim = '"';
        s++;
    }
    while(*(s+i)!=delim && *(s+i) != '\0'){
        i++;
    }
    if(*(s+i) != '\0'){
        *(s+i)='\0';
        reste = s+i+quote;
    }else{
        reste = NULL;
    }
    return s;
}

