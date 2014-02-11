# include <stdio.h>
# include <string.h>

# define MAXSTRING 100

main()
{
  char test[] = "This is the test string";
  
  char temp[MAXSTRING];
  int length;
  char *sp;
  
  /* tokenize the test string */
  while(sscanf(test,"%s",&temp) == 1) {
    printf("%d: %s\n",length = strlen(temp),temp);
    sp = strstr(test,temp) + length;
    strcpy(test,sp);
  }
}