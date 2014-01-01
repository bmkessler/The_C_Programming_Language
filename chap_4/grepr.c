# include <stdio.h>
#define MAXLINE 1000  /* the maximum input line length  */

int getline(char line[], int max);
int strrindex(char source[], char searchfor[]);

char pattern[] = "ould";  /* pattern to search for  */

/* find all lines matching pattern  */
main()
{
  char line[MAXLINE];
  int found = 0;
  int loc;
  
  while( getline(line,MAXLINE) > 0) {
    printf("%d\n",strrindex(line,pattern));
    if ( strrindex(line,pattern) >=0) {
      printf("%s",line);
      found++;
    }
  }
    return found;
}

/* getline: get line into x, return length  */
int getline(char s[], int lim)
{
  int c, i;
  
  i=0;
  while(--lim > 0 && (c=getchar()) != EOF && c!= '\n')
    s[i++] = c;
  if( c == '\n' )
    s[i++] = c;
  s[i] = '\0';
  return i;
}

/* strindex: return index of t in s, -1 if none */
int strrindex(char s[], char t[])
{
  int i, j, k, out;
  
  out = -1;
  for( i = 0; s[i] != '\0'; i++) {
    for( j=i, k=0; t[k] != '\0' && s[j]==t[k]; j++, k++)
      ;
    if( k > 0 && t[k] == '\0')
      out = i;
  }
  return out;
}