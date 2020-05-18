#include <iostream>

#include <emscripten.h>

using namespace std;
int IsPrime(int value) {
  if (value == 2) { return 1; }
  if (value <= 1 || value % 2 == 0) { return 0; }

  for (int i = 3; (i * i) <= value; i += 2) {
    if (value % i == 0) { return 0; }
  }

  return 1;
}
         
extern "C" {

EMSCRIPTEN_KEEPALIVE
void FindPrimes(int start, int end) {                        
  cout<<"Prime numbers between "<<start<<" and " <<end;

  for (int i = start; i <= end; i += 2) {
    if (IsPrime(i)) {
      cout<<i<<" ";
    }
  }
  cout<<endl;
}

int main() {
  FindPrimes(3, 100000);                                     

  return 0;
}

                                         
}
