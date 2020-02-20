/*---- Link List program----*/
/*----With Insert Dispaly And Delete Function----*/
/*----Author: Partha Pratim Dey----Date-20/2/2020----*/

#include<stdio.h>
#include<malloc.h>
typedef struct node{
	int data;
	struct node *next;
}node;

node *start = NULL;
//------Insert Function-----
void insert(int data){
	node *new_node,*ptr;
	new_node = (node*)malloc(sizeof(node));
	new_node->data = data;
	if(start == NULL){
		start = new_node;
		new_node->next = NULL;
	}
	else{
		ptr = start;
		while(ptr->next!=NULL)
			ptr = ptr->next;
		ptr->next = new_node;
		new_node->next = NULL;
	}
}
//-----Display function------
node dispaly()
{
	node *ptr;
	
	if(start == NULL)
	{
		printf("\nThere is no element in the list..\n");
	}
	else{
		ptr = start;
		while(ptr!=NULL)
		{
			printf("%d-->",ptr->data);
			ptr = ptr->next;
		}
		printf("NULL");
	}
}
//------Delete Function-----
node delete_from_end(){
	node *ptr,*prev_node;
	ptr = start;
	if(ptr->next==NULL){
		start = NULL;
		free(ptr);
		printf("Node is deleted..\nyou can check");
	}
	else{
		while(ptr->next!=NULL)
		{
			prev_node = ptr;
			ptr = ptr->next;
		}
		prev_node->next = NULL;
		free(ptr);
		printf("Node is deleted..\nyou can check");
	}
}
//-----Main Function-----
int main()
{
	int option,data;
	while(1){
		printf("\n-----Menu----\n");
		printf("1.Insert\n");
		printf("2.Display\n");
		printf("3.Delete from end\n");
		printf("5.Exit\n");
		printf("Enter your option...\n");
		scanf("%d",&option);
		switch(option){
			case 1: printf("Enter your data-->");
					scanf("%d",&data);
					insert(data);
					break;
			case 2: dispaly();
					break;
			case 3: delete_from_end();
					break;
			case 5: printf("Happy to see you again...\n");
					exit(0);
					break;
			default: printf("please select a correct option..\n");
					 break;
		}
	}
	return 0;
}
