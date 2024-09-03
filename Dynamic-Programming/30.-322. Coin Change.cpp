
class Solution {
public:
    int help(int pos, int curr_req_sum,vector<int>& nums, vector<vector<int>>& dp)
    {
        //since have to take a element any number of times hence we can't deal with 0th index element properly hence let's try the code go on pos<0
        if(curr_req_sum == 0)return 0;
        if(pos < 0 || curr_req_sum < 0)return 1e9;
        //normal cases
        //take
        if(dp[pos][curr_req_sum] != -1) return dp[pos][curr_req_sum];
        int take = 1e9;
        if (curr_req_sum-nums[pos]>= 0)take =1+help(pos, curr_req_sum-nums[pos], nums, dp);
        //not take
        int not_take = 0+ help(pos-1, curr_req_sum, nums, dp);
        return dp[pos][curr_req_sum] = min(not_take, take);
    }
    int coinChange(vector<int>& coins, int amount) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
		//if sorted or sort the elements
        sort(coins.begin(), coins.end());
        int a = help(n-1,amount,coins, dp);
		if (a == 1e9) return -1;
		else return a ;
    }
};
