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
  if (!list->root) {
    Item *item = malloc(sizeof(Item));
    (*item).id = 0;
    char *str2 = str;
    (*item).str = str2;
    list->root = item;
  }
  else {
    int current_id = 0;
    Item *temp_item = list->root;
    while (temp_item->next) {
      current_id++;
      temp_item = temp_item->next;
      }
    Item *item = malloc(sizeof(Item));
    (*item).id = current_id;
    char *str2 = str;
    (*item).str = str2;
    temp_item->next = item;
  }
  printf("Add history works");
}

char *get_history(List *list, int id)
{
  Item *temp_item = list->root;
  while (temp_item->next) {
    if (id == temp_item->id) {
      char *str2 = temp_item->str; 
      printf("Given the ID, the string is %s\n", str2);
    }
      temp_item = temp_item->next;
  }
}

void print_history(List *list)
{
  Item *temp_item = list->root;
  while (temp_item->next) {
    char *str2 = temp_item->str; 
    printf("%s\n", str2);
    temp_item = temp_item->next;
  }
}

void free_history(List *list)
{
  Item *temp_item = list->root;
  while (temp_item) {
    free(temp_item);
    temp_item = temp_item->next;
  }
  free(list);
}
