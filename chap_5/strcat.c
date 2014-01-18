# include <stdio.h>

# define MAXSTRING 1000

main()
{ 
  void strcat(char *, char *);
  void strcopy(char *, char *);
  
  char begin[MAXSTRING];
  char front[] = "I'm at the front";
  char end[] = " add me to the end";
  
  strcopy(begin,front);
  printf("Starting string: %s\n",begin);
  strcat(begin,end);
  printf("Final string: %s\n",begin);
}

/* strcat: copy t to the end of s */
void strcat( char *s, char *t)
{
  while(*s != '\0')  /* find the end of s */
    s++; 
  while(*t != '\0')  /* append t to it */
    *s++ = *t++;
}

/* strcopy: copy t  to s; pointer version 3 */
void strcopy( char *s, char *t)
{
  while( *s++ = *t++)
    ;
}