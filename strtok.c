/* 
 * strtok.c --
 *
 *	Source code for the "strtok" library routine.
 *
 * Copyright 1988 Regents of the University of California
 * Permission to use, copy, modify, and distribute this
 * software and its documentation for any purpose and without
 * fee is hereby granted, provided that the above copyright
 * notice appear in all copies.  The University of California
 * makes no representations about the suitability of this
 * software for any purpose.  It is provided "as is" without
 * express or implied warranty.
 */

#ifndef lint
static char rcsid[] = "$Header: /sprite/src/lib/c/string/RCS/strtok.c,v 1.1 89/03/22 16:08:00 rab Exp $";
#endif

#ifndef __STDC__
#define const
#endif

#include<stdio.h>
#include<string.h>
#include<stdbool.h>

/*
 *----------------------------------------------------------------------
 *
 * strtok --
 *
 *  	Split a string up into tokens
 *
 * Results:
 *      If the first argument is non-NULL then a pointer to the
 *      first token in the string is returned.  Otherwise the
 *      next token of the previous string is returned.  If there
 *      are no more tokens, NULL is returned.
 *
 * Side effects:
 *	Overwrites the delimiting character at the end of each token
 *      with '\0'.
 *
 *----------------------------------------------------------------------
 */

char * strtok1(char* s)
{
    static char* reste;
    char delim = ',';
    int i = 0;
    if(reste==NULL && s==NULL)
        return NULL;
    if (s == NULL) 
        s = reste;
    if(*s=='"'){
        delim = '"';
        i++;
    }
    while(*(s+i)!=delim){
        i++;
    }
    *(s+i)='\0';
    reste = s+i+1;
    return s;
}
char *parse(char *s){
    static char* reste;
    char delim = ',';
    bool quotes = false;
    int i = 0;
    if(reste==NULL && s == NULL)
        return NULL;
    if(s==NULL)
        s = reste;
    do{
        if(*(s+i)=='"')
            quotes=!quotes;
        i++;
    }while((*(s+i)!=delim) ^ quotes);
    *(s+i)='\0';
    reste = s+i+1;
    return s;
}

int main(){
    char str[]="test,coucou,lala,\"ta,ta\",tutu";
    char *str2 = strdup(parse(str));
    printf("%s\n",str2);
    str2 = parse(NULL);
    printf("%s\n",str2);
    str2 = parse(NULL);
    printf("%s\n",str2);
    str2 = parse(NULL);
    printf("%s\n",str2);
    str2 = parse(NULL);
    printf("%s\n",str2);
    str2 = parse(NULL);
    printf("%s\n",str2);

}
