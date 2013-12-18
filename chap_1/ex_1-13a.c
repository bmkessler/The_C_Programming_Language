# include <stdio.h>

# define IN 1
# define OUT 0
# define MAXWORD 50

main()
{
  int i, j, c, wl, state, maxcount;
  int whist[MAXWORD+1];
  state = OUT;
  wl = 0;
  
  for(i=0;i<=MAXWORD;i++)
    whist[i]=0;
  
  while((c=getchar())!=EOF) {
  if( c == ' ' || c == '\t' || c == '\n') {
    if( state == IN) {
	  state = OUT;
	  whist[wl]++;
	  wl = 0;
	}
  }
  else {
       if( state == OUT)
          state = IN;
	   wl++;
  }
  
  }
  
  maxcount = 0;
  for(i =1; i<= MAXWORD; i++) {
    if(whist[i]>maxcount)
	  maxcount = whist[i];
  }
  
  for( j=maxcount; j>0; j--) {
  
    for( i = 1 ; i<=MAXWORD; i++) {
	   if( whist[i] >= j)
	     putchar('*');
	   else
	     putchar(' ');
    }
	putchar('\n');
  }
}