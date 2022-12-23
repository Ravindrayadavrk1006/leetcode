PLEASE UPVOTE IF U LIKE THE SOLUTION

Approach
the idea is simple we have take top-down approach i.e coming from m-1,n-1 to 0,0 . If we are standing at any cell then we can move in only two direction in top-down approach left and up (totally opposite of what is given but we can also go in the given direction will get same result).
solution 1 is simple and on top of recursion dp is done to reduce the time.
from a current cell we go in both left and up direction and at that we find the minimum of the both the paths and we return the minimum value. and same thing is done using recursion again and again starting from m-1,n-1 .

Complexity
Time complexity:
O(m*n)

Space complexity:
O(mn + stack space of m-1+n-1)
in solution two(tabulation) the stack space is not present S.C O(mn)
in solution 3(space optimization) space we have used is O(2*n)=O(n)

Code
class Solution {
public:
    int help(int x, int y, vector<vector<int>>& grid, vector<vector<int>>& dp)
    {
        if(x < 0 || y < 0 )return 4000001;
        if(x == 0 && y ==0 )return grid[x][y];
        if(dp[x][y] != -1 )return dp[x][y];
        //normal cases
        int left = grid[x][y] + help(x, y-1, grid, dp);
        int up = grid[x][y] + help(x-1, y, grid, dp);
        return dp[x][y] = min(left, up);
    }
    //SOLUTION 2 TABULATION FORM OF ABOVE RECURSIVE MEMOIZATION
    int tabulation(int m, int n, vector<vector<int>>& grid)
    {
        vector<vector<int>> dp(m,vector<int>(n, -1));
        for(int i = 0; i < m ; i++)
        {
            for(int j= 0; j< n; j++)
            {
                if(i==0 && j==0)dp[i][j] = grid[i][j];
                else
                {
                    int left = 4000001;
                    int up = 4000001;
                    if(i-1 >=0)
                    {
                        up = grid[i][j] + dp[i-1][j];
                    }
                    if(j-1 >= 0)
                    {
                        left = grid[i][j] + dp[i][j-1]; 
                    }
                    dp[i][j]= min(up,left);
                }
            }
        }
        return dp[m-1][n-1];
    }
    int space_optimization(int m , int n, vector<vector<int>>& grid)
    {
        vector<int> prev (n, 4000001);
        for(int i =0; i< m; i++)
        {
            vector<int> curr(n,0);
            for(int j=0 ; j< n ; j++)
            {
                if(i==0 && j==0) curr[j] = grid[i][j];
                else
                {
                    int left = 4000001;
                    int up = 4000001;
                    if(i-1 >=0)
                    {
                        up = grid[i][j] + prev[j];
                    }
                    if(j-1 >= 0)
                    {
                        left = grid[i][j] + curr[j-1]; 
                    }
                    curr[j]= min(up,left);

                }
            }
            prev = curr;
        }
        return prev[n-1];
    }
    int minPathSum(vector<vector<int>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        //calling solution 1
        // vector<vector<int>> dp(m,vector<int>(n, -1));
        // return help(m-1, n-1, grid,dp);

        //calling solution 2
        // return tabulation(m,n,grid);

        //calling solution 3
        return space_optimization(m,n,grid);
    }
};
