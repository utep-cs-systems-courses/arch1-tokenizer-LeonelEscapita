#include <stdio.h>
#include <stdlib.h>
#include "tokenizer.h"

int main()
{
  char sentence[100];
  int q;
  while (1)
    {
      printf("enter your string $ ");
      scanf("%s", sentence);
      printf(" ");
      
      printf("quit? 1 for yes, 0 for no ");
      scanf("%d", &q);
      switch(q){
      case 1:
	printf("good-bye!");
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
