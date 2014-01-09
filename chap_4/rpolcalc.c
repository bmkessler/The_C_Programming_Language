#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>  /* for math functions sin, cos, etc. */

#define MAXOP    100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
# define NUMVAR 26  /* the number of variables allowed currently all lowercase letters */

int getop( char []);
void push(double);
double pop(void);
void printop(void);
void dup(void);
void swap(void);
void clearstack(void);

/* reverse Polish calculator */
main()
{
  int type;
  double op2;
  char s[MAXOP];
  double var[NUMVAR];  /* note the variables are not initialized */
  
  while ((type = getop(s)) != EOF) {
    switch (type) {
    case NUMBER:
      push(atof(s));
      break;
    case '+':
      push(pop() + pop());
      break;
    case '*':
      push(pop() * pop());
      break;
    case '-':
      op2 = pop();
      push(pop() - op2);
      break;
    case '/':
      op2 = pop();
      push(pop() / op2);
      break;
    case '%':
      op2 = pop();
      push(pop() / op2);
      break;
    case 'n':  /* unary negation */
      push(-1.0*pop());
      break;
    case 's':  /* sin function */
      push(sin(pop()));
      break;
    case 'c':  /* cos function */
      push(cos(pop()));
      break;
    case 't':  /* tan function */
      push(tan(pop()));
      break;
    case 'l':  /* log function */
      push(log(pop()));
      break;
    case 'e':  /* exp function */
      push(exp(pop()));
      break;
    case 'p':  /* pow function */
      op2 = pop();
      push(pow(pop(),op2));
      break;
    case '=':  /* assign the top of the stack to the following variable, ie. 2 = e */
      type = getop(s);  /* get the next op which should be a variable, need error catching if not */
      if( type >= 'a'  && type <= 'z') {
        var[type-'a'] = pop();
        push(var[type-'a']);
      } else
        printf("variables must be between a-z\n");
      break;
    case '\n':
      printf("\t%.8g\n",pop());
      break;
    default:  /* catch variable usage here */
      if( type >= 'a'  && type <= 'z')  /* push the variable onto the stack */
        push( var[type-'a'] );
      else
        printf("error: unknown command %s\n", s); /* if not above or a variable */
      break;
    }
  }
  return 0;
}

#define MAXVAL 100  /* the maximum depth of the val stack */

int sp = 0;         /* the next free stack position */
double val[MAXVAL];  /* value stack */

/* push: push f onto value stack */
void push(double f)
{
  if(sp < MAXVAL)
    val[sp++] = f;
  else
    printf("error: stack full, can't push %g\n",f);
}

/* pop: pop and return top value from stack */
double pop(void)
{
  if(sp > 0)
    return val[--sp];
  else {
    printf("error: stack empty\n");
    return 0.0;
  }
}

/* printop: print the top value from the stack without popping it */
void printop(void)
{
  if(sp > 0)
    printf("\t%.8g\n", val[sp-1]);
  else
    printf("error: stack empty\n");
}

/* dup: duplicate the top element of the stack */
void dup(void)
{
  double tmp;
  
  if(sp > 0) {
    tmp = val[sp-1];
    val[sp++] = tmp;
  } else
    printf("error: stack empty\n");
}

/* swap: swap the top two elements in the stack */
void swap(void)
{
  double tmp;
  
  if(sp > 1) {
    tmp = val[sp-1];
    val[sp-1] = val[sp-2];
    val[sp-2] = tmp;
  } else
    printf("error: stack does not have at least two elements\n");
}

/* clearstack:  clears the stack by reseting the stack pointer */
void clearstack(void)
{
  sp = 0;
}

#include <ctype.h>

int getch(void);
void ungetch(int);

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
  if (c != EOF)
    ungetch(c);
  return NUMBER;
}

# define BUFSIZE 100

char buf[BUFSIZE];  /* buffer for ungetch */
int bufp = 0;       /* next free position in buf */

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