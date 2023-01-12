QUESTION
FROM CODING NINJA
https://www.codingninjas.com/codestudio/problems/rod-cutting-problem_800284?source=youtube&campaign=striver_dp_videos&utm_source=youtube&utm_medium=affiliate&utm_campaign=striver_dp_videos&leftPanelTab=0



/*
 if we look closely it same as unbounded knapsack (unbounded  since we can take the current element any number of times)
problem idea: 
 if we look closely cutting is same as joining since coming up and going down but take same process  hence using this concept 
 we will try to form all possible combination of the rods to form a rod of length n(or alias target)
since combination present are 1 to n hence will try to use it 
which is same as index(of array)+1 since array start from 0
so using the idea of forming all the possible subsets(take and non take concept )since it is unbounded then the take concept position won't change see the take var value in code
*/
int help(int pos, int target , vector<int>& price,vector<vector<int>>& dp)
{
    //base case 
    if(pos == 0)
    {
        //important since we are at pos 0 which states we can make a cut of size 1 only since 0+1 we return value (target/1)*price[0]
        return target*price[0];
    }
    //normal cases
    //not taking the current position element
    if(dp[pos][target] != -1)return dp[pos][target];
    int not_take = 0 + help(pos-1, target, price, dp);
    int take = INT_MIN;
    //taking the current position element
    //since pos+1 is the cut we are trying to make now
    int req_length = pos+1;
    if(req_length<= target)take = price[pos] + help(pos,target -req_length,price, dp);
    return dp[pos][target] = max(not_take, take);
}
int cutRod(vector<int> &price, int n)
{
    int price_size = price.size();
    vector<vector<int>> dp(price_size,vector<int>(n+1,-1));
    return help(price_size-1,n,price,dp);
	// Write your code here.
}
