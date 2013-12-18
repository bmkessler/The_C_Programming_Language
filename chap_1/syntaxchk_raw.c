# include <stdio.h>

main()
{

int i, lastc, c, ccount[256];
int incomment, instring, inchar, charerr;

for(i=0;i<256;i++)
  ccount[i]=0;
  
incomment = 0;
instring = 0;
lastc = getchar();

ccount[lastc]++;  /* count the first character */

while((c=getchar())!=EOF) {

  /* check for start of comment */
  if(lastc == '/' && c == '*' )
    incomment = 1;

  if(incomment) {
  /* check for end of comment */
    if( lastc == '*' && c == '/' ) {
      incomment = 0;
    }
  } else if(instring) {
  /* check for end of string */
    if( c == '"')
      instring = 0;
  } else {
  /* check if start of string or char */
    if(c=='"')
      instring = 1;
  /* increment the character counter if not in comment, string or char */
    ccount[c]++;
  }
  lastc = c;
}

/* check if left and right par match */
if(ccount['(']!=ccount[')'])
  printf("Left=%d and right=%d parantheses mismatch!\n",ccount['('],ccount[')']);
if(ccount['{']!=ccount['}'])
  printf("Left=%d and right=%d brackets mismatch!\n",ccount['{'],ccount['}']);
if(incomment)
  printf("Unterminated comment!\n");
if(instring)
  printf("Unterminated string!\n");

return 0;

}