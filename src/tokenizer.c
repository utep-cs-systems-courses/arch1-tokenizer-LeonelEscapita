#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  printf("At space_char %c",c);
  printf("\n");
  if (c == ' ' && c == '\t' && c != '\0') {
      return 1;
    } 
  return 0;
}

int non_space_char(char c)
{
  printf("At non_space_char %c",c);
  printf("\n");
  if (c != ' ' && c != '\t' && c != '\0') {
      return 1;
    }
  return 0;
}

char *word_start(char *s)
{
  while (1) {
    printf("At word_start %c",*s);
    printf("\n");
    if (space_char(*s) == 0) {
        return s;
      }
    
    if (space_char(*s) == 1) {
        s++;
      }
    }
}

char *word_terminator(char *word)
{
  while (1) {
    printf("At word_terminator %c",*word);
    printf("\n");
    if (non_space_char(*word) == 0) {
        return word;
      }
    
    if (non_space_char(*word) == 1) {
        word++;
      }
    }
}

int count_words(char *s)
{
  int count = 0;
  
  while (*s) {

      printf("%s", s);
    
      s = word_start(s);
      
      if (*s == '\0') {
	  printf("returned over here");
	  printf("\n");
	  return count;
	}
 
      s = word_terminator(s);
      count++;
      printf("%d", count);
      printf("\n");
     
    }
  return count;
  
}

char *copy_str(char *inStr, short len)
{
  char *copy = malloc((len + 1) * sizeof(char));
  
  for (int i = 0; i < len; i++) {
      copy[i] = inStr[i];
    }

  copy[len] = '\0';
  return copy;
}

char **tokenize(char* str)
{
  int word_count = count_words(str);
  char **token_ptr = malloc((word_count + 1) * sizeof(char*));

  printf("word count: %d", word_count);
  printf("\n");

  
  for (int i = 0; i < word_count; i++) {
    if (str[0] = ' ') {
      str = word_start(str);
    }
    int len = word_terminator(str) - word_start(str);
    token_ptr[i] = copy_str(str,len);
    str = word_start(word_terminator(str));
  } 
  return token_ptr;
  
}

void free_tokens(char **tokens)
{
 while(**tokens != '\0') {
    free(*tokens);
    tokens++;
   }
}

void print_tokens(char **tokens)
{
  while(**tokens != '\0') {
    printf(*tokens);
    tokens++;
   }
 }



