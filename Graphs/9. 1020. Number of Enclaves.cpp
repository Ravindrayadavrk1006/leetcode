/*
    question -> same as https://github.com/Ravindrayadavrk1006/leetcode/blob/main/Graphs/8.%20130.%20Surrounded%20Regions.cpp
    i.e same as previous problem in the github.

    approach -> reach all the 1 which are reachable from the boundaries , by running dfs travesal from all the boundary nodes which are 1.
    the 1 which are finally not visited would not reachable from the boundary hence count them and return it as answer
*/
class Solution {
private:
    vector<int> pos_arr = {0,-1,0,1,0};
    //normal dfs algorithm 
    void helper_dfs(int i,int j,vector<vector<int>>& visited,vector<vector<int>>& board){
        visited[i][j] =1;
        int n = board.size();
        int m = board[0].size();
        //checking for current element all for adjecent positions
        for(int pos = 0 ; pos<4; pos++){
            int new_i = i+pos_arr[pos];
            int new_j = j+pos_arr[pos+1];
            //new_i,new_j should be a valid positin and it should not be already visited and should be equal to O since being called when board[i][j]=1 only hence will be O only
            if(new_i < n && new_j < m && new_i >=0 && new_j >= 0 && !visited[new_i][new_j] && board[new_i][new_j] == board[i][j]) 
                helper_dfs(new_i,new_j,visited,board);
        }
    }
    int count_enclaves(vector<vector<int>>& board){
        int n = board.size();
        int m = board[0].size();
        //initially all are marked non visited
        vector<vector<int>> visited(n,vector<int>(m,0));
        
        //see how the boundaries are travesed
        //for first and last row
        for(int j = 0 ; j < m; j++){
            if(board[0][j]== 1 && !visited[0][j]){
                helper_dfs(0,j,visited,board);
            }
            if(board[n-1][j]==1 && !visited[n-1][j]){
                helper_dfs(n-1,j,visited,board);
            }
        }
        //for first column and last column
        for(int i=0; i<n; i++){
            if(board[i][0]==1 && !visited[i][0]){
                helper_dfs(i,0,visited,board);
            }
            if(board[i][m-1]==1 && !visited[i][m-1]){
                helper_dfs(i,m-1,visited,board);
            }
        }
        int count = 0;

        //now since the O which were reachable from boundary zero would have become 1 because visited so let's keep them O and other make make them O non reachable ones
        for(int i = 0; i< n; i++){
            for(int j=0;j<m;j++){
                if(board[i][j]==1 && !visited[i][j])count++;
            }
        }
        return count;
    }
public:
    int numEnclaves(vector<vector<int>>& grid) {
        return count_enclaves(grid);
    }
};