#ifndef HASH_H
#define HASH_H
#include <stdbool.h>
#include"structure.h"
int hash_word(char *word);
int hash_int(int id);
int asciis(char *word);
void init_ht(HashListeArtiste ht); 
void ajout_artiste(int artistId, char* nom, HashListeArtiste ht);
Artiste* artiste_present(int artistId, ListeArtiste currentArtist);
void detruire_hash_table(HashListeArtiste ht);
#endif
