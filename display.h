#define DISPLAY_H

#ifndef STRUCTURE_H
	#include "structure.h"
#endif

void listeOeuvre(ListeArtiste liste);

void displayOeuvre(Artiste * artiste);

void listeOeuvreByArtist(int idArtist, HashListeArtiste liste);

void displayNbOeuvre(Artiste * ptArtist);

void nbOeuvreByArtist(int idArtist, HashListeArtiste liste);

void listeNbOeuvreByArtist(ListeArtiste liste);

void oldestOeuvre(Oeuvre * oldest);


