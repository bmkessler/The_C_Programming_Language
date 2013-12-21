# include <stdio.h>

/* binsearch: find x in v[0]<=v[1]<=...<=v[n-1] */
int binsearch(int x, int v[], int n)
{
  int low, high, mid;
  
  low = 0;
  high = n - 1;
  while(low <= high){
    mid = (low+high)/2; /* midpoint of section */
    if(x < v[mid])
      high = mid -1;
    else if (x> v[mid])
      low = mid + 1;
    else  /* found match */
      return mid;
  }
  return -1;  /* no match */
}

main()
{
  int t[8];
  t[0]=1;
  t[1]=3;
  t[2]=4;
  t[3]=6;
  t[4]=9;
  t[5]=11;
  t[6]=15;
  t[7]=17;
  printf("number = %d, is at position = %d\n",1,binsearch(1,t,8));
  printf("number = %d, is at position = %d\n",2,binsearch(2,t,8));
  printf("number = %d, is at position = %d\n",3,binsearch(3,t,8));
  printf("number = %d, is at position = %d\n",4,binsearch(4,t,8));
  printf("number = %d, is at position = %d\n",5,binsearch(5,t,8));
  printf("number = %d, is at position = %d\n",6,binsearch(6,t,8));
  printf("number = %d, is at position = %d\n",7,binsearch(7,t,8));
  printf("number = %d, is at position = %d\n",8,binsearch(8,t,8));
  printf("number = %d, is at position = %d\n",9,binsearch(9,t,8));
  printf("number = %d, is at position = %d\n",10,binsearch(10,t,8));
  printf("number = %d, is at position = %d\n",11,binsearch(11,t,8));


}
