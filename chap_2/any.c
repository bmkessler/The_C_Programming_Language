# include <stdio.h>

int any(char s1[], char s2[])
{
  int i,j;
  for(i=0;s1[i]!='\0';i++)
    for(j=0;s2[j]!='\0';j++)
      if(s1[i]==s2[j])
        return i;
   return -1;
   
}


main()
{

  char test1[] = "and this is a test";
  char test2[] = "set";
  char test3[] = "apple";
  char test4[] = "not";
  
  printf("%s, %s, %d\n",test1,test2,any(test1,test2));
  printf("%s, %s, %d\n",test1,test3,any(test1,test3));
  printf("%s, %s, %d\n",test2,test3,any(test2,test3));
  printf("%s, %s, %d\n",test3,test4,any(test3,test4));


  return 0;
}