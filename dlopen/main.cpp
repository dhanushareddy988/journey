#include<iostream>
#include<dlfcn.h>
#include<emscripten.h>
using namespace std;
extern "C"{
   
    typedef void(*FindPrimes)(int,int);
       void CalculatePrimes(const char* prime) {
  void* handle = dlopen("prime.wasm", RTLD_NOW);      
  if (handle == NULL) { return; }

  FindPrimes find_primes =
      (FindPrimes)dlsym(handle, "FindPrimes");     
  if (find_primes == NULL) { return; }

  find_primes(3, 100);                          

  dlclose(handle);                                 
}
    int main() {
  emscripten_async_wget("prime.wasm",     
      "prime.wasm",                       
      CalculatePrimes,                               
      NULL); 
      
                                      

  return 0;
}



}
