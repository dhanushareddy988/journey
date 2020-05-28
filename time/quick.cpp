#include<cstdlib>
#include<chrono>
#include<iostream>
#include<numeric>
#include<vector>
using namespace std::chrono;
#include <algorithm>
#include <iostream>
#include <iterator>
#include <vector>
#include <forward_list>
 
template <class ForwardIt>
 void quicksort(ForwardIt first, ForwardIt last)
 {
    if(first == last) return;
    auto pivot = *std::next(first, std::distance(first,last)/2);
    ForwardIt middle1 = std::partition(first, last, 
                         [pivot](const auto& em){ return em < pivot; });
    ForwardIt middle2 = std::partition(middle1, last, 
                         [pivot](const auto& em){ return !(pivot < em); });
    quicksort(first, middle1);
    quicksort(middle2, last);
 }
 
int main()
{
    std::vector<int> nums(100000, 0);
    std::vector<long> times;
    for(int i=0;i<1000;i++){
        std::generate(nums.begin(), nums.end(), &rand);
        auto now= duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        quicksort(nums.begin(),nums.end());
        auto later= duration_cast<milliseconds>(system_clock::now().time_since_epoch());
        times.push_back(duration_cast<milliseconds>(later-now).count());
    }
    std::cout<<std::accumulate(times.begin(), times.end(),0.0) / times.size()<<"\n";
    return 0;
    
  
 
    
}
