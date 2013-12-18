# include <stdio.h>

unsigned setbits(unsigned x, int p, int n, unsigned y)
{
  unsigned mask = (~0<<p) | ~( ~0 << (p-n));  /* n zeros starting at p */
  return   (x & mask)|(y & ~mask);  /* return x on the mask and y otherwise */
}

void printbits(unsigned n,int width)
{
  /* determine the value of the required width */
  int k,w;
  k = 1;
  for(w=1;w<width;w++)
    k*=2;  /* max value */
  while(k>0){
    printf("%d",n/k);
    n%=k;
    k/=2;
  }
}

main()
{
  int x,y,i,j;
  x=123;
  y=87;
  for(i=1;i<8;i++) {
    for(j=1;j<=i;j++){
	printf("x   ");
    printbits(x,8);
    printf("\n");
	printf("y   ");
    printbits(y,8);
    printf("\n");
	printf("%d %d ",i,j);
    printbits(setbits(x,i,j,y),8);
    printf("\n");
  }
  printf("\n");
}


}