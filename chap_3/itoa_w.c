# include <stdio.h>
# include <string.h>

# define MAXSTRING 1000

void itoa(int n, char s[],int w);
void reverse( char s[]);

/* itoa: convert n to characters in s */
void itoa(int n, char s[], int w)
{
  int i, sign;
  unsigned int t;
  
  if((sign = n) < 0 ) /* record the sign */
    n = -n;  /* make n positive */
  t = (unsigned int)n;  /* casting to an unsigned int to handle MIN_INT */
  i = 0;
  do{  /* generate digits in reverse order */
    s[i++] = t % 10 + '0';  /* get next digit  */
  } while( (t /= 10) > 0 );                /* delete it */
  while((i+(sign<0))<w)  /* count the sign as part of the width */
    s[i++]='0';
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
  n = 5;
  itoa(n,test,3);
  printf("%d  %s\n",n,test);
  n = 52;
  itoa(n,test,1);
  printf("%d  %s\n",n,test);
  n = -400;
  itoa(n,test,6);
  printf("%d  %s\n",n,test);
  n = 127;
  itoa(n,test,12);
  printf("%d  %s\n",n,test);
  
}

