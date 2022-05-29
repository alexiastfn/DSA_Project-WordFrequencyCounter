/*STEFAN Alexia - 312CB*/
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

#ifndef _WORD_LIST_
#define _WORD_LIST_

struct wordList {
  int n;
  char *word;
  struct wordList *next;
};

int compareWords(struct wordList *w1, struct wordList *w2);
void addWord(struct wordList **first, char *word);
void printWord(struct wordList *first);
int countWordMax(struct wordList *first, int wCounter);
void printWordMax(struct wordList *first, int lenght);
void deleteWords(struct wordList *first);

#endif
