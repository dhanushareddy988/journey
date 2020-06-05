#include<stdio.h>
#include<unistd.h>
#include<pthread.h>


//#include <stdatomic.h>
pthread_mutex_t myMutex;


struct thread_args {
   long balanceA;
    long balanceB;
};

void* thread_func1(void* arg) {                                 
   struct thread_args* args = (struct thread_args*)arg;        
    pthread_mutex_lock(&myMutex);
     if(args->balanceB>=130){
        args->balanceB=args->balanceB-130;
       
       args->balanceA=args->balanceA+130;
       
   
   }
    pthread_mutex_unlock(&myMutex);
   return arg;
}
void* thread_func(void* arg) {                                 
   struct thread_args* args = (struct thread_args*)arg;        
     pthread_mutex_lock(&myMutex);
     if(args->balanceA>=50){
        args->balanceA=args->balanceA-50;
       args->balanceB=args->balanceB+50;
       
   
   }
   return arg;
   pthread_mutex_unlock(&myMutex);
}
int main (int argc, char *argv[]) {

    pthread_t thread1,thread2;
    pthread_mutex_init(&myMutex,0);                            
  struct thread_args args;    
   long balanceA=100;
    long balanceB=100;
     args.balanceA=balanceA;
     args.balanceB=balanceB;
     
      pthread_create(&thread1, NULL, thread_func, &args);
      pthread_create(&thread2, NULL, thread_func1, &args);
    
    
  
    
    pthread_join(thread1, NULL); 
     pthread_join(thread2, NULL);                
    
    

       
   printf(" value is: %ld\n", args.balanceA );
   pthread_mutex_destroy(&myMutex);
   pthread_exit(NULL);
   
}




