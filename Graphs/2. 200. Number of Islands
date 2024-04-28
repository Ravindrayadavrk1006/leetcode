

class Solution {
private:
    void helper_modified_dfs(int i,int j,vector<vector<char>>& grid,vector<vector<int>>& visit,int m, int n ){
            visit[i][j] =1;
            cout<<"i "<<i<<"j "<<j<<endl;
            //then call the travesal for right and down from the current position

            //calling for right
            //if j not out of range and i,j+1 is not yet visited then call recursion
            if(j+1 < n && visit[i][j+1] == 0 && grid[i][j+1]== '1' ){
                helper_modified_dfs(i,j+1,grid,visit,m,n);
            }
            if(i+1 < m && visit[i+1][j] == 0 && grid[i+1][j]== '1'){
                helper_modified_dfs(i+1,j,grid,visit,m,n);
            }
            if(j-1 >= 0 && visit[i][j-1] == 0 && grid[i][j-1]== '1'){
                helper_modified_dfs(i,j-1,grid,visit,m,n);
            }
            if(i-1 >= 0 && visit[i-1][j] == 0 && grid[i-1][j]== '1'){
                helper_modified_dfs(i-1,j,grid,visit,m,n);
            }
    }
    int sol_num_island(vector<vector<char>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        //create a visited matrix of same size
        vector<vector<int>> visit(m,vector<int>(n));  //visit array
        //so visited array we are making initally the visitable elements i.e element with value 1 in grid as 0 and and since which element are 0 in grid are not visitable ever so making it -1 
        for(int i = 0 ; i <m ; i++){
            for(int j = 0 ; j<n ; j++){
                if(grid[i][j] == '1')visit[i][j]=0;
                else visit[i][j]=-1;
            }
        }
        for(int i = 0 ; i <m ; i++){
            for(int j = 0 ; j<n ; j++){
                cout<<visit[i][j]<<" ";
            }
            cout<<endl;
        }
        int count_islands = 0 ;
        for(int i = 0 ; i <m ; i++){
            for(int j = 0 ; j<n ; j++){
                //i.e the current element is not visisted yet and it is visitable i.e not a -1
                if(visit[i][j] != -1 && visit[i][j]==0 && grid[i][j]== '1')
                {
                    cout<<"main loop"<<i<<" "<<j<<endl;
                    count_islands++;
                    helper_modified_dfs(i,j,grid,visit,m ,n);
                }
            }
        }
        return count_islands;
    }
public:
    int numIslands(vector<vector<char>>& grid) {
        return sol_num_island(grid);
    }
};
