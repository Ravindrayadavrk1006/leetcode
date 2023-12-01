class Solution {
private:
    //SOL 2 using stack
    /*
        idea --> 
        since we were traversing entire array for finding '.' element. To optimize that point stored all the '.' positions in an stack. and only traversing for that. 
    working: initially have stored all the elements in a array so that intial empyt pos remains and top and last empty at last in the stack . For each empty positions will check if a valid character can be placed if can be placed , will store this position in a stack and move to fill the next empty space . We will do till all the empty spaces are occupied by valid character if we are done . 
    If out of 1 to 9 none can be placed at a position . We return false and for false we try to remove the char we placed in ealier position(by making the board position again '.' and moving the top most element from second stack again to first stack (i.e bringing to initial position or removing the disturbance we did on going)) and try to replace it with some other valid char and try and try to procced again 
    */
    bool usingStack(vector<vector<char>>& board, stack<pair<int,int>>& first_stack, stack<pair<int,int>>& second_stack){
        if(first_stack.empty())return true;
        for(char c='1'; c<='9'; c++){
            pair p =first_stack.top();
            if(ifValid(board,p.first, p.second,c)){
                board[p.first][p.second] = c;
                first_stack.pop();
                second_stack.push(p);
                if(usingStack(board, first_stack, second_stack))return true;
                else {
                    board[p.first][p.second] = '.';
                    second_stack.pop();
                    first_stack.push(p);
                }
            }
        }
        return false;
    }

    //SOL 1 NORMAL SOLUTION
    /*
      logic : in each rucursion we traverse entire board and once we find a '.' we insert a valid character there and 
      try to fill the next '.' in board by recursively calling the function . If we are not able to fill a position by any valid character . It means we have
      made mistake somewhere earlier in filling hence we return false after trying 1-9 all chars at the position. We remove the fill that we made and let other valid char to be tried at that position
      
    */
    bool sudokuHelper(vector<vector<char>>& board ){
        for(int i = 0 ; i <9; i++){
            for(int j=0; j<9;j++){
                if(board[i][j] == '.'){
                    //if uses ascii number to compare when addition is done hence works fine 
                    for(char c = '1'; c<= '9'; c++){
                        if(ifValid(board, i, j, c)){
                            board[i][j] = c;
                            if(sudokuHelper(board))return true;
                            else board[i][j] = '.';
                        }
                    }
                    return false;
                }
            }
        }
        return true;
    }
    //explained logic in C.P notes 
    bool ifValid(vector<vector<char>>& board, int i, int j, char c){
        for(int pos = 0; pos < 9; pos++){
            //check if occurs in that row
            if(board[pos][j] == c)return false;
            //check if occurs in that column
            if(board[i][pos] == c )return false;
            //if occur in that 3*3 grid 
            if(board[3*(i/3)+ (pos/3)][3*(j/3)+(pos%3)]== c)return false;
        }
        return true;
    }
public:
    void solveSudoku(vector<vector<char>>& board) {
        //CALLING SOL. 1
        // sudokuHelper(board);

        
        //CALLING SOL 2
        stack<pair<int,int>> first_stack;
        stack<pair<int,int>> second_stack;
        pair<int,int> temp_pair;
        //storing all empty cells in stack in normal order 
        //starting from last cell so that the last element store at last in the stack 
        for(int i = 8 ; i>=0 ; i--){
            for(int j = 8 ; j>=0 ;j--){
                if(board[i][j]== '.'){
                    temp_pair.first = i;
                    temp_pair.second = j;
                    first_stack.push(temp_pair);
                }
            }
        }
        //now calling the solution
        usingStack(board, first_stack, second_stack);

        
    }
};
