#include<stdio.h>
#include<sys/time.h>
#include<gmp.h>
int main()
{
	int i;
	for(i =0;i < 32; i++)
		func(i);
	return 0;
}
int func(unsigned long u_id)
{
	struct timeval t;
	unsigned long id;
	gettimeofday(&t,NULL);
	id = (t.tv_sec * 1000 * 1000) + (t.tv_usec * 1000) << 42;
	id |= (u_id % 16777216) << 24; 
	printf("%lu\n ",id);
	return 0;
}
