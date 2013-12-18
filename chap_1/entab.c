# include <stdio.h>

# define MAXLINE 1000  /* the maximum length of an input line */
# define TABSTOP 8     /* the spacing of tab stops, every n spaces */

int getline(char line[], int maxline);
void entab(char line[]);
void copy(char to[], char from[]);

/********************************************
 
supposed to replace consecutive spaces with tabs
currently this only works on lines with NO tabs in the input

********************************************/

main()
{
  
  int len;
  char line[MAXLINE];

  while( (len = getline(line,MAXLINE)) > 0){
    entab(line);
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

void entab(char s[])
{
  char t[MAXLINE];
  int i,j,k,l,spaces;
  i = 0;
  j = 0;
  l = 0;
  spaces = 0;
  while(s[i]!='\0') {
    if(s[i]!=' ') { /* not in a set of spaces anymore so put them all back in */
	  for(k=0;k<spaces;k++) {
	    t[j]=' ';
		j++;
      }
	  spaces = 0;
	  t[j]=s[i];
	  j++;
	} else {  /* count space tab with equivalent spaces */
	  if(spaces && ((l%TABSTOP)==0)){ /* if on a tab stop and consecutive spaces use tab for true location l */
	    t[j] = '\t';
		j++;
		spaces = 0;
	  }
	  spaces++;
	}
	if(s[i]=='\t') {
	  l += TABSTOP - (j % TABSTOP);  /* the spaces equivalent to the tab */
	} else {
	  l++;
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