/*
  simply how to use previous node pointer for deleting a node 
  also remember if given the value of node to be deleted instead of position exactly similar code will be used instead of position just the value will come nothing else will change


*/


/****************************************************************
 
    Following is the class structure of the Node class:

        class Node
        {
        public:
	        int data;
	        Node *next;
	        Node(int data)
	        {
		        this->data = data;
		        this->next = NULL;
	        }
        };

*****************************************************************/

Node *deleteNode(Node *head, int pos)
{
	//if there are no node in the linked list
	if(head == NULL)return head;
	//temp is the traveser pointer we are using
	Node* temp = head;

	//deleting the head
	if(pos == 0){
		head = head->next;
		delete temp;   //delete the node
		return head;
	}
	int counter = 0 ;
	//since we need to delete a node we will remember it's previous as well
	Node* prev = NULL; //initally the previous will be behind head
	while(temp != NULL){
		//if we found the traverser
		if(counter == pos){
			prev->next = prev->next->next;
			delete temp;
			break;
		}
		counter++;
		prev = temp;
		temp = temp->next;
	}
	return head;
}
