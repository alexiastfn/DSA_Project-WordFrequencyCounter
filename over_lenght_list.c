/*STEFAN Alexia - 312CB*/
#include "over_lenght_list.h"

int compareLenghts(struct overLenghtList *l1, struct overLenghtList *l2) {
  if (l1 == NULL)
    return -1;
  if (l2 == NULL)
    return 1;

  if (l1->lenght < l2->lenght)
    return 1;
  else
    return -1;
}

void addLengh(struct overLenghtList **first, char *word) {
  int lenght = strlen(word);
  struct overLenghtList *iter = (*first);
  struct overLenghtList *work_item = NULL;

  // verifica daca deja exista si incrementeaza contor in acest caz
  while (iter != NULL) {
    if (iter->lenght == lenght) {
      work_item = iter;
      break;
    }
    iter = iter->next;
  }

  iter = (*first);
  if (work_item == NULL) {
    work_item = malloc(sizeof(struct wordList));
    work_item->lenght = lenght;
    work_item->p = NULL;
    work_item->next = NULL;

    if (iter == NULL) {
      iter = work_item;
      (*first) = iter;
    } else {
      if (compareLenghts(iter, work_item) < 0) {
        work_item->next = iter;
        (*first) = work_item;
      } else {
        while (compareLenghts(iter->next, work_item) > 0)
          iter = iter->next;
        work_item->next = iter->next;
        iter->next = work_item;
      }
    }
  }
  addWord(&work_item->p, word);
}

void printLenghts(struct overLenghtList *first) {
  while (first != NULL) {
    printf("(%d:", first->lenght);
    printWord(first->p);
    printf(")");
    first = first->next;
  }
}

void printLenghtsLen(struct overLenghtList *first, int lenght) {
  int printed = 0;
  while (first != NULL) {
    if (first->lenght == lenght) {
      printf("(%d:", first->lenght);
      printWord(first->p);
      printf(")");
      printed++;
    }
    first = first->next;
  }
  if (printed > 0)
    printf("\n");
}

int countLenghtsMax(struct overLenghtList *first, int wCounter) {
  int counter = 0;
  while (first != NULL) {
    if (countWordMax(first->p, wCounter) > 0)
      counter++;
    first = first->next;
  }
  return counter;
}

void printLenghtsMax(struct overLenghtList *first, int wCounter) {
  while (first != NULL) {
    if (countWordMax(first->p, wCounter) > 0) {
      printf("(%d: ", first->lenght);
      printWordMax(first->p, wCounter);
      printf(")");
    }
    first = first->next;
  }
}

void deleteLenghts(struct overLenghtList *first) {
  while (first != NULL) {
    struct overLenghtList *aux = first->next;
    deleteWords(first->p);
    free(first);
    first = aux;
  }
}
