# include <stdio.h>
# include <stdlib.h>   /* for atof() */
# include <math.h>  /* for math functions sin, cos, etc. */
# include "calc.h"  /* custom headers */

# define MAXOP    100  /* max size of operand or operator */
# define NUMVAR 26  /* the number of variables allowed currently all lowercase letters */

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
      if( type >= 'a'  && type <= 'z')  /* push the variable onto the stack, note variables that share names with functions can never be retrieved */
        push( var[type-'a'] );
      else
        printf("error: unknown command %s\n", s); /* if not above or a variable */
      break;
    }
  }
  return 0;
}