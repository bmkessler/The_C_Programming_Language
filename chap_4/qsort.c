# include <stdio.h>

void qsort(int [], int, int);

main()
{
  int test[] = { 3,5,1,7,3,9,7,0,2 };
  int i;
  
  for( i = 0; i < 9; i++)
    printf("%d, ",test[i]);
  putchar('\n');
  
  qsort(test,0,8);

  for( i = 0; i < 9; i++)
    printf("%d, ",test[i]);
  putchar('\n');
}

/* qsort: sort v[left] ... v[right] into increasing order */
void qsort(int v[], int left, int right)
{
  int i, last;
  void swap(int v[], int i, int j);
  
  if( left >= right)
    return;  /* do nothing if array contains less than two elements */
  swap(v,left, (left + right) / 2);  /* move partition element  to v[0] */
  last = left;
  for( i = left + 1; i <= right; i++)  /* partition */
    if( v[i] < v[left] )
      swap(v, ++last, i);
  swap(v, left, last);  /* restore partition element */
  qsort(v, left, last-1);
  qsort(v, last+1, right);
}

/* swap: swap element i and j */
void swap( int v[], int i, int j)
{
  int temp = v[i];
  v[i] = v[j];
  v[j] = temp;
}