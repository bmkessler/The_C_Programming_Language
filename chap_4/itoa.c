# include <stdio.h>

# define MAXSTRING 1000

int itoa(int, char[],int);

main()
{
  char test[MAXSTRING];
  int a = 1234;
  int i;
  i = itoa(a,test,0);
  printf("%s %d\n", test,i);
  a = -9582;
  i = itoa(a,test,0);
  printf("%s %d\n", test,i);
}

/* itoa: print n in decimal, p is a counter, can't be static or won't reset on first call, bad programming style */
int itoa( int n, char s[],int p)
{
  int i = p;
  if( n < 0) {
    s[p++] = '-';
    n = -n;
  }
  if( n / 10 )
    i = itoa(n / 10, s, p );
  s[i+1] = '\0';
  s[i] = (n % 10 + '0');
  return i + 1;
}