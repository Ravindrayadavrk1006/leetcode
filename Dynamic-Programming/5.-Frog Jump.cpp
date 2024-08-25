problem-link -> https://www.naukri.com/code360/problems/frog-jump_3621012?leftPanelTabValue=PROBLEM
#include <bits/stdc++.h> 
/*
    basic approach of fibbonaci series

*/
int frog_jump_dp(int ind, vector<int>& heights, vector<int>& dp){
    if(ind == 0)return 0;

    //normal cases
    if(dp[ind] != -1)return dp[ind];
    int left = frog_jump_dp(ind-1, heights, dp) + abs(heights[ind]- heights[ind-1]);
    int right = INT_MAX;
    if(ind>1){
        right = frog_jump_dp(ind-2, heights, dp) + abs(heights[ind]- heights[ind-2]);
    }
    return dp[ind] = min(left,right);
}
int frogJump(int n, vector<int> &heights)
{
    vector<int> dp(n+1,-1);
    //starting from n-1 since given in question is 1 based indexing
    return frog_jump_dp(n-1,heights,dp);
}
