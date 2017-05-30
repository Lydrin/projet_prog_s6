#ifndef DISPLAY_H
#define DISPLAY_H

#include "structure.h"
void listeOeuvre(HashListeArtiste liste);
void rechercheArtiste(int idArtist, HashListeArtiste liste); //TODO
void displayOeuvre(Artiste * ptArtist);
void listeOeuvreByArtist(int idArtist, HashListeArtiste liste);
void displayNbOeuvre(Artiste * ptArtist);
void nbOeuvreByArtist(int idArtist, HashListeArtiste liste);
void listeNbOeuvreByArtist(HashListeArtiste liste);
void oldestOeuvre(Oeuvre* oldest);


#endif
