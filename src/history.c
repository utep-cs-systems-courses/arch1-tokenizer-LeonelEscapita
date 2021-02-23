#include <stdio.h>
#include <stdlib.h>
#include "history.h"

struct s_Item {
  int id;
  char *str;
  struct s_Item *next;
}

struct s_List {
  struct s_Item *root;
}

List* init_history()
{
  return 0;
  
}

void add_history(List *list, char *str)
{
  printf("history works");

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

void free_history(List *list)
{
  free(*list);
}
