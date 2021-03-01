#include <stdio.h>
#include <stdlib.h>
#include "history.h"
#include "tokenizer.h"

int find_len(char *str)
{
  int len = 0;
  while (*str) {
      len++;
      str++;
  }
  return len;
}

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
    char *str2 = copy_str(str, find_len(str));
    (*item).str = str2;
    list->root = item;
    //printf("inside");
  }
  else {
    int current_id = 1;
    Item *temp_item = list->root;
    while (temp_item->next) {
      current_id++;
      temp_item = temp_item->next;
      }
    Item *item = malloc(sizeof(Item));
    (*item).id = current_id;
    char *str2 = copy_str(str, find_len(str));
    (*item).str = str2;
    (*item).next = 0;
    temp_item->next = item;
  }
  printf("Add history works\n");
}

char *get_history(List *list, int id)
{
  Item *temp_item = list->root;
  while (temp_item) {
    printf("inside node%d\n", temp_item->id);
    if (id == temp_item->id) {
      char *str2 = temp_item->str; 
      printf("Given the ID, the string is %s\n", str2);
      return str2;
    }
    temp_item = temp_item->next;
  }
  return 0;
}

void print_history(List *list)
{
  printf("printing..\n");
  Item *temp_item = list->root;
  while (temp_item) {
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
