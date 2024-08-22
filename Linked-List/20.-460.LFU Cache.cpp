/*
we are using two maps 
1.one map will store all the current insert node address with their key as key
2.second map will be frequency map which will store frequency as key and a doubly linked list which contains all the elements with that frequency

we create node which has key,value,next node ,prev prevnode we also store the number of times this element node is get or putt as count


doubly linked list --> contains two extra nodes head and tail for avoiding if else conditions
both node and linked list are created as structure
each linked list has delete_node and add_node function which are used respectively
delete_node --> for deleting a node from given position 
add_node --> for adding the element to the front of the liked list


update_freq_map()  --> this function is called when a node is referenced called for put on it{i.e updating it's value} or just get it's value
this remove the element from the current freq_map and add it to the next higher frequency_map list


*/




//structure of node
struct Node
{
    int key,val,count;
    Node* next =NULL;
    Node* prev = NULL;
    Node(int in_key,int in_value)
    {
        key = in_key;
        val = in_value;
        //very important for recognizing in which freq_map it will go 
        count = 1;
    }
};
struct List
{
    int size;
    Node* head;
    Node* tail;
    List()
    {
        size = 0;
        //we are having head and tail two extra nodes for avoiding many if else conditions
        head = new Node(-1,-1);
        tail = new Node(-1,-1);
        head->next = tail;
        tail->prev = head;
    }

    //since all the elements deletion and addition will take place in list hence function defined here
    void add_node(Node* node)
    /*
        description -> add a node next to head of the list
    */
    {
        //current previous before node addition
        Node* head_next = head->next;
        head->next = node;
        node->prev = head;
        node->next = head_next;
        head_next->prev = node;
        size++;
    }
    
    void delete_node(Node* node)
    /*
        description: used for deleting node from any place
    */
    {
        Node* node_prev = node->prev;
        Node* node_next = node->next;
        node_prev->next = node_next;
        node_next->prev = node_prev;
        size--;
    }
};

class LFUCache {
    //this store the keys inserted element node address 
    unordered_map<int,Node*> node_map;
    //this store the list of elements by  frequency as maps key
    unordered_map<int,List*> freq_map;
    //current no of elements total in cache 
    int curr_size;
    int min_freq;
    //total size of cache
    int size;
public:
    LFUCache(int capacity) {
       size = capacity;
       min_freq= 0;
       curr_size = 0;
    }
    void update_freq_map(Node* node)
    {
        //deleting this node from the node_map to remove it's reference
        node_map.erase(node->key);
        //from the freq_list in which element is present remove the node
        //node 
        freq_map[node->count]->delete_node(node);
        //if current deleted node is from min_freq and after deletion min size becomes 0
        if(node->count == min_freq && freq_map[node->count]->size == 0)
        {
            min_freq++;
        }
        List* next_higher_freq_list = new List();
        if(freq_map.find(node->count+1) != freq_map.end())
        {
            next_higher_freq_list = freq_map[node->count+1];
        }
        node->count+=1;
        //add node to this higher frequency list
        next_higher_freq_list->add_node(node);
        //add/update the freq_map list
        freq_map[node->count] = next_higher_freq_list;
        node_map[node->key] = node;

    }
    int get(int key) {
        if(node_map.find(key) != node_map.end())
        {
            Node* node = node_map[key];
            int value = node->val;
            update_freq_map(node);
            return value;
        }
        return -1;
    }
    
    void put(int key, int value) {
        //a edge case in leetcode specific problem
        if(size == 0)return ;

        if(node_map.find(key) != node_map.end())
        {
            Node* node = node_map[key];
            node->val = value;
            update_freq_map(node);
        }
        
        //node is new node
        else
        {
            //LFU cache is full
            if(curr_size == size)
            {
                List* list = freq_map[min_freq];
                node_map.erase(list->tail->prev->key);
                freq_map[min_freq]->delete_node(list->tail->prev);
                curr_size--;
            }
            curr_size++;
            //new node to be added in freq_map[1]
            min_freq=1;
            List* list_freq = new List();
            if(freq_map.find(min_freq) != freq_map.end())
            {
                list_freq = freq_map[min_freq];
            }
            Node* node = new Node(key,value);
            list_freq->add_node(node);
            node_map[key] = node;
            freq_map[min_freq] = list_freq; 
        }
    }
};

/**
 * Your LFUCache object will be instantiated and called as such:
 * LFUCache* obj = new LFUCache(capacity);
 * int param_1 = obj->get(key);
 * obj->put(key,value);
 */
