#include<stdio.h>
#include<math.h>

int isprime(int n)
{
  int rt,i;
  rt = floor(sqrt(n));
  for(i=2;i<=rt;i++){
    if((n%i)==0)return 0;
  }
  return 1;
}

int main()
{
  int inp[30],inp1[30],N,i,k,sum,count,flag=0;
  long n;
  scanf("%d",&N);
  for(i=0;i<N;i++)
    scanf("%d %d",&inp[i],&inp1[i]);
  i = 0;
  while(i<N){
    count=0;
    if(inp[i]<2)inp[i]=2;
    for(k=inp[i];k<=inp1[i];k++){
      n = k;
      sum=0;
      flag = 0;
      while(n>0){
	sum += n%10;
	n = n/10;
      }
      if(isprime(sum))flag=1; 
      if(flag){ /*for n^2*/
	n = k*k;
	sum = 0;
	while(n>0){
	  sum += n%10;
	  n = n/10;
	}
	if(isprime(sum))count++;
      }
    }
    i++;
    printf("%d\n",count);
  }
  return 0;
}
