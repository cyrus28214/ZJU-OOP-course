#include <iostream>
using namespace std;

struct Student {

    double id;
    double age;

    void print() {
        cout << "ID: "<< id << " Age: " << age << endl;
    }

    Student() {
        id = 0;
        age = 18;
        cout << "Construct a Student by default" << endl;
    }

    ~Student() {
        cout << "Delete student " << id << endl;
    }

};

int main() {

    
    Student s1;
    Student s2;
    s2.id = 1;
    s2.age = 18;

    Student *ps3 = &s2;

    cout << sizeof(Student) << endl;

    s1.print();
    s2.print();
    (*ps3).print();

    Student *ps4;
    ps4 = ps3;
    ps4->print();
    //(*ps4).print();

    cout << &s2 << " " << ps3 << " " << ps4 <<endl;


    Student* ps1 = (Student*)malloc(sizeof(Student));
    cout << ps1->id << endl;

    Student* ps2 = new Student();
    cout << ps2->id << endl;


    return 0;
}