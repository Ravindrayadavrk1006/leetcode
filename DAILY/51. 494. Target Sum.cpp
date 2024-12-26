/*
    Basic dp problem try to implement space optimized dp

*/

class Solution {
private:
    int countSums(int pos, vector<int>& nums, int target){
        if(pos == -1 && target == 0)return 1;
        if(pos == -1 )return 0;
        if(target > 1000 || target < -1000)return 0;

        //dp doesn't help
        // if(dp[pos][1000+ target] != -1 )return dp[pos][1000+ target];
        int left = countSums(pos-1, nums, target + nums[pos]);
        int right = countSums(pos-1, nums, target- nums[pos]);
        return left + right;
    }
public:
    int findTargetSumWays(vector<int>& nums, int target) {
        //dp doesn't help
        // vector<vector<int>> dp(20,vector<int>(20002, -1));
        return countSums(nums.size()-1, nums, target);
    }
};
