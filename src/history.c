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

void add_history(List *list, char *str)
{
  printf("history works");

}
