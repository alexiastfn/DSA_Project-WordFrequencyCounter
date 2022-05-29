/*STEFAN Alexia - 312CB*/
#include "tabela_hash.h"

int getWordIndex(char word) {
  if (word >= 'a')
    return (int)(word - 'a');
  else if (word >= 'A')
    return (int)(word - 'A');
  else
    return -1;
}

void initHash(struct tabelaHash *hash) {
  hash->dim = (int)(('Z' - 'A') + 1);
  hash->vect = NULL;
  hash->vect = malloc(hash->dim * sizeof(struct overLenghtList *));
  int i;
  for (i = 0; i < hash->dim; i++)
    hash->vect[i] = NULL;
}

void deleteHash(struct tabelaHash *hash) {
  int i;
  for (i = 0; i < hash->dim; i++)
    deleteLenghts(hash->vect[i]);
  free(hash->vect);
}

void insertWordInHash(struct tabelaHash *hash, char *word) {
  int index = getWordIndex(word[0]);
  if (index != -1 && strlen(word) >= 3)
    addLengh(&(hash->vect[index]), word);
}

void printHash(struct tabelaHash *hash) {
  int i;
  for (i = 0; i < hash->dim; i++)
    if (hash->vect[i] != NULL) {
      printf("pos %d: ", i);
      printLenghts(hash->vect[i]);
      printf("\n");
    }
}

void printHashCharLen(struct tabelaHash *hash, char c, int lenght) {
  int index = getWordIndex(c);
  if (hash->vect[index] != NULL) {
    printLenghtsLen(hash->vect[index], lenght);
  }
}

void printHashMax(struct tabelaHash *hash, int lenght) {
  int i;
  for (i = 0; i < hash->dim; i++)
    if (hash->vect[i] != NULL) {
      if (countLenghtsMax(hash->vect[i], lenght) > 0) {
        printf("pos%d: ", i);
        printLenghtsMax(hash->vect[i], lenght);
        printf("\n");
      }
    }
}
