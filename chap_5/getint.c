#include <ctype.h>
# include <stdio.h>

int getch(void);
void ungetch(int);

/* getint: get the next integer from input into *pn */
int getint(int *pn)
{
  int c, sign;
  
  while(isspace(c = getch())) /* skip white space */
    ;
  if(!isdigit(c) && c != EOF && c != '+' && c != '-') {
    ungetch(c);  /* it's not a number */
    return 0;
  }
  sign = (c == '-') ? -1 : 1;
  if( c == '+' || c =='-' )
    if(!isdigit( c = getch()) ) {
      ungetch(c);  /* plus/minus without number is not a number */
      return 0;
    }
  for(*pn = 0; isdigit(c); c = getch())
    *pn = 10 * *pn + (c - '0');
  *pn *= sign;
  if(c != EOF)
    ungetch(c);
  return c;
}

# define SIZE 100

main()  /* test loop */
{
  int n, array[SIZE], getint(int *);
  
  for(n = 0; n < SIZE && getint(&array[n]) != EOF; n++)
    ;
  
  printf("\nThe array now holds:\n");
  int i;
  for(i=0;i <= n; i++)
    printf("%d\n",array[i]);
  
}

# define BUFSIZE 100

static char buf[BUFSIZE];  /* buffer for ungetch */
static int bufp = 0;       /* next free position in buf */

int getch(void) /* get a (possibly pushed back) character */
{
  return (bufp > 0) ? buf[--bufp] : getchar();
}

void ungetch(int c)  /* push back character on input */
{
  if( bufp >= BUFSIZE)
    printf("ungetch: too many characters\n");
  else
    buf[bufp++] = c;
}