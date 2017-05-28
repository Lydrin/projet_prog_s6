#define READ_DATA_H
#define FICHIER "./data/tate_artwork.csv"
#define MAX_STR_LEN 20000

#include <stdio.h>
#include <stdbool.h>
#include <stdlib.h>
#include <string.h>
#include "structure.h"
#include "listechaines.h"
#include "hash.h"
#include "display.h"

bool read_file(HashListeArtiste ht);
