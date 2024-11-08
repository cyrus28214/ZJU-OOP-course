#include <iostream> 
using namespace std;
#include <list>
#include <string>
int main( ) {  
    list<string> s;
    s.push_back("hello");  
    s.push_back("world");  
    s.push_front("tide");  
    s.push_front("crimson"); 
    s.push_front("alabama");  
    list<string>::iterator p;
    for (p=s.begin(); p!=s.end(); p++) 
        cout << *p << " ";
    cout << endl;

    for (string tmp : s)
        cout << tmp << " ";
    cout << endl;
    
    for (auto tmp : s)
        cout << tmp << " ";
    cout << endl;
}
