# include <stdio.h>

# define LOWER 0 
# define UPPER 200
# define STEP 20

/* print fahrenheit to celsius conversion from 0..300 */

main()
{
  int cels;
  printf("  C      F\n");
  for(cels=LOWER; cels<=UPPER; cels+=STEP) {
      printf("%3d %6.1f\n",cels,((9.0/5.0)*cels) + 32.0 );
  }
}