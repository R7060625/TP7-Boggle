# ============================================================
#  Makefile — Boggle
# ============================================================

CC      = clang
CFLAGS  = -Wall -Wextra -g -std=c17
TARGET  = programme

# Tous les fichiers objets nécessaires
OBJ     = main.o \
          Dictionnaire.o \
          Graphique.o \
          Grille.o \


# ------------------------------------------------------------
# Cible principale : édition des liens
# ------------------------------------------------------------
$(TARGET): $(OBJ)
	$(CC) $(CFLAGS) $(OBJ) -o $(TARGET)

# ------------------------------------------------------------
# Compilation des fichiers objets avec leurs dépendances
# ------------------------------------------------------------

main.o: main.c Dictionnaire.h Graphique.h Grille.h 
	$(CC) $(CFLAGS) -c main.c -o main.o

Dictionnaire.o: Dictionnaire.c Dictionnaire.h
	$(CC) $(CFLAGS) -c Dictionnaire.c -o Dictionnaire.o

Graphique.o: Graphique.c Graphique.h
	$(CC) $(CFLAGS) -c Graphique.c -o Graphique.o

Grille.o: Grille.c Grille.h
	$(CC) $(CFLAGS) -c Grille.c -o Grille.o


# ------------------------------------------------------------
# Cibles utilitaires
# ------------------------------------------------------------

# Supprime les fichiers objets et l'exécutable
clean:
	rm -f $(OBJ) $(TARGET)

# Force une recompilation totale
re: clean $(TARGET)

# Ces cibles ne correspondent pas à des fichiers
.PHONY: clean re