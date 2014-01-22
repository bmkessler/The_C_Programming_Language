# include <stdio.h>

# define MAXSTRING 1000

main()
{ 
  void strcat(char *, char *, int);
  void strcopy(char *, char *, int);
  int strcmp(char *, char *, int);
  
  char begin[MAXSTRING];
  char front[] = "I'm at the front";
  char end[] = " add me to the end";
  char snip[]= "I'm at the end";
  int t;
  
  strcopy(begin,front,5);
  printf("Starting string: %s\n",begin);
  strcat(begin,end,5);
  printf("Final string: %s\n",begin);
  t = strcmp(front,snip,13);
  printf("The first %d characters of \"%s\" cmp \"%s\": %d \n",13,snip,front,t); 
}

/* strcat: copy t to the end of s */
void strcat( char *s, char *t, int n)
{
  int i = 0;
  while(*s != '\0')  /* find the end of s */
    s++; 
  while( (*t != '\0') && i < n )  /* append t to it for the first n char */
    *s++ = *t++, i++;
  if( i == n )  /* if terminated before the end of t */
    *s = '\0';
}

/* strcopy: copy t  to s; pointer version 3 */
void strcopy( char *s, char *t, int n)
{
  int i = 0;
  while( (*s++ = *t++) && (i < n) )
    i++;
  if( i == n )  /* if terminated before the end of t */
    *s = '\0';
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp( char *s, char *t, int n)
{
  int i = 0;
  for( ; (*s == *t) && (i < n); s++, t++, i++)
    if( *s == '\0')
      return 0;
  return *s - *t;
}