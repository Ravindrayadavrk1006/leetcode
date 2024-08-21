
/**
 * Definition for singly-linked list.
 * struct ListNode {
 *     int val;
 *     ListNode *next;
 *     ListNode(int x) : val(x), next(NULL) {}
 * };
 */
class Solution {
public:
    /*
        We are taking a hashmap which will store the address of the visited node if the node we are currently at is already present in the hashmap then there is a cycle 

    THIS DOES NOT CHANGE THE VALUE OF ELEMENTS

    */
    bool sol_1(ListNode* head)
    {
        unordered_map<ListNode* , int> map;
        while(head != NULL &&  map.find(head) == map.end() )
        {
            map[head] = 1;
            head = head->next;
        }
        if(map.find(head) != map.end())return true;
        return false;
    }
    /*
        sol_2 in this whenever we are visiting a node we  are setting it's value to be INT_MAX and next time when we find a value to INT_MAX it will be cycle same as setting a visited node value as 'v' and again if we find a node whose value is already set to 'v' then there is a cycle
    
    WARNING THE VALUE OF THE NODE WILL CHANGE ALSO WHICH IS NOT A GOOD THING BUT SINCE NO EXTRA DATA STRUCTURE USED HENCE BETTER SOLUTION
    */
    bool sol_2(ListNode* head)
    {
        while(head != NULL && head->val != INT_MAX)
        {
            head->val = INT_MAX;
            head = head->next;
        }
        if(head == NULL)return false;
        if(head->val == INT_MAX)return true;
        //the program will never come to this point
        return false;
    }


    /*
        *important 
        CORRECT APPROACH OF FINDING A CYCLE
        WE TAKE A FAST AND SLOW POINTER AND TRY TO MOVE FAST BY 2 STEPS AND SLOW BY ONE STEP
    */
    bool sol_3(ListNode * head)
    {
        //HANDING THE BASE CASE TO START I CAN SET SLOW AT HEAD AND FAST AT HEAD->NEXT
        //if there is no node or just one node in ll
        if(head == NULL || head->next == NULL)return false;
      //we can start by setting both slow and fast at head , we will get the result
        ListNode* slow = head;
        ListNode* fast = head->next;
      
        //since we are skipping two nodes at a time hence here checking if fast!=NULL and fast->next != NULL 
        while(fast != NULL && fast->next != NULL && fast != slow)
        {
            fast = fast->next->next;
            slow = slow->next;
        }
        // if(fast == NULL || fast->next == NULL)return false;
        if(fast == slow)return true;
        return false;
    }
    bool hasCycle(ListNode *head) {
        
        // return sol_1(head);
        // return sol_2(head);
        return sol_3(head);

    }
};
