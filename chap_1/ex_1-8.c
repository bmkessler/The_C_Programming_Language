# include <stdio.h>

/*  count blanks tabs and lines in input */

main() {
  int c, nl;
  nl = 0;
  while((c=getchar())!=EOF) {
    if(c==' ' || c == '\t' || c=='\n')
	  nl++;
  }
  printf("%d\n",nl);
}