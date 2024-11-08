// Examples of polymorphism

#include <iostream>
using namespace std;

#pragma pack(push, 1) // #pragma pack(1) will ask the compiler to align each member with 1 Byte.
class Base {
public:
	Base() { age = 10; }
	virtual void func() { cout << "Base() " << age << endl; }
	virtual void func(int i) { cout << "Base(int) " << age + i << endl; }
	virtual ~Base(){}
protected:
	int age;
};

class Derived : public Base {
public:
	Derived() { age = 100; aged = 20; }
	void func() { cout << "Derived() " << age << " " << aged << endl; }
	virtual ~Derived(){}
protected:
	int aged;
};
#pragma pack(pop)

int main() {
	cout << sizeof(Base) << " " << sizeof(Derived) << endl;

	cout << "----------1------" <<endl;
	Base b, b2;
	Derived d;	
	//cout << d.age << " " << d.aged << endl; //Wrong, since they are protected, they cannot be used outside.

	Base* pb = &d;
	pb->func(); // dynamic -- Derived::func()
	pb->func(1); // dynamic but no overiden funciton in derived -- Base::func(i) 
	//d.func(1); // Wrong, since func(int i) is hidden in the derived.

	/*
	// Sliced
	b = d;
	//b.func();
	pb = &b;
	pb->func();
	*/
	cout << "----------2------" <<endl;
	// Change the vptr directly for better understanding
	void* * ppb = (void* *)&b;
	void* * ppd = (void* *)&d;
	void* vptrb = *ppb;
	void* vptrd = *ppd;
	
	void* * ppb2 = (void* *)&b2;
	void* vptrb2 = *ppb2;
	
	cout<< vptrb << " " << vptrb2 << " " << (void *) main<<endl;
	
	
	*ppb = *ppd;
	pb = &b;
	pb->func();	// Derived::func() since the vptr of b has been changed
	pb->func(1);
	
	b.func(); // static -- Base::func(),  known at compile-time
	
	/*
	void* *vfuncsb = (void* *)vptrb;
	void* f0d = (void*)vfuncsb[0];
	cout << "f0d: " << f0d << endl;
	*/
	
	/*
	// directly call the function with pointer
	cout << " ----------- " << endl;
	int** vp = (int**)pb; // for x64, use long long
	void (*pf) () = (void (*)()) (*(*vp));
	pf();
	*/

}
