#include<stdio.h>

int main()
{
  char a[10][100000],*x,*y;
  int count=0,c,i,j=0,k=0,N;
  scanf("%d",&N);
  for(k=0;k<N;k++)
    scanf("%s",&a[k]);
  for(k=0;k<N;k++){
    x = a[k];count=0;
    for(i=0;a[k][i]!='\0';i++){
      j=i;
      c=0;
      x=a[k];
      while(*x==a[k][j] && a[k][i]!='\0' && a[k][j]!='\0'){
	c++; j++;x++;
      }
      count+=c;
    }
    printf("%d\n",count);
  }
  return 0;
}
