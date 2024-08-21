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
    
        simple approach understand by taking two nodes , then three nodes , then four nodes example
        we take two pointer ->leader and follower, leader is placed at next to head and follower at head node.
        

        //changing pointers==>
        the below things we keep doin till follwer pointer != null
        we store leader->next in a temp var 
        leader->next = follower 
        imptortant points
                    we check if temp var is null or temp->next = null we set follwer to temp and break the loop because we need atleast two next pointers to do the swapping
                    if temp or temp->next is not null we set follwer->next = temp->next and then move follwer to temp and leader to temp->next
                    
                    
        we already store the head->next = head_return and return this head
    
    */
    ListNode* swap_helper(ListNode* head)
    {

        //if no node or just 1 node
        if(head== NULL || head->next == NULL)return head;
        //more than one node
        ListNode* head_return = head->next;
        ListNode* first = head->next;
        ListNode* second = head;
        while(first != NULL)
        {
            ListNode* temp = first->next;
            first->next = second;
            
            // second = temp;
            if(temp == NULL || temp->next == NULL)
            {
                second->next = temp;
                break;
            }
            else
            {
                second->next = temp->next;
            }
            first = temp->next;
            second = temp;
        }
        return head_return;
    }
public:
    ListNode* swapPairs(ListNode* head) {
        return swap_helper(head);
    }
};
