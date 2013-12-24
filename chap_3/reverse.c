# include <string.h>
# include <stdio.h>

/* reverse: reverse a string s in place */
void reverse( char s[])
{
  int c,i,j;
  for(i = 0, j = strlen(s)-1; i<j; i++, j--)
    c = s[i], s[i] = s[j], s[j] = c;
}

main()
{

  char test[] = "The test string of strings!";
  printf("%s\n",test);
  reverse(test);
  printf("%s\n",test);



}