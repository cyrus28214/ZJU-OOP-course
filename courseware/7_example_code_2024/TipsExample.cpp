#include<iostream>
using namespace std;

class Base { 
public: 
	void nonVirtualFunc() { cout << "Base::nonVirtualFunc" << endl;} 
	virtual void virtualFunc(int x = 10) { cout << "Base " <<  "x: "  << x << endl;} 
}; 

class Derived : public Base { 
public: 
	void nonVirtualFunc() { cout << "Derived::nonVirtualFunc" << endl; } 
	void virtualFunc(int x = 20) override { cout <<  "Derived x: " << x << endl;} 
}; 

int main(){
	Derived d;
	Base& b = d;
	
	b.nonVirtualFunc();
	b.virtualFunc();
	d.virtualFunc();		
}

