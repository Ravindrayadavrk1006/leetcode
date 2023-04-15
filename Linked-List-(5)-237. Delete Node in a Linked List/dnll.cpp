/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
    /*
        easy approach --> we are just taking approach of setting next node value in current node , done till last node 
    
    */
public:
    void deleteNode(ListNode* node) {
        //we keep on moving the values one node back till second last node 
        while(node->next->next != NULL)
        {
            node->val = node->next->val;
            node = node->next;
        }
        //we set the value of last node in second last node
        node->val = node->next->val;
        //set second last node to null to make the LL of size one less node
        node->next = NULL;
    }
};
