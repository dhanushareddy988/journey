#include <iostream>
  #include <emscripten.h>
 
using namespace std; 
  
class A { 
public: 
    virtual void fun_a() 
    { 
        cout << " In class A\n"; 
    } 
}; 
  
class B { 
public: 
    virtual void fun_b() 
    { 
        cout << " In class B\n"; 
    } 
}; 
  
int main() 
{ 
    // creating object of class B 
    A *a = new A();
        B* x = new B(); 
  
    // converting the pointer to object 
    // referenced of class B to class A 
    a->fun_a();
   a = reinterpret_cast<A*>(x); 
  
    // accessing the function of class A 
    a->fun_a(); 
    return 0; 
} 

 