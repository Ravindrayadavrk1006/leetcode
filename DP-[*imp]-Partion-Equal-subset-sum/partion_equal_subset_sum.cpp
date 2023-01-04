Intuition
since we require only to partition the problem into two parts . Hence looking for half of total sum as subset of the given nums

Approach
simple approach of recursive dp by keeping two variable one position for starting the current position of element and curr_req_sum to state what is the required sum at current position.

for getting the solution we tried to form all the subsequences with certain condition like 1.sum should't go below the required sum
Complexity
Time complexity:
simply recursive(without dp) -> 2^n
dp solutions -> n*(nums.size()/2)

Space complexity:
recursive dp -> O(n*(nums.size()/2) i.e dp array + n i.e stack space)
tabulation -> O(n*(nums.size()/2) i.e dp array)
space_optimized -> O(nums.size()/2)

Code
class Solution {
public:

    bool help(int pos, int curr_req_sum, vector<int>& nums, vector<vector<int>>& dp)
    {
        if(curr_req_sum == 0 )return true;
        // if(curr_req_sum < 0)return false;
        //way 1 --> other base cases
        // if(pos < 0 )return false;
        // if(curr_req_sum < 0)return false;

        //way 2 --> other base cases
        if(pos == 0)return(nums[0] == curr_req_sum);
        //normal cases
        if(dp[pos][curr_req_sum] != -1) return dp[pos][curr_req_sum];
        //not take
        bool not_take = help(pos-1, curr_req_sum, nums, dp);
        //take
        bool take = false;
        if (curr_req_sum-nums[pos]>= 0)take = help(pos-1, curr_req_sum-nums[pos], nums, dp);
        return dp[pos][curr_req_sum] = not_take || take;
    }
    //pay special care while writing base cases. look how the base cases from recurisve one are converted here to fit tabulation
    bool tabulation(vector<int>& nums , int req_sum)
    {
        int n = nums.size();
        int k = req_sum;
        vector<vector<bool>> dp(n,vector<bool>(k+1, false));
        for(int i=0; i<n; i++)dp[i][0] = true;
        if (nums[0]<=k)dp[0][nums[0]] = true;
        for(int i = 1; i< n ; i++ )
        {
            for(int j= 1 ; j<=k; j++)
            {
                //not take
                 bool not_take = dp[i-1][j];
                //take
                bool take = false;
                if (j-nums[i]>= 0)take = dp[i-1][j-nums[i]];
                dp[i][j] = not_take || take;                              
            }
        }
        return dp[n-1][k];
    }
    /*
    the idea comes since in the recrusive or tabulation current-1 row is only being referenced and hence will be space optimizing using same intuition
    */
    bool space_optimization(vector<int>& nums , int req_sum)
    {
        int n = nums.size();
        int k = req_sum;
        vector<bool> prev(k+1, false);
        prev[0] = true;
        if (nums[0]<=k)prev[nums[0]] = true;
         for(int i = 1; i< n ; i++ )
        {
            vector<bool> curr(k+1, false);
            curr[0]=true;
            for(int j= 1 ; j<=k; j++)
            {
                //not take
                 bool not_take = prev[j];
                //take
                bool take = false;
                if (j-nums[i]>= 0)take = prev[j-nums[i]];
                curr[j] = not_take || take;                              
            }
            prev = curr;
        }
        return prev[k];
    }
    bool canPartition(vector<int>& nums) {
        int total_sum = 0;
        int n = nums.size();
        //small problem
        if(n == 1)return false;

        for(int i =0; i < n; i++)
        {
            total_sum+=nums[i];
        }
        if(total_sum %2 == 1 )return false;
        int half = total_sum/2;
        // vector<vector<int>> dp(n+1,vector<int>(half+1, -1));
        // return help(n-1, half, nums,dp);

        //TABULATION SOLUTION
        //calling tabulation 
        // return tabulation(nums, half);

        //calling space optimization
        return space_optimization(nums,half);

    }

};
