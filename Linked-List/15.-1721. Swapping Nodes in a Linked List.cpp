/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode() : val(0), next(nullptr) {}
 *     ListNode(int x) : val(x), next(nullptr) {}
 *     ListNode(int x, ListNode *next) : val(x), next(next) {}
 * };
 */
class Solution {
private:
    /*
        APPROACH : we start from head and move a pointer traverser k position from start
    after traverser has moved k positions :
     we do following things
        1. set another pointer k_from_last at head , this is done to find k_th element from last;
        2. set k_from_start at traverser to state that it is k_th position from start 
        

    once above variables are set we start moving traverser and k_from_last one by one node simultaneously so that traverser reaches at last node and k_from_last at k nodes from last .

    finally we swap values of k_from_start and k_from_end
    
    */
    ListNode* swap_helper(ListNode* head, int k)
    {
        if(head == NULL)return head;
        ListNode* store_head = head;
        ListNode* k_from_last = NULL;
        ListNode* traverser = head;
        ListNode* k_from_start = NULL;
        int pos = 1;
        while(pos < k  && traverser->next != NULL)
        {   
            traverser = traverser->next;
            pos++;
        }
        // if(traverser == NULL)return head;
        // else
        // {
        k_from_last = head;
        k_from_start = traverser;
        // }
        while(traverser->next != NULL)
        {
            k_from_last = k_from_last->next;
            traverser = traverser->next;
        }
        //traversing k from start
        int temp = k_from_start->val ;
        k_from_start->val = k_from_last->val;
        k_from_last->val = temp;
        return head;
    }
public:
    ListNode* swapNodes(ListNode* head, int k) {
        return swap_helper(head, k);   
    }
};
