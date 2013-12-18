#include <stdio.h>
#define MAXLINE 1000  /* maximum line size */


int getline(char line[],int maxline);
void copy(char to[], char from[]);

/* removing traling whitespaces and entirely blank lines */

main()
{

  int len;
  char line[MAXLINE];

  while( (len = getline(line,MAXLINE)) > 0){
	while(line[len-1]=='\n' || line[len-1]==' ' || line[len-1]=='\t') {
	  len--;
	}
	if(line[len]!='\0'){
	  line[len]='\n';
	  line[len+1]='\0';
	}
	if(len>0)
	  printf("%3d %s",len,line);
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
