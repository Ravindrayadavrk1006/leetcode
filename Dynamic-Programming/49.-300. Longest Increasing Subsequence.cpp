/*
  basic approach of take and non-take recursion
  see where the range of values is from -ve to +ve is managed in index, eg. -1e4 to 1e4 for it we have created index from 0 to 2*1e4

*/
class Solution {
private:
    //APPROACH 1
    int recursive_sol(int i,int prev, vector<int>& nums, vector<vector<int>>& dp)
    {
        //base case
        if(i == nums.size())return 0;
        
        //normal cases
        //since have to find the subsequence hence will take the approach of take not take
        //here +10001 done since the index we have used is between 0 to 20002 and 0 value lies at 10001
        if(dp[i][prev+10001] != -1)return dp[i][prev+10001];
        //NOT TAKE
        //since we aren't taking hence no condition check
        //we will move on the next element and prev will remain same since not taken current element and since not taken will contirbute 0 in the subsequence lenght increase
        int not_take = 0 + recursive_sol(i+1,prev,nums,dp);

        //TAKE
        
        //since there is a condition check when we go for take path hence we have initialized with 0 contribution initially
        int take = 0;
        if(nums[i]> prev) take = 1 + recursive_sol(i+1,nums[i],nums,dp);
        return dp[i][prev+10001] = max(not_take,take);
    }

    //APPROACH 2
    //HERE INSTEAD OF KEEPING A TRACK OF PREVIOUS VALUE WE WILL TRY TO KEEP A TRACK OF PREVIOUS INDEX
    //VERY SIMILAR CODE TO ABOVE
    int approach_previous_index(int i,int prev_index, vector<int>& nums, vector<vector<int>>& dp)
    {
        //base case
        if(i == nums.size())return 0;
        
        //normal cases
        if(dp[i][prev_index+1] != -1)return dp[i][prev_index+1];
        //NOT TAKE
        int not_take = 0 + approach_previous_index(i+1,prev_index,nums,dp);

        //TAKE

        int take = 0;
        //if prev_index == -1 it means we have not taken any element yet hence we can take the current element or we can take the current element if nums[current_index i.e. i ]> nums[prev_index]
        if(prev_index==-1 || nums[i]> nums[prev_index]) take = 1 + approach_previous_index(i+1,i,nums,dp);
        return  dp[i][prev_index+1] = max(not_take,take);
    }
public:
    int lengthOfLIS(vector<int>& nums) {

        //APPROACH 1 CALL
        //in dp since the min value acc. to constraints is -10001 hence we are making it positive by making a shift of +10001 so that -10001 is represented by -10001+10001 = 0 and hence our values will go upto 20002
        // vector<vector<int>> dp(nums.size(), vector<int>(20002,-1));
        // return recursive_sol(0,-10001,nums,dp);


        //APPROACH 2 CALL
        int n = nums.size();
        //since we have taken -1 as index hence we have to do shifting of index
        //since shifting of index won't change the cod but will change only the places of representation in the dp hence using the same trick in approach_previous_index
        vector<vector<int>> dp(nums.size(), vector<int>(nums.size()+1,-1));
        return approach_previous_index(0,-1,nums,dp);
    }
};
