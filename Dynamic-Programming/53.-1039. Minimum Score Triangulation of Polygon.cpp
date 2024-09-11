class Solution {
public:
    //using the concept of matrix chain multiplication here directly mcm is being used no change

    //MATRIX CHAIN MULTIPLICATION
    //explained in the notes     
    int sol(int i , int j , vector<int> & values,vector<vector<int>>& dp)
    {
        if(i==j )return 0;

        //normal cases
        //parition the array into parts using the a var k which runs from 1 to k-1  
        if(dp[i][j] != -1)return dp[i][j];
        int min_val = 1e9;
        for(int k = i; k<j ; k++)
        {
            int curr_val = values[i-1]*values[k]*values[j]+sol(i,k,values,dp)+sol(k+1, j, values,dp);
            min_val= min(min_val, curr_val); 
        }
        return dp[i][j] = min_val;
    }
    int minScoreTriangulation(vector<int>& values) {
        int n = values.size();
        //since on looking at the sol recursion two vars are being used hence we use the two vars and since max i and j can go to n each hence of size n*n
        vector<vector<int>> dp(n,vector<int>(n,-1));
        return sol(1,n-1,values,dp);
    }
};
