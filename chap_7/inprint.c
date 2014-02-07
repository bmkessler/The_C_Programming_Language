# include <stdio.h>
# define LINEWRAP 50

main()
{

 int c, n = 0;
 
  while((c = getchar() ) != EOF) {
    switch(c) {
      case '\a': case '\b': case '\f':  /* non-printing characters */
      case '\r': case '\t': case '\v': case '\n':
        printf("%#04x",c);  /* print hex equivalent */
        n += 4;  /* non-printing characters increment the line count 4 */ 
        break;
      default:
        putchar(c);
        n++;
        break;
      } 
    if( n >= LINEWRAP || c == '\n') {
      putchar('\n');
      n = 0;
    }
  }
  return 0;
}