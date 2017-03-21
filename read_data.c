#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <stdbool.h>
#include "structure.h"

#define FICHIER "./data/small_artwork.csv"
#define MAX_STR_LEN 1000 

bool read_file(){
    FILE *fp;
    char *buf = (char*)malloc(MAX_STR_LEN*sizeof(char));
    char *tmp;
    if(buf==NULL){
        printf("Impossible d'allouer de la mémoire pour lire le fichier\n");
        return false;
    }
    if((fp=fopen(FICHIER,"r"))==NULL){
        printf("Imossible d'ouvrir le fichier, introuvable ?\n");
    }
    while(fgets(buf,MAX_STR_LEN,fp)!=NULL){  //Utilisation de fgets car il garde les whitespace contrairement à fscanf
        if((strlen(buf)>0) && (buf[strlen(buf)-1]== '\n')){ //On vire les \n pour les remplacer par des fins de chaines ( on change de ligne )
            buf[strlen(buf)-1] = '\0';
        }
        tmp = strtok(buf,";");
        // A revoir, strtok s'arrète à la première occurence de la , =>
        // problème à regler dans une nouvelle fonction 
    }
}
