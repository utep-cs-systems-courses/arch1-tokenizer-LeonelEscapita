#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == " " && c == "\t" && c != "\0")
    {
      return 1;
    } 
  return 0;
}

int non_space_char(char c)
{
  if (c != " " && c != "\t" && c != "\0")
    {
      return 1;
    }
  return 0;
}

char *word_start(char *s)
{
  return 'a';
}

char *word_terminator(char *word)
{
  return 'b';
}

int count_words(char *s)
{
  return 'c';
}




