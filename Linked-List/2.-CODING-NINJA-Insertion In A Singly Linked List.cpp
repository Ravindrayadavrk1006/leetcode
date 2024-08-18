/*
    explanation-> 
        in linked list always remember to handle the base test cases
            1. if the head is null then the node can be inserted at 0th position only
            2. if to insert at 0th position i.e head then we create a node and make it as head and 
            3. if inserting at any other position 1 to ...last
                we normally stand at one postion behind and check if this position is counter = pos-1 if so we insert at that position


        **important 
            also remember if given the value of node to be inserted instead of position exactly similar code will be used instead of position just the value will come nothing else will change

*/
Node * insert(Node * head, int n, int pos, int val) {
    if(head == NULL){
        //if the head is null then the node can be inserted at index 0 only
        if(pos == 0){
            Node* temp = new Node(val);
            return temp;
        }
    }
    //inserting at start
    if(pos == 0){
        Node* temp = new Node(val);
        temp->next = head;
        return temp;
    }
    //if inserting at any other index i.e 1 or further
    int counter = 0;
    Node* traverser = head;
    //if the node has not reached the null 
    while(traverser){
        if(counter == pos-1){
            Node* temp = new Node(val);
            //this line is done first so that we don't loose reference for traverser->next
            temp->next = traverser->next;
            traverser->next = temp;
            break;
        }
        counter++;
        traverser = traverser->next;
    }
    return head;
}
