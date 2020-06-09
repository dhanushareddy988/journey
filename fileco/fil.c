#include<stdio.h>
#include<stdlib.h>
#include<string.h>
#include<pthread.h>

pthread_mutex_t myMutex;
void* thread_func1(void* handle) {                                 
     
    pthread_mutex_lock(&myMutex);
   handle = fopen("test", "wb");
  
   fputs("hello from file2!", handle);
    fputs("This shows how to write2!", handle);
   
   fclose(handle);
     pthread_mutex_unlock(&myMutex);
   return NULL;
  
}
void* thread_func(void* handle) {                                 
     
   pthread_mutex_lock(&myMutex);
   handle = fopen("test", "wb");
   
   fputs("hello from file!", handle);
    fputs("This shows how to write!", handle);
    
   fclose(handle);
     pthread_mutex_unlock(&myMutex);
   return NULL;
  
}
int main(){
    FILE *handle = fopen("test", "wb");
    
   
   
     pthread_t thread1,thread2;
     pthread_mutex_init(&myMutex,0);  
     
      pthread_create(&thread1, NULL, thread_func, (void*)handle);
      pthread_create(&thread2, NULL, thread_func1, (void*)handle);
      pthread_join(thread1, NULL);
      pthread_join(thread2, NULL); 
      pthread_mutex_destroy(&myMutex);           
     fclose(handle);
	handle = fopen("test", "r");
	char str[256] = {};
	fgets(str, 255, handle);
	 printf("%s\n", str);
   
    return 0;
}