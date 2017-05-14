#include<stdio.h>
#include<string.h>
/*
La fonction suivante est une modification personelle de la fonction strtok afin de pouvoir renvoyer un pointeur vers la chaine située
après la "," et de la remplacer par /0. La modification repose sur le traitement du cas ",,," et du cas des "," non comptabilisées à
l'intérieur des quotes.

Ainsi "1970,"Blake, Robert",,," donnera quelque chose asimilable à [ "1970","Blake,Robert","","",""]

*/
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

