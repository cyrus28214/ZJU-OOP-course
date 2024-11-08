#include <iostream>
#include <list>
#include <string>  
#include <iterator>

using namespace std;

int main( ) {
list<string> s; 
string t;  
list<string>::iterator p;  
for (int a=0; a<5; a++) {
	cout << "enter a string : "; 
 	cin >> t;
	p = s.begin();
	while (p != s.end() && *p < t)  
		p++;
	s.insert(p, t);
}
for (p=s.begin(); p!=s.end(); p++)
	cout << *p << " ";
cout << endl;	

/*
list<int> L;
for(int i=1; i<=5; ++i)
	L.push_back(i);

//delete second item.
L.erase( ++L.begin() );

// Prints: 1,3,4,5,
copy(L.begin(), L.end(), ostream_iterator<int>(cout, ","));
*/

}

