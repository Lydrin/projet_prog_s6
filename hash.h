#ifndef STDIO_H
    #include <stdio.h>
#endif

#ifndef STDBOOL_H
    #include <stdbool.h>
#endif

#ifndef STDLIB_H
    #include <stdlib.h>
#endif

#ifndef STRING_H
    #include <string.h>
#endif

#ifndef STRUCTURE_H
    #include"structure.h"
#endif

#ifndef LISTECHAINES_H 
    #include "listechaines.h"
#endif

#define HASH_H


int asciis(char* word);
int hash(char* word);
void init_ht(HashListArtist ht);
void ajout_artiste(Artiste* artiste, HashListArtist ht); 
bool is_artist(Artiste* artist, HashListArtist ht);
