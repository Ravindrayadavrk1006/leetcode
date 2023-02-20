class Solution {
public:

/*
approach of MCM[matrix chain multiplication] since they wan't to calculate all the approaches and if goes out of bound then assume the values to be 1
for assuming this have added 1 at end of array
and for 1 at start started i = 0 instead of 1 so that it assumes index 0 and 1 before it and to handle out of bound in this cases have asked 
if(i-1<0)
            {
                curr_val = values[k]*values[j]+sol(i,k,values,dp)+sol(k+1, j, values,dp); 
            }
*/
     int sol(int i , int j , vector<int> & values,vector<vector<int>>& dp)
    {
        if(i==j )return 0;

        //normal cases
        //parition the array into parts using the a var k which runs from 1 to k-1  
        if(dp[i][j] != -1)return dp[i][j];
        int max_val = -1e9;
        for(int k = i; k<j ; k++)
        {
            int curr_val = 0 ;
            if(i-1<0)
            {
                curr_val = values[k]*values[j]+sol(i,k,values,dp)+sol(k+1, j, values,dp); 
            }
            else
            {
                curr_val = values[i-1]*values[k]*values[j]+sol(i,k,values,dp)+sol(k+1, j, values,dp);
            }
            max_val= max(max_val, curr_val); 
        }
        return dp[i][j] = max_val;
    }
    int maxCoins(vector<int>& nums) {
        int n = nums.size();
        //since on looking at the sol recursion two vars are being used hence we use the two vars and since max i and j can go to n each hence of size n*n
        nums.push_back(1);
        vector<vector<int>> dp(n+2,vector<int>(n+2,-1));
        return sol(0,n,nums,dp);
    }
};
