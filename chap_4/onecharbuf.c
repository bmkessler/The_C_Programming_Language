char buf;  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp) ? --bufp, buf : getchar();
}

void ungetch(int c)  /* push back character on input */
{
  if( bufp )
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}