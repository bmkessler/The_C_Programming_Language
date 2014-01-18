/* strcopy: copy t to s; subscript array version */
void strcopy( char *s, char *t)
{
  int i;
  
  i=0;
  while( (s[i] = t[i]) != '\0' )
    i++;
}

/* strcopy: copy t to s; pointer version 1 */
void strcopy( char *s, char *t)
{
  while( (*s = *t) != '\0' ) {
    s++;
    t++;
  }
}

/* strcopy: copy t to s; pointer version 2 */
void strcopy(char *s, char *t)
{
  while( (*s++ = *t++ ) != '\0' )
    ;
}

/* strcopy: copy t  to s; pointer version 3 */
void strcopy( char *s, char *t)
{
  while( *s++ = *t++)
    ;
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp( char *s, char *t)
{
  int i;
  
  for( i = 0; s[i] == t[i]; i++)
    if( s[i] == '\0')
      return 0;
  return s[i] - t[i];
}

/* strcmp: return <0 if s<t, 0 if s==t, >0 if s>t */
int strcmp( char *s, char *t)
{
  for( ; *s == *t; s++, t++)
    if( *s == '\0')
      return 0;
  return *s - *t;
}

*p++ = val;  /* push val onto stack */
val = *--p;  /* pop top of stack onto val */

}