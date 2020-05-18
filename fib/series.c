#include <emscripten.h>

EM_JS(void, two_alerts, (int x), {
  var a=0,b=1;
  for(var i=0;i<x-2;i++){
  $x=a+b;
  a=b;
  b=$x;
  }
  console.log('result ' + $x);
});

int main() {
  
  two_alerts(4);
  return 0;
}