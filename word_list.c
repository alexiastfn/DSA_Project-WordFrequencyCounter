/*STEFAN Alexia - 312CB*/
#include <ctype.h>
#include <stdarg.h>
#include <stdio.h>
#include <stdlib.h>
#include <string.h>

struct wordList {
  int n;
  char *word;
  struct wordList *next;
};

int compareWords(struct wordList *w1, struct wordList *w2) {
  if (w1 == NULL)
    return -1;
  if (w2 == NULL)
    return 1;

  if (w1->n > w2->n)
    return 1;
  else if (w1->n < w2->n)
    return -1;
  else
    return (strcmp(w2->word, w1->word));
}

void addWord(struct wordList **first, char *word) {
  struct wordList *iter = (*first);
  struct wordList *work_item = NULL;

  // verifica daca deja exista si incrementeaza contor in acest caz
  while (iter != NULL) {
    if (strcmp(iter->word, word) == 0) {
      iter->n++;
      work_item = iter;
      break;
    }
    iter = iter->next;
  }

  iter = (*first);
  // daca nu exista il adauga la inceput
  if (work_item == NULL) {
    work_item = malloc(sizeof(struct wordList));
    work_item->n = 1;
    work_item->word = malloc(sizeof(char) * (strlen(word) + 1));
    strcpy(work_item->word, word);
    work_item->next = NULL;
  } else {
    // extrage nod din lista
    if (iter == work_item) {
      iter = iter->next;
      (*first) = iter;
    } else {
      while (iter->next != NULL) {
        if (iter->next == work_item) {
          iter->next = iter->next->next;
          break;
        }
        iter = iter->next;
      }
    }
  }

  // plaseaza pe pozitia corecta
  iter = (*first);
  if (iter == NULL) {
    work_item->next = iter;
    iter = work_item;
    (*first) = iter;
  } else {
    if (compareWords(iter, work_item) < 0) {
      work_item->next = iter;
      (*first) = work_item;
      return;
    }

    while (compareWords(iter->next, work_item) > 0)
      iter = iter->next;
    work_item->next = iter->next;
    iter->next = work_item;
  }
}

void printWord(struct wordList *first) {
  while (first != NULL) {
    printf("%s/%d", first->word, first->n);
    if (first->next != NULL)
      printf(", ");
    first = first->next;
  }
}

int countWordMax(struct wordList *first, int wCounter) {
  int counter = 0;
  while (first != NULL) {
    if (first->n <= wCounter) {
      counter++;
    }
    first = first->next;
  }
  return counter;
}

void printWordMax(struct wordList *first, int lenght) {
  while (first != NULL) {
    if (first->n <= lenght) {
      printf("%s/%d", first->word, first->n);
      if (first->next != NULL)
        printf(", ");
    }
    first = first->next;
  }
}

void deleteWords(struct wordList *first) {
  while (first != NULL) {
    struct wordList *aux = first->next;
    free(first->word);
    free(first);
    first = aux;
  }
}
