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
//top down approach 
//it is exactly same as above just instead of starting from 0th and going towards
//here we will start from index = n-1 and try to come to index 0
int ans_dp_top_down_approach(int indx, vector<int>& nums, vector<int>& dp){
    //base case 
    if(indx == 0)return nums[0];
    if(indx < 0 )return 0;
    if(dp[indx] != -1)return dp[indx];
    //normal cases
    int pick = nums[indx] + ans_dp_top_down_approach(indx-2, nums, dp);
    int non_pick = 0 + ans_dp_top_down_approach(indx-1,nums, dp);
    return dp[indx] = max(pick,non_pick);
}

/*
    below is the tabluation approach:
        read in notes in algo-ds notes
        how to convert recusive dp to tabulation dp
        we are using the same concept , by manually calcualting smaller values and then using the same concept for calculating larger values

        tabulation uses bottom up approach from small values it goes to larger values
*/
int memoization(vector<int>& nums){
    if(nums.size()== 0)return -1;
    if(nums.size() == 1)return nums[0];
    if(nums.size() == 2 )return max(nums[0], nums[1]); 
    vector<int> dp(nums.size(),0);
    /*below two lines are by using the above two conditions when sizes are 0 and 1 
        we can also start by using two more elements with index -1 and -2 with values 0  for both 
        and we have to extend the dp array by 2 more elemnts and nth index in dp will store actual value for index-2
        but instead we can pre-calculate values for dp[0] and dp[1],
        since dp[0] = max(dp[0]+dp[0-2], dp[-1])   //where dp[-2] and dp[-1] are always zero
        dp[1] = max(dp[1]+dp[1-2], dp[0])     using the above function we can see easily
    */
    dp[0] = nums[0];
    dp[1] = max(nums[0], nums[1]);
    int n = nums.size();
    for(int i = 2; i<n; i++){
        dp[i] = max(nums[i] + dp[i-2], dp[i-1]);
    }
    return dp[n-1];
}
int maximumNonAdjacentSum(vector<int> &nums){
    //calling recursive dp starting from index 0 to index n
    // vector<int> dp(nums.size(),-1);
    // return ans_dp(0,nums,dp);

    //CALLING RECURSIVE DP USING TOP DOWN APPRAOCH I.E SAME AS ABOVE CALLING BUT STARTING FROM N-1 AND GOING TOWARDS ZERO
    // vector<int> dp(nums.size(),-1);
    // return ans_dp_top_down_approach(nums.size()-1, nums,dp);

    //CALLING momoization dp
    return memoization(nums);

    //READ BELOW PART AFTER MEMOIZATION OR TABULATION DP
    //we can further solve it by using two variable since 1d dp can be converted into two variable for space optimization
    /*

        
        by calulating the value of first = nums[0] and second =max(nums[0], nums[1]);
        now we can run just for loop and keep storing the values in first and second 
    
    */
}
