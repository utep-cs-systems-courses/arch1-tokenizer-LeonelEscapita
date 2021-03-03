#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int space_char(char c)
{
  //  printf("At space_char %c",c);
  //  printf("\n");
  if ((c == ' ' || c == '\t') && c != '\0') { //checks if character is a space
      return 1;
    } 
  return 0;
}

int non_space_char(char c)
{
  //printf("At non_space_char %c",c);
  //printf("\n");
  if (c != ' ' && c != '\t' && c != '\0') { //checks if character is not a space
      return 1;
    }
  return 0;
}

char *word_start(char *s) //moves sentence pointer to the next word
{
  while (1) {
    //printf("At word_start %c",*s);
    //printf("\n");
    if (space_char(*s) == 0) { 
        return s;
      }
    
    if (space_char(*s) == 1) {
        s++;
      }
    }
}

char *word_terminator(char *word) //moves sentence pointer to the ending of the word
{
  while (1) {
    //printf("At word_terminator %c",*word);
    //printf("\n");
    if (non_space_char(*word) == 0) {
        return word;
      }
    
    if (non_space_char(*word) == 1) {
        word++;
      }
    }
}

int count_words(char *s) //counts the amount of words in the sentence using the sentence pointer
{
  int count = 0;
  
  while (*s) { //while the sentence pointer is not at the end

    //printf("%s", s);
    
    s = word_start(s); //sentence pointer moves to the front of word
      
      if (*s == '\0') {
	//printf("returned over here");
	//printf("\n");
	  return count;
	}
 
      s = word_terminator(s); //sentence pointer moves to the end of word
      count++; //add to the count of words
      //printf("%d", count);
      //printf("\n");
     
    }
  return count;
  
}

char *copy_str(char *inStr, short len)
{
  char *copy = malloc((len + 1) * sizeof(char)); //allocates memory for pointer array for char

  //len + 1 for 0 to len index
  
  for (int i = 0; i < len; i++) {
    copy[i] = inStr[i]; //passes the chars from string passed to copy
    }

  copy[len] = '\0'; //len being the last allocation of the memory stores the ending '\0'
  return copy;
}

char **tokenize(char* str)
{
  int word_count = count_words(str); //counts words
  char **token_ptr = malloc((word_count + 1) * sizeof(char*));//makes memrory alloction for the pointer of pointers token_ptr of the number of words + 1 to compensate for the 0th index

  //printf("word count: %d", word_count);
  //printf("\n");

  
  for (int i = 0; i < word_count; i++) { //goes through the number of words and copies each of the words and saves them onto the array of token_ptr, a pointer of pointers
    if (str[0] == ' ') {
      str = word_start(str); //find the first word and start there
    }
    int len = word_terminator(str) - word_start(str); //length of the word
    //printf("str is %s\n", str);
    token_ptr[i] = copy_str(str,len); //token_ptr at index i will point to pointers pointing toeach character in the word, which is divided by the len
    //printf("%s\n", token_ptr[i]);
    str = word_start(word_terminator(str));//moves onto the next word by moving to a space then to the next word
  }
  token_ptr[word_count] = 0; //initializes the end of the array
  return token_ptr;
  
}

void free_tokens(char **tokens)
{
  char **copy_tokens = tokens; //keeps a copy of the first allocation being pointed to
  while (*tokens) { //clears up all of the copy[] memory allocation inside of tokens 
    free(*tokens);
    tokens++;
   }
  free(copy_tokens); //clears memory allocated of tokens itself through the copy
}

void print_tokens(char **tokens)
{
  while (*tokens) { //while *tokens is pointing to a word, print that word
    printf("%s\n",*tokens);
    tokens++; //points to next word, remember **tokens points to the individual char
   }
 }



