# include <ctype.h>
# include <stdio.h>
#define MAXLINE 1000  /* the maximum input line length  */

int getline(char line[], int max);
double atof(char s[]);

/* convert all lines to floating point  */
main()
{
  char line[MAXLINE];
  
  while( getline(line,MAXLINE) > 0)
    printf("%g\n",atof(line));
}

/* atof: convert a string s to double */
double atof(char s[])
{
  double val, power, emult;
  int i, sign, exp;
  for (i = 0; isspace(s[i]); i++)  /* skip white space */
    ;
  sign = (s[i] == '-') ? -1 : 1;
  if(s[i] == '+' || s[i] == '-')
    i++;
  for (val = 0.0; isdigit(s[i]); i++)
    val = 10.0 * val + (s[i] - '0');
  if(s[i] == '.')
    i++;
  for(power = 1.0; isdigit(s[i]); i++) {
    val = 10.0 * val + (s[i] - '0');
    power /= 10.0;
  }
  if(s[i] == 'e') {
    i++;
    emult = (s[i] == '-') ? 0.10 : 10.0;
    if(s[i] == '+' || s[i] == '-')
      i++;
    for (exp = 0; isdigit(s[i]); i++)
      exp = 10 * exp + (s[i] - '0');
    for(i=0;i<exp;i++)
      power *= emult;
    }
    return sign * val * power;
}

/* getline: get line into x, return length  */
int getline(char s[], int lim)
{
  int c, i;
  
  i=0;
  while(--lim > 0 && (c=getchar()) != EOF && c!= '\n')
    s[i++] = c;
  if( c == '\n' )
    s[i++] = c;
  s[i] = '\0';
  return i;
}