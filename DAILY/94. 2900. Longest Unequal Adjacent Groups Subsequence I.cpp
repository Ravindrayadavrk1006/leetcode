class Solution {
private:

    /*  
    SOL 1 MY SOLUTION
        explanation:
            we are trying to find all the subsequence, and saving the largest subsequence to, improve the efficiency we are trying to use DP

    */
    vector<string>  final_ans = {};
    int subSeqLength  = 0;
    int n = 0; 
    int sol_longest_subsequence(int pos, int prev, int  currSubSeqLength, vector<string>& curr_vec, vector<string>& words, vector<int>& groups, vector<vector<vector<int>>>& dp){
        if(pos >= n){
            if(currSubSeqLength > subSeqLength ){
                subSeqLength = currSubSeqLength;
                final_ans = curr_vec;
            }
            return 0 ;
        }
        if(dp[pos][prev][currSubSeqLength] != -1)return dp[pos][prev][currSubSeqLength];
        //checking the possibility
        //if current element is not equal to previous element then TAKE
        int len = INT_MIN;
        if(groups[pos] != prev){
            curr_vec.push_back(words[pos]);
        int  left_length  = words[pos].size() +  sol_longest_subsequence(pos +1, groups[pos], currSubSeqLength + words[pos].size(), curr_vec, words, groups, dp );
            curr_vec.pop_back();
            len = max(len, left_length);
        }
        //NOT TAKE
        int right_length = 0 +  sol_longest_subsequence(pos+1 , prev, currSubSeqLength, curr_vec, words, groups, dp);
        len = max(len, right_length);
        return dp[pos][prev][currSubSeqLength] = len ;
    }
public:
    vector<string> getLongestSubsequence(vector<string>& words, vector<int>& groups) {
        vector<string> curr_vec; 
        n = words.size();
        vector<vector<vector<int>>> dp(n+1, vector<vector<int>>(3, vector<int>(1001, -1)));
        sol_longest_subsequence(0, 2 , 0, curr_vec, words, groups, dp );
        return final_ans;
    }
};
