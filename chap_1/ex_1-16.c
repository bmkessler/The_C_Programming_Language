#include <stdio.h>
#define MAXLINE 20  /* maximum line size */

int getline(char line[],int maxline);
void copy(char to[], char from[]);

/* print longest line */

main()
{

  int len;
  int max;
  char line[MAXLINE];
  char longest[MAXLINE];
  
  max = 0;
  while( (len = getline(line,MAXLINE)) > 0)
    if( len > max) {
	  max = len;
	  copy(longest,line);
	}
  if( max > 0 )
    printf("%d %s", max, longest);
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
  if( i == MAXLINE-1 && c !='\n') {  /* the line is full, but still not completely read */
	while((c=getchar())!=EOF && c!='\n')
	  i++;
  }
  return i;

}

void copy(char to[], char from[])
{
  int i;
  
  i = 0;
  while( (to[i]=from[i]) != '\0')
    i++;
	
}