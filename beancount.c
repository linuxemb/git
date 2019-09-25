#include "stdio.h"
#include <stdlib.h>
#include <pthread.h>

pthread_mutex_t mutex = PTHREAD_MUTEX_INITIALIZER;
void* bcnt(void* beans_arg)
{
	int cnt;
	int* beans =(int*) beans_arg;

        pthread_mutex_lock(&mutex);
	for (cnt=0; cnt<100000;cnt++) {
  //      printf("%x before next beans %d|", (int)clock(), (*beans));
//	fflush(stdout);
	   	(*beans)++;
//	printf( "%x after next bean %d|\n", (int)clock(), (*beans));	
//	fflush(stdout);
	}
       pthread_mutex_unlock(&mutex);
	return beans_arg;
}


int main()
{
	pthread_t t_bcnt0, t_bcnt1, t_bcnt2,t_bcnt3;
	int beans =0;

	pthread_create(&t_bcnt0,0, bcnt, (void*) (&beans));
	pthread_create(&t_bcnt3,0, bcnt, (void*) (&beans));
	pthread_create(&t_bcnt2,0, bcnt, (void*) (&beans));
	
	pthread_create(&t_bcnt1, 0, bcnt, (void*) (&beans));
	
	pthread_join(t_bcnt0,0);
	pthread_join(t_bcnt2,0);
	pthread_join(t_bcnt3,0);
	pthread_join(t_bcnt1,0);


	printf("the sume of all bean is %d \n",beans);
	return 0;
}
