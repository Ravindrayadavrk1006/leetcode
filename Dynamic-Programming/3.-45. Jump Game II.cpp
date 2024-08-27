/*
Approach
simple approach of from current position going in the all possible direction i.e between 1 and current index value and returning the minimum of it.

Complexity
Time complexity:
O(n)

Space complexity:
O(n*max(value of nums array))

instead of finding the minimum of a for loop we can take a variable initized with max_value and then we can keep comparing and storing min(curr_value, this_run_value)
  
*/  
  
  class Solution {
public:
    int help(int pos, vector<int>& nums, vector<int>& dp)
    {
        if(pos >= nums.size()-1)return 0;
        if(nums[pos] == 0)return  nums.size();
        if(dp[pos] != -1)return dp[pos];
        int curr_min = INT_MAX;
        //from current position going in all the possible direction of jumps
        for(int i=1;i<=nums[pos];i++)
        {
            //one step for every jump made 
            int temp=1+help(pos+i, nums, dp);
            curr_min = min(temp,curr_min);
        }
        return dp[pos] = curr_min;
    }
    int jump(vector<int>& nums) {
        vector<int> dp(nums.size()+1, -1);
        return help(0, nums, dp);   
    }
};
