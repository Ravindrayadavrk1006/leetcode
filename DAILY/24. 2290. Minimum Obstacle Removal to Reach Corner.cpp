/*
    how to traverse all the ways in a 2D grid  with shorted distance
*/


class Solution {
private:
    //implement dijikstra algorithm normal

    //see the commented code in the answer is how we can avoid the already visited path, to simplify it we are using the visited trick because that is much better and efficient
    int solDijkstra(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> distance(m, vector<int>(n,INT_MAX));
        set<pair<int,pair<int,int>>> st;
        vector<vector<bool>> visited(m, vector<bool>(n,false));
        //distance of  0,0  is at 0 in the the set/
        //order -> {distance,{i,j}}
        // set<vector<int>> st;
        // st.insert({0,0,0,-1,-1});
        st.insert({0,{0,0}});
        vector<int> neighbour = {0,-1,0,1,0,};
        distance[0][0]= 0;
        visited[0][0] = true;
        while(!st.empty()){
            auto front = *(st.begin());
            // int dist = front[0];
            // int row = front[1];
            // int col = front[2];
            // int par_row = front[3];
            // int par_col = front[4];
            int dist = front.first;
            int row = front.second.first;
            int col = front.second.second;
            st.erase(front);
            // cout<<"front "<<row<<" "<<col<<endl;
            if(row == m-1 && col == n-1)return dist;
            for(int a=0; a<4; a++){
                int new_row = row +neighbour[a];
                int new_col = col + neighbour[a+1];
                // cout<<"new_pos"<<new_row<<" "<<new_col<<endl;

                //for preventing the infinite loop we are using that the next element should not be the parent of the current element  !(new_row == par_row && new_col == par_col)
                // if(new_row>=0 && new_col>=0 && new_row< m && new_col<n && !(new_row == par_row && new_col == par_col) && grid[new_row][new_col] + dist < distance[new_row][new_col] ){
                //     // cout<<grid[new_row][new_col] + dist<<" "<<new_row<<" "<<new_col<<" "<<row<<" "<<col<<endl;
                //     st.insert({grid[new_row][new_col] + dist,new_row, new_col, row, col});
                // }


                //normally checking if the new_row and new_col is in correct range and checking that this element has not been visited earlier
                if(new_row>=0 && new_col>=0 && new_row< m && new_col<n && !visited[new_row][new_col] &&  grid[new_row][new_col] + dist < distance[new_row][new_col] ){
                    // cout<<grid[new_row][new_col] + dist<<" "<<new_row<<" "<<new_col<<" "<<row<<" "<<col<<endl;
                    // st.insert({grid[new_row][new_col] + dist,new_row, new_col, row, col});
                    st.insert({grid[new_row][new_col] + dist,{new_row, new_col}});
                    visited[new_row][new_col] = true;
                }
            }
        }
        //code will never reach here
        return INT_MAX;
    }
public:
    int minimumObstacles(vector<vector<int>>& grid) {
        return solDijkstra(grid);
    }
};
