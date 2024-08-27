/*
Approach
I have tried to apply the idea if I am standing at the current position and then we move and we start checking for the elements 
in the dictionary if the any dictionary element matches subtstring of same size from current position . to reduce the time complexity used DP

Complexity
Time complexity:
O(n)

Space complexity:
constant time of vector size 301 int storage

Code
*/
class Solution {
public:
    /*
    IDEA-->
        I have tried to apply the idea if I am standing at the current position and then we move and we start checking for
        the elements in the dictionary if the any dictionary element matches subtstring of same size from current position 
        to reduce the time complexity used DP 



        here we are standing at current position and for all the elements of dictionary we are we are taking a substr of that size and comparing that substr is that element of dictionary
        if yess then we move ahead and check for next remaining part.
        we are doing this so that we can take all possible string that can be formed and valid and start.
    */
    int help (int pos, string s, vector<string>& wordDict,vector<int>& dp)
    {
        if(pos == s.size())return 1;
        //normal cases
        if(dp[pos] != -1)return dp[pos];
        for(int i=0; i < wordDict.size(); i++)
        {
            if(s.substr(pos,wordDict[i].size()) == wordDict[i])
            {
                bool check = help(pos+wordDict[i].size(), s, wordDict,dp);
                if (check) return dp[pos] = check;
            }
        }
        return dp[pos] = 0;
    }
    bool wordBreak(string s, vector<string>& wordDict) {
        int wordDict_size=wordDict.size();
        // unordered_map<string,bool> umap;
        vector<int> dp(301,-1);
        return help(0, s,wordDict, dp);

        
    }
};
