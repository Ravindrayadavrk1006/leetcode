/*
  PROBLEM-LINK: https://www.naukri.com/code360/problems/0-1-knapsack_920542?leftPanelTabValue=PROBLEM
    0/1 knapsack is a simple problem of take or not take since have to find maximum that trying out all ways and finding maximum is the solution

*/
#include <bits/stdc++.h> 
using namespace std;

int help(int pos , int max_weight, int n ,  vector<int>& weight, vector<int>& value, vector<vector<int>>& dp)
{

    if(pos == 0)
    {
        if( weight[0] <= max_weight)return value[0];
        return 0;
    }
    int take = 0;
    if(dp[pos][max_weight] != -1 )return dp[pos][max_weight];
    if(weight[pos] <= max_weight)take = value[pos] + help(pos-1,max_weight-weight[pos],n, weight, value , dp);
    int not_take = 0 + help(pos-1, max_weight, n , weight, value, dp);
    return dp[pos][max_weight] = max(take, not_take);
}
int knapsack(vector<int> weight, vector<int> value, int n, int maxWeight) 
{
    vector<vector<int>> dp(n,vector<int>( maxWeight+1,-1));
	return help(n-1,maxWeight, n ,weight , value, dp );
}
