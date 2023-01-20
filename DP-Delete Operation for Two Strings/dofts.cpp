class Solution {
public:
    /*
using the concept of finding the longest common subsequence(lcs) between two strings
and since asked minimum opeartions to make both string same ==>
when we have the longest subsequence we have the common part between two now.
from first-lcs then we get what is the deletion we need to do in first
and secondstring - lcs gives the deletion we need to do in the second string 
hence ans will be firststr-lcs + secondstr-lcs  
*/
    int tabulation(string text1, string text2)
    {
        int text1_size = text1.size();
        int text2_size = text2.size();
        vector<vector<int>> dp(text1_size+1, vector<int>(text2_size+1,-1));
        //by seeing the base case in shiftindex make all 0 row and 0th column 0 
        for(int pos2 = 0 ; pos2<= text2_size; pos2++)dp[0][pos2]= 0;
        //making the 0th column elements as zero
        for(int pos1= 0 ; pos1<= text1_size; pos1++)dp[pos1][0]= 0;
        //normal case
        //copy the remaining logic of above
        for(int pos1 = 1 ;pos1<=text1_size; pos1++)
        {
            for(int pos2= 1; pos2<=text2_size; pos2++)
            {
                if(text1[pos1-1] == text2[pos2-1])
                {
                    dp[pos1][pos2] = 1 + dp[pos1-1][pos2-1];
                }
                else
                {
                    dp[pos1][pos2] = max(dp[pos1-1][pos2],dp[pos1][pos2-1]);
                }

            }
        }
        return dp[text1_size][text2_size];
    }
    int minDistance(string word1, string word2) {
        int lcs = tabulation(word1,word2);
        int ans = word1.size()-lcs + word2.size()-lcs;
        return ans;
    }
};
