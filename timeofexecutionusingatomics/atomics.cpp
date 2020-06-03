#include<iostream>
#include <chrono>
//#include<cstdio.h>
#include<pthread.h>

#include <stdatomic.h>

#define NUM_THREADS     10
#define NUM_INCREMENTS  100000

atomic_int counter;

void *AddThings(void *threadid) {
   for (int i = 0; i < NUM_INCREMENTS; i++){
       
        counter++;
        
   }
   pthread_exit(NULL);
}

int main (int argc, char *argv[]) {
   pthread_t threads[NUM_THREADS];
   long t;
    std::chrono::high_resolution_clock::time_point duration_start =
      std::chrono::high_resolution_clock::now(); 
   for(t = 0; t<NUM_THREADS; t++){
      int rc = pthread_create(&threads[t], NULL, AddThings, (void *)t);
      if (rc){
         printf("ERROR; return code from pthread_create() is %d\n", rc);
         return 1;
      }
   }

   for (t = 0; t < NUM_THREADS; t++)
       pthread_join(threads[t], NULL);
       
  std::chrono::high_resolution_clock::time_point duration_end =
      std::chrono::high_resolution_clock::now();                    

  std::chrono::duration<double, std::milli> duration =
      (duration_end - duration_start);                              

  std::cout<<"FindPrimes took "<< duration.count()<<" milliseconds to execute"<< std::endl;
       
   printf("Final value of counter is: %d\n", counter);
   
   pthread_exit(NULL);
   
}