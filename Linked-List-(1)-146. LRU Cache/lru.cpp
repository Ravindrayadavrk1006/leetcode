/*
since asked for put and get function to perform in O(1) since removal of element from a linked list take O(1) if the position is known hence  we have kept
a hash map for keeping a track of position of element with key as key
we have stored key in the LL since at one place required while we delete a element from last when it's capacity is full.
when a element is accessed we try to take it from it's previous position and place it at head 
the last used element is placed before tail.
for simplicity we have used two extra nodes head and tail

*/


class LRUCache {
public:
    class Node
    {
        
        public:
            int key;
            int val;
            Node *next = NULL;
            Node *prev = NULL;

        Node(int in_key ,int in_val)
        {
            key= in_key;
            val = in_val;
        }
    };
    Node* head = new Node(-1,-1);
    Node* tail = new Node(-1,-1);
    int cap;
    unordered_map<int,Node*> map;
    int map_el_counts = 0;
    void delete_node(Node* old_node)
    {
        Node* del_prev = old_node->prev;
        Node* del_next = old_node->next;
        //forming connections 
        del_prev->next = del_next;
        del_next->prev= del_prev;

    }
    //adding node in the front
    void add_node(Node* node)
    {
        //always at the head
        Node* temp = head->next;
        head->next = node;
        node->prev = head;
        temp->prev = node;
        node->next = temp;
    }
    LRUCache(int capacity) {
        cap = capacity;
        head->next = tail;
        tail->prev = head;
    }
    
    int get(int key) {
        if(map.find(key) != map.end())
        {
            //delete the node from that position and place it at head
            Node* old_node = map[key];
            int res = old_node->val;
            //map.erase(key);
            delete_node(old_node);
            //add node in start 
            add_node(old_node);
            map[key] = head->next;
            return res;
            
        }
        return -1;
    }
    
    void put(int key, int value) {
        
        //if element is already present then add in start
        if(map.find(key) != map.end())
        {
            Node* present = map[key];
            delete_node(present);
            map.erase(key);

           //adding the element is done at last in the put() 
        }
        //if capacity is full
        if(map.size() == cap)
        {
            //the capacity is full
            //remove the last element
            map.erase(tail->prev->key);
            delete_node(tail->prev);
            // add_node(new Node(key, value));
        }
        
        add_node(new Node(key,value));
        map[key] = head->next;
    }
};

/**
 * Your LRUCache object will be instantiated and called as such:
 * LRUCache* obj = new LRUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
