#include<iostream>
#include<emscripten.h>
using namespace std;
typedef struct UAF {
 void (*vulnfunc)();
} UAF;
extern "C"{
    void before(){
        cout<<"before delete "<<endl;
    }
    void after(){
        cout<<"after delete "<<endl;
    }
    }
int main() {
    UAF *uaf = new UAF;
    printf("sizeof(UAF) = %d\n", (int)sizeof(UAF));
    uaf->vulnfunc = before;
    printf("Address of function before UAF: %x\n",(int)(uaf->vulnfunc));
    uaf->vulnfunc();
    delete(uaf);
    long *newobj = new long(8);
    *newobj = (long)after;
    printf("Address of function after UAF: %x\n",(int)(uaf->vulnfunc));
    uaf->vulnfunc();
    return 0;
}




