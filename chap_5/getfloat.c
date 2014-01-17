#include <ctype.h>
# include <stdio.h>

int getch(void);
void ungetch(int);

/* getfloat: get the next float from input into *pn */
int getfloat(double *pn)
{
  int c, sign, exp, i;
  double power, emult;
  
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
  for(*pn = 0.0; isdigit(c); c = getch())
    *pn = 10.0 * *pn + (c-'0');
  
  if(c == '.')  /* fractional part */
    c = getch();
  else {
    ungetch(c);
    return c;
  }

  for(power = 1.0; isdigit(c); c = getch() ) {
    *pn = 10.0 * *pn + (c - '0');
    power /= 10.0;
  }
  if(c == 'e') {
    emult = ((c = getch()) == '-') ? 0.10 : 10.0;
    if(c == '+' || c == '-')
      c = getch();
    for (exp = 0; isdigit(c); c = getch())
      exp = 10 * exp + (c - '0');
    for(i=0;i<exp;i++)
      power *= emult;
    }
  *pn *= sign * power;
  if(c != EOF)
    ungetch(c);
  return c;
}

# define SIZE 100

main()  /* test loop */
{
  int n, getfloat(double *);
  double array[SIZE];
  
  for(n = 0; n < SIZE && getfloat(&array[n]) != EOF; n++)
    ;
  
  printf("\nThe array now holds:\n");
  int i;
  for(i=0;i <= n; i++)
    printf("%g\n",array[i]);
  
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