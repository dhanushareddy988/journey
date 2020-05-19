#include<iostream>
#include <emscripten/bind.h>
using namespace emscripten;
class MyClass {
    private:
    int x;
    float y;
public:
  MyClass(int x, float y) :x(x),y(y){}
  int displayx(){
      return x;
  }
  float displayy(){
      return y+x;
  }
 // void someFunction();
};

EMSCRIPTEN_BINDINGS(external_constructors) {
  class_<MyClass>("MyClass")
    .constructor<int, float>()
    .function("displayx", &MyClass::displayx)
    .function("displayy", &MyClass::displayy)
    ;
}