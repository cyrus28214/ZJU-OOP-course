// C++ program to demonstrate the working of friend class

#include <iostream>
using namespace std;

// forward declaration
class ClassB;

class ClassA {
private:
    int numA;

    // friend class declaration
    //friend class ClassB;

    // friend function declaration
    friend int addAB(ClassA, ClassB);

public:
    // constructor to initialize numA to 12
    ClassA() : numA(12) {}
};

class ClassB {
private:
    int numB;

    // friend function declaration
    friend int addAB(ClassA, ClassB);

public:
    // constructor to initialize numB to 1
    ClassB() : numB(1) {}

    // member function to add numA
    // from ClassA and numB from ClassB
    //int add() {
    //    ClassA objectA;
    //    return objectA.numA + numB;
    //}
};

// access members of both classes
int addAB(ClassA objectA, ClassB objectB) {
    return (objectA.numA + objectB.numB);
}

int main() {
    ClassB objectB;
    //cout << "Sum: " << objectB.add() << endl;

    ClassA objectA;
    cout << "Sum: " << addAB(objectA, objectB) << endl;

    return 0;
}