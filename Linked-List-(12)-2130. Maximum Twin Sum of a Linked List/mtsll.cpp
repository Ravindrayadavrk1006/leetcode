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
    //basic approach 
        1. find the middle of linked list here since even no of nodes hence we are taking n/2+1'th middle for our easiness
        2. reverse the second half of linked list assumming the middle found in step 1 as head of second part of linked list
        3. after reversing the second part we will have two linked list one start from the initial given head and other head is at start of second reversered linked list which is last node of actual given list
        4. we find the max sum of siblings by running a looop for n/2 iterations 
    */   
    int sol(ListNode* head)
    {
        // //if just two nodes
        // if(head->next->next == NULL)return head->val+head->next->val;
        ListNode* store_head = head;
        ListNode* fast = head;
        ListNode* slow = head;
        int node_count = 0;
        while(fast != NULL  && fast->next != NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
            node_count +=2;
        }
        //slow will get the middle element
        //let's reverse the second part of the ll
        ListNode* leader = slow;
        ListNode* prev = NULL;
        ListNode* next = NULL;
        while(leader != NULL)
        {
            next = leader->next;
            leader->next = prev;
            prev = leader;
            leader = next;
        }
        //prev will contain the second head;
        ListNode* start_head = store_head;
        ListNode* end_head = prev;
        int temp_counter = 0;
        int max_val = 0;
        //now let's traverse for n/2 elements and add them
        while(temp_counter < node_count/2)
        {
            int temp_val = start_head->val + end_head->val;
            if( temp_val > max_val)max_val = temp_val;
            start_head = start_head->next;
            end_head = end_head->next;
            temp_counter++;
        }
        return max_val;
    }
public:
    //if we want to do it in correct way then reach the middle of linked list and till there we have to reverse a linked list
    int pairSum(ListNode* head) {
        return sol(head);
    }
};
