#define MAX_OEUVRES 10 
typedef struct{
    char dimtext[248];
    short width;
    short height;
    short depth;
    char unit[2];
}Dimensions;

typedef struct{
    char nom[120];
    int artistId;
}Artist;

typedef struct{
    int id;
    char accession_number[6];
    Artist artiste;
    char artisteRole[24];
    char title[320];
    char dateText[75];
    char medium[120];
    char creditLine[821];
    int year;
    int acquisitionYear;
    Dimensions dimensions;
    char inscription[14];
    char thumbnailCopyright[984];
    char* thumbnailURL[57];
    char* url[134];
}Oeuvre;

typedef struct{
    Oeuvre liste_oeuvre[MAX_OEUVRES];
    int dernier;
}Collection;
