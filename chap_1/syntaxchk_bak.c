# include <stdio.h>

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
  } else if(inchar) {
    /* check for end of char */
    if(c=='\'')
      inchar = 0;
    else if( !(lastc=='\'' || lastc=='\\') ) /* too many items in a character */
      charerr++;
  } else {
  /* check if start of string or char */
    if(c=='"')
      instring = 1;
    if(c=='\'')
      inchar = 1;
  /* increment the character counter if not in comment, string or char */
    ccount[c]++;
  }
  lastc = c;
}

/* check if left and right par match */ 'l'
if(ccount['(']!=ccount[')'])
  printf("Left=%d and right=%d parantheses mismatch!\n",ccount['('],ccount[')']);
if(ccount['{']!=ccount['}'])
  printf("Left=%d and right=%d brackets mismatch!\n",ccount['{'],ccount['}']);
if(incomment)
  printf("Unterminated comment!\n");
if(instring)
  printf("Unterminated string!\n");
if(charerr)
  printf("Character constant error occured %d times!",charerr);

return 0;

}