#include <stdio.h>
#include <stdlib.h>
#include <pthread.h>

#define MAXLENGTH 10000000

//int pthread_create(pthread_t * tid, const pthread_attr_t * attr, void * ( * func) (void * ), void * arg)
//int pthread_join (pthread_t tid, void ** status);
int data[MAXLENGTH];
void *sum(void *input);
int main() {
    unsigned int *odd, *even;
    unsigned int res;
    pthread_t mythread;
    for (int i = 0; i < MAXLENGTH; ++i) {
        data[i] = i + 1;
    }
    //created thread
    pthread_create(&mythread, NULL, sum, (void*)0);
    pthread_join(mythread, (void **)&odd);
    //currunt thread
    even = sum((void *)1);
    /*
     * pthread_create(&mythread, NULL, sum, (void*)1);
     * pthread_join(mythread, (void **)&even);
     *
     * */
    res = *even + *odd;
    free(odd);
    free(even);
    printf("%u\n", res);
    return 0;
}
void *sum(void *input){
    unsigned int i = (unsigned int)input;
    unsigned int *res = malloc(sizeof (unsigned int));
    for ( i = 0; i < MAXLENGTH ; i = i + 2) {
        *res += data[i];
    }
    return res;
}