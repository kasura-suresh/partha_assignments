/*****************************************************************
	Program to implement interators
	Author -- Partha Pratim Dey
	Date -- 12/03/2020
	
******************************************************************/

#include<iostream>
#include<vector>
using namespace std;

int main(){
	vector<int> v;
	int count = 1;
	vector<int>::iterator it;
	for(int i=0;i<=10;i++){
		v.push_back(i);
	}
	for(it = v.begin();it!= v.end();it++){
		cout<<"vector number "<<count<<" :"<<*it<<endl;
		count++;
	}
	return 0;
}
