PROBLEM LINK -> https://www.naukri.com/code360/problems/complete-string_2687860?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=PROBLEM
/*
    explanation-> 
        simple approach inserting all the strings of the vector first,
        once all the strings are inserted, 
        then for each string of the vector ,we check if all it's prefixes are word or not,
        the moment we see that it's prefix is not a word we return false else we return true.


        for checking if all the prefix of a string are word we are doing in function has_all_prefix_as_word(),


        here one condition is given if there are two possible answer 
        always return the lexicographical one , hence we are using the else case here where we are checking if the string are of same size and lexograpically smaller
        then only we are adding to the answer

*/
#include <bits/stdc++.h> 

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
    bool has_all_prefix_as_word(string prefix){
        TrieNode* node = root;
        for(int i=0; i< prefix.length(); i++){
                //if the current's char doesn't exist return false
                if(!node->containsChar(prefix[i]))return false;
                node = node->getCharPointer(prefix[i]);
                //every prefix must be a word
                if( !node->ifIsAWord())return false;
        }
        return true;
    }
};

string completeString(int n, vector<string> &a){
    // //sort the vector for simplicity
    // sort(a.begin(), a.end());
    Trie t = Trie();
    //inserting all the strings
    for(string str:a){
        t.insert(str);
    }
    int largest_pos = -1;
    int largest_size = 0;
    //we can start from start also no issues in that
    for(int i =0; i<n; i++){
        int word_size = a[i].size();
        if (word_size > largest_size && t.has_all_prefix_as_word(a[i])) {
                largest_pos = i;
                largest_size = word_size;
        }
        //size of equal and lexograpically smaller
        else if (word_size == largest_size && a[i]< a[largest_pos] && t.has_all_prefix_as_word(a[i])){
            largest_pos = i;
            largest_size = word_size;
        }
    }
    if(largest_pos == -1)return "None";
    return a[largest_pos];
}
