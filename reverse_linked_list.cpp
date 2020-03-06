 /*****************************************************
 	Program to reverse a linklist
 	Author-- Partha Pratim Dey
 	Date-- 6 / 3 / 2020
 
 *******************************************************/
 
 #include<iostream>
 using namespace std;
 
 struct node{
 	int data;
 	node *next;
 	node *prev;
};

node *start = NULL;

void insert(int data){
	node *new_node,*ptr;
	new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	if(start == NULL){
		start = new_node;
		new_node->next = NULL;
		new_node->prev = NULL;
	}
	else{
		ptr = start;
		while(ptr->next!=NULL)
			ptr = ptr->next;
		ptr->next = new_node;
		new_node->prev = ptr;
		new_node->next = NULL;
	}
}

void display()
{
	node *ptr;
	
	if(start == NULL)
	{
		cout<<"\nThere is no element in the list..\n";
	}
	else{
		ptr = start;
		while(ptr!=NULL)
		{
			cout<<ptr->data<<"-->";
			ptr = ptr->next;
		}
		cout<<"NULL\n";
	}
}

void display_reverse(){
	node *last;
	if(start == NULL)
		cout<<"list is empty\n";
	else{
		last = start;
		while(last->next!=NULL)
			last = last->next;
		while(last!=NULL){
			cout<<last->data<<"-->";
			last = last->prev;
		}
	cout<<"NULL\n";	
}
}

int main(){
	int data,option;
	while(1){
		cout<<"----Operations----"<<endl;
		cout<<"----1.Insert----"<<endl;
		cout<<"----2.Display----"<<endl;
		cout<<"----3.Display Reverse----"<<endl;
		cout<<"----4.Exit----"<<endl;
		cout<<"----Now Enter Your Option----"<<endl;
		cin>>option;
		switch(option){
			case 1:
				cout<<"Please enter the data:\n";
				cin>>data;
				insert(data);
				break;
			case 2:
				cout<<"Normal data print\n";
				display();
				break;
			case 3:
				cout<<"Data Print in reverse order\n";
				display_reverse();
				break;
			case 4:
				exit(0);
				break;
			default:
				cout<<"please enter a valid option.....\n";
				break;
		}
	}
	return 0;
}
