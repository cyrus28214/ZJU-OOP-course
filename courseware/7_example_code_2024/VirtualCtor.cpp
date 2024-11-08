#include <iostream>
using namespace std;

class A { 
public: 
	A() { f(); } 
	virtual void f() { cout << "A::f()" << endl; }  
}; 

class B : public A { 
public: 
	B() { f(); } 
	void f() { cout << "B::f()" << endl; }
};

int main() {
    A* obj = new B(); 
	
	delete obj; 
    return 0;
}