#include <iostream>
using namespace std;


class A {
public:
	A() { i = 10; cout << "A()" << i<< endl; }
	~A() { cout << "~A()" <<endl;}
public:
	int i;
};

class B : public A {
public:
	B() { i = 20; cout << "B()" << i << endl; }
	~B() {cout << "~B()" <<endl;}
public:
	int i;
};

int main() {
	cout << sizeof(A) << " " << sizeof(B) << endl;
	B b;
	cout<< b.i << " " << b.A::i  <<endl;

	//int* p = (int*) &b;
	//cout << p[0] << " "<< p[1] <<endl;
}
