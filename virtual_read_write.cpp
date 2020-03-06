/****************************************************************
	Program to implement virtual memory with read write function
	Author -- Partha Pratim Dey
	Date -- 3 / 5 / 2020
*****************************************************************/
#include<iostream>
using namespace std;

class Processor
{
	public:
		int data;
		virtual int read(){
			return data;
		}
		virtual void write(int num){
			data = num;
		}
};

class Sram : public Processor{
	public:
		int data;
		int read(){
			return data;
		}
		void write(int num){
			data = num;
		}
};

class Dram : public Processor{
	public:
		int data;
		int read(){
			return data;
		}
		void write(int num){
			data = num;
		}
};

int main(){
	Processor *p;
	Sram s;
	Dram d;
	p = &s;
	cout<<"Enter the number you want to write:\n";
	cin>>s.data;
	p->write(s.data);
	cout<<"The number you entered in Sram is:\n";
	s.data = p->read();
	cout<<s.data<<endl;
	p = &d;
	cout<<"Enter the  number for Dram:\n";
	cin>>d.data;
	p->write(d.data);
	cout<<"The number you entered in Dram is:\n";
	d.data = p->read();
	cout<<d.data;
	return 0;
}
