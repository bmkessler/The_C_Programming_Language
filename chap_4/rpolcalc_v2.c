#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>  /* for math functions sin, cos, etc. */

#define MAXOP    100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
# define NUMVAR 26  /* the number of variables allowed currently all lowercase letters */
# define MAXLINE 1000 /*the maximum length of an input line  */

int getop( char [], char [] );
int getline(char [], int );
void push(double);
double pop(void);
void printop(void);
void dup(void);
void swap(void);
void clearstack(void);

int lp = 0;  /* the line pointer */

/* reverse Polish calculator using getline rather than getch, ungetch*/
main()
{
  int type;
  double op2;
  char s[MAXOP];
  double var[NUMVAR];  /* note the variables are not initialized */
  char line[MAXLINE];  /* the current input line  */
  
  while( getline(line,MAXLINE) > 0 ) {
  lp = 0;
  while ((type = getop(s,line)) != EOF && type ) {
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
      type = getop(s,line);  /* get the next op which should be a variable, need error catching if not */
      if( type >= 'a'  && type <= 'z') {
        var[type-'a'] = pop();
        push(var[type-'a']);
      } else
        printf("variables must be between a-z\n");
      break;
    case '\n': case '\0':  /* get line needs to handle end of string properly */
      printf("\t%.8g\n",pop());
      break;
    default:  /* catch variable usage here */
      if( type >= 'a'  && type <= 'z')  /* push the variable onto the stack, note variables that share names with functions can never be retrieved */
        push( var[type-'a'] );
      else
        printf("error: unknown command %s\n", s); /* if not above or a variable */
      break;
    }
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


/* getop: get next operator or numeric operand from line starting at lp */
int getop( char s[],char line[])
{
  int i, c;

  while ((s[0] = c = line[lp++]) == ' ' || c == '\t')
    ;  /* skip white space and tabs */
  s[1] = '\0';
  if(!isdigit(c) && c != '.')
    return c;  /* not a number */
  i = 0;
  if (isdigit(c))  /* collect integer part */
    while ( isdigit(s[++i] = c = line[lp++]))
      ;
  if (c =='.')  /* collect fraction part */
    while ( isdigit(s[++i] = c = line[lp++]))
      ;
  s[i] = '\0';
  
  lp--; /* step back one because we read too far */
  return NUMBER;
}

/* getline: get line into x, return length  */
int getline(char s[], int lim)
{
  int c, i;
  
  i=0;
  while(--lim > 0 && (c=getchar()) != EOF && c!= '\n')
    s[i++] = c;
  if( c == '\n' )
    s[i++] = c;
  s[i] = '\0';
  return i;
}