#include <iostream>
using namespace std;

int global_i = 10;
static int static_global_j;
void print_global();

int main() {

    int local_k;
    static int static_local_m;
    int* local_p = (int*)malloc(sizeof(int));

    cout << "Hello World!" << endl;
    cout << "global_i position: " << &global_i << endl;
    cout << "static_global_j position: " << &static_global_j << endl;
    cout << "static_local_m position: " << &static_local_m << endl;

    cout << "local_k position: " << &local_k << endl;
    cout << "local_p value: " << local_p << endl;
    cout << "local_p position: " << &local_p << endl;

    for (int i =0; i< 5; i++)
    {
        print_global();
    }
 //   int* a = new int;

 //   cout << *a << endl;

 //   int x = 3;
 //   const int& z = x;
 //   cout << z << endl;
 //   x = 5;
 //   cout << z << endl;

    return 0;
}