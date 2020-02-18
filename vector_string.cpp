#include <iostream>
#include<vector>

using namespace std;

int main()
{
    vector<string> myString;
    string firstName,secondName,ThirdName;
    cout<<"Enter your First name:"<<"\n";
    getline(cin,firstName);
    cout<<"Enter your Second name:"<<"\n";
    getline(cin,secondName);
    cout<<"Enter your Third name:"<<"\n";
    getline(cin,ThirdName);
    int i = 0,j;
    
    
    myString.push_back(firstName);
    myString.push_back(secondName);
    myString.push_back(ThirdName);
    
    cout<<"";
    for(auto i = myString.begin(); i!=myString.end();i++)
    {
        cout<<*i<<"\n";
    }


    return 0;
}

