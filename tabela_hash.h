/*STEFAN Alexia - 312CB*/
#include "over_lenght_list.h"

#ifndef _HASH_TABLE_
#define _HASH_TABLE_

struct tabelaHash {
  int dim;
  struct overLenghtList **vect;
};

int getWordIndex(char word);
void initHash(struct tabelaHash *hash);
void deleteHash(struct tabelaHash *hash);
void insertWordInHash(struct tabelaHash *hash, char *word);
void printHash(struct tabelaHash *hash);
void printHashCharLen(struct tabelaHash *hash, char c, int lenght);
void printHashMax(struct tabelaHash *hash, int lenght);

#endif
