#include <stdio.h>
#define MAXLINE 1000  /* maximum line size */


int getline(char line[],int maxline);
void reverse(char line[]);

/* reverse each line */

main()
{

  int len;
  char line[MAXLINE];

  while( (len = getline(line,MAXLINE)) > 0){
    reverse(line);
	printf("%s",line);
  }
  return 0;
 
}

int getline( char s[], int lim)
{
  int c, i;
  
  for(i=0; i<lim-1 && (c=getchar())!=EOF && c!='\n'; i++)
    s[i] = c;
  if( c == '\n') {
    s[i]=c;
	i++;
  }
  s[i]='\0';
  return i;

}

void reverse(char s[])
{
  char t[MAXLINE];
  int i,max;
  i = 0;
  while(s[i]!='\0')
    t[i]=s[i++];
  max = i;
  for(i=0; i<max;i++)
    s[i]=t[max-1-i];
}
