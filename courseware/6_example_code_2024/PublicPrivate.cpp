// C++ program to demonstrate the working of public inheritance

#include <iostream>
using namespace std;

class Base {
private:
    int pvt = 1;

protected:
    int prot = 2;

public:
    int pub = 3;

    // function to access private member
    int getPVT() {
        return pvt;
    }
};

class PublicDerived : public Base {
public:
    // function to access protected member from Base
    int getProt() {
        return prot;
    }
};

int main() {
    PublicDerived object1;
    cout << "Public = " << object1.pub << endl;
    cout << "Protected = " << object1.getProt() << endl;
    cout << "Private = " << object1.getPVT() << endl;
    return 0;
}