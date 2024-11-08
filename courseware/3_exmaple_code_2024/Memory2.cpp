#include <iostream>
using namespace std;

extern int global_i;
//extern int static_global_i;  // Error

void print_global() {
    cout << "global_i:" << global_i << endl;
    //    cout << static_global_i << endl; // Error

    static int static_local_t = 0; 
    static_local_t++;
    cout << "static_local_t:" << &static_local_t << " " << static_local_t << endl; 

    int local_t = 0; // Non-static local variable must be initialized to avoid undefined behavior.
    local_t++;
    cout << "local_t:" << &local_t << " " << local_t << endl; 

}