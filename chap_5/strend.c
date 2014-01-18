# include <stdio.h>



main()
{
  int strend(char *, char *);
  
  char first[] = "the begining";
  char second[] = "ing";
  char third[] = "john";
  
  printf("Does \"%s\" end in \"%s\": %d\n",first,second,strend(first,second));
  printf("Does \"%s\" end in \"%s\": %d\n",first,third,strend(first,third));
  printf("Does \"%s\" end in \"%s\": %d\n",second,third,strend(second,third));
  
  printf("Does \"%s\" end in \"%s\": %d\n",second,first,strend(second,first));
  printf("Does \"%s\" end in \"%s\": %d\n",third,first,strend(third,first));
  printf("Does \"%s\" end in \"%s\": %d\n",third,second,strend(third,second));

}

/* strend: returns 1 if t occurs at the end of s, 0 otherwise */
int strend(char *s, char *t)
{
  char *p = s;  /* the start of s */
  char *q = t;  /* the start of t */
  
  while( *s != '\0')  /* find the end of s */
    s++;
  
  while( *t != '\0')  /* find the end of t */
    t++;
  
  while( s >= p && t >= q )  /* check to make sure don't run of fthe front of the strings */
    if( *s-- != *t--)
      return 0;
  if( t == q-1 )  /* all of t matches we read one past the end */
    return 1;
  return 0;    /* we ran out of characters in s  before t was matched */

}