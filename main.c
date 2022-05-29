/*STEFAN Alexia - 312CB*/
#include "tabela_hash.h"

int main(int argc, char *argv[]) {
  if (argc < 2) {
    return 0;
  }

  FILE *fisier = NULL;
  fisier = fopen(argv[1], "r");
  if (fisier == NULL) {
    return 0;
  }

  size_t len = 255;
  char *input = malloc(sizeof(char) * len);

  struct tabelaHash *tabela = malloc(sizeof(tabela));
  initHash(tabela);

  struct overLenghtList *cuv = NULL;

  while (getline(&input, &len, fisier) != -1) {
    char *c = NULL; //instructiunea
    c = strtok(input, " \n.,");
    if (c != NULL) {
      if (strcmp(c, "insert") == 0) {
        c = strtok(NULL, " \n.,");
        while (c != NULL) {
          insertWordInHash(tabela, c); //de unde se apeleaza addLenght
          c = strtok(NULL, " \n.,");
        }
      } else if (strcmp(c, "print") == 0) {
        c = strtok(NULL, " \n.,");
        if (c != NULL) {
          if (isdigit(c[0]) == 0) {
            char fLetter = c[0];
            c = strtok(NULL, " \n.,");
            int lenght = atoi(c);
            printHashCharLen(tabela, fLetter, lenght);
          } else

          {
            int lenght = atoi(c);
            printHashMax(tabela, lenght);
          }
        } else {
          printHash(tabela);
        }
      }
    }
  }

  deleteHash(tabela);
  free(tabela);
  free(input);
  fclose(fisier);
  return 0;
}
