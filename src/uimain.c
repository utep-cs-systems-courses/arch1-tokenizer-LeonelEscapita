#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char sentence[100];
  char c;
  int id;
  List *list = init_history();
  while (1)
    {
      printf("Enter String or Enter Command(!h[all history], !q[quit], !#[show item from id]) $");
      fgets(sentence, 100, stdin);
      //getchar(); //catch new line
      char *s = sentence;
      //printf("%c",*s);
      if (*s == '!') {
	//printf("inside '!' \n");
        s++;
	if (*s == 'q') {
          free_history(list);
	  printf("good-bye!\n");
	  goto done;
	}
	if (*s == 'h') {
          print_history(list);
	}
	else {
          id = *s - 48;
	  //printf("%d\n", id);
	  char *t = get_history(list, id);
	  if (t != 0) {
	     char **r = tokenize(get_history(list, id));
	     print_tokens(r);
	     free_tokens(r);
	  }
	  //getchar();
	}
      }
      else {
        add_history(list, sentence);
	char **d = tokenize(sentence); //saves **d with double pointer returned by tokenize
        print_tokens(d); //prints the list of words that were tokenized
        free_tokens(d); //frees all allocated memory used for the tokens
	//getchar();
      }   
    }
 done:
  return 0;
}
