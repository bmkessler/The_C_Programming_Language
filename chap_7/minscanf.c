# include <stdarg.h>
# include <stdio.h>

int minscanf(char *fmt, ...)
{
  va_list ap;  /* points to each unnamed argument in turn */
  char *p, *sval, c;
  int *ival, matches;
  double *dval;
  
  matches=0;
  va_start(ap, fmt);  /* make ap point to the first unnamed argument */
  for(p = fmt; *p; p++) {
    if( *p != '%' ) { 
      if((c = getchar()) == *p)  /* literal text matches */
        continue;
      else if( c == EOF )  /* check for end of file */
        return EOF;
      else
        return matches;  /* other text did not match so quit searching */
    }
    switch(*++p) {
      case 'd':
        ival = va_arg(ap, int *);
        if( scanf("%d",ival) != EOF)
          matches++;
        else 
          return EOF;
        break;
      default:
        break;
    }
  }
  return matches;
}

main()
{
  int i;
  
  if(minscanf("i: %d",&i) == 1)
    printf("found: %d\n",i);
  return 0;
}