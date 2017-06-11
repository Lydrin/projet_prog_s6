#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include"structure.h"
#include "listechaines.h"
#include "hash.h"

int asciis(char *word)
{
  int i=0;
  int h=0;
  while(word[i]!='\0')
    {
      h=h+(word[i]);
      i++;
    }
  return h;
}

int hash_word(char *word)
{
  return (asciis(word) % TABLE_SIZE);
}

int hash_int(int id){
    return id % TABLE_SIZE;
}

void init_ht(HashListeArtiste ht) {
    int i;
    for(i=0;i<TABLE_SIZE;i++){
        ht[i]=NULL;
    } 
}

Artiste* artiste_present(int artistId, ListeArtiste currentArtist){
    while(currentArtist != NULL){
        if(artistId==currentArtist->artisteId){
                return currentArtist;
        }
        currentArtist=currentArtist->next;
    }
    return NULL;
}

void detruire_hash_table(HashListeArtiste ht){
    ListeArtiste listeArtiste;
    for(int i=0;i<TABLE_SIZE;i++){
        listeArtiste = ht[i];
        detruite_liste_artiste(&listeArtiste);
    }
}
