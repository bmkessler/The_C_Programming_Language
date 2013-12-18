# include <stdio.h>
# include <limits.h>

unsigned rightrot(unsigned x, int n)
{
  int w,d;
  w=1;
  for(d=1;INT_MAX/d;d*=2)  /* figuring out the width of the field, should be better way to do this */
    w++;
  return  ((x<<(w-n)) & (~0<<n) ) | (  (x>>n) & ~(~0<<(w-n)));  /* rotate left and right and mask */
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
  int x,i;
  x=123;
  for(i=1;i<10;i++) {
	printf("x ");
    printbits(x,31);
    printf("\n");
	printf("%d ",i);
    printbits(rightrot(x,i),31);
    printf("\n");
  }
  
}
