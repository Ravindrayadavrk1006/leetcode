Intuition
using three pointers well known approach

Approach
keep the prev_node as head
curr_node = head->next
and next_node as head->next->next

**[IMPORTANT POINT] --> MAKE THE FIRST NODE->NEXT AS NULL
we run a looop till next_node is not null
inside this for looop we keep making
curr->next = prev (important reverses the links)
prev_node = curr_node
curr_node = next_node
and finally since next_node when null we will have two pointers to reverse their links hence reverse curr->next = prev
curr = head and return this head

Complexity
Time complexity:
O(N)

Space complexity:
(1)

Code
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
    ListNode* reverseList(ListNode* head) {
        if(head == nullptr)return head ;
        //contains one element
        if(head->next == nullptr) return head;
        //for list with two or greater element
        ListNode* prev_node = head;
        ListNode* curr_node = head->next;
        ListNode* next_node = head->next->next;
        prev_node->next = nullptr;
        while(next_node != nullptr)
        {
            curr_node->next = prev_node;
            prev_node = curr_node;
            curr_node = next_node ;
            next_node = next_node->next;
        }
        curr_node->next = prev_node;
        return curr_node;
    }
};
