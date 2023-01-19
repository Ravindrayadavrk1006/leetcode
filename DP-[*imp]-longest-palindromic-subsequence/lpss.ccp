class Solution {
public:
//using the same concept of finding the maximum length subsequence between two string
//taking given string as one string 
//reverse of given as other string since need to match the largest palindromic subsequence
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
    int longestPalindromeSubseq(string s) {
        //reversing the string
        // int len = s.size();
        // int half_len = len/2;
        string rev = s;
        //INSTEAD OF THIS THERE IS A REVERSE FUNCTION
        // for(int i=0; i<len; i++)
        // {
        //     reverse[i]=s[len-1-i];
        // }
        reverse(rev.begin(),rev.end());
        return tabulation(s,rev);
    }
};
