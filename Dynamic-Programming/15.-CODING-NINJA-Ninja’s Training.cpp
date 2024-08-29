#include <bits/stdc++.h>
QUESTION LINK -> https://www.naukri.com/code360/problems/ninja-s-training_3621003?leftPanelTabValue=PROBLEM
/*
    always try to write recursion because we know recursive dp is nothing but recursion with two extra line

    here we are trying all the ways possible and returing the maximum out of all the ways
    


    explanation of approach ->
        we are starting from n-1 and prev_task = 3 since we are assuming non task is done before,
        we are trying to try all the ways except if prev_task since we can't go vertically as told in the question
*/

int recursive_dp(int day, int prev_task,vector<vector<int>> &points,vector<vector<int>>& dp){
        if (day < 0 )return 0;
        //normal cases
        if(dp[day][prev_task] != -1)return dp[day][prev_task];
        int max_i = INT_MIN;
        for(int i = 0; i<=2; i++){
            if(i != prev_task){
                int curr_point = points[day][i] + recursive_dp(day-1, i,points,dp);
                max_i = max(max_i, curr_point); 
            } 
        }
        return dp[day][prev_task] = max_i;
}
int ninjaTraining(int n, vector<vector<int>> &points)
{   /*
        from the notes we found out that dp array will be same size as number of changing variables in the dp 
        we have two variables in array day and prev_task and hence we will keep a array of that size
        max of days = n 
        max of prev_task = 3 hence we will create vector of size n*3
*/
    vector<vector<int>> dp(n, vector<int>(3+1,-1));
    //initially the prev_task is 3 since none task is done so it will never class with any of 0 to 2 tasks
    return recursive_dp(n-1, 3, points, dp);
}
