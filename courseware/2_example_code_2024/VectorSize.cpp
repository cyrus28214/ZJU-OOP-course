#include <iostream>

#include <vector>
#include <iostream>
using namespace std;

void print_size(vector<int>& v)
{
    cout<< "size: " << v.size() <<" capacity: " << v.capacity() << endl;
}

int main( ) {
    vector<int>  v(151);
    v[10] = 10;
    print_size(v);
    cout << v[10] <<" " << v[11] << endl;

    v.push_back(10);
    print_size(v);
    v.push_back(200);
    print_size(v);

    v.resize(1000);
    print_size(v);

    v.reserve(2000);
    print_size(v);

    v.clear();
    print_size(v);
    
    v.shrink_to_fit();
    //vector<int>().swap(v);
    print_size(v);
}

