//: C06:AutoDefaultConstructor.cpp
// From Thinking in C++, 2nd Edition
// Available at http://www.BruceEckel.com
// (c) Bruce Eckel 2000
// Copyright notice in Copyright.txt
// Automatically-generated default constructor

#include <iostream>
using namespace std;

class Y {
  int m_i;  // private

  public:
  Y(int i) {m_i = i;} 
  Y() {}  // Since a self-defined constructor, i.e.,  Y(int i), exists, Y() {} will be not be created by default; otherwise, it will be created by default. 
};

/*
class MyClass {
private:
    int a;
    double b;
public:
    MyClass(int x, double y) : b(y), a(b + x) { cout<< a << " " << b <<endl;}  // Even though 'b' is before 'a' in the list, 'a' is initialized first!
};
*/

int main() {
  Y v1, v2[10]; // If there is not Y(){}, there will be error. 
  Y v3[2] = {Y(1)}; // If there is not Y(){}, there will be error. 

  int b[6] = {5};
  for(int i = 0; i < sizeof(b)/sizeof(*b); ++i)
    cout << b[i] <<endl;
  
  //MyClass a(3, 4);

} ///:~
