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
public:
/*
    idea-> take two pointer master_ptr and slave_ptr we start by placing the slave_ptr at a difference of n from master_ptr and keep moving till master reaches the null and hence slave will be at the required position for the node to be deleted



    CODE EXPLANATION-->
        we start by placing the master_pointer at head and slave_ptr n position behind for n movements slave_ptr will remain nullptr so that master is n_pointer ahead 


*/
    ListNode* removeNthFromEnd(ListNode* head, int n) {

        //we have kept master_ptr at head initially
        ListNode* master_ptr = head;
        int diff = n;
        ListNode* slave_ptr= head; 

        /*
            since the master_ptr is kept at head and hence for 
            in first example 
            for diff = 2 master_ptr will be at node 2
            for diff = 1 master node will at 3 
            for diff = 0 master will be at 4 and slave_ptr will be at node 1
        
        */
        while(master_ptr != nullptr)
        {
            if(diff>0){
                slave_ptr = nullptr;
            }
            else if(diff == 0)
            {
                slave_ptr = head;
            }
            else
            {
                slave_ptr=slave_ptr->next;
            }
            diff--;
            master_ptr = master_ptr->next;
        }
        //deleting the head node

        //logic if slave_ptr has not reached the head and master_ptr has reached last node it means we have to delete the head node hence we delete the head node 
        if(slave_ptr == nullptr && master_ptr ==nullptr)
        {
            head = head->next;
            return head;
        }
        slave_ptr->next = slave_ptr->next->next;
        return head;

    }
};
