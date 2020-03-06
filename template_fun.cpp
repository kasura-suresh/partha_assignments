/*************************************************

	program to implement temmplete function
	Author-- Partha Pratim Dey
	
*************************************************/

#include <iostream>
using namespace std;
template<typename P> 
P maxFun(P a,P b)
{
   	if(a > b)
   		return a;
	else
		return b;
}

int main()
{
    cout<<maxFun<int>(5,8)<<endl;
    cout<<maxFun<float>(8.36,5.2)<<endl;
    return 0;
}
