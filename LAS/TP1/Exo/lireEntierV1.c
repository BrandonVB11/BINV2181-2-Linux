#include <stdio.h>
#include <stdlib.h>

int main() {
  FILE *fichier = fopen("entier.txt", "r");

    if (fichier == NULL) {
        printf("Erreur lors de l'ouverture du fichier\n");
        return -1;
    }

   
    for (int i = 0; i <= 10000000; i++) {
        fwrite(&i, sizeof(int), 1, fichier);
    }

    fclose(fichier);

    return 0;
}