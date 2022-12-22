
//for better solution look at DP-UNIQUE PATH 

class Solution {
public:
    
    //SOLUTION 1
    int help(int x, int y,vector<vector<int>>& obstacleGrid, vector<vector<int>>& dp)
    {
        if(x < 0 || y < 0)return 0;
        //THIS LINE ADDITION TO UNIQUE PATHS
        if(obstacleGrid[x][y] == 1)return 0;
        if( x == 0 && y == 0)return 1;
        if(dp[x][y] != -1)return dp[x][y];
        //normal cases
        //since starting from n-1 and m -1 hence going in left and top direction
        int up = help(x-1,y,obstacleGrid, dp);
        int left= help(x, y-1,obstacleGrid, dp);
        return dp[x][y] = up + left;
    }
    int uniquePathsWithObstacles(vector<vector<int>>& obstacleGrid) {
      int m = obstacleGrid.size();
      int n = obstacleGrid[0].size();
      vector<vector<int>> dp (m,vector<int>(n,-1));
      return help(m-1, n-1,obstacleGrid, dp);
   
    }
};
