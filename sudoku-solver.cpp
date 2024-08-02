class Solution {
private:
    //SOL 2 using stack
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
