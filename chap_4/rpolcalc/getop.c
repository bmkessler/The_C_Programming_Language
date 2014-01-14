# include <stdio.h>
# include <ctype.h>
# include "calc.h"

/* getop: get next operator or numeric operand */
int getop( char s[])
{
  int i;
  static int c = ' ';  /* initialize to white space for check */

  while ((s[0] = c ) == ' ' || c == '\t')
    c = getch();  /* skip white space and tabs assign in the loop for static implemetation */
  s[1] = '\0';
  if(!isdigit(c) && c != '.') {
    i = c;
    c = getch();
    return i;  /* not a number */
   }
  i = 0;
  if (isdigit(c))  /* collect integer part */
    while ( isdigit(s[++i] = c = getch()))
      ;
  if (c =='.')  /* collect fraction part */
    while ( isdigit(s[++i] = c = getch()))
      ;
  s[i] = '\0';
  /* note c will retain previous value on next call and skip initialization */
  return NUMBER;
}