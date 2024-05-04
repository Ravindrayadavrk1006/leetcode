/*
    problem expalnation: it is saying that if there is a zero on the boundary then all the O which can be reached from this boundary zero will remain O.
    from a position we can traverse only in four directions up,down,left and right

    so the probelm become very simple of traversing a graph ,from all the boundry points if they are O, 

    approach:
        we keep a visited array, and do dfs traversal for all the boundary points where the elemnt is O , 
            while doing dfs travesal we try to traverse , if the position are O .

        finally once we have done all the travesal , all the boundary attached or reachable O will be marked 1 in visited array and non reachable O will be zero only.
        so finally we mark all the board O as X , if the value in visited is 0.
*/
class Solution {
private:
    vector<int> pos_arr = {0,-1,0,1,0};
    //normal dfs algorithm 
    void helper_dfs(int i,int j,vector<vector<int>>& visited,vector<vector<char>>& board){
        visited[i][j] =1;
        int n = board.size();
        int m = board[0].size();
        //checking for current element all for adjecent positions
        for(int pos = 0 ; pos<4; pos++){
            int new_i = i+pos_arr[pos];
            int new_j = j+pos_arr[pos+1];
            //new_i,new_j should be a valid positin and it should not be already visited and should be equal to O since being called when board[i][j]='O' only hence will be O only
            if(new_i < n && new_j < m && new_i >=0 && new_j >= 0 && !visited[new_i][new_j] && board[new_i][new_j] == board[i][j]) 
                helper_dfs(new_i,new_j,visited,board);
        }
    }
    void x_to_s(vector<vector<char>>& board){
        int n = board.size();
        int m = board[0].size();
        //initially all are marked non visited
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //see how the boundaries are travesed
        //for first and last row
        for(int j = 0 ; j < m; j++){
            if(board[0][j]== 'O' && !visited[0][j]){
                helper_dfs(0,j,visited,board);
            }
            if(board[n-1][j]=='O' && !visited[n-1][j]){
                helper_dfs(n-1,j,visited,board);
            }
        }
        //for first column and last column
        for(int i=0; i<n; i++){
            if(board[i][0]=='O' && !visited[i][0]){
                helper_dfs(i,0,visited,board);
            }
            if(board[i][m-1]=='O' && !visited[i][m-1]){
                helper_dfs(i,m-1,visited,board);
            }
        }


        //now since the O which were reachable from boundary zero would have become 1 because visited so let's keep them O and other make make them O non reachable ones
        for(int i = 0; i< n; i++){
            for(int j=0;j<m;j++){
                if(board[i][j]=='O' && !visited[i][j])board[i][j] = 'X';
            }
        }
    }
public:
    void solve(vector<vector<char>>& board) {
        x_to_s(board);
    }
};
