#include <stdio.h>
#include <pthread.h>
#include <unistd.h>
#include <string.h>
#include <stdlib.h>

void *tfn(void *arg)
{
	printf("I'm thread, Thread_ID = %lu, pid = %u\n", pthread_self(), getpid());
	return NULL;
}

int main(void)
{
	pthread_t tid;

	printf("I am main, Thread_ID = %lu, my pid = %d\n", pthread_self(), getpid());
	int ret = pthread_create(&tid, NULL, tfn, NULL);
	if(ret != 0) {
		fprintf(stderr ,"pthread_create error:%s\n", strerror(ret));
		exit(1);
	}
	// sleep(1);
	printf("I am main, Thread_ID = %lu, my pid = %d\n", pthread_self(), getpid());

	pthread_exit(NULL); // 退出主线程，不影响子线程
	// return 0; 
}
