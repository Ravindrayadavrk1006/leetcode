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
        approach:
        what we do is we have taken two extra nodes n1 and n2 
        and we attach the elements which are smaller than x to n1 and which bigger or equal to n2 and finally when the given list is finished or we have traversed all the elements of given linked list we attach the last node of nodes attached to n1 to the next element of n2(since n2 is extra node)and we return the next node of n1 as head 
    
    
    */
    ListNode* sol(ListNode* head, int x)
    {
        ListNode n1 = ListNode();
        ListNode* temp1 = &n1;
        ListNode* store_temp1 = temp1;
        ListNode n2 = ListNode();
        ListNode* temp2 = &n2;
        ListNode* store_temp2 = temp2;
        while(head != NULL)
        {
            if(head->val < x)
            {
                temp1->next = head;
                temp1 = head ;
            }
            else
            {
                temp2->next = head;
                temp2 = head;
            }
            head = head->next;
        }
        store_temp2 = store_temp2->next;
        temp1->next = store_temp2;
        temp2->next = NULL;
        return store_temp1->next;
    }
public:
    ListNode* partition(ListNode* head, int x) {
        return sol(head, x);
    }
};
