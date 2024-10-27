problem link -> https://www.naukri.com/code360/problems/maximum-xor_973113?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=SUBMISSION


/*
    explanation is given in CP notes trie section Q1. and Q2., for bits related trie questions,

    important points:
        1. we store integers from root of trie in order of 32th bit and towards the leaf we store 1st bit
        2. int bit = (num >> i) & 1; //to find if the bit is set or not or in simple language to get the ith bit
            more about it, in the CP notes 
        3. max_xor = max_xor | 1<<i; here in (1<<i) we are first making ith bit equal to 1 and then we are doing bitwise or wit max_xor number which means
        it will make that position  bit 1 that's all


*/
#include <bits/stdc++.h>
using namespace std;
struct TrieNode{
    TrieNode* link[2];
    int flag = -1;
    bool isABit(int bit){
        return link[bit] != NULL;
    }
    TrieNode* getBitPointer(int bit){
        return link[bit];
    }
    void insertBit(int bit, TrieNode* node){
        link[bit] = node;
    }
    void setFlag(int num){
        flag = num;
    }
};
class Trie{
    private:
        TrieNode* root;
    public:
        Trie(){
            root = new TrieNode();
        }
        void insert(int num){
            TrieNode* node = root;
            for(int i = 31; i >=0; i--){
                int bit = (num>>i) & 1;
                if(!node->isABit(bit)){
                    node->insertBit(bit,new TrieNode());
                }
                node = node->getBitPointer(bit);
            }
            node->setFlag(num);
        }
        int getMax(int num){
            TrieNode* node = root;
            int max_xor = 0;
            for(int i = 31; i>=0; i--){
                int bit = (num >> i) & 1;
                //if opposite of bit exist, because to maximize xor we need opposite bits
                //1-bit since we want opposite of bit and bit can be 0 or 1 and 1-bit will do opposite of it
                if(node->isABit(1-bit)){
                    //1<<i to create a number which has just that bit set
                    //we are doing bitwise or with the existing value of max_sum to make i'th bit 1
                    max_xor = max_xor | 1<<i;
                    node = node->getBitPointer(1-bit);
                }
                //if opposite of the bit doesn't exist
                else{
                    node = node->getBitPointer(bit);
                }
            }
            return max_xor;
        }

};
int maxXOR(int n, int m, vector<int> &arr1, vector<int> &arr2) 
{
    Trie t = Trie();
    //inserting all the elements of arr1
    for(int i = 0; i <n; i++){
        t.insert(arr1[i]);
    }
    int max_xor = INT_MIN;
    //now we are doing xor of all the elemnts of arr2 and finding the maximum xor value we get
    for(int i = 0; i < m; i++){
        max_xor = max(max_xor, t.getMax(arr2[i]));
    }
    return max_xor;
}
