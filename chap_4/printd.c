# include <stdio.h>

void printd(int);

main()
{
  int a = 1234;
  printd(a);
  putchar('\n');
  a = -9582;
  printd(a);
  putchar('\n');
}

/* printd: print n in decimal */
void printd( int n )
{
  if( n < 0) {
    putchar('-');
    n = -n;
  }
  if( n / 10 )
    printd(n / 10);
  putchar(n % 10 + '0');
}