# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAXLINE 1000

int getline(char *line, int max);

/* find: print lines that match pattern from first arg */
int main(int argc, char *argv[])
{
  char line[MAXLINE];
  long lineno = 0;
  int c;
  char *prog = argv[0];
  int found = 0;;
  FILE *fp;
  
  if(argc < 2) {
    fprintf(stderr,"usage: %s pattern [file1 file2 ...]",prog);
    exit(1);  /* bad arguments */
  }
  char *pat = *++argv;
  /* printf("pattern: %s\n",pat); */
  
  int i;
  if(argc > 2) {  /* process files */
    for(i = 3; i <= argc; i++) {
      fp = fopen(*++argv,"r");
      while(fgets(line,MAXLINE,fp) != NULL) {
        lineno++;
        if( (strstr(line,pat) != NULL) ) {
          printf("%s: %s",*argv,line);
          found++;
        } 
      }
    }
  } else { /* process stdin here*/
      while(fgets(line,MAXLINE,stdin) != NULL) {
        lineno++;
        if( (strstr(line,pat) != NULL) ) {
          printf("%s",line);
          found++;
        }
      }
  } /* process stdin here*/
  exit(0);
  
}