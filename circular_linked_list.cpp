/****************************************
 Programe to implement CIRCULAR LinkedList 
 using structure and class 
 Author :Partha Pratim Dey
 
 ****************************************/


#include<iostream>
using namespace std;
struct node // making a node of structure type
{
    int data;
    node *next;
};	
class Circular_LL
{
	private :
	node *START;
	public :
	Circular_LL( ) //constructor to intialize the start pointer
	{
		START = NULL ;
	}
	void createNode()
	{
		int data;
		cout<<"enter an element"<<endl;
		cin>>data;
		node* temp = new node ; // allocating memory to new node
		node* ptr = START ; // to keep START intact
		temp->data = data ;
		
		//if the list is NOT empty
    	if(START != NULL)
		{
			while(ptr->next != START)
			    ptr = ptr->next ;
			ptr->next = temp ; // last node pointing the newly created node
			temp->next = START ;
		}
		else // Incase of empty node
		{
		temp->next = temp ;// new node pointing to itself
		START = temp ;
	}
	}
	void display() 
	{ 
       node*  ptr;
       ptr = START;
   do 
   { 
      cout<< ptr->data <<" "; 
      ptr = ptr->next; 
   } while(ptr != START);
   
   
  // cout<<ptr->next<<endl; //JUST trying to see the address of START node here
   
   
   if(ptr == START)       // to ensure circular linked list 
   cout<<"\nyes it is a circular linked list"<<endl;
   else
    cout<<"NO it is NOT a circular linked list"<<endl; 
    
    
   }
}; 
int main()
{
	Circular_LL obj ; // creating an object of class circular_LL
	int option ;
	cout<<"CIRCULAR LINKED LIST"<<endl;
	cout<<" 1 . insert element"<<endl;
	cout<<" 2 . display the list"<<endl;
	cout<<" 3 . exit"<<endl;
	do
	{
		cout<<"choose any one option"<<endl;
		cin>>option;
		switch(option)
		{
			case 1:
				obj.createNode();
			    break;
			case 2:
				obj.display();
			case 3:
				exit(0);
				break ;
			default :
				cout<<"Invalid Choice"<<endl;
				break;
	    }
	}while(option != 3);
	return 0;
}

