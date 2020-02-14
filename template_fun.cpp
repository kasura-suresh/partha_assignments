#include <iostream>
using namespace std;
template<class X,class Y> 
float fun(X a,Y b)
{
   return a+b;
}

int main()
{
    float b;
    b=fun(56,14.3);
    cout<<b;
    return 0;
}
