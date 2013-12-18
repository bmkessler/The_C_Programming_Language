# include <stdio.h>

# define LOWER 0
# define UPPER 300
# define STEP 20

/* print fahrenheit to celsius conversion from 0..300 */

main()
{
  int fahr;
  printf("  F      C\n");
  for(fahr=UPPER; fahr>=LOWER; fahr-=STEP) {
      printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32.0) );
  }
}