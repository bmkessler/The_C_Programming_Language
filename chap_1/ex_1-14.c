# include <stdio.h>

# define IN 1
# define OUT 0
# define MAXCHAR 256

main()
{
  int i, j, c, wl, state, maxcount;
  int whist[MAXCHAR];
  state = OUT;
  wl = 0;
  
  for(i=0;i<MAXCHAR;i++)
    whist[i]=0;
  
  while((c=getchar())!=EOF) {
    whist[c]++;
  }
  
  maxcount = 0;
  for(i =1; i< MAXCHAR; i++) {
    if(whist[i]>maxcount)
	  maxcount = whist[i];
  }
  
  for( j=maxcount; j>0; j--) {
  
    for( i = 1 ; i<MAXCHAR; i++) {
	   if( whist[i] >= j)
	     putchar('*');
	   else
	     putchar(' ');
    }
	putchar('\n');
  }
  
  for( i = 1 ; i<MAXCHAR; i++) { 
	    if(i=='\n'|| i=='\t' || i== '\b' || i=='\v' || i=='\r' || i=='\f' || i=='\a')
		  putchar(' ');
		else
		  putchar(i);
  }
  putchar('\n');
}