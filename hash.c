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

#ifndef HASH_H
    #include "hash.h"
#endif

int asciis(char *word)
{
  int i=0;
  int h=0;
  while(word[i]!='\0')
    {
      h=h+(word[i]-96);
      i++;
    }
  return h;
}

int hash(char *word)
{
  return (asciis(word) % TABLE_SIZE);
}

void init_ht(HashListArtist ht) {
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        ht[i]=NULL;
    } 
}

void ajout_artiste(char* artistId, char* nom, HashListArtist ht) {
    int indice = hash(artistId);
    Artiste* artist = ht[indice];
    ajout_tete_artist(&(artist),artistId,nom); 
    artist->nombreOeuvre +=1;
}

bool is_artist(char* artistId, HashListArtist ht){
    int indice = hash(artistId);
    Artiste* currentArtist = ht[indice];
    while(currentArtist != NULL){
        if(strcmp(artistId,currentArtist->artistId)==0){
            return true;
        }
        currentArtist=currentArtist->next;
    }
    return false;
}

