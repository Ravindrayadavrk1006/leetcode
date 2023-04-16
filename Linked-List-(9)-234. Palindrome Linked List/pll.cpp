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
        brute force--> we store all the elements of in a vector and then check it's element
    */
    bool brute_force(ListNode* head)
    {
        vector<int> el;
        while(head != NULL)
        {
            el.push_back(head->val);
            head = head->next;
        }
        int len = el.size();
        int half = len/2;
        for(int i = 0 ; i<half; i++)
        {
            if(el[i] != el[len-i-1])return false;
        }
        return true;
    }
    
    /*
        better approach we find the middle of linked using concept of middle of linked list and the we reverse the second half of linked list
        and try to match the element
    */
    ListNode* reverse_ll(ListNode* head)
    {
        ListNode* prev=NULL;
        ListNode* next = NULL;
        while(head != NULL)
        {

            next = head->next;
            head->next = prev;
            prev = head;
            head = next;
        }
        return prev;
    }
    bool sol_2(ListNode* head)
    {
        //if just one node return True
        if(head->next == NULL)return true;
        if(head->next->next == NULL)
        {
            if(head->val == head->next->val)return true;
            return false;
        }
        //finding first middle of linked list
        ListNode* fast = head;
        ListNode* slow = head;
        while(fast->next !=  NULL && fast->next->next !=  NULL)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        //slow will store the middle of linked list
        //reverse the second half of linked list
        ListNode* middle_node = slow;
       
        ListNode* second_head= reverse_ll(slow->next);
        while(second_head != NULL)
        {
            if(head->val != second_head->val)return false;
            head = head->next;
            second_head = second_head->next;
        }
        return true;
    }
    bool isPalindrome(ListNode* head) {
        // return brute_force(head);
        return sol_2(head);
    }
};
