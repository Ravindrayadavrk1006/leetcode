class Solution {
private:
        // ---------------------  SOL 1 --------------------------------
        /*
            basic djkistra using normal queue 
              this is the best approach in case of unweighted graph , since all the elements will be already inserted in the sorted order only hence no need to do further sorting
        */
        vector<int> pos_arr = {-1, 0, 1};
        int smallest_path(vector<vector<int>>& grid){
            if(grid[0][0] != 0)return -1;
            int n = grid.size();
            queue<pair<int,int>> q;
            q.push({0,0});
            vector<vector<int>> dist(n,vector<int>(n,INT_MAX));
            dist[0][0] = 1 ;
            while(!q.empty()){
                int row = q.front().first;
                int col = q.front().second;
                q.pop();
                //this statement since it is bfs travesal with no sorting hence all neighbours will be done at same level -> this implies whoever will reach the last n-1,n-1 position first will be answer
                if(row == n-1 && col == n-1)return dist[row][col];
                for(int i = 0; i< 3 ; i++){
                    for(int j = 0 ; j < 3 ; j++ ){
                        int new_i = row  + pos_arr[i];
                        int new_j = col + pos_arr[j];
                        if( new_i >= 0 && new_i < n && new_j>= 0 && new_j < n && grid[new_i][new_j] == 0 && (dist[row][col] + 1 < dist[new_i][new_j])){
                            
                            dist[new_i][new_j] = dist[row][col] + 1;
                            q.push({new_i,new_j});
                        }
                    }  
                }
            }
            return -1;
        }


        
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // return smallest_path(grid);


        //calling sol 2
        return sol_2(grid);
    }
};
