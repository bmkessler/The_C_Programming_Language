# include <stdio.h>

/* getbits: get n bits from position p */
unsigned getbits(unsigned x, int p, int n)
{
  return (x >> (p+1-n)) & ~( ~0 << n);
}

/*  a helper function to print bit patterns to the screen */

void printbits(unsigned n)
{
  /* determine the required width */
  int k = 1;
  for(k=1;n/k;k*=2);  /* max value */
  k=1024; /*manual max value  could be gotten from limits */
  while(k>0){
    printf("%d",n/k);
    n%=k;
    k/=2;
  }
}

main()
{
  unsigned t=15;
  int i,j;
  for(t=0;t<16;t++) {
  for(i=0;i<4;i++)
    for(j=1;j<=4;j++) {
	  printf("%d, %d, %06.x, %06.x  ",i,j,t,getbits(t,i,j)); 
        printbits(getbits(t,i,j));
		printf("\n");
    }

	}
}