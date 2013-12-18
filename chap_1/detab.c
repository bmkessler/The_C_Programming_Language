# include <stdio.h>

# define MAXLINE 1000  /* the maximum length of an input line */
# define TABSTOP 8     /* the spacing of tab stops, every n spaces */

int getline(char line[], int maxline);
void detab(char line[]);
void copy(char to[], char from[]);

main()
{
  
  int len;
  char line[MAXLINE];

  while( (len = getline(line,MAXLINE)) > 0){
    detab(line);
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

void detab(char s[])
{
  char t[MAXLINE];
  int i,j,k,spaces;
  i = 0;
  j = 0;
  while(s[i]!='\0') {
    if(s[i]!='\t') {
	  t[j]=s[i];
	  j++;
	} else {  /* replace tab with equivalent spaces */
	  spaces = TABSTOP - (j % TABSTOP);
	  for(k=0;k<spaces;k++) {
	    t[j]=' ';
		j++;
	  }
	}
	i++;
  }
  t[j]='\0';
  copy(s,t);
}

void copy(char to[], char from[])
{
  int i;
  
  i = 0;
  while( (to[i]=from[i]) != '\0')
    i++;
	
}