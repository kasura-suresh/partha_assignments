/*************************************************

	program to implement usefull array alogithm
	Author-- Partha Pratim Dey
	
*************************************************/

#include<iostream>
#include<algorithm>
using namespace std;
int main()
{
	int a[5] = {1,2,5,6,7};
	 all_of(a, a+5, [](int x) { return x>0; })? 
          cout << "All are +ve elements in array a[]\n" : 
          cout << "All are not +ve elements\n";
	int a1[5] = {1,-2,5,-4,7};
	any_of(a1, a1+6, [](int x){ return x<0; })? 
          cout << "In array a1 There exists -ve elements\n" : 
          cout << "All are +ve elements\n"; 
    none_of(a, a+5, [](int x){ return x<0; })? 
          cout << "No negative elements in array a[]\n" : 
          cout << "There are negative elements\n";
    int new_arr[5];
    copy_n(a1,5,new_arr);
    cout<<"After copy from array a1[] the new_arr[]:\n";
    for(int i=0;i<5;i++)
    {
    	cout<<new_arr[i]<<" ";
	}
	return 0;
}
