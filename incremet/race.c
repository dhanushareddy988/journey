#include <pthread.h>
#include <stdio.h>

// Calculate Fibonacci numbers shared function
int increment(int a) {
    a++;
    return a;
}
// Start function for the background thread
void *bg_func(void *arg) {
    int     *iter = (void *)arg;

    *iter = increment(*iter);
    return arg;
}
// Foreground thread and main entry point
int main(int argc, char *argv[]) {
    int c = 8;
   
    pthread_t   bg_thread[4];
    
    
    for(int i=0;i<4;i++){
    if (pthread_create(&bg_thread[i], NULL, bg_func, &c)) {
        perror("Thread create failed");
        return 1;
    }
    }
    
    for(int i=0;i<4;i++){
    if (pthread_join(bg_thread[i], NULL)) {
        perror("Thread join failed");
        return 1;
    }
    }

    
    printf("%d\n", c);

    return 0;
}