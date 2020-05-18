#include<stdio.h>
#include<emscripten.h>


 EMSCRIPTEN_KEEPALIVE
 void say(){
    printf("HI\n");
}
