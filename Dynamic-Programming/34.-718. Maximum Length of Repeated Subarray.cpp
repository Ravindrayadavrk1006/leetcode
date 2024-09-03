/*
  in previous problem 33 we have found longest common subsequence here are to find the longest common sub-array and sub-array is always consecutive element.

  here we are using the concept of longest common subsequence doing using tabulation approach.
    importantt point to note is in case of equal element we use to do 1+ f(i-1,j-1) . also , see how putting 0 in place of max(f(i-1,j),f(i,j-1)) let's us calculate properly.
    also when we were putting max(f(i-1,j),f(i,j-1)) when element do not used to match we were saying till now we have this largest subsequence which is not required now and it won't affect our solution

*/
class Solution {
public:
    // the addition of dp is creating problem otherwise the solution seems fine hence don't consider this solution

    //read the correct solution first which is TABULATION ONE
    int help(int pos1, int pos2, vector<int>& nums1, vector<int>& nums2, vector<vector<int>>& dp)
    {
        if(pos1 < 0 || pos2<0 )return 0;
        if(dp[pos1][pos2] != -1)return dp[pos1][pos2];
        int match_len = 0;
        int max_val = -1e9;
        while(pos1>=0 && pos2>=0 && nums1[pos1] == nums2[pos2])
        {
            match_len++;
            max_val = max(max_val ,help(pos1-1,pos2,nums1,nums2, dp ));
            max_val =  max(max_val ,help(pos1,pos2-1,nums1,nums2, dp ));
            pos1--;
            pos2--;
        }
        match_len = max(match_len,max_val);
        int b = max(help(pos1-1,pos2,nums1,nums2, dp),help(pos1,pos2-1,nums1,nums2, dp));
        int temp = max(match_len,b);
        if(pos1>= 0 and pos2 >= 0)dp[pos1][pos2] = temp;
        return temp;
    }

    //working solution

    /*
    since we need consecutive pairs we start filling from the table 
    if the current char matches then we write the current value to be 1+ dp[pos1-1][pos2-1]
    which means that if the current char is matching then we take the current char and the previous position in both string matched .
    if the current char doesn't match then we don't consider it and put 0 in longest subsequence  we use to put max(dp[pos1-1][pos2],dp[pos1][pos2-1]) since we say that till now whatever maximum match we have found if consecutive or not whereas the pos1-1 , pos2-1 represent the just previous word;

    */
    int tabulation(vector<int>& text1, vector<int>& text2)
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
        int max_val = 0;
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
                    dp[pos1][pos2] = 0;
                }
                if(dp[pos1][pos2] > max_val)max_val = dp[pos1][pos2];
            }
        }
        return max_val;
    }
    int findLength(vector<int>& nums1, vector<int>& nums2) {

        //CALLING THE NON WORKING SOLUTION
        // int nums1_size = nums1.size();
        // int nums2_size = nums2.size();
        // vector<vector<int>> dp(nums1_size,vector<int>(nums2_size,-1));
        // return help(nums1_size-1, nums2_size-1,nums1,nums2, dp);

        //CALLING THE TABULATION WORKING SOLUTION
        return tabulation(nums1,nums2);
    }
};
