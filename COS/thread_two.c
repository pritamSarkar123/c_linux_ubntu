#include<stdio.h>
#include<stdlib.h>
#include<unistd.h>
#include<sys/types.h>
#include<string.h>
#include<sys/wait.h>
#include<semaphore.h>
#include<pthread.h>
int glob=0;
sem_t mutex;
void *incrby2(void *arg){
	sem_wait(&mutex);
	int i,*j=(int *)arg;
	for(i=0;i<1000;i++){
		*j=*j+2;
	}
	sem_post(&mutex);
	return NULL;
}
void *incrby3(void *arg){
	sem_wait(&mutex);
	int i,*j=(int *)arg;
	for(i=0;i<1000;i++){
		*j=*j+3;
	}
	sem_post(&mutex);
	return NULL;
}
void *decrby1(void *arg){
	sem_wait(&mutex);
	int i,*j=(int *)arg;
	for(i=0;i<1000;i++){
		*j=*j-1;
	}
	sem_post(&mutex);
	return NULL;
}
void *decrby4(void *arg){
	sem_wait(&mutex);
	int i,*j=(int *)arg;
	for(i=0;i<1000;i++){
		*j=*j-4;
	}
	sem_post(&mutex);
	return NULL;
}
int main(int argc,char **argv){
	sem_init(&mutex,0,1);
	printf("before %d\n",glob);
	pthread_t t[4];
	pthread_create(t,NULL,incrby2,&glob);
	pthread_create(t+1,NULL,incrby3,&glob);
	pthread_create(t+2,NULL,decrby1,&glob);
	pthread_create(t+3,NULL,decrby4,&glob);
	pthread_join(t[0],NULL);
	pthread_join(t[1],NULL);
	pthread_join(t[2],NULL);
	pthread_join(t[3],NULL);
	sem_destroy(&mutex);
	printf("after %d\n",glob);
	return 0;
}
