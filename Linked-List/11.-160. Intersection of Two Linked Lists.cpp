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
    
        simple logic of traversing both the linked list and inserting the nodes address in the node and when other linked list finds a node already visited by the other node it will declare that it has found the node and return that node address
    */
    ListNode *getIntersectionNode(ListNode *headA, ListNode *headB) {
        unordered_map<ListNode*,int> visited;
        int a_el = 0;
        int b_el = 0;
        while(headA != NULL && headB != NULL)
        {
            if(visited.find(headA) == visited.end())
            {
                visited[headA] = 1;
                headA = headA->next;
            }
            else
            {
                return headA;
            }
            if(visited.find(headB) == visited.end())
            {
                visited[headB] = 1;
                headB = headB->next;
            }
            else
            {
                return headB;
            }
        }
        //if B linked list is finished checking in LL A
        while(headA != NULL)
        {
            if(visited.find(headA) == visited.end())
            {
                visited[headA] = 1;
                headA = headA->next;
            }
            else
            {
                return headA;
            }
        }
        //if LL A is over and checking for remaining element of LL B
        while(headB != NULL)
        {
            if(visited.find(headB) == visited.end())
            {
                visited[headB] = 1;
                headB = headB->next;
            }
            else
            {
                return headB;
            }   
        }
        return NULL;
    }
};
