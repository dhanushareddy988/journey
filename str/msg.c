#include<stdlib.h>
#include<stdio.h>
#include<emscripten.h>
int main(){
    char* msg=(char*)EM_ASM_INT({
        const greetings="Hello from EM_ASM_INT!";
        const bytecount=(Module.lengthBytesUTF8(greetings)+1);
        const greetingsPointer=Module._malloc(bytecount);
        Module.stringToUTF8(greetings,greetingsPointer,bytecount);
        return greetingsPointer;
    });
    printf("%s\n",msg);
    free(msg);
}