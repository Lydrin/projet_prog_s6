#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include"structure.h"
#include "listechaines.h"
#include "hash.h"
#include "display.h"

#define FICHIER "./data/tate_artwork.csv"
#define MAX_STR_LEN 20000
char* parse(char* s);

bool read_file(HashListeArtiste ht)
{ 
    FILE* fp;
    char* chaine = (char*)malloc(MAX_STR_LEN * sizeof(char));
    if ((fp = fopen(FICHIER, "r")) == NULL) {
        printf("Impossible d'ouvrir le fichier, introuvable ?\n");
    }
    fgets(chaine, MAX_STR_LEN,fp); //On passe la première ligne useless
        while (fgets(chaine, MAX_STR_LEN, fp) != NULL){
        int idOeuvre;
        //char* accession_number;
        char* artistName;
        int artistId;
        char* title;
        int year;
        int hashindice;
        Artiste* Ptartiste_existant;
        idOeuvre = atoi((parse(chaine)));
        //accession_number = strdup((parse(NULL)));
        parse(NULL);
        artistName = strdup(parse(NULL));
        parse(NULL); //Pass artistRole
        artistId = atoi((parse(NULL)));
        title = strdup(parse(NULL));
        parse(NULL); //Pass dateText
        parse(NULL);   //Pass medium
        parse(NULL); //Pass creditLine
        year = atoi(parse(NULL)); 
        hashindice = hash_int(artistId);
        Ptartiste_existant = artiste_present(artistId,ht[hashindice]);
        if(Ptartiste_existant  !=NULL){             //Si l'artiste actuel est déja renseigné
            ajout_tete_oeuvre(&(Ptartiste_existant->PtOeuvre),idOeuvre,title,year);
            Ptartiste_existant->nombreOeuvre+=1;
        }else{
            ajout_tete_artist(&(ht[hashindice]),artistId,artistName);
            ajout_tete_oeuvre(&(ht[hashindice]->PtOeuvre),idOeuvre,title,year);
            ht[hashindice]->nombreOeuvre+=1;
        } 
        //free(accession_number);
        free(artistName);
        free(title);
    }
    free(chaine);
    chaine = NULL;
    fclose(fp);
    return true;
}

int main(void)
{
    HashListeArtiste ht; 
    init_ht(ht);
    read_file(ht);
    listeOeuvre(ht);
    detruire_hash_table(ht);
    return 0;
}
