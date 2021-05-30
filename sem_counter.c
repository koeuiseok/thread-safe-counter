#include <stdio.h>
#include <stdlib.h>
#include <string.h>
#include <unistd.h>
#include <semaphore.h>
#include <pthread.h>
#include <time.h>

typedef struct __counter_sema {
	int value_s;
	sem_t semaphore;
}counter_sema;

unsigned int loop_cnt;
counter_sema counter;

void init(counter_sema* s, int sss){
	s->value_s = 0;
	sem_init(&s->semaphore,0,sss);
}

void increment(counter_sema *s) {
    sem_wait(&s->semaphore);
    s->value_s++;
    sem_post(&s->semaphore);
}

void decrement(counter_sema *s) {
    sem_wait(&s->semaphore);
    s->value_s--;
	sem_post(&s->semaphore);
}

int get(counter_sema *s) {
	sem_wait(&s->semaphore);
    int rc = s->value_s;
	sem_post(&s->semaphore);
    return rc;
}

void *mythread(void *arg)
{
    char *letter = arg;
    int i;

    printf("%s: begin\n", letter);
    for (i = 0; i < loop_cnt; i++) {
        increment(&counter);
    }
    printf("%s: done\n", letter);
    return NULL;
}

void error_handling(char* msg)
{
    fputs(msg, stderr);
	fputc('\n', stderr);
	exit(1);
}


int main(int argc, char *argv[])
{   
    clock_t start, end;
    float cct;
	if(argc != 2){
		error_handling("argument error!");
	}
    loop_cnt = atoi(argv[1]);

    start = clock();
    init(&counter, 1);

    pthread_t p1, p2;
    //printf("main: begin [counter = %d]\n", get(&counter));
    pthread_create(&p1, NULL, mythread, "A"); 
    pthread_create(&p2, NULL, mythread, "B");
    // join waits for the threads to finish
    pthread_join(p1, NULL); 
    pthread_join(p2, NULL); 
    end = clock();
    cct = (float)(end - start) / CLOCKS_PER_SEC;
    printf("time of thread mutex : %f\n", cct);
    printf("main: done [counter: %d] [should be: %d]\n", get(&counter), loop_cnt * 2);
    return 0;
}
