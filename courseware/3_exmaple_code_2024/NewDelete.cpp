#include <iostream>
using namespace std;

struct Student {

    int id;

    void print() {
        cout << id << endl;
    }

    Student() {
        id = 0;
        cout << "Construct a Student by default" << endl;
    }

    ~Student() {
        cout << "Delete student " << id << endl;
    }

};

int main() {

    Student* ps1 = (Student*)malloc(sizeof(Student));
    Student* ps2 = new Student();

    cout << ps1->id << " " << ps2->id << endl;

    //    Student *ps1 = (Student*)malloc(sizeof(Student)*4);
    Student* ps3 = new Student[4];

    for (int i = 0; i < 4; ++i)
    {
        ps3[i].id = i;
    }

    size_t* pc = (size_t*)ps3;

    cout << *(pc - 1) << endl;

    free(ps1);
    delete ps2;
    delete[] ps3;

     ps2 = nullptr;
    delete ps2;
    return 0;

}