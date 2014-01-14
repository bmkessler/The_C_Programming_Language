# include <stdio.h>
# include <ctype.h>
# include "calc.h"

/* getop: get next operator or numeric operand */
int getop( char s[])
{
  int i, c;

  while ((s[0] = c = getch()) == ' ' || c == '\t')
    ;  /* skip white space and tabs */
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c;  /* not a number */
  i = 0;
  if (isdigit(c))  /* collect integer part */
    while ( isdigit(s[++i] = c = getch()))
      ;
  if (c =='.')  /* collect fraction part */
    while ( isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  /*if (c != EOF)  not sure why the text says EOF is not handled appropriately, it seems fine to me */
    ungetch(c);
  return NUMBER;
}