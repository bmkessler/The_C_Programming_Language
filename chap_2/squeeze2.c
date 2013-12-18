# include <stdio.h>

int cnotint(char c, char t[]);
void squeeze(char s[], char t[]);

/* squeeze */
void squeeze(char s[], char t[])
{
  int i, j;
  for(i = j = 0; s[i]!='\0';i++)
    if(cnotint(s[i],t))
      s[j++]=s[i];
  s[j]='\0';
}

int cnotint(char c, char t[])
{
  int i,out;
  out=1;
  for(i=0;t[i]!='\0';i++)
    if(c==t[i])
      out=0;
  return out;
}

main()
{
  char test1[]="a man a plan a boat a can deaf fred";
  char test2[]="abc";
  char test3[]="def";
  printf("%s\n",test1);
  squeeze(test1,test2);
  printf("%s\n",test1);
  squeeze(test1,test3);
  printf("%s\n",test1);
  return 0;


}