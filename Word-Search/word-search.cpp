Approach
from the given board we will start our help function which have same starting as our word .
help we are trying to find the possible word in all the four direction from current location if not found return false.
we have used * for making sure if something like "dfd" to be found
and suppose we have df only in the board then on finding df it will try to move back and find d and form dfd to avoid it have put * ;
finally replacing back * to original so that next time when we come back our board remain intact.

[*important] in such board question try to keep if(x<0 || x== x_size || y < 0 || y == y_size || board[x][y] != word[i])return false;
or similar as base condition

Complexity
Time complexity:
O((m*n)*4^word.size())

Space complexity:
O(m*n)

Code
class Solution {
public:
    bool help(int i , int x, int y, int x_size, int y_size, string word, vector<vector<char>>& board )
    {
        if(i==word.size())return true;
        //
        if(x<0 || x== x_size || y < 0 || y == y_size || board[x][y] != word[i])return false;

        board[x][y]='*';
        //go right
        bool right = help(i+1, x+1, y, x_size, y_size, word, board);
        bool left = help(i+1, x-1, y, x_size, y_size, word, board);
        bool up = help(i+1, x, y+1, x_size, y_size, word, board);
        bool down = help(i+1, x, y-1, x_size, y_size, word, board);
        board[x][y]=word[i];
        return right || left || up || down;
    }
    bool exist(vector<vector<char>>& board, string word) {
        for(int i=0;i<board.size();i++)
        {
            for(int j=0;j<board[0].size();j++)
            {
                if(board[i][j]==word[0])
                {
                    if(help(0,i,j,board.size(),board[0].size(),word,board))return true;
                }
            }
        }
        return false;
        
    }
};
