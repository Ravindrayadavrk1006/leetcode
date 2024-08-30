APPROACH
--RECURSIVE MOMOIZATION APPROACH
simple starting from 0,0 element and from there going in the direction i+1,y and i+1,y+1 and taking minimum of that .
for optimization simple DP is added to id , which is a matrix of size of m*m where m is triangle size . since if we draw the recursive tree then we find that there are overlapping subproblem
eg 0,0
/
1,0 1,1
/\ / \
2,0 2,1 2,1 2,2
since we have 2,1 and 2,1 as overlapping subproblems and hence dp is used

--TABULATION APPROACH SOLUTION 2
//[IMPORTANT]
/
TABULATION WILL ALWAYS BE OPPOSITE OF WHAT WE DO IN NORMAL MEMOIZATION RECURSION
but the inner calls of the function will remain same

here --> 
we have m-1 cell in the last line hence we form a array and store all the base cases in it
since in recursion if(x == triangle.size() -1  )return triangle[x][y]; it is saying that all the values in the last row can be returned .
After it we start from n-2 row and keep going till row 0 doing the same thing
and since dp[0][0] is the last performed and hence have the minimal value hence we return this.
*/
SOLUTION 3 SPACE OPTIMIZATION--->
//from above we can see that we require only two row at a time hence using the same logic
//here ->
/*
we are filling the last row and then starting from row m-2 we start filling all the other rows using the logic that we requre just previous row same column element and and previous row current_column's next column elements minimum

Approach
Complexity
Time complexity:
o(N*N)

Space complexity:
RECURSIVE DP APPROACH : STACK SPACE -> O(N) + O(NN) <- DP MATRIX
TABULATION APPROACH -> O(NN)
SPACE OPTIMIZATION -> O(N)




class Solution {
public:

  //this is bottom up approach since it starts from smaller values and goes to larger values in solution 1.1 i have written top down approach for it since top down approach is more helpful in converting to tabulation dp

  ///1.0 solution
    int help(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp )
    {
        if(x == triangle.size() -1  )return triangle[x][y];
        if(dp[x][y] != -1)return dp[x][y];
        //normal cases
        int down = triangle[x][y] + help(x+1, y, triangle, dp);
        int dig = triangle[x][y] + help(x+1, y+1, triangle, dp);
        return dp[x][y] = min(down, dig); 
    }
    //------------------------------------------1.1---------------------------------------------------
    /*
      since in bottom up recursive approach i.e 1.0 it has just one starting point whereas in top down approach it can start from any of the last element hence taking that into consideration
      that's why in caller minimumTotal function there is a for loop which is used for calling the recursive_dp function for each of the last row elements as starting point
    */
    int recursive_dp(int row, int col, vector<vector<int>>& triangle, vector<vector<int>>& dp){
        if(row == 0 && col == 0)return triangle[0][0];
        //out of bound cases
        if(row < 0 || col<0  || col > row )return triangle.size()* 1e4;
        if(dp[row][col] != -1)return dp[row][col];
        //normal cases
        int up = triangle[row][col] + recursive_dp(row-1,col, triangle,dp);
        int diag = triangle[row][col] + recursive_dp(row-1, col-1, triangle, dp);
        return dp[row][col] = min(up, diag);
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        int n = triangle.size();
        vector<vector<int>> dp(n,vector<int>(n,-1));
        int min_i = INT_MAX;
        // return recursive_dp(n-1, n-1, triangle);
        for(int i = 0; i<n; i++){
            int curr_min = recursive_dp(n-1,i, triangle,dp);
            min_i = min(min_i , curr_min);
        }
        return min_i;
    }
};

---------------------------------------------1.1 end here




    

    
    //[*IMPORTANT]
    /*
    TABULATION WILL ALWAYS BE OPPOSITE OF WHAT WE DO IN NORMAL MEMOIZATION RECURSION
    but the inner calls of the function will remain same
    
    here --> 
    we have m-1 cell in the last line hence we form a array and store all the base cases in it
    since in recursion if(x == triangle.size() -1  )return triangle[x][y]; it is saying that all the values in the last row can be returned .
    After it we start from n-2 row and keep going till row 0 doing the same thing
    and since dp[0][0] is the last performed and hence have the minimal value hence we return this.
    */
    int tabulation(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        vector<vector<int>> dp(m,vector<int>(m,-1));
        //filling up the last level or the base case
        for(int i=0; i<m; i++)
        {
            dp[m-1][i] = triangle[m-1][i];
        }
        for(int i=m-2; i>=0 ; i--)
        {
            for(int j = i; j>=0; j--)
            {
                int down = triangle[i][j] + dp[i+1][j];
                int dig = triangle[i][j] + dp[i+1][j+1];
                dp[i][j] = min(down, dig);
            }
        }
        return dp[0][0];
    }
    //from above we can see that we require only two row at a time hence using the same logic
    //here -> 
    /*
        we are filling the last row and then starting from row m-2 we start filling all the other rows using the logic that we requre just previous row same column element and and previous row current_column's next column elements minimum
    */
    int space_optimization(vector<vector<int>>& triangle)
    {
        int m = triangle.size();
        vector<int> prev(m+1,0);
        for(int i=0; i<m; i++)
        {
            prev[i] = triangle[m-1][i];
        }
        for(int i=m-2; i>=0 ; i--)
        {
            vector<int> curr(i+1,0);
            for(int j = i; j>=0; j--)
            {
                int down = triangle[i][j] + prev[j];
                int dig = triangle[i][j] + prev[j+1];
                curr[j] = min(down, dig);
            }
            prev = curr;
        }

        return prev[0];
    }
    int minimumTotal(vector<vector<int>>& triangle) {
        // vector<vector<int>> dp(triangle.size(),vector<int>(triangle.size(),-1));
        // return help(0,0, triangle, dp);

        //calling tabulation 
        // return tabulation(triangle);

        //calling space optimization
        return space_optimization(triangle);
    }
};
