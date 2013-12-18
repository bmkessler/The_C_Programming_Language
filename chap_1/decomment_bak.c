# include <stdio.h>

main()
{

int lastc, c, incomment;
incomment = 0;
lastc = getchar();
while((c=getchar())!=EOF) {

  /* check for start of comment */
  if(lastc == '/' && c == '*' )
    incomment = 1;


  if(incomment) {
  /* check for end of comment */
    if( lastc == '*' && c == '/' ) {
      incomment = 0;
      c = '\0';  /* print a null character at the end of comments */
    }
  } else {
  /* else just print the character */
     putchar(lastc);
  }
  lastc = c;
}
return 0;

}