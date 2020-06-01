#include<iostream>

struct Base{
   Base(){}
   virtual ~Base() {}
   virtual void printme(){
   std::cout << "Base::printme" << std::endl;
}
};
struct Derived: Base{
    Derived(){}
    virtual ~Derived() {}
    virtual void printme(){
    std::cout<<"Derived::printme\n";
}
};
struct Evil{
Evil(){}
virtual ~Evil() {}
virtual void wrongpath(){
std::cout<<"Evil::wrongpath\n";
}
};
int main(){
    Evil *eptr = new Evil();
    Derived *dptr = new Derived();
    dptr->printme();
    dptr = reinterpret_cast<Derived*>(eptr);
    dptr->printme();
    return 0;
    }