# include <stdio.h>
# include <stdlib.h>   /* for atof() */
# include <math.h>  /* for math functions sin, cos, etc. */

/* reverse Polish calculator */
int main(int argc, char *argv[])
{
  void push(double);
  double pop(void);
  
  double op2;
  
  while (--argc > 0) {
    switch ((*++argv)[0]) {  /*switch on the first character of argv */
    case '0': case '1': case '2': case '3': case '4':
    case '5': case '6': case '7': case '8': case '9':
      push(atof(*argv));
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
    default:  /* catch unknown usage here */
      printf("error: unknown command %s\n", *argv); /* if not above or a variable */
      break;
    }
  }
  printf("%g\n",pop());
  return 0;
}

# define MAXVAL 100  /* the maximum depth of the val stack */

static int sp = 0;         /* the next free stack position */
static double val[MAXVAL];  /* value stack */

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