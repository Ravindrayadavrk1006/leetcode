class Solution {
private:

//solution 1
    bool isPrefix(string s1, string s2){
        int n = s1.size();
        if(s2.size()< n)return false;
        for(int i =0; i<n; i++){
            if(s1[i] != s2[i])return false;
        }
        return true;
    }




//solution 2

//Trie Implementation
//APPROACH -> we are keeping a variable prefix_count which count the number of time we come to that node while inserting all the words
//trieNode
struct TrieNode{
    TrieNode* link[26];
    int prefix_count = 0;
};

//Trie Class
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insertWord(string word){
            TrieNode* curr = root;
            for(char c: word){
                if(curr->link[c-'a'] == NULL){
                    //create a new trieNode and attached to it
                    curr->link[c-'a'] = new TrieNode();
                    
                }
                curr = curr->link[c-'a'];
                //increment the prefix_count
                curr->prefix_count++;
            }
        }
        int countPrefix(string pref){
            TrieNode*  curr = root;
            for(char c: pref){
                if(curr->link[c-'a'] == NULL)return 0;
                curr = curr->link[c-'a'];
            }
            return curr->prefix_count;
        }
};
public:
    int prefixCount(vector<string>& words, string pref) {


        //BRUTE FORCE
        // int ans = 0;
        // int n = words.size();
        // for(int i =0; i<n; i++){
        //     if(isPrefix(pref, words[i]))ans++;
        // }
        // return ans;


        //TRIE APPROACH
        //insert all the word in trie
        Trie t = Trie();
        for(auto word: words){
            t.insertWord(word);
        }
        return t.countPrefix(pref);
    }
};
