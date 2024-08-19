/*
    explanation: 
        simple approach, since current node is having reference for the previous node also, 
        hence we do not need previous node variable as in case of singly linked list 
        https://www.naukri.com/code360/problems/deletion-in-doubly-linked-list_4609672?interviewProblemRedirection=true&search=doubly%20linked%20&leftPanelTabValue=PROBLEM
*/
void deleteNode(Node * ( & head), int pos) {
    // if there are no node in dll
    if(head == NULL)return;
    // if just one node in the dll
    if(head->next == NULL){
        //if have to delete the head
        if(pos == 0){
            Node* temp = head;
            delete temp;
            head = NULL;
        }
        else{
            cout<<"this node is not present";
        }
    }

    //more than one node will be there
    //if have to delete head
    if(pos == 0){
        Node* prev = head;
        head = head->next;
        //delete prev link of next node
        head->prev = NULL;
        prev->next = NULL;
        delete prev;
        return;
    }
    //deleting any other node which can be 1 to last index
    Node* traverser = head;
    int counter = 0 ;
    while(traverser){
        if(counter == pos){
            traverser->prev->next = traverser->next;
            //for handling the last node condition
            //we are saying if there is a valid node next to traverser then we link it's previous to traverser->prev otherwise it would mean the next is null
            if(traverser->next){
                traverser->next->prev = traverser->prev;
            }
            traverser->prev = NULL;
            traverser->next = NULL;
            delete traverser;
            break;
        }
        counter++;
        traverser = traverser->next;
    }
    return;
}
