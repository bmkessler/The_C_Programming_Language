# include <stdio.h>

# define swap(t,x,y) {t temp = x; x = y; y = temp;}

main()
{
  int a, b;
  a = 3;
  b = 6;
  printf("%d, %d\n",a,b);
  swap(int,a,b);
  printf("%d, %d\n",a,b); 
  
  char c,d;
  c = 'c';
  d = 'd';
  printf("%c, %c\n",c,d);
  swap(char,c,d);
  printf("%c, %c\n",c,d); 
  
}