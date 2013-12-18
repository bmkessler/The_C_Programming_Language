# include <stdio.h>

# define MAXLINE 1000
# define FOLDLEN 25
# define TABSTOP 4

int getline(char line[], int maxline);
void printwrap(char line[]);

main()
{
  
  int len;
  char line[MAXLINE];

  while( (len = getline(line,MAXLINE)) > 0){
	printwrap(line);
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

void printwrap(char line[])
{
  int i,lastbreak,start,stop;
  i=0;
  lastbreak=0;
  start = 0; 
  
  while(line[start]!='\0'){
  /* find the last break */
    lastbreak = 0;
    for(i=0; i<FOLDLEN && line[start+i] != '\0'; i++) {
       if(line[start+i]==' ' || line[start+i]=='\t')
	     lastbreak = start + i;
       /* count tabs appropriately here */
    }

    if(!lastbreak){
	  stop = start+i;  /* break at the edge */
	} else {
      stop = lastbreak;  /* break at the last blank  */
    }
	
    /* print the line */
    for(i=start;i<stop;i++) {
      putchar(line[i]);
    }
    putchar('\n');
	/* printf("%d %d %d\n",start,stop, lastbreak); */
    start = stop;
	if(lastbreak)
	  start++;

  }

}