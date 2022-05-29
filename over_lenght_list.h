/*STEFAN Alexia - 312CB*/
#include "word_list.h"

#ifndef _LEN_LIST_
#define _LEN_LIST_

struct overLenghtList {
  int lenght;
  struct wordList *p;
  struct overLenghtList *next;
};

int compareLenghts(struct overLenghtList *l1, struct overLenghtList *l2);
void addLengh(struct overLenghtList **first, char *word);
void printLenghts(struct overLenghtList *first);
void printLenghtsLen(struct overLenghtList *first, int lenght);
int countLenghtsMax(struct overLenghtList *first, int wCounter);
void printLenghtsMax(struct overLenghtList *first, int wCounter);
void deleteLenghts(struct overLenghtList *first);

#endif
