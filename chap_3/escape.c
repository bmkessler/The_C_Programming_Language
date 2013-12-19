# include <stdio.h>

/* escape: converts nonvisible characters to their escape sequence when copying t to s */
void escape(char s[], char t[])
{
  int i,j;
  i=j=0;
  while(t[i]!='\0'){
    switch(t[i]) {
      case '\t':
        s[j++]='\\';
        s[j++]='t';
        i++;
        break;
      case '\n':
        s[j++]='\\';
        s[j++]='n';
        i++;
        break;
      default:
        s[j++]=t[i++];
        break;
      }
    }
  s[j]='\0';
}

main()
{
  char t[]="the test\tstring\nshould print\tescape \nsequences\n";
  char s[1000];
  printf("%s\n",t);
  escape(s,t);
  printf("%s\n",s);


}
