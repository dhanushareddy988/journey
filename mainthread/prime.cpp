#include<iostream>
#include <vector>
#include <chrono>

int IsPrime(int value) {
  if (value == 2) { return 1; }
  if (value <= 1 || value % 2 == 0) { return 0; }

  for (int i = 3; (i * i) <= value; i += 2) {
    if (value % i == 0) { return 0; }
  }

  return 1;
}
void FindPrimes(int start, int end,
    std::vector<int>& primes_found) {           
  for (int i = start; i <= end; i += 2) {
    if (IsPrime(i)) {
      primes_found.push_back(i);                
    }
  }
}
int main() {
  int start = 3, end = 1000000;
  std::cout<<"Prime numbers between "<<start<<" and "<< end<<std::endl;

  std::chrono::high_resolution_clock::time_point duration_start =
      std::chrono::high_resolution_clock::now();                    

  std::vector<int> primes_found;
  FindPrimes(start, end, primes_found);                             

  std::chrono::high_resolution_clock::time_point duration_end =
      std::chrono::high_resolution_clock::now();                    

  std::chrono::duration<double, std::milli> duration =
      (duration_end - duration_start);                              

  std::cout<<"FindPrimes took "<< duration.count()<<" milliseconds to execute"<< std::endl;

  std::cout<<"The values found:"<<std::endl;
  for(int n : primes_found) {                                       
    std::cout<<n<<" ";
  }
  std::cout<<std::endl;

  return 0;
}

