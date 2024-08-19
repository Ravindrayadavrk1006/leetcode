/*
    simple approach , in it we are standing at one place before where to insert since asked to insert at k 
    so in 0 based indexing we will stand at k-1th node and try to insert from there

*/

Node* insert(int k, int val, Node *head) {

    //inserting at begining
    if(k==0){
        Node* temp = new Node(val);
        temp->next = head;
        head->prev = temp;
        head = temp;
        return head;
    }
    //will have to insert at 1 or further positions
    Node* traverser = head;
    int counter = 0;
    while(traverser){
        //we are standing one node before that node
        if(counter == k-1){
            Node* temp = new Node(val);
            temp->prev = traverser;
            temp->next = traverser->next;
            //this if condition to check if traverser is not the last node since traverser->next will not exist then
            if(traverser->next){
                traverser->next->prev = temp;
            }
            traverser->next = temp;
            break;
        }
        counter++;
        traverser = traverser->next;
    }
    return head;
}
