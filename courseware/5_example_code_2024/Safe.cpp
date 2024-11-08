#include <iostream>
using namespace std;

#define unsafe(i) ((i)>=0?(i):-(i))

inline int safe(int i)
{
    return i >= 0 ? i : -i;
}

int main()
{

    int j = -4;
    cout << unsafe(j++) << endl;
    cout << j << endl;;

    int jj = -4;
    cout << safe(jj++) << endl;
    cout << jj << endl;

}
