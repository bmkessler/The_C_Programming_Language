#include <stdio.h>

# define MAXCHAR 255

main()
{
  int c;
  for(c=0; c<=MAXCHAR; c++){
    putchar(c);
	putchar('\n');
  }
}