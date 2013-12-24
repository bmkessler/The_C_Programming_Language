# include <stdio.h>
# include <string.h>
# include <limits.h>

# define MAXSTRING 1000

void itoa(int n, char s[]);
void reverse( char s[]);

/* itoa: convert n to characters in s */
void itob(int n, char s[], int b)
{
  int i, sign;
  unsigned int t;
  
  if((sign = n) < 0 ) /* record the sign */
    n = -n;  /* make n positive */
  t = (unsigned int)n;  /* casting to an unsigned int to handle MIN_INT */
  i = 0;
  do{  /* generate digits in reverse order */
    if( (t % b) < 10 )
      s[i++] = t % b + '0';  /* get next digit  */
    else
      s[i++] = t % b - 10 + 'A';  /* use letters  */
  } while( (t /= b) > 0 );                /* delete it */
  if( sign < 0 )
    s[i++] = '-';
  s[i] = '\0';
  reverse(s);
}

/* reverse: reverse a string s in place */
void reverse( char s[])
{
  int c,i,j;
  for(i = 0, j = strlen(s)-1; i<j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}


main()
{
  int n;
  char test[MAXSTRING];
  n = 16;
  itob(n,test,16);
  printf("%d  %s\n",n,test);
  n = 15;
  itob(n,test,16);
  printf("%d  %s\n",n,test);
  n = 9;
  itob(n,test,16);
  printf("%d  %s\n",n,test);
  n = INT_MAX;
  itob(n,test,16);
  printf("%d  %s\n",n,test);
  
}

