class Solution {
private:

    //wrong approach
    int sol1(vector<vector<int>>& grid){
        //creating adjaceny list for the graph
        //for us 
        // int m = grid.size();
        // int n = grid[0].size();
        // vector<int, vector<int>> adj_list(m*n);
        // for(int i =0; i<m; i++){
        //     for(int j = 0; j<n; j++){
                
        //     }
        // }
        //rows
        int m = grid.size();
        //columns
        int n = grid[0].size();
        //count no of connections
        int count_conn = 0;
        vector<int> mover  ={0,-1,0,1,0};
        //for each element in the grid which is a server checking if it has a neighbouring server to see it's connected
        for(int i =0; i<m; i++){
            for(int j = 0; j<n; j++){
                if(grid[i][j] == 1){
                    for(int pos = 0; pos<4; pos++){
                        int new_i = i+mover[pos];
                        int new_j = j+mover[pos+1];
                        //checking if the adjcent is a valid position 
                        if(new_i>=0 && new_i< m && new_j>=0 && new_j< n){
                            //if the neighbour is 1 then add it is connected add and move 
                            if(grid[new_i][new_j] == 1){
                                count_conn++;
                                break;
                            }
                        }
                    }
                }
                
            }
        }

        return count_conn;
    }
    //my approach
    //this is brute force approach, i.e for each element we are checking if has a neighour in that row or column
    int brute_force(vector<vector<int>>& grid){
        int counter = 0;
        int m = grid.size();
        int n = grid[0].size();
        for(int i =0; i<m; i++){
            for(int j =0; j<n; j++){
                //if it's a server
                if(grid[i][j] ==1){
                    bool added_to_counter=false;
                    //checking if it has a neighbour in that column
                    for(int run_i =0; run_i<m; run_i++ ){
                        if(run_i != i &&  grid[run_i][j] == 1){
                            counter++;
                            added_to_counter = true;
                            break;
                        }
                    }
                    //if already found it has a neighbour then try for next element
                    if(added_to_counter)continue;
                    //checking if it has a neigbhour in that row
                    for(int run_j =0; run_j<n;run_j++){
                        if(run_j != j && grid[i][run_j] == 1){
                            counter++;
                            break;
                        }
                    }
                }
            }
        }
        return counter;
    }

    //from editorial
    //sol 2
    //we count the number of server in each row and column 
    //while checking for each element in the grid if current element is a server and if the number of server in that row or column is more than one it means there is one other server in that row or column
    int sol_2_editorial(vector<vector<int>>& grid){
        int count = 0;
        int m = grid.size();
        int n = grid[0].size();
        vector<int> row_counter(m,0);
        vector<int> col_counter(n,0);
        for(int i =0; i<m; i++ ){
            for(int j =0; j<n; j++){
                if(grid[i][j]){
                    row_counter[i]++;
                    col_counter[j]++;
                }
            }
        }
         for(int i =0; i<m; i++ ){
            for(int j =0; j<n; j++){
                if(grid[i][j]){
                    if(row_counter[i]> 1 || col_counter[j] >1)count++;
                }
            }
        }
        return count;

    }
public:
    int countServers(vector<vector<int>>& grid) {
        // return brute_force(grid);

        return sol_2_editorial(grid);
    }
};
