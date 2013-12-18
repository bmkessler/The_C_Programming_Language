# include <stdio.h>

# define IN 1
# define OUT 0

/* unix utility wc */

main()
{
  int c, state;
  
  state = OUT;
  while((c = getchar())!=EOF){
	if(c == ' ' || c == '\n' || c == '\t') {
	  state = OUT;
	  c = '\0';
	}
	else if ( state == OUT ) {
	  state = IN;
	  putchar('\n');
	}
	putchar(c);
  }
  putchar('\n');
}

