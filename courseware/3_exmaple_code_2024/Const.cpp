#include <iostream>
using namespace std;

int main()
{
	const char* s1 = "hello world";
	char s2[] = "hello world";

    //s1[0] = 'B';

	int i = 123;
	//cout << " i @" << &i << endl;
	const int* pi = &i;
	//cout << (void *) pi << endl;

	cout << (void*)s1 << endl;
	cout << (void*)s2 << endl;
	cout << (void*)main << endl;
	
	return 0;
}