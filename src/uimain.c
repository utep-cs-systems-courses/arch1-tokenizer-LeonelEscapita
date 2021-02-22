#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char sentence[100];
  char q;
  while(1)
    {
      printf("enter your string $");
      fgets(sentence, 100, stdin);
      printf("%s", sentence);

       count_words(sentence);
       // char **d = tokenize(sentence);
       // print_tokens(d);
      
      printf("quit? 1 for yes, 0 for no ");
      q = getchar();
      switch(q){
      case '1':
	printf("good-bye! \n");
	goto done;
      case '0':
	break;
      default:
	printf("printed something wrong");
	goto done;
      }
        
    }
 done:
  return 0;
  
}
