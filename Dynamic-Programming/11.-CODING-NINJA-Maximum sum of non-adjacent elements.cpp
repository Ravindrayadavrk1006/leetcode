problem_link = https://www.naukri.com/code360/problems/maximum-sum-of-non-adjacent-elements_843261?leftPanelTabValue=PROBLEM
/*

  ***THIS IS ONE OF THE MAJOR CONCEPT 
    CONCEPT -> 
        of pick and non-pick used with picking non_adjcent element as addition constraint
        SIMPLE EXPLANATION:
        HERE constraint is that we don't have to take the adjacent values,
    approach:
        we know how to form all possible combinations, by using the approach of pick and non-pick so if we we use that concept,
        pick = arr[i] + f(i+1)
        non_pick = f(i+1)
        return max(pick,non_pick)

    but here one more condition is there:
        that we don't have to take adjancent element when we have picked current element it means in pick case in above code we have to move to f(i+2) once we have picked the current element
        and hence it would look like pick = arr[i] + f(i+2) 
        non_pick = f(i+1)
        retur max(pick,non_pick)




    the way we have started from indx 0 we can start from index n-1 and can move backward instead of f(i+2) we can go f(i-2) and similarly for f(i+1) we can go f(i-1)

*/

#include <bits/stdc++.h> 

int ans_dp(int indx, vector<int>& nums, vector<int>& dp){
    //base case 
    if(indx>=nums.size())return 0;
    if(dp[indx] != -1)return dp[indx];
    //normal cases
    int pick = nums[indx] + ans_dp(indx+2, nums, dp);
    int non_pick = ans_dp(indx+1,nums, dp);
    return dp[indx] = max(pick,non_pick);
}
int maximumNonAdjacentSum(vector<int> &nums){
    vector<int> dp(nums.size(),-1);
    return ans_dp(0,nums,dp);
}
