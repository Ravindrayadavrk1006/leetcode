Approach
approach explained inside the code

Complexities
TIME COMPLEXITY O(N!))
SPACE COMPLEXITY N+N^2+ 3N= O(n^2)
Code
class Solution {
public:
    //no omptimized Is_safe
    //simply using logic to check
    bool Is_safe(int i, int j, int n, vector<string>& board)
    {
        int temp_i=i;
        //checking if the  current above has any element and if position of current queen is being attacked by the the other queens placed before 
        while(temp_i >= 0)
        {
            if(board[temp_i][j]=='Q')return false;
            temp_i--;
        }
        //going in left diagonal
        int tmp_i=i;
        int tmp_j=j;
        while(tmp_i >= 0 &&  tmp_j >= 0)
        {
            if(board[tmp_i][tmp_j]=='Q')return false;
            tmp_j--;
            tmp_i--;
        }
        tmp_i=i;
        tmp_j=j;
        while(tmp_i>=0 && tmp_j < n)
        {
            if(board[tmp_i][tmp_j]=='Q')return false;
            tmp_i--;
            tmp_j++;
        }
        return true;
    }
    //optimized is_safe
    //here we are using a vector occupied_board which has just three rows 
    //row 0 represent if current occupied or not
    //row 1 is used for cheking if right top diagonal occupied or not
    //row 2 is used for checking if left top diagonal occupied or not
    //the logic of checking conflict of placing can be verified by taking a simple n*n matrix and doing x+y for each square and simpilary in other n*n matrix x-y+n-1 for each square we will find right diagonal and left diagonal value in each 
    bool is_safe(int x, int y, int n, vector<vector<int>>& occupied_board )
    {
        //checking if no element in the column;
        if(occupied_board[0][y])return false;

        //right top diagonal
        if(occupied_board[1][x+y])return false;
        
        //check for top left diagonal
        if(occupied_board[2][x-y+n-1])return false;
        return true;
    }
    void help(int row, int n, vector<string>& board , vector<vector<string>>& ans , vector<vector<int>>& occupied_board)
    {
        //base
        if(row == n)
        {
            ans.push_back(board);
            return;
        }
        //for each element checking if safe or not
        for(int j=0;j<n;j++)
        {
            if(is_safe(row, j, n, occupied_board))
            {
                board[row][j]='Q';
                occupied_board[0][j]=1;
                occupied_board[1][row + j]=1;
                occupied_board[2][row-j+n-1]=1;
                help(row+1,n,board,ans, occupied_board);
                board[row][j]='.';
                occupied_board[0][j]=0;
                occupied_board[1][row + j]=0;
                occupied_board[2][row-j+n-1]=0;
            }
        }
        //doesn't matter if we write return  or not  since no other statement after it
        return;
    }
    vector<vector<string>> solveNQueens(int n) {
        vector<vector<string>> ans;
        vector<string> board(n, string (n,'.'));
        //in occupied_board
        // row 0 is for column occupancy , row 1 for left top diagonal , row 2 for right top diagonal
        vector<vector<int>> occupied_board(3,vector<int>(2*n,0));
        help(0, n, board, ans, occupied_board);
        return ans;
    }
};
