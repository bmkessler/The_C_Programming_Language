# include <stdio.h>

/* a simple syntax checker to match parentheses and brackets
   confirm that comments and strings are terminated
   note does not handle character constants appropriately
   */

main()
{

int lastc, c, incomment, instring, inchar, charerr, i, ccount[256];

for(i=0;i<256;i++)
  ccount[i]=0;
incomment = 0;
instring = 0;
inchar = 0;
charerr = 0;
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
  /* check if start of string */
    if(c=='"')
      instring = 1;
  /* increment the character counter if not in comment, string or char */
    ccount[c]++;
  }
  lastc = c;
}

/* check if left and right parentheses match */ 
if(ccount['(']!=ccount[')'])
  printf("Left=%d and right=%d parantheses mismatch!\n",ccount['('],ccount[')']);
/* check if left and right brackets match */
if(ccount['{']!=ccount['}'])
  printf("Left=%d and right=%d brackets mismatch!\n",ccount['{'],ccount['}']);
/* check if unterminated comment */ 
if(incomment)
  printf("Unterminated comment!\n");
/* check if unterminated string */ 
if(instring)
  printf("Unterminated string!\n");


return 0;

}