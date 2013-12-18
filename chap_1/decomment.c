# include <stdio.h>

main()
{

int lastc, c, instring, incomment;
incomment = 0; /* can't be in a comment at the start */
lastc = getchar();
instring = 0; /* strings can't legally start a file? */

while((c=getchar())!=EOF) {

  if(incomment) {
  /* check for end of comment */
    if( lastc == '*' && c == '/' ) {
      incomment = 0;
      c='\0';  /* print a null character at the end of comments */
    }
  } else {
  /* check for start of comment if not in string */
    if(lastc == '/' && c == '*' && !instring)
        incomment = 1;
    else {
      if(instring) {
    /* check for end of string  if in string */
        if( c == '"' && lastc!='\\')  /* unescaped quotes end a string  */
          instring = 0;
      } else {
    /* check if start of string otherwise */
        if(c=='"'&& lastc != '\'')  /* quotes not proceeded by ' always start a string? */
          instring = 1;
      }
  /* else print the character when not in comment */
      putchar(lastc);
    }
  }
  lastc = c;
}
return 0;

}