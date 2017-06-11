import csv
import sys
from math import *

def asciis(word):
    h=0
    for i in range(len(word)):
        h+=ord(word[i])
    return h

def hashage(ID, table_size):
    return(ID%table_size)

def add_dict(ID, table_size):
    if(hashage(ID,table_size) not in dict_hash.keys()):
        dict_hash[hashage(ID,table_size)]=[ID]
    else:
        dict_hash[hashage(ID, table_size)].append(ID)

def moyenne(dict_hash, table_size):
    somme = 0
    for e in dict_hash:
        somme += len(dict_hash[e])
    somme /= table_size 
    return somme

def ecart_type(dict_hash, table_size):
    moy = moyenne(dict_hash, table_size)
    somme = 0
    for e in dict_hash:
        somme = pow(len(dict_hash[e]) - moy,2)
    somme /= table_size
    somme = sqrt(somme)
    return somme

fichier = open("stat.csv","a")
list_rows = []
set_artist = set()
if(len(sys.argv)>1):
    with open(sys.argv[1], mode = 'r') as file:
        reader = csv.DictReader(file)
        for row in reader:
            list_rows.append(row)
        for e in list_rows:
            set_artist.add(e['artistId'])
    for table_size in range(1,5000):
        dict_hash={}
        for e in set_artist:
            add_dict(e, table_size)
        print("------------------------------------")
        print("Table size = " + str(table_size))
        print("Moyenne des colisions = " + str(moyenne(dict_hash,table_size)))
        print("Ecart type des colisions = " + str(ecart_type(dict_hash,table_size)))
        fichier.write(str(table_size)+",")
        fichier.write(str(moyenne(dict_hash, table_size))+",")
        fichier.write(str(ecart_type(dict_hash, table_size))+"\n")
else:
    print("Ca marche quand même mieux avec le fichier, non ? ")
fichier.close()
