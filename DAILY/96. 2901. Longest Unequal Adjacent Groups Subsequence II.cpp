class Solution {
vector<string> ans;
int n = 0;
private:
    bool valid_hamming_distance(int pos, int prev_indx, vector<string>& words){
        int hamming_dist = 0;
        string s1, s2;
        s1 = words[pos];
        s2 = words[prev_indx];
        int size_n = s1.size();
        for(int i =0; i<size_n; i++){
            if(s1[i] != s2[i])hamming_dist++;
            if(hamming_dist > 1)return false;
        }
        return true;
    }
    //SOL 1 -> recursion is correct but the DP is giving wrong answer
    int recursive_sol(int pos, int prev_indx, vector<string>& curr_vec, vector<string>& words, vector<int>& groups, vector<vector<int>>& dp ){
        if(pos == n){
            if(curr_vec.size() > ans.size()){
                ans = curr_vec;
            }
            return 0;
        }
        if(dp[pos][prev_indx] != -1)return dp[pos][prev_indx];
        //don't take current
        int max_value = recursive_sol(pos+1, prev_indx, curr_vec, words, groups, dp );
        //take
        if(prev_indx == 1001 || (groups[pos] != groups[prev_indx] && words[pos].size() == words[prev_indx].size() && valid_hamming_distance(pos, prev_indx, words)) ){
            curr_vec.push_back(words[pos]);
            max_value = max(max_value, 1 + recursive_sol(pos+1, pos, curr_vec, words, groups, dp ));
            curr_vec.pop_back();
        }
        return dp[pos][prev_indx] = max_value;
    }




//SOL 2 ----->>>>>>>>>>>>>>prefered approach

    /*
        LIS is very important concept for finding the LONGEST SUBSEQUENCE
        the condition of IF inside the nested O(n^2) for loop will say what  we are finding, hence whenver we are asked about longest subsequence always try to go for LIS

        eg . if we want to find the longest increasing subsequence then we need to put in the IF condition if(arr[j]< arr[i]) , if decreasing then arr[j]> arr[i] and son.



        here we have to find the longest subsequence which satisifies three condition i.e groups are not same,  equal size, and have hamming distance of 1,
        we put all these three condition in the IF block.

        also 
    */
    vector<string> sol_using_LIS(vector<string>& words, vector<int>& groups){
        int n = words.size();
        //since we need to parent the longest subsequence hence using the parent vector for storing the parent of each elemnet
        vector<int> parent(n, -1);
        vector<int> lis(n, 1);
        int longest_increasing_subsequence_length = 0;
        int longest_increasing_subsequence_index = 0;
        for(int i =0; i<n; i++){
            for(int j =0; j<i; j++){
                if(groups[j] != groups[i] && words[i].size() == words[j].size() && valid_hamming_distance(i, j, words)){            

                    //basic condition of LIS 
                    if(lis[j] + 1 > lis[i]){
                        //update the lis[i] value
                        lis[i] = lis[j] + 1;
                        //this we are doing since we need to print the largest subsequence hence saving current's parnt so that we can traverse and get it
                        parent[i] = j;
                        //this is normal part of LIS, we are storing the answer in the a variable
                        if(lis[i]> longest_increasing_subsequence_length){

                        longest_increasing_subsequence_length = lis[i];
                        //this is is jsut for this problem that we can find the array of largest subsequence
                        longest_increasing_subsequence_index = i;
                    }
                    }
                }
            }
        }

        //BELOW APPROACH IS IMPORTANT 
        vector<string> ans;
        //now forming the largest subsequence, since we have the last index of the largest subsequence we save the subsequence
        while(longest_increasing_subsequence_index != -1){
            ans.push_back(words[longest_increasing_subsequence_index]);
            longest_increasing_subsequence_index = parent[longest_increasing_subsequence_index];
        }
        //we are reversing since the above for loop store last element at first and hence to maintain the order
        reverse(ans.begin(), ans.end());
        return ans;
    }
public:
    vector<string> getWordsInLongestSubsequence(vector<string>& words, vector<int>& groups) {

        //CALLING SOL 1, WHEN USING DP IT IS WRONG, DP IS NOT BEING USED PROPERLY
        // vector<string> curr_vec;
        // n = words.size();
        // vector<vector<vector<string>>> dp(n, vector<int>(n+2, vector<int>()));
        // recursive_sol(0, 1001, curr_vec, words, groups, dp, "");
        // return ans;



        //SOL 2 
        //using the concept of LONGEST INCREASING SUBSEQUENCE
        return sol_using_LIS(words, groups);
    }
};
