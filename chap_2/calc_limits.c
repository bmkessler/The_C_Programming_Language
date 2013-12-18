# include <stdio.h>

main()
{

char c1,c2;
c1=0;
c2=c1+1;
while(c1<c2) {
  c1++;
  c2++;
}
printf("max char = %d\n",c1);
printf("min char = %d\n",c2);

short int s1,s2;
s1=0;
s2=s1+1;
while(s1<s2) {
  s1++;
  s2++;
}
printf("max short = %d\n",s1);
printf("min short = %d\n",s2);
  
int i1,i2;
i1=0;
i2=i1+1;
while(i1<i2) {
  i1++;
  i2++;
}
printf("max int = %d\n",i1);
printf("min int = %d\n",i2);

long int l1,l2;
l1=0;
l2=l1+1;
while(l1<l2) {
  l1++;
  l2++;
}
printf("max long = %d\n",l1);
printf("min long = %d\n",l2);


}
