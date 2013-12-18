# include <stdio.h>

/*  a helper function to print bit patterns to the screen */

void printbits(unsigned n)
{
  /* determine the required width */
  int k = 1;
  for(k=1;n/k;k*=2);  /* max value */
  while(k>0){
    printf("%d",n/k);
    n%=k;
    k/=2;
  }
}

main()
{
  printbits(15);

}