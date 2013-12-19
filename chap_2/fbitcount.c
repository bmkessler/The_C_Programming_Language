# include <stdio.h>

/* bitcount: count one bits in int */
int fbitcount(int x)
{
  int b;
  if(!x)
    return 0;
  for(b=1; x &= (x-1);b++);
  return b;

}

main()
{

  int i;
  for(i=0;i<16;i++)
    printf("%d %d\n",i,fbitcount(i));



}