QUESTION LINK -> https://www.naukri.com/code360/problems/max-xor-queries_1382020?utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_tries_videos&leftPanelTabValue=SUBMISSION
/*
    1. this is based on 5.question of trie series i.e bitwise inserting element. struct TrieNode and Trie class are copied from there
    since here asking that we have to find the maximum xor value smaller than a particular number so what are doing is
    we have sorted the given arr, we have sorted the queries array also by inserting the intitial queies position at last forming offline queies ,
    it is done in order to remember the position of queies to be used in answer later.
    2. we start processing all the elements of offline queries form.
        we push all the elements smaller or equal to offline queries current element and once all smaller or equal numbers are inserted
        we find the maximum xor value and insert in ans array at the postion we saved in offline query to remember the index of original query



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
vector<int> maxXorQueries(vector<int> &arr, vector<vector<int>> &queries){

	int n = arr.size();
	int q_size = queries.size();
    // we are sorting because we will insert all the smaller values than queries[i][1] a
    sort(arr.begin(), arr.end());

    //storing the queries along with the query index so that we can sort this offline queries according to queries[i][1]
    vector<pair<int, pair<int, int>>> offline_queries;
    for(int i = 0 ; i< q_size; i++){
        //queries[i][1] is first element because will be sorting according to that
        offline_queries.push_back({queries[i][1], {queries[i][0], i}});
    }
    //by default any kind of element inside a vector will be sorted by first element and if first element same then will be sorted by second element
    sort(offline_queries.begin(), offline_queries.end());
    vector<int> ans(q_size, 0);
    int ind = 0;
    Trie t;

    //now processing all the offline queries element
    /*
        we have offline queries sorted already so for offline_queries i we are inserting all the arr elementwhich are smaller than offlinequeries[0]
        and finding the maximum till that position
    */
    for(int i = 0 ; i< q_size; i++){
        int max_el = offline_queries[i].first;
        int x  = offline_queries[i].second.first;
        int qindex = offline_queries[i].second.second;
        while(ind < n && arr[ind]<= max_el){
            t.insert(arr[ind]);
            ind++;
        }
        if(ind == 0)ans[qindex] = -1;
        else ans[qindex] = t.getMax(x);
    }
    return ans;

}
