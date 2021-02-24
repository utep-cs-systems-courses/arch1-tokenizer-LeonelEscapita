#include <stdio.h>
#include <stdlib.h>
#include "history.h"

List* init_history()
{
  List *list = malloc(sizeof(List));
  return list;
}

void add_history(List *list, char *str)
{
  if ((*list).root == NULL) {
    Item *item = malloc(sizeof(Item));
    (*item).id = 0;
    (*item).str = *str;
  }
  printf("Add history works");
}

char *get_history(List *list, int id)
{
  char *p;
  return p;
}

void print_history(List *list)
{
  printf("History goes here");
}

//void free_history(List *list)
//{
//free(list);
//}
