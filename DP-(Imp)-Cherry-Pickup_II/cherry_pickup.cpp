# Complexity
- Time complexity:
 O(row*col*col*9)

- Space complexity:
solution 1 -> O(row*col*col(i.e dp array) + row(i.e stack space))
solution 2-> O(row*col*col(i.e dp array)) since non recursive solution
solution 3 -> (2*col*col(i.e array)) = O(col*col(i.e array))
  
class Solution {
public:
    //SOLUTION 1
    //simple recursive dp solution
    //we start from two corner of row 0 since we will move same row at the same time hence we need only var for row
    //according to question we will take one time value if both reach at the same cell else both cell values using the same logic
    int memoization(int i, int j1, int j2, int row, int col, vector<vector<int>>& grid, vector<vector<vector<int>>>& dp)
    {
        if(j1 < 0 || j1>col-1 || j2< 0 || j2>col-1)return -4901;
        if(i == row-1)
        {
            if(j1 == j2 )return grid[i][j1];
            else return grid[i][j1]+ grid[i][j2];
        }

        //normal cases
        /*cases for possible at a particular i  j1 can be j1+1 and for it j2 can go in j2-1,j2, j2+1 
        i.e total 9 cases possible from current j value value added to it can be [-1,0,1]
        .ie if j1 goes j1-1 then j2 value can become  j2+[-1,0,+1]
        if j1+1 then j2 can become j2+[-1,0,+1]
        j1+0  then j2 can be j2+[-1,0,+1]
        */
        if(dp[i][j1][j2] != -1)return dp[i][j1][j2];
        int m_val = -4901;
        for(int tempj1=-1 ; tempj1<=+1 ; tempj1++)
        {
            for(int tempj2=-1 ; tempj2<=+1 ; tempj2++)
            {
                int val = 0;
                if(j1 == j2) val = grid[i][j1];
                else val = grid[i][j1] + grid[i][j2];
                m_val = max(m_val, val+ memoization(i+1 ,j1+tempj1,j2+tempj2,row, col, grid, dp));
            }
        }
        return dp[i][j1][j2] = m_val;
    }
    //SOLUTION 2
    /*
     [*important point] the loops required will for storing values at each point which will equal to the number of variable parameters in the recurisve DP and futher inside logic will be copy pasted from the recursive one

     base cases are filled first
    */
    int tabulation(int row, int col , vector<vector<int>>& grid)
    {
         vector<vector<vector<int>>> dp(row, vector(col,vector<int>(col, 0)));
         //filling the base case
         for(int j1 = 0; j1<col; j1++)
         {
            for(int j2 = 0; j2<col; j2++)
            {
                if(j1 == j2)dp[row-1][j1][j2] = grid[row-1][j1];
                else dp[row-1][j1][j2] = grid[row-1][j1] + grid[row-1][j2];
            }
         }
         //all other cases for each cell
        for(int i = row -2 ; i>=0 ; i--)
         {
            for(int j1 = 0; j1<col; j1++)
             {
                for(int j2=0;j2<col; j2++)
                 {
                    int m_val = -4901;
                    for(int tempj1=-1 ; tempj1<=+1 ; tempj1++)
                    {
                        for(int tempj2=-1 ; tempj2<=+1 ; tempj2++)
                        {
                            int val = 0;
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2];
                            int temp =  -4901;
                            if(j1+tempj1 >= 0 && j1+tempj1<col && j2+tempj2>=0  && j2+tempj2<col)
                            {
                                temp = dp[i+1][j1+tempj1][j2+tempj2];
                               
                            }
                             m_val = max(m_val, val+ temp);
                        }
                    }
                    dp[i][j1][j2] = m_val;

                 }
             }
         }
        return dp[0][0][col-1];
    }
    //SOLUTION  3
    //for space optimization since we require only n+1 row for computing the nth row 
    //here we are using the same logic for space optimizing the solution from O(row*col*col) of tabulation to (col*col)
    int space_optimization(int row, int col, vector<vector<int>>& grid)
    {
        vector<vector<int>> prev(col, vector<int>(col,0));
         //filling the base case
         for(int j1 = 0; j1<col; j1++)
         {
            for(int j2 = 0; j2<col; j2++)
            {
                if(j1 == j2)prev[j1][j2] = grid[row-1][j1];
                else prev[j1][j2] = grid[row-1][j1] + grid[row-1][j2];
            }
         }
         //all other cases for each cell
        for(int i = row -2 ; i>=0 ; i--)
         {
            vector<vector<int>> curr(col, vector<int>(col,0));
            for(int j1 = 0; j1<col; j1++)
             {
                for(int j2=0;j2<col; j2++)
                 {
                    int m_val = -4901;
                    for(int tempj1=-1 ; tempj1<=+1 ; tempj1++)
                    {
                        for(int tempj2=-1 ; tempj2<=+1 ; tempj2++)
                        {
                            int val = 0;
                            if(j1 == j2) val = grid[i][j1];
                            else val = grid[i][j1] + grid[i][j2];
                            int temp =  -4901;
                            if(j1+tempj1 >= 0 && j1+tempj1<col && j2+tempj2>=0  && j2+tempj2<col)
                            {
                                temp = prev[j1+tempj1][j2+tempj2];
                               
                            }
                             m_val = max(m_val, val+ temp);
                        }
                    }
                    curr[j1][j2] = m_val;
                 }
             }
            prev = curr;
         }
        return prev[0][col-1];
    }
    int cherryPickup(vector<vector<int>>& grid) {
        int row = grid.size();
        int col = grid[0].size();
        
        //solution 1 call
        // vector<vector<vector<int>>> dp(row, vector(col,vector<int>(col, -1)));
        // return memoization(0, 0, col-1,row, col, grid, dp);


        //SOLUTION 2 CALL
        // return tabulation(row, col , grid);


        //SOLUTION 3 CALL
        return space_optimization(row, col, grid);
    }
};
