class Solution {
private:
    int MOD = 1e9 + 7;
    int ans = 0;

    //SOL 1, giving TLE, since sudoku was 10*10 hence it was possible to solve it under time but here worst case 1000*5 which goes too big
    /*Using the sudoku approach to solve it, sudoku is explained int the CP notes*/
    bool valid_color(int i, int j, int color, vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        //checking for 
        //i,j-1
        if(j-1>=0 && grid[i][j-1] == color)return false;

        if(i-1>=0 && grid[i-1][j] == color)return false ;
        
        return true;
    }

    //THIS IS RECURSIVE APPROACH, IT SHOULD BE MEMOIZED TO MAKE IT WORK, BUT FOR THAT WE NEED TO USE Different approach
    void sudoku_solver(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        for(int i=0; i<m; i++){
            for(int j=0; j<n; j++){
                //if the current location is empty then try to fill it 
                //3 denotes empty cell position
                if(grid[i][j] == 3)
                {
                    //if current position is empty then try to place the colors
                    for(int color =0; color<3; color++){
                        //if current color can be placed, then color and recursively check for next empty cell
                        if(valid_color(i,j, color, grid)){
                            grid[i][j] = color;
                            //when backtracking make it empty
                            sudoku_solver(grid);
                            grid[i][j] = 3;
                        }
                    }
                    //when all has been tried and we can't place any color then return, and backtrack and try other position     
                    return;
                }
            }
        }
        ans = (ans+1)%MOD;
        return;
    }





    ///SOL 2
    /*
            APPROACH -> we are trying to fill column by column REASON: because the size of column is less just at max 5

        1. since a column size is at max 5 hence forming all the combinations of RGB which can be filled in the column, once we have all the possible string that can be filled in the column one at a time.

        one of these same string will also be filled in the next column which is different from the current column and whose non-character should match with character in that row. 

        eg  
        R    B
        G    R
        B    G 
        something like this should we should try to attain.

        1. we have written a function called generate_col_states which find all the possible string which have dissimilar character next to it, col_states contain all the string which can be filled in a column
        this function is just a simple recursive function.
            
        2. find_all_solutions
                this function try to recursively fill a valid combination in the next column
                we are passing the column no which we are trying to fill and the index of string from col_states which was filled in the previous column, so that we should not fill that string or any string which has similar character in that row.

            normal recursive is not very efficient hence using  DP to improve it's time complexity 
    */
    vector<string> col_states;
    void generate_col_states(int pos, char prev_char, string curr_str, int m){
        if(pos >= m){
            col_states.push_back(curr_str);
            return;
        }
        //trying all three posibility for current position
        for(char c: {'R', 'G', 'B'}){
            if(prev_char != c){
                generate_col_states(pos+1, c, curr_str +c, m);
            }
        }
    }

    //this function uses two parameter which col we are filling now and what was the previous col state index
    int find_all_solutions(int col, int prev_state_index, int m , int n, vector<vector<int>>& dp ){
        if(col >= n )return 1;

        if(dp[col][prev_state_index] != -1 ) return dp[col][prev_state_index] ;
        int ways = 0;

        //get the previous string
        string prev_string = col_states[prev_state_index];
        //trying to fill a column state in the present column
        for(int i =0; i<col_states.size(); i++){
            //it means if the string we are trying we have filled in the previous column then no means of trying this string
            if(prev_state_index == i)continue;
            bool valid = true;

            //trying current string if it can be filled
            string curr_string = col_states[i]; 
            //checking if any character of current col is not same as previous column character, in the same row
            for(int j =0; j<m; j++){
                //if this character is same as previous colum same row character then we break and try for next possible col state
                if(curr_string[j] == prev_string[j]){
                    valid = false;
                    break;
                };
            }

            //if the current string is valid we check for the next column
            if(valid){
                ways = (ways + find_all_solutions(col+1, i, m, n, dp)) % MOD;
            }
        }
        return dp[col][prev_state_index] = ways;
    }
public:
    int colorTheGrid(int m, int n) {
        //the elmeent can be 0,1,2 representing R,G,B respectively and 3 is empty
        // vector<vector<int>> grid(m, vector<int>(n, 3));
        // sudoku_solver(grid);
        // return ans;

        //generate all the possible string that can be filled in a column
        generate_col_states(0,'d',"", m);
        //we will try by passing all the possible col_states which can be places in the current string
        int ans = 0;

        //giving TLE hence let's memoize it
        vector<vector<int>>  dp(n, vector<int>(col_states.size(), -1));
        for(int i =0; i< col_states.size(); i++){
            ans = (ans + find_all_solutions(1, i , m, n, dp)) % MOD;
        }
        return ans;
    }
};
