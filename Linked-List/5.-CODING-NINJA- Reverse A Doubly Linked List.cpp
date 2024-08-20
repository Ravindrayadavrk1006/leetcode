/*

  problem link-> https://www.naukri.com/code360/problems/reverse-a-doubly-linked-list_1116098?leftPanelTabValue=PROBLEM

  
    BRUTE FORCE APPROACH -> we first traverse to all nodes of dll till last and store every element in a stack. so last element will be at top and first element at last of stack
    now once start traversing from start and start overwriting just the values of node by poping one element from stack at a time and inserting in each node while traversing towrads the end
    t.c O(n+n) = O(2n) , s.c => O(n)


    **CHANGING LINKS:
        in this we swap the link:
            
            i.e in node->prev = store node->next and in node->next store node->prev

*/

Node* reverseDLL(Node* head)
{
    Node* traverser = head;
    //after doing this link swapping and reversing the dll, the last node will be dll
    while(traverser){
        //swapping the link
        Node* temp = traverser->prev;
        traverser->prev = traverser->next;
        traverser->next = temp;
        //last node will be head and hence we are saving the head
        if(traverser->prev == NULL)head = traverser;
        //now next node will be in previous so let's move to that
        traverser = traverser->prev;
    }
    return head; 
}
