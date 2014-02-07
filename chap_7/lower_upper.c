# include <stdio.h>
# include <ctype.h>
# include <string.h>

main(int argc, char *argv[])  /* lower: convert input to lower case */
{
  int c;
  while((c = getchar()) != EOF) {
    if(strcmp("lower.exe",argv[0]) == 0 )
      putchar(tolower(c));
    else if(strcmp("upper.exe",argv[0]) == 0 )
      putchar(toupper(c));
  }
  if( strcmp("lower.exe",argv[0]) && strcmp("upper.exe",argv[0]) )
    printf("error: unknown caller %s, should be called as lower.exe or upper.exe\n",argv[0]);
  return 0;
}