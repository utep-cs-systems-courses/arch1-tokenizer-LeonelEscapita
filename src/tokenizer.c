#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  if (c == ' ' && c == '\t' && c != '\0')
    {
      return 1;
    } 
  return 0;
}

int non_space_char(char c)
{
  if (c != ' ' && c != '\t' && c != '\0')
    {
      return 1;
    }
  return 0;
}

char *word_start(char *s)//pointer to a specific char in the sentence, keep going until you find a new word!!!!
{
  while (1)
    {  
    if (space_char(*s) == 0)
      {
        return s;
      }
    if (space_char(*s) == 1)
      {
        s++;
      }
    }
}

char *word_terminator(char *word)
{
  while (1)
    {
    if (non_space_char(*word) == 0)
      {
        return word;
      }
    if (non_space_char(*word) == 1)
      {
        word++;
      }
    }
}

int count_words(char *s)
{
  int count = 0;
  while (1)
    {
      if (*s == '\0')
	{
	  return count;
	}
      s = *word_start(s);
      if (*s == '\0')
	{
	  return count;
	}
      s = *word_terminator(s);
      count++;
    }
}




