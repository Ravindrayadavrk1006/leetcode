class Solution {
/*
        can refer to editorial of this question as well

*/
public:

    //dp_func is just calculating the maximum sum of three non overlapping subarrays of nums,
    //here we are not calculating the final anwer
    //once we have the anwer we will use this dp solution to calculate the final answer by traversing the same function using dfs function below
    int dp_func(int i, int rem, int k , vector<int>& sums, vector<vector<int>>& dp){
        if(rem == 0)return 0;
        if(i >= sums.size()){
            //here we are saying if the remaining element to take is more than 0 then we don't consider it in solution i.e we take it as INT_MIN, if rem = 0 but but we can return 0 since previous three elemnt would have been already added
            return rem > 0 ? INT_MIN : 0;
        }
        if(dp[i][rem] != -1)return dp[i][rem];
        //take the current element, reduce the count of elements to take further by 1 and move to i+k index because we can't any element before that
        int take = sums[i] + dp_func(i+k, rem -1,k,  sums, dp);
        //if not taken then try for the next element
        int not_take = dp_func(i+1, rem,k, sums, dp);
        //maximum of both will be the answer
        return dp[i][rem] = max(take, not_take);
    }

    /*
        it traveses the dp function once again and see how we are getting the final answer, similar to dp but see the approach , ***NOTE [using tabluation appraoch after writing the recursive approach, the path finding will become very easy]
    */
    void dfs(int i, int rem, int k, vector<int>& sums, vector<int>& indices, vector<vector<int>>& dp){
        if(rem == 0)return;
        if(i >= sums.size())return;

        int take = sums[i] + dp_func(i+k, rem-1, k, sums, dp);
        int not_take = dp_func(i+1,rem, k, sums, dp);
        //choosing the path that gives optimal result

        //we are saying which ever will return the more will be one index of the anwer
        if(take >= not_take){
            indices.push_back(i);
            dfs(i + k, rem-1, k, sums, indices, dp);
        }
        else{
            dfs(i+1,rem,k,  sums, indices, dp);
        }
    }
    vector<int> maxSumOfThreeSubarrays(vector<int>& nums, int k) {
        int n = nums.size();
        //length of the sum array , sum array contain from current index to next k element sum
        int sumSize = n -k +1;
        vector<int> sums(sumSize);
        //using sliding window to calculate the sum;
        int windowSum = 0;
        for(int i = 0; i<k; i++){
            windowSum+=nums[i];
        }
        sums[0] = windowSum;
        for(int i = 1; i<=n-k; i++){
            //adding the i+k-1 th element and subtracting i-1 the element
            windowSum+=nums[i+k-1];
            windowSum-=nums[i-1];
            sums[i] = windowSum;
        }

        vector<vector<int>> dp(sumSize, vector<int>(4, -1));
        //after we have window let's do DP and find the maximum sum after it we are traversing the dp to find the path
        vector<int> indices;
        dp_func(0, 3, k, sums, dp);
        //forming the final solution
        dfs(0,3, k, sums, indices, dp);
        return indices;
    }
};
