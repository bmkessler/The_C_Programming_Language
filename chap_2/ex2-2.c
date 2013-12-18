int endcond = 1;
for(i=0;endcond;i++) {
  if(i>=lim)
    endcond = 0 ;
  if((c=getchar())=='\n')
    endcond = 0;
  if(c==EOF)
    endcond = 1;
  s[i] = c;
}