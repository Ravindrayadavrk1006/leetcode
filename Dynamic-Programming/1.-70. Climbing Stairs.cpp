/*
INTUITION
Idea is using DP and the solution is same as fibonacci series.
Idea is climbing the staircases is coming down
hence used the same approach

APPROACH
stored memo[0]=1 since coming to zero from previous step either by taking one step or two step has just one way.
Starting from n and taking one and two step in each cases coming down.

***[***important] took bottom up approach, this is very important in case of recursive search that is we should try to find value of bigger using the smaller values
*/
Complexity
Time complexity:
O(N)

Space complexity:
O(N)

class Solution {
private:
    int climb_dp(int n, vector<int>& dp){
        if(n==0)return 1;
        if(n<0)return 0;
        //if the value already exist return it
        if(dp[n] != -1)return dp[n];
        //save in the dp array before returning
        return dp[n] = climb_dp(n-1, dp) + climb_dp(n-2, dp);
    }
public:
    int climbStairs(int n) {
        vector<int> dp(n+1,-1);
        return climb_dp(n, dp);
    }
};
