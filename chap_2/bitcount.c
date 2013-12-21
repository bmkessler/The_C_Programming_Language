# include <stdio.h>

/* bitcount: count one bits in int */
int bitcount(int x)
{
  int b;
  for(b=0;x!=0;x>>=1)
    if(x & 01)
      b++;
  return b;

}

main()
{

  int i;
  for(i=0;i<16;i++)
    printf("%d %d\n",i,bitcount(i));



}