#include<stdio.h>
#include<malloc.h>

int sort(long*,int);

int main()
{
  int N,K,i=0,j,t,count=0;
  long *a;
  scanf("%d %d",&N,&K);
  a = (long*)malloc(sizeof(int) * N);
  while(i<N)
  {
    scanf("%d",&a[i]); i++;
  }
  sort(a,N);
  for(i=0;i<N;i++){
    for(j=i+1;j<=N;j++){
      t = a[i] - a[j];
      if(t<0)t=t*-1;
      if(t>K)break;
      else if(t==K)count++;
    }
  }
  printf("%d", count);
  return 0;
}

int sort(long *a, int N){
  int i,j;
  long tmp;
  for(i=1;i<N;i++){
    j = i;
    while(j>0 && a[j-1]>a[j]){
      tmp = a[j];
      a[j] = a[j-1];
      a[j-1] = tmp;
      j--;
    }
  }
  return 0;
}
