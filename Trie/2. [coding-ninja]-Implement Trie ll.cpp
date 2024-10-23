/*
    improvement on the first function, here instead of just having flag = true false for denoting if it's a word or not
    we are using , two int variables wordCount to count the word and prefixCount to count the prefix.

    1.we are updating the wordCount where we used to set flag = True in the first trie solution
    2.the way we set value of wordCount, in similar fashion we are incrementing the value of character for prefix count
    3.erase word:
        for deleting the word , i am decrementing the prefix count and at last decrementing the wordCount as well

*/

#include <bits/stdc++.h>
struct TrieNode {
    //by default the pointers are false
    TrieNode* a[26];
    //this is for denotation if the word ends here
    int prefixCount = 0;
    int wordCount = 0;
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
        wordCount = wordCount +1; 
    }
    void setIsAPrefix(){
        prefixCount = prefixCount+1;
    }
    bool ifIsAWord(){
        return wordCount != 0;
    }
    int getWordCount(){
        return wordCount;
    }
    int getPrefixCount(){
        return prefixCount;
    }
    void deletePrefix(){
        prefixCount = max(prefixCount-1, 0);
    }
    void deleteWord(){
        wordCount = max(wordCount-1, 0);
    }
}; 
class Trie{
    private:
        TrieNode* root;
    public:

    Trie(){
        root = new TrieNode();
    }

    void insert(string &word){
        TrieNode* node = root;
        //inserting all the characters of the word
        for(int i = 0; i<word.length(); i++){
            //we will insert if the character doesn't exist
            if(!node->containsChar(word[i])){
                node->insertChar(word[i], new TrieNode());
            }
            //moving to the pointer of the current character
            node = node->getCharPointer(word[i]);
            
            //it means it will countribute in the prefix
            //here shrewdly we are saving the prefix till now to the next trieNode added to current trieNode same as we do in case of number of words
            node->setIsAPrefix();
            //cout<<word[i]<<" count-> "<<node->getPrefixCount()<<endl;
        }
        //all the chars are inserted and the node points to the trieNode created on insertion of the last char let's make it true
        node->setIsAWord();
    }

    int countWordsEqualTo(string &word){
        TrieNode* node = root;
        for(int i = 0; i<word.length(); i++){
            //we will insert if the character doesn't exist
            if(!node->containsChar(word[i])){
                return 0;
            }
            //moving to the pointer of the current character
            node = node->getCharPointer(word[i]);
        }
        return node->getWordCount();
    }

    int countWordsStartingWith(string &word){
        TrieNode* node = root;
        for(int i = 0; i<word.length(); i++){
                //we will insert if the character doesn't exist
                if(!node->containsChar(word[i])){
                    return 0;
                }
                //moving to the pointer of the current character
                node = node->getCharPointer(word[i]);
                //cout<<word[i]<<" count-> "<<node->getPrefixCount()<<endl;
            }
            return node->getPrefixCount();
    }
    //according to the question the word will exist for sure to be deleted
    void erase(string &word){
        TrieNode* node = root;
        for(int i = 0; i<word.length(); i++){
            //moving to the pointer of the current character
            node = node->getCharPointer(word[i]);
            node->deletePrefix();
            //cout<<word[i]<<" count-> "<<node->getPrefixCount()<<endl;
        }
        return node->deleteWord();
    }
};
