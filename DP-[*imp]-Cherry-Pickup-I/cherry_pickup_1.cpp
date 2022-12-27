Intuition
using the concept if we move in y direction or x direction by taking equal steps value of x1+y1 = x2+y2 we will be using the same concept.
for converting four variables to three variables since if we have value of x1, y1,y2 we can get values of x2 easily from above equation.
Also important point going from top to bottom and then from bottom to top to the same position can be converted to going from top to bottom 2 times . The intuition comes from the point that top down dp recursion is same as bottom up recursion because we will follow the same path.
possible directions using two pointers(x1,y1),(x2,y2) will be moving in (down,down),(right,right),(right,down),(down,right)
Now this problem become equal to cherry pickup 2.

Approach
we will be taking three vars since fourth will be calculated on basis of above explained concept.
//base cases we will check if we are not moving out of bound or out of grid then we return a negative value eg -202 which will be biggest negative and it won't ever contribute in the ans.
also if the current grid value is -1 then also return -202 since this path won't be taken into consideration.

//for normal cases we will take the value of both the (x1,y1) and (x2,y2) if both values are not same else take just once if both are same.
we traverse all the four direction from current position and return the max value out of the four directions

using DP to remove the traversed path from traversing again
the[*Important] DP has three variables since the recursive function has three variables

Complexity
Time complexity:
O(n^3)

Space complexity:
O(n^3)

Code

class Solution {
public:
    //instead of coming in the backward direction like starting dp from n-1 or 0 gives same result
    //using the same concept we are travelling using two pointers from 0 
    int help(int x1, int y1, int y2, int n, vector<vector<int>>& grid, vector<vector<vector<int>>> &dp)
    {
        //since by taking any step in the right -right , down-right we have x1 +y1 = x2 +y2
         int x2 = x1+y1-y2;
         if(x1>=n || x2>=n || y1>=n || y2>=n)return -202;
         if(grid[x1][y1] == -1 || grid[x2][y2] == -1)return -202;
         if(x1== n-1 && x1 == x2 && y1 == n-1 && y1==y2)return grid[n-1][n-1];
        
        //normal cases 
        //four cases will be formed
        if(dp[x1][y1][y2] != -1 )return dp[x1][y1][y2];
        int val = 0;
        if(x1 != x2) val+= grid[x1][y1]+ grid[x2][y2];
        else val+=grid[x1][y1];
        int max_val = max(help(x1,y1+1,y2+1,n, grid, dp), help(x1+1,y1,y2+1,n,grid,dp));
        int max_val_2 = max(help(x1,y1+1,y2,n, grid, dp), help(x1+1,y1,y2,n,grid, dp));
        val+=max(max_val,max_val_2);
        return dp[x1][y1][y2] = val;

    }
    int cherryPickup(vector<vector<int>>& grid) {
        int n = grid.size();
        vector<vector<vector<int>>> dp(n,vector(n,vector<int>(n,-1)));
        return max(0,help(0, 0,0, n, grid, dp));
    }
};
