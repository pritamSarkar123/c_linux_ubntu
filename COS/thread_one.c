#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>
int glob=10;
sem_t mutex;
void *threadFunction(void *arg){
	int *i=(int *)arg;
	//printf("thread %d\n",pthread_self());
	sem_wait(&mutex);// critical section
	sleep(3);
	*i=20;
	sem_post(&mutex);
	
	return NULL;
}
int main(int argc,char** argv){
	sem_init(&mutex,0,1);
	pthread_t t1;
	printf("before %d\n",glob);
	pthread_create(&t1,NULL,threadFunction,&glob);
	pthread_join(t1,NULL);
	printf("after %d\n",glob);
	sem_destroy(&mutex);
	return 0;
}
