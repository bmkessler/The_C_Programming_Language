# include <stdio.h>
# include <string.h>
# include <stdlib.h>  /* for atoi */

# define MAXLINES 5000  /* max # lines to be sorted */

char *lineptr[MAXLINES];  /* pointers to text lines */

int readlines( char *lineptr[], int nlines);
void writetail( char *lineptr[], int nlines, int tail);

/* sort input lines */
int main(int argc, char *argv[])
{
  int nlines;  /* number of input lines read */
  int tail = 0;  /* tail lines to print */
  int c;
  
  if(argc > 2) {  /* too many arguments */
    printf("usage: tail -n\n");
    return 0;
  }
  
  if(argc == 2)  /* the -n argument may be used */
    if((*++argv)[0] == '-') {
      while(c = *++argv[0] ) {
        if(isdigit(c))
          tail = 10*tail + ( c - '0' );
        else
          break;
      }
    }
  
  if( tail == 0 )
    tail = 10;  /* default to 10 lines */
    
  if( tail > MAXLINES) {
    printf("warning: requested tail of %d truncated to maximum value of %d\n",tail,MAXLINES);
    tail = MAXLINES;
  }
  
  if((nlines = readlines(lineptr,MAXLINES)) >= 0) {
    writetail(lineptr,nlines,tail);
    return 0;
  } else {
    printf("error: input too big to handle\n");
    return 1;
  }
  
  
}

# define MAXLEN 1000 /* max length of any input line */

int getline(char *, int);
char *alloc(int);

/* readlines: read input lines */
int readlines(char *lineptr[], int maxlines)
{
  int len, nlines;
  char *p, line[MAXLEN];
  
  nlines = 0;
  while((len = getline(line,MAXLEN)) > 0)
    if( nlines >= maxlines ||(p = alloc(len)) == NULL)
      return -1;
    else {
      line[len-1] = '\0';  /* delete new line */
      strcpy(p,line);
      lineptr[nlines++] = p;
    }
  return nlines;
}

/*writetail: write output lines */
void writetail( char *lineptr[], int nlines, int t)
{
  int i;
  
  for( i = ( (nlines - t) > 0 ? (nlines - t) : 0) ; i < nlines; i++)
    printf("%s\n",lineptr[i]);
}


