#include <stdio.h>
#include <stdlib.h>   /* for atof() */
#include <math.h>  /* for math functions sin, cos, etc. */
#include <string.h>  /* for getop parsing */

#define MAXOP    100  /* max size of operand or operator */
#define NUMBER  '0'  /* signal that a number was found */
# define MAXLINE 1000 /*the maximum length of an input line  */

int getop( char [], char [] );
int getline(char [], int );
void push(double);
double pop(void);

int lp = 0;  /* the line pointer */

/* reverse Polish calculator using getline rather than getch, ungetch*/
main()
{
  int type;
  double op2;
  char s[MAXOP];
  char line[MAXLINE];  /* the current input line  */
  
  while( getline(line,MAXLINE) > 0 ) {
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
    default:
        printf("error: unknown command %s\n", s); /* if not above or a variable */
      break;
    }
  }
  printf("\t%.8g\n",pop());  /* print top of stack at end of each line */
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

/* getop: get next operator or numeric operand from line starting at lp */
int getop( char s[],char line[])
{
  int i, c;
  char *sp, temp[MAXOP];
  double d;
  
  /* get next token */
  if( sscanf(line,"%s",&temp) == 1) {
    /* move pointer to next token */
    sp = strstr(line,temp) + strlen(temp);
    strcpy(line,sp);
    strcpy(s,temp);
    /* parse token into number or operator */
    if( sscanf(temp,"%f",&d) == 1)
      return NUMBER;  /* its a number, but don't do anything with d in this implementation */ 
    else
      return s[0];  /* just return the first character for all one character operators */
  } else  /* its the end of the line */
      return 0;
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