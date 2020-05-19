#include<iostream>
#include <emscripten/bind.h>
#include <algorithm>

using namespace emscripten;

struct ProcessMessageOpts {
  bool reverse;
  bool exclaimatory;
  int repeat;
};


std::string result(std::string message, ProcessMessageOpts opts) {
  std::string copy = std::string(message);
  if(opts.reverse) {
    std::reverse(copy.begin(), copy.end());
  }
  if(opts.exclaimatory) {
    copy += "!";
  }
  std::string acc = std::string("");
  for(int i = 0; i < opts.repeat; i++) {
    acc += copy;
  }
  return acc;
}

EMSCRIPTEN_BINDINGS(my_module) {
    
  value_object<ProcessMessageOpts>("ProcessMessageOpts")
    .field("reverse", &ProcessMessageOpts::reverse)
    .field("exclaimatory", &ProcessMessageOpts::exclaimatory)
    .field("repeat", &ProcessMessageOpts::repeat);
    function("result", &result);
  
}