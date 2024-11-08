#include <iostream>
using namespace std;


struct Student{
    int id;
    char address[10000]; 
};

void foo1(Student s)
{
    cout << s.id <<endl;
}

void foo2(Student *s)
{
    cout << s->id <<endl;
}

void foo3(Student &s)
{
    cout << s.id <<endl;
}

int main()
{
	Student s;
    s.id = 0;

    foo1(s);
    foo2(&s);
    foo3(s);

	return 0;
}