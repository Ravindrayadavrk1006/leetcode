Approach
[note] for easily understanding go through the solution 1 i.e recursive dp or memoization solution
//solution 1
since we don't have any idea starting from which element will give us the min value and also one point to note that starting point is only not known for futher movement they have given that we can go in three direction down , left diagonal and right diagonal hence leveraging this info
we have called out help(recursive dp function) for each element of first row and then moving in the all the three direction tried to find the minimum value
[important] 1000001 this value is coming from the contraint since maximum sum can 100100100+1 i.e total rowscolumns value at each columns. (in reality we can keep smaller value since moving in three direction but still taking only one of them hence we can keep it to be 100*100+1 i.e total_rows *max value in each cell +1 (+1 since in worst case also won't succeed)
//base cases -> if(y < 0 || y > n-1 )return 1000001; since before(that is why this case kept before if(x == n -1 )return matrix[x][y]; base case )reaching the last row we can go out of bound in left and right direction .
then normally going in all the three possible direction and calculating the min val of all the three directions.

Complexity
Time complexity:
O(nn) reduced from 3^(nn)

Space complexity:
solution 1-> O(nn + n(stack space))
solution 2 -> O(nn(i.e only table)) since non recursive
solution 3-> 2*n= O(n) since require two row previous and current of size n

Code
class Solution {
public:
    //solution 1
    int help(int x, int y, int n, vector<vector<int>>& matrix, vector<vector<int>>& dp)
    {
        //base case
        //
        if(y < 0 || y > n-1 )return 1000001;
        if(x == n -1 )return matrix[x][y];

        //normal cases
        if (dp[x][y] != -1)return dp[x][y];
        int down = matrix[x][y] + help(x+1, y,n, matrix, dp);
        int left_diag = matrix[x][y] + help(x+1, y-1,n, matrix, dp);
        int right_diag = matrix[x][y] + help(x+1,y+1,n,matrix, dp);
        return dp[x][y] = min(down, min(left_diag, right_diag));
    }
    //SOLUTION 2
    //since above has a stack space of O(n) let's try to remove it and make the solution non recursive 
    //since tabulation is opposite of the recursive traversal hence the variable names are tottaly opposite of that being used in recursion DP
    //tabulation 
    int tabulation(int n , vector<vector<int>>& matrix)
    {
        //STEP 1 -> FORM A DP ARRAY OF SAME SIZE AS IN RECURSIVE
        vector<vector<int>> dp(n, vector<int>(n,-1));
        //STEP 2 -> IF REQUIRED FILL THE BASE CASE SEPARATELY
        for(int j = 0; j<n ; j++)
        {
            dp[n-1][j]= matrix[n-1][j];
        }
        //normal cases
        for(int x = n-2 ; x > -1 ; x--)
        {
            for(int y = 0; y <n; y++)
            {
                int left_diag =  1000001;
                int right_diag = 1000001;
                //since down will never go out of bound hence no need of default value
                int down =  matrix[x][y] + dp[x+1][y];
                if(y-1 > -1)left_diag =  matrix[x][y] + dp[x+1][y-1];
                if(y+1 < n) right_diag = matrix[x][y] + dp[x+1][y+1];
                dp[x][y] = min(down, min(left_diag, right_diag));
            }
        }
        int min_val = 1000001;
        for(int y = 0 ; y<n ; y++)
        {
            min_val= min(min_val, dp[0][y]);
        }
        return min_val;
    }
    //for optimizing the space from n*n to better space optimization 
    //idea for using this is since in every tabulation call we just needed the previous row for calculating the current values hence leveraging the same concept
    //SOLUTION 3 
    int space_optimization(int n , vector<vector<int>>& matrix)
    {
        vector<int> prev(n, 0 );
        for(int j = 0; j<n ; j++)
        {
            prev[j]= matrix[n-1][j];
        }

        //for each row
         for(int x = n-2 ; x > -1 ; x--)
        {
            vector<int> curr(n, 0 );   
            for(int y = 0; y <n; y++)
            {
                int left_diag =  1000001;
                int right_diag = 1000001;
                //since down will never go out of bound hence no need of default value
                int down =  matrix[x][y] + prev[y];
                if(y-1 > -1)left_diag =  matrix[x][y] + prev[y-1];
                if(y+1 < n) right_diag = matrix[x][y] + prev[y+1];
                curr[y] = min(down, min(left_diag, right_diag));
            }
            prev = curr;
        }
        int min_val = 1000001;
        for(int y = 0 ; y<n ; y++)
        {
            min_val= min(min_val, prev[y]);
        }
        return min_val;
    }
    int minFallingPathSum(vector<vector<int>>& matrix) {
        int min_val = 1000001;
        int n = matrix.size();
        //calling solution 1
        /*
        vector<vector<int>> dp(n, vector<int>(n,-1));
        for(int j = 0 ; j<n; j++)
        {
            min_val = min(min_val, help(0, j, n, matrix, dp));   
        }
        return min_val;
        */

        //CALLING SOLUTION 2
        // return tabulation(n, matrix);

        //CALLING SOLUTION 3
        return space_optimization(n, matrix);

    }
};
