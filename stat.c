#include "structure.h"
#include <stdio.h>
int collision(ListeArtiste liste){
    int i = 0;
    while(liste != NULL){
        i+=1;
        liste = liste->next;
    }
    return i;
}

int collision_moyenne(HashListeArtiste ht, int taille){
    int somme = 0;
    for(int i=0;i<taille;i++){
        somme += collision(ht[i]);
    }
    somme /= taille;
    return somme;
}
