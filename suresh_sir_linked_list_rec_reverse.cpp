/****************************************************
	Revverse the linked list using 
	recursion
	Author - Partha Pratim Dey
*******************************************************/

#include <stdio.h>
#include <iostream>
using namespace std;

// Self referential structure
struct node {
    int data;
    node* next;
};

node* head = NULL;  // singly linked list

void insert(int x) {
    node* n = new node;
    n->data = x;
    n->next = NULL;
   
    if (head == NULL) {
        head = n;
        return;
    }
    node* ptr = head;
    while (ptr->next != NULL)
        ptr = ptr->next;
    ptr->next = n;
}

// use recursion to reverse the list
void recursive_reverse(node* ptr) {
	if(ptr->next == NULL){
		head = ptr;
		return;
	}
	recursive_reverse(ptr->next);
	struct node *q = ptr->next;
	q->next = ptr;
	ptr->next = NULL;
}

void print_list()
{
    node* ptr = head;
    while (ptr != NULL){
        cout << ptr->data << " ";
    	ptr = ptr->next;
	}
    cout << endl;
}

int main()
{
    insert(1);
    insert(2);
    insert(10);
    print_list();
    recursive_reverse(head);
    print_list();
    // printf("Hello World");

    return 0;
}

