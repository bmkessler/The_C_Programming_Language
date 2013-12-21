# include <string.h>
# include <stdio.h>

/* expand: expand a-z -> abc...xyz from string s1 to s2 */
void expand( char s1[],char s2[])
{
  int i,j,from,to;
  i = j = 0;
  for(i = 0; i<=strlen(s1); i++)
    if(s1[i] == '-'){ /* expand on dash */
      if(i==0) {  /* start of the string is '-' */
        if(s1[i+1]!='\0') {/* catch pathological "-" string */
          from = s1[i];
          to = s1[i+1];
        } else {
          s2[j++]=s1[i];  /* just return the pathological string */
          s2[j]='\0';
          return;
        }
      } else if( (i+1)<strlen(s1) ) {  /* middle of the string */
        from = s1[i-1];
        to = s1[i+1];
      } else {  /* '-' ends the string */
        from = s1[i-1];
        to = s1[i];
      }
      
      /*  now expand from -> to, always print from,to but only expand if from < to */
      if(from=='-')
        s2[j++]=from;
      from++;
      while(from < to )
        s2[j++] = from++;
      if(to=='-')
        s2[j++]='-';
      
      
    } else {  /* just copy s1 to s2 */
      s2[j++]=s1[i];
    }
    return;
}

main()
{

  char test1[] = "a-z";
  char test2[1000];
  char test3[] = "a-b-c";
  char test4[1000];
  char test5[] = "0-9";
  char test6[1000];
  char test7[] = "a-z0-9";
  char test8[1000];
  char test9[] = "-a-z";
  char test0[1000];
  printf("%s\n",test1);
  expand(test1,test2);
  printf("%s\n",test2);
  printf("%s\n",test3);
  expand(test3,test4);
  printf("%s\n",test4);
  printf("%s\n",test5);
  expand(test5,test6);
  printf("%s\n",test6);
  printf("%s\n",test7);
  expand(test7,test8);
  printf("%s\n",test8);
  printf("%s\n",test9);
  expand(test9,test0);
  printf("%s\n",test0);



}