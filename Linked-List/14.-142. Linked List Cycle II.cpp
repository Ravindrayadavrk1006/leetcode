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
        storing the visited nodes address in the hashmap and running the for loop
        till head != null , and inside this for loop checking if the node is already present inside the map if present then this is the first node we return this node
    
    */
    ListNode* sol_1(ListNode* head)
    {
        unordered_map<ListNode*,int> map;
        while(head != NULL)
        {
            if(map.find(head) != map.end())return head;
            map[head] = 1;
            head  = head->next;
        }
        return NULL;
    }

    /*
        idea --> we find the meeting point of fast and slow pointer where slow pointer moves by one step and fast pointer moves by two steps 
        then we take "another pointer"" from given head and move another pointer and slow one step each till the point where both meet is point first node of cycle 


        logic or intuition -->

        n1->n2->n3->n4->n5
                /\        |
                |        \|/ 
                <-n7 <- n6
        
        let's suppose distance from n1 to n3 is l1
        let suppsose n6 is meeting point of slow and fast pointer
        then distance from n3 to n6 be l2 
        let cycle length be C
        distance coverred by slow pointer = l1+l2
        distance coverred by fast pointer = l1 +l2 + nC
        nC because we don't know how many times it travelled around the circle
        we also distance moved by slow pointer = half of distance moved by fast pointer 
        i.e distance betweenn n6 to n3 to meeting point n6

        ==> 2(l1 +l2) = l1+l2+nC
        => l1+l2 = nC
        => l1 =  nC -l2
        => n6 to n3 is is nC-l2 since l2 is n3 to n6 clockwise

        therefore if we move a pointer from starting point moving one distance and slow pointer from slow fast pointer meeting position we will reach the start of cycle at same time
    */
    ListNode* better_approach(ListNode* head)
    {
        if(head == NULL)return NULL;
        //just one node only
        if(head->next == NULL)return NULL;

        //two and more nodes
        ListNode* slow = head;
        ListNode* fast = head;
        while(fast->next != NULL && fast->next->next != NULL)
        {
            slow = slow->next;
            fast = fast->next->next;
            if(slow == fast)break;
        }
        if(fast->next == NULL ||  fast->next->next == NULL)return NULL;
        ListNode* another_ptr  = head;
        while(another_ptr != slow)
        {
            another_ptr = another_ptr->next;
            slow = slow->next;
        }
        return slow ;
    }
    ListNode *detectCycle(ListNode *head) {
        // return sol_1(head);

        return better_approach(head);
    }
};
