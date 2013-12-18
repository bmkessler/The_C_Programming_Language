# include <stdio.h>

# define LOWER 0 
# define UPPER 200
# define STEP 20

/* print fahrenheit to celsius conversion from 0..300 */

main()
{
  int fahr;
  printf("  F      C\n");
  for(fahr=LOWER; fahr<=UPPER; fahr+=STEP) {
      printf("%3d %6.1f\n",fahr,(5.0/9.0)*(fahr-32.0) );
  }
}