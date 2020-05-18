#include <iostream>
using namespace std;
#include <emscripten.h>

int IsPrime(int value) {
  if (value == 2) { return 1; }
  if (value <= 1 || value % 2 == 0) { return 0; }

  for (int i = 3; (i * i) <= value; i += 2) {
    if (value % i == 0) { return 0; }
  }

  return 1;
}
int main() {
  int start = 2;
  int end = 100;

  cout<<"Prime numbers between "<<start<< " and "<< end<<endl;

  for (int i = start; i <= end; i += 1) {
    if (IsPrime(i)) {
      cout<<i<<" ";
    }
  }
  cout<<endl;

  return 0;
}