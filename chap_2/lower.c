# include <stdio.h>

int lower(int c)
{
  
  return (c>='A' && c <='Z') ? c + 'a' - 'A' :  c;

}

main()
{
  int l;
  for(l='A';l<='Z';l++){
    putchar(l);
    putchar(lower(l));
  }
  putchar('\n');
  
}