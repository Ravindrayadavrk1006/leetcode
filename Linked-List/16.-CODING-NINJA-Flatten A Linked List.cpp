#include <bits/stdc++.h>

/****************************************************************

    Following is the class structure of the Node class:

class Node {
public:
	int data;
	Node* next;
	Node* child;

	Node(int data) {
		this->data = data;
		this->next = NULL;
		this->child = NULL;
	}
};


*****************************************************************/

/*
simple function which merge two linked lists
we take a temporary node for easy solution

*/
Node* merge_ll(Node* first, Node* second)
{
	Node* res = new Node(-1);
	Node* temp = res;
	while(first != NULL && second != NULL)
	{
		if(first->data <second->data)
		{
			temp->child = first;
			temp = temp->child;
			first = first->child; 
		}
		else{
			temp->child = second;
			temp = temp->child;
			second = second->child;
		}
	}
	if(first != NULL)
	{
		temp->child = first;
	}
	else{
		temp->child = second;
	}
	return res->child;

}
/*
	here we are using recusion to call the linked lists to merge them first last two ll will be merged . i.e from right to left the merging of linked list is taking place

*/
Node* sol_1(Node* head)
{
	//we say it is last child ll hence we return it
	if(head == NULL || head->next == NULL)return head;
	
	//storing the last node in head->next and current node in head and then calling the merge function
	head->next = sol_1(head->next);
	head = merge_ll(head,head->next);
	return head;

}
Node* flattenLinkedList(Node* head) 
{
	return sol_1(head);
}
