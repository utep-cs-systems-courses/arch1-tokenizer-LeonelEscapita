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
      printf("Add to History(0), Retrieve from History(1), Quit(2) $");
      c = getchar();
      getchar(); //catch new line
      switch (c){
      case '2':
	//free_history();
	printf("good-bye!\n");
	goto done;
      case '0':
	printf("enter your string $");
        fgets(sentence, 100, stdin);
        printf("%s\n", sentence); //gets string
        add_history(list, sentence);
	char **d = tokenize(sentence); //saves **d with double pointer returned by tokenize
        print_tokens(d); //prints the list of words that were tokenized
        free_tokens(d); //frees all allocated memory used for the tokens
	getchar();
	break;
      case '1':
	printf("enter your id $");
	scanf("%d", &id);
	//char **r = tokenize(get_history(list, id));
	//print_tokens(r);
	//free_tokens(r);
	getchar();
	break;
      default:
	printf("printed something wrong\n");
	goto done;
      }
        
    }
 done:
  return 0;
  
}
