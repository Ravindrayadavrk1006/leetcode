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
    int help(int x, int y, vector<vector<int>>& triangle, vector<vector<int>>& dp )
    {
        if(x == triangle.size() -1  )return triangle[x][y];
        if(dp[x][y] != -1)return dp[x][y];
        //normal cases
        int down = triangle[x][y] + help(x+1, y, triangle, dp);
        int dig = triangle[x][y] + help(x+1, y+1, triangle, dp);
        return dp[x][y] = min(down, dig); 
    }
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
