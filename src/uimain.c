#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"
#include "history.h"

int main()
{
  char sentence[100];
  char c = '0';
  int id;
  List *list = init_history();
  while (1)
    {
      printf("Enter Command $");
      fgets(sentence, 100, stdin);
      commands(sentence);//get rid of use case!
      printf('%c',c);
      getchar(); //catch new line
      switch (c){
      case '2':
	//free_history();
	printf("good-bye!\n");
	goto done;
      case '0':
        add_history(list, sentence);
	char **d = tokenize(sentence); //saves **d with double pointer returned by tokenize
        print_tokens(d); //prints the list of words that were tokenized
        free_tokens(d); //frees all allocated memory used for the tokens
	getchar();
	print_history(list);
	break;
      case '1':
	*sentence = sentence[1];
	id = (int)(*sentence);
	char *t = get_history(list, id);
	if (t != 0) {
	   char **r = tokenize(get_history(list, id));
	   print_tokens(r);
	   free_tokens(r);
	}
	getchar();
	break;
      case '3':
	print_history(list);
      default:
	printf("printed something wrong\n");
	goto done;
      }
        
    }
 done:
  return 0;
  
}
