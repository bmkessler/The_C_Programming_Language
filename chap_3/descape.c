# include <stdio.h>

/* escape: converts nonvisible characters to their escape sequence when copying t to s */
void escape(char s[], char t[])
{
  int i,j;
  char lastc;
  i=j=0;
  lastc = t[i];
  switch(lastc) {
    case('\0'):
      s[j]='\0';  /* catch the empty string input */
      return;
    case('\\'):  /* punt till nextc on escape char */
      i++;
      break;
    default:
      s[j++]=t[i++];  /* copy the char */
      break;
  }
  while(t[i]!='\0'){
    switch(lastc) {
      case '\\':
        switch(t[i]) {
          case('t'):
            s[j++]='\t';
            lastc=t[i++];
            break;
          case('n'):
            s[j++]='\n';
            lastc=t[i++];
            break;
          default:
            s[j++]=lastc;
            lastc = t[i++];
            s[j++]=lastc;
            break;
        }
        break;
      default:
        switch(t[i]){
          case('\\'):  /* punt till nextc on escape char */
            lastc=t[i++];
            break;
          default:
            lastc = t[i++];
            s[j++] = lastc;  /* copy the char */
            break;
        }
      break;
   }
  }
  s[j]='\0';
}

main()
{
  char t[]="the test\\tstring\\nshould print\\tescape \\nsequences\\n";
  char s[1000];
  printf("%s\n",t);
  escape(s,t);
  printf("%s\n",s);


}
