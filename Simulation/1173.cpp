#include <stdio.h>

int main(void) {
  int N,m,M,T,R;

  scanf("%d %d %d %d %d",&N,&m,&M,&T,&R);
  int X =m;
  int i=0;  //¿îµ¿
  int a=0;  //ÈÞ½Ä
  while(1)
  {
      if(X + T > M)
      {
          X = X-R;
          a++;
          if(X < m)
            X = m;
            
      }
      if(X + T <=M)
      {
          X = X + T;
          i++;
          
          if(i == N)
            break;
      }
      if(X == m && X+T > M)
      {
          a=-1;
          break;
      }
    
  }
  if(a == -1)
    printf("%d", a);
  else
    printf("%d",i+a);
  

}
