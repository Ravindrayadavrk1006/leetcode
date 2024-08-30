Approach
using the DP recursive approach thinking in the way if we are standing at the last i.e m-1,n-1 position what are ways we can reach to 0,0 we will take movement in left and up direction . Left means x,y-1 and up means x-1,y and computing all the possible directions to reach.
To reduce the time from recursive 2^mn to mn used DP since maximum places we can go in the matrix are m*n and hence used DP array to deal with overlapping sub problems.

Complexity
Time complexity:
all solution -> m*n

Space complexity:
solution one ( m-1 + n-1 + mn)where m-1 + n-1 are stack space
to remove the stack space
as usual used tabulation-> S.C -> mn
for improving the space complexity used solution 3 -> S.C = O(n)
// DP MATRIX PROBLEM
class Solution {
public:

    //using normal DP solution i.e 
    //SOLUTION 1
    //T.C O(m*n)
    //S.C O(n-1 + m-1 + m*n)
    int help(int x, int y, vector<vector<int>>& dp)
    {
        if( x == 0 && y == 0)return 1;
        if(x < 0)return 0;
        if(y < 0)return 0;
        if(dp[x][y] != -1)return dp[x][y];
        //normal cases
        //since starting from n-1 and m -1 hence going in left and top direction
        int up = help(x-1,y, dp);
        int left= help(x, y-1, dp);
        return dp[x][y] = up + left;
    }

    //SOLUTION 2 I.E FOR REDUCING THE STACK SPACE WE CAN USE TABULATION 
    int tabulation(int m , int n) 
    {
        //step 1 . declare a dp of size used earlier
        // vector<vector<int>> dp (m,vector<int>(n,-1));
        int dp[m][n];
        for(int i=0;i<m; i++)
        {
            for(int j=0; j<n; j++)
            {
                if(i== 0 && j==0)dp[i][j]= 1;
                else 
                {
                    //to prevent the n-1 i.e out of bound condition
                    int left = 0;
                    int up = 0;
                    if(i-1 >= 0 )
                    {
                        up = dp[i-1][j];
                    }
                    if(j-1 >= 0)
                    {
                        left = dp[i][j-1];
                    }
                    dp[i][j]= left  + up;
                }
            }
        }
        return dp[m-1][n-1];
    }
  
  //SOLUTION 3
    int spaceOptimized(int m , int n)
    {
        vector<int> prev(n,0);
        for(int i=0;i<m; i++)
        {
            vector<int> curr(n,0);
            for(int j=0; j<n; j++)
            {
                if(i== 0 && j==0)curr[j]= 1;
                else 
                {
                    int left = 0;
                    int up = 0;
                    if(i-1 >= 0 )
                    {
                        up = prev[j];
                    }
                    if(j-1 >= 0)
                    {
                        left = curr[j-1];
                    }
                    curr[j]= left  + up;
                }
            }
            prev= curr;
        }
        return  prev[n-1];

    }
    int uniquePaths(int m, int n) {
        //USING THE TOP DOWN APPROACH(i.e starting from top going till bottom)
        //CALLLING SOLUTION 1
        // vector<vector<int>> dp (m,vector<int>(n,-1));
        // return help(m-1, n-1, dp);

        //CALLING SOLUTION 2
        // return tabulation(m,n);

        //CALLING SOLUTION 3
        return spaceOptimized(m,n);
    }
};
