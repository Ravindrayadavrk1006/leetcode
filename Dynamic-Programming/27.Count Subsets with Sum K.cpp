/*
  PROBLEM LINK: - https://www.naukri.com/code360/problems/number-of-subsets_3952532?leftPanelTabValue=PROBLEM
  explanation: normal approach of take and non-take

*/

#include <bits/stdc++.h>
using namespace std;
int recursive_dp(int pos, int target, vector<int>& arr, vector<vector<int>>& dp ){
	if(pos == 0){

		//this is done to tacke the case when arr[0] is 0 since in that case if the target is already 0 then take or not take will both contribute in 1 , 1  and hence returning two
		if(arr[0] == 0){
			if(target == 0)return 2;
		}
		if(target == 0)return 1;
		//only equal to case taking since the other case is handled above if(target == 0)return1
		return arr[0] == target;
	}

	//normal approach of take and non-take 
	if(dp[pos][target] != -1)return dp[pos][target];
	int count = 0;
	//non take
	count +=recursive_dp(pos-1,target, arr, dp);
	//take
	if(arr[pos]<= target){
		count+= recursive_dp(pos-1, target-arr[pos], arr, dp);
	}

	return dp[pos][target] =  count % (1000000007);
}
int findWays(vector<int>& arr, int k)
{
	int n = arr.size();
	vector<vector<int>> dp(n, vector<int>(k+1, -1));
	return recursive_dp(n-1, k, arr, dp);
}
