#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char sentence[100];
  int q;
  while(1)
    {
      printf("enter your string $");
      fgets(sentence, 100, stdin);
      printf("%s", sentence); //gets sentence

       //count_words(sentence);
      char **d = tokenize(sentence); //saves **d with double pointer returned by tokenize
      print_tokens(d); //prints the list of words that were tokenized
      free_tokens(d); //frees all allocated memory used for the tokens

      //printf("%s\n",*d);
      
      printf("quit? 1 for yes, 0 for no");
      scanf("%d", q);
      switch(q){
      case 1:
	printf("good-bye! \n");
	goto done;
      case 0:
	break;
      default:
	printf("printed something wrong");
	goto done;
      }
        
    }
 done:
  return 0;
  
}
