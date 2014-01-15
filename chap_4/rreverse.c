# include <stdio.h>
# include <string.h>  /* for length function */

main()
{
  void reverse(char[],int,int);
  
  char test[] = "the test string";
  printf("%s\n",test);
  reverse(test,0,strlen(test)-1);
  printf("%s\n",test);
}

/* reverse: reverses a string in place recursively first start and last length(s)*/
void reverse(char s[], int first, int last)
{
  void swap(char[],int,int);
  
  if(first<last) {
    swap(s,first,last);
    reverse(s,first+1,last-1);
  }
}

/* swap: swap element i and j in string s */
void swap( char s[], int i, int j)
{
  char temp = s[i];
  s[i] = s[j];
  s[j] = temp;
}

