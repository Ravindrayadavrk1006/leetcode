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
    
        simple idea of traversing in both the LL at the same time and adding the values and if there comes carry we take it to the next node

        tried to use l2 linked list to store the values of ans;
        
        caveats -->
        if l1 is longer than when l2 is at null since l2 is our answer we connect l1 LL remaining elements with the l2 last node and then just adding the remaineder if any from previous node to current node

    */
    ListNode* addTwoNumbers(ListNode* l1, ListNode* l2) {
        ListNode* ans = l2;
        //if any list doesn't contain single nodes
        if(l1 == NULL)return l2;
        if(l2 == NULL)return l1;
        ListNode* last_node = NULL;
        int temp = 0;

        //traversing and adding till the point both ll have qual nodes
        while(l1 != NULL && l2 != NULL)
        {
            int div_val = (l1->val+l2->val+temp)/10;
            l2->val = (l1->val+l2->val+temp)%10;
            temp = div_val;
            l1 = l1->next;
            if(l2->next == NULL)last_node=l2;
            l2=l2->next;
        }

        //if l1 nodes are not exhausted we out of the remaining elements of l1 we add first node to the last node of l2 =>last_node->next = l1;
        if(l1 != NULL)
        {
            last_node->next = l1;

            //simply traversing the remaining elements and add the remainder from last node to current node
            while(l1 != NULL)
            {
                int div_val = (l1->val+temp)/10;
                l1->val = (l1->val+temp)%10;
                temp = div_val;
                //we are storing last node so if there is a remainder left after traversing all the nodes we can add remainder to this node
                if(l1->next == NULL)last_node= l1;
                l1 = l1->next;

            }
        }

        //if l2 is not exhuausted just adding remainder from last node to current node linearly
        if(l2 != NULL)
        {
            while(l2 != NULL)
            {
                int div_val = (l2->val+temp)/10;
                l2->val = (l2->val+temp)%10;
                temp = div_val;
                //we are storing last node so if there is a remainder left after traversing all the nodes we can add remainder to this node
                if(l2->next == NULL)last_node = l2;
                l2 = l2->next;

            }
        }

        //if both the linked list are depleted and is a remaineder left
        //eg 999 999   in last 1 remaineder will be left so we create a new node and add to the last node
        if(temp == 1)
        {
            ListNode* temp_node = new ListNode(temp);
            last_node->next = temp_node;
        }
        return ans;



    }
};
