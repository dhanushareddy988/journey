
#include<iostream>
#include <emscripten/bind.h>
using namespace emscripten;

class Count {
public:
  int x;

  Count(int init) :
    x(init) {
  }

  void increase() {
    x++;
  }

  int squareCount() {
    return x * x;
  }
};

EMSCRIPTEN_BINDINGS(my_module) {
  class_<Count>("Count")
    .constructor<int>()
    .function("increase", &Count::increase)
    .function("squareCount", &Count::squareCount)
    .property("x", &Count::x);
}