#include<stdio.h>
#include<sys/time.h>
#include<gmp.h>
int main()
{
	struct timeval t;
	
	func(16777217);
	return 0;
}
int func(unsigned long u_id)
{
	struct timeval t;
	unsigned long id;
	gettimeofday(&t,NULL);
	id = (t.tv_sec * 1000 * 1000) + (t.tv_usec * 1000) << 42;
	printf("%lu   ",id);
	id |= (u_id % 16777216) << 24; 
	printf("%lu\n ",id);
	return 0;
}
