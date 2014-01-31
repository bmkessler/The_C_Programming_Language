# include <stdio.h>
# include <string.h>

# define MAXLINES 5000     /* max # lines to be sorted */
char *lineptr[MAXLINES];   /* pointers to text lines   */

int readlines(char *lineptr[], int nlines);
void writelines(char *lineptr[], int nlines);

void qsort(void *lineptr[], int left, int right, int (*comp)(void *, void *), int reverse );
int numcmp(char *, char *);

int main( int argc, char *argv[])
{
  int nlines;       /* number of input lines read */
  int c, numeric = 0, reverse = 0; /*flags for options */
  

  while(--argc > 0 && (*++argv)[0] == '-') 
    while(c = *++argv[0]) 
      switch(c) {
        case 'n':
          numeric = 1;
          break;
        case 'r':
          reverse = 1;
          break;
        default:
          printf("sort: illegal option %c\n",c);
          break;
      }
  if((nlines = readlines(lineptr,MAXLINES)) >= 0) {
    qsort((void **) lineptr, 0, nlines-1, (int (*)(void*,void*))(numeric ? numcmp : strcmp),reverse);
    writelines(lineptr,nlines);
    return 0;
  } else {
    printf("input too big to sort \n");
    return 1;
  }
}

/* qsort: sort v[left]...v[right] into increasing/decreasing order via reverse */
void qsort(void *v[], int left, int right, int (*comp)(void *, void *),int reverse)
{
  int i, last;
  void swap(void *v[], int, int);
  
  if(left >= right)  /* do nothing if array contains fewer than two elements */
    return;
  swap(v,left, (left + right) /2);
  last = left;
  for(i = left+1; i <= right; i++)
    if((*comp)(v[i],v[left]) < 0 == !reverse)
      swap(v, ++last, i);
  swap(v, left, last);
  qsort(v, left, last-1, comp, reverse);
  qsort(v, last+1, right, comp, reverse);
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

/*writelines: write output lines */
void writelines( char *lineptr[], int nlines)
{
  int i;
  
  for( i = 0; i < nlines; i++)
    printf("%s\n",lineptr[i]);
}

void swap(void *v[], int i, int j)
{
  void *temp;
  
  temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}