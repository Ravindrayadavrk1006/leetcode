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
    we use merge algorithm here also

    we traverse through the given  linked lists  and whose ever LL current element is smaller we take add this node in the answer next node  
    we take a variable ans which store the head of answer linked list
    we take ans_ptr which will store the current last node of answer linked list
    

*/
    ListNode* mergeTwoLists(ListNode* list1, ListNode* list2) {
       
       if(list1 == NULL)return list2;
       if(list2 == NULL)return list1;
       //ans is the head of answer linked list 
       ListNode* ans = NULL;
       //pointer which will point to ans current last node
       ListNode* ans_ptr = NULL;
       //setting the head of linked list by checking first nodes from list1 and list2
       if(list1->val < list2->val)
       {
           ans = list1;
           list1 = list1->next;
           ans_ptr = ans;
       }
       else
       {
           ans = list2;
           list2 = list2->next;
           ans_ptr = ans;
       }

       while(list1 != NULL && list2 != NULL )
       {
           if(list1->val < list2->val)
           {

               //we add the current node to the ans linked list as last node 
               ans_ptr->next = list1;
               //make the current added node as last node of answer linked list
               ans_ptr  = list1;
               list1 = list1->next;
           }
           else
           {
               ans_ptr->next = list2;
               ans_ptr = list2;
               list2 = list2->next;
           }
       }

       //if any one lists has remaining element we add them to ans linked list
       while(list1 != NULL)
       {
           ans_ptr->next = list1 ;
           ans_ptr = list1;
           list1 = list1->next;
       }
       while(list2 != NULL)
       {
           ans_ptr->next = list2 ;
           ans_ptr = list2;
           list2 = list2->next;
       }
       return ans;
    }
};
