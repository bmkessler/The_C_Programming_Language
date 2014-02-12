# include <stdio.h>
# include <stdlib.h>
# include <string.h>

# define MAXLINE 1000

/* comp: compare two files and print the first line where they disagree */
main(int argc, char *argv[])
{
  FILE *fp1, *fp2;
  char *prog = argv[0];  /* program name for errors */
  
  if(argc != 3) {
    fprintf(stderr,"usage: %s file1 file2\n", prog);
    exit(1);  /* wrong number of arguments */
  }
  
  char *file1 = argv[1], *file2 = argv[2];  /* the two file names for printing */
  
  if( (fp1 = fopen(file1, "r")) == NULL ) {
    fprintf(stderr,"%s: can't open %s\n", prog, file1);
    exit(2);
  }
  if( (fp2 = fopen(file2, "r")) == NULL ) {
    fprintf(stderr,"%s: can't open %s\n", prog, file2);
    exit(2);
  }
  
  char line1[MAXLINE], line2[MAXLINE];
  
  while( fgets(line1,MAXLINE,fp1) != NULL && fgets(line2,MAXLINE,fp2) != NULL && strcmp(line1,line2) == 0);
  /* while data and it matches keep going */
  if(strcmp(line1,line2) != 0) {
      printf("%s: %s\n%s: %s\n", file1, line1, file2, line2);
  }
  exit(0);
}