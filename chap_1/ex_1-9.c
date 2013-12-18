#include <stdio.h>

/*  copies stdin to stdout replacing repeated spaces with one space */

main() {
   int c,lastc;
   lastc='a'; /* any character that is not a space for iinitialization*/
   while((c=getchar())!=EOF) {
      if(c!=' ' || lastc !=' ')
	     putchar(c);
	  lastc = c;
   }
}