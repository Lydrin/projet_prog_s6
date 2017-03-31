CC = gcc
CLAGS = 
LDFLAGS = -lSDL
EXEC = test
SRC = $(wildcard *.c) #définit la liste des .o du dossier
OBJ = $(SRC:.c=.o) #définit la liste des .o grâce aux .c dans le dossier

all : $(EXEC)

test: $(OBJ)
	$(CC) -o $@ $^ $(LDFLAGS) 

%.o: %.c   #de base va toujours construire un .o avec sa première dépendance .c
	$(CC) -o $@ -c $< $(CFLAGS)

clean:
	rm -rf *.o

cleanall: clean
	rm -rf $(EXEC)
	rm pics/A00*
