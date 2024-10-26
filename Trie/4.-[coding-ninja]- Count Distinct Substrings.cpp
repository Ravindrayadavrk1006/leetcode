PROBLEM LINK -> https://www.naukri.com/code360/problems/count-distinct-substrings_985292?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=SUBMISSION

/*
  explanation -> 
  let's suppose string is abab
  all substrings
  starting with ----->
  (a) -> a, ab,aba, abab
  (b) -> b, ba , bab
  #stating with second a
  (a) -> a, ab
  #starting with second b
  (b) -> b

  so here idea used is to print all the prefixes after moving to that character
  1.we print all the prefix from a
  2.we move to index 1 and print all the prefix from there 

*/
#include <bits/stdc++.h>
using namespace std;
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
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
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
    void startWith(int starting_pos, int n, set<string>& st, string& word){
        TrieNode* node = root;
        //moving to the starting point in the trie ds
        for(int i = 0; i< starting_pos; i++){
            node = node->getCharPointer(word[i]);
        }

        //printing all the substring from the current starting point
        string temp = "";
        for(int i = starting_pos ; i<n; i++){
            temp+=word[i];
            // cout<<temp<<endl;
            st.insert(temp);
            node = node->getCharPointer(word[i]);
        }
    }
};
int countDistinctSubstrings(string &s)
{
    set<string> st;
    Trie t = Trie();
    t.insert(s);
    int n = s.size();

   //stating point index sending from here
    for(int i = 0; i <n; i++){
        t.startWith(i, n,st, s );
    }
    return st.size()+1;

} 
