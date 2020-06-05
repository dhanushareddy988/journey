#include <stdlib.h>
#include <stdio.h>
#include <pthread.h>
#include<stdatomic.h>
//pthread_mutex_t accum_mutex = PTHREAD_MUTEX_INITIALIZER;
atomic_int accum = 0;

void* square(void* x) {
   // pthread_mutex_lock(&accum_mutex);
    int xi = (int)x;
    accum += xi * xi;
   // pthread_mutex_unlock(&accum_mutex);

    return NULL; 
}
int main(int argc, char** argv) {
    int i;
    pthread_t ths[20];
    for (i = 0; i < 20; i++) {
        pthread_create(&ths[i], NULL, square, (void*)(i + 1));
    }

    for (i = 0; i < 20; i++) {
        void* res;
        pthread_join(ths[i], &res);
    }

    printf("accum = %d\n", accum);
    return 0;
}