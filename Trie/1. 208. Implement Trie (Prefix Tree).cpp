/*
    explanation-> for more indepth explanation see the notes Trie in CP note

    this problem is about what is the concept of trie, here we are creating the trie data structure

    trie has three main functions
        1. insert a word 
        2. search a word
        3. search startsWith or search the prefix of the word
    

    trie data structure is a form of a tree, where each node contain, 26 links here represented by TrieNode* a[26], these links when are not null means that charcter is present and it points to a new trienode.
    when a character is inserted it creates a new node and store it's pointer the present node.
    so supppose we are inserting apple

    a will be inserted in the root node and it will create a new node and it's pointer will be stored in a[0] since the position of a is 0 in the root node, when p will be stored it will be stored in the node created on insertion of a , and new node will be be created whose pointer will be stored in the p of the node created on insertion of a and this process keep going.
    when all the chracters of a word are inserted , the insertion of last character would have created a node , where no all characters a to z would have null have pointer, there we make the bool flag = true to denote that till here is a word.

        searching the word:    we start from the root and we keep moving to the pointer of character in the word at any moment if the character doesn't have pointer it means the word is not present, if the word is present totally we will be able to reach to the last of the word and the last chracter of the word would have a trieNode pointer and it will contain flag = True , denoting it is a word
        the process of finding the startswith is very easy, if all chracters of the prefix are present in the trie structure in the same order it means the prefix is present.




*/
struct TrieNode {
    //by default the pointers are false
    TrieNode* a[26];
    //this is for denotation if the word ends here
    bool flag = false;
    bool containsChar(char c){
        return a[c-'a'] != NULL;
    }
    void insertChar(char c, TrieNode* node){
        a[c-'a'] = node;
    }
    TrieNode* getCharPointer(char c){
        return a[c-'a'];
    }
    void setIsAWord(){
        flag = true; 
    }
    bool ifIsAWord(){
        return flag;
    }
};
class Trie {
private:
    TrieNode* root;
public:
    Trie() {
        //we are creating the root node
        root = new TrieNode();
    }
    
    void insert(string word) {
        TrieNode* node = root;
        //inserting all the characters of the word
        for(int i = 0; i<word.length(); i++){
            //we will insert if the character doesn't exist
            if(!node->containsChar(word[i])){
                node->insertChar(word[i], new TrieNode());
            }
            //moving to the pointer of the current character
            node = node->getCharPointer(word[i]);
        }
        //all the chars are inserted and the node points to the trieNode created on insertion of the last char let's make it true
        node->setIsAWord();
    }
    
    bool search(string word) {
       TrieNode* node = root;
       for(int i=0; i<word.length(); i++){
            //if the current's char doesn't exist return false
            if(!node->containsChar(word[i]))return false;
            node = node->getCharPointer(word[i]);
       }
        return node->ifIsAWord();
    }
    
    bool startsWith(string prefix) {
        TrieNode* node = root;
        for(int i=0; i< prefix.length(); i++){
                //if the current's char doesn't exist return false
                if(!node->containsChar(prefix[i]))return false;
                node = node->getCharPointer(prefix[i]);
        }
        return true;
    }
};

/**
 * Your Trie object will be instantiated and called as such:
 * Trie* obj = new Trie();
 * obj->insert(word);
 * bool param_2 = obj->search(word);
 * bool param_3 = obj->startsWith(prefix);
 */
