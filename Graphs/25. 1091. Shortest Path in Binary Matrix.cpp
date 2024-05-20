class Solution {
private:
        // ---------------------  SOL 1 --------------------------------
        /*
            basic djkistra using normal queue 
              not very optimal approach
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


        //----------------------- SOL 2 ------------------------
        /*
        
            here we are using set to keep the element in sorted order on basis of distance but not sort the node position hence using a comparator to sort;
            since two node can be at same distance which is the differentiation point for set for two elements hence we are using multiset to store more than one node at the same distance 

            st.erase(it)  //deletes all occurance of the element in mutliset ;
            so using st.erase(st.find(it))  //to delete first occurance of it, searches in same fashion smaller to larger
        */
        //optimal approach
        struct CompareByFirst{
            bool operator()(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b)const {
                return a.first < b.first;
            }
        };
        int sol_2(vector<vector<int>>& grid){
            int n = grid.size();
            if(grid[0][0] != 0)return -1;
            multiset<pair<int,pair<int,int>>,CompareByFirst> st;
            // <distance, <node row val, node col val>>
            //i.e pair.first is distance
            //pair.second is node position
            st.insert({1, {0,0}});
            vector<vector<int>> dist(n,vector<int>(n,1e9));
            dist[0][0] = 1 ;
            while(!st.empty()){
                auto front = *(st.begin());
                int distance = front.first;
                int row = front.second.first;
                int col = front.second.second;
                cout<<"{"<<distance<<" "<<row<<" "<<col<<"}"<<endl;
                //deleting only one occurance of the solution
                st.erase(st.find(front));
                if(row == n-1 && col == n-1)return dist[row][col];
                //this statement since it is bfs travesal with no sorting hence all neighbours will be done at same level -> this implies whoever will reach the last n-1,n-1 position first will be answer            
                //traversing all it's neighbours
                for(int i = 0; i< 3 ; i++){
                    for(int j = 0 ; j < 3 ; j++ ){
                        int new_i = row  + pos_arr[i];
                        int new_j = col + pos_arr[j];
                        int distance_to_this_adj_node = distance + 1; 
                        if( new_i >= 0 && new_i < n && new_j>= 0 && new_j < n && grid[new_i][new_j] == 0 && (distance_to_this_adj_node < dist[new_i][new_j])){
                            
                            dist[new_i][new_j] =distance_to_this_adj_node;
                            st.insert({distance_to_this_adj_node, {new_i,new_j}});
                        }
                    }  
                }
            }
            if(dist[n-1][n-1] == 1e9 )return -1;
            else return dist[n-1][n-1];
        }
public:
    int shortestPathBinaryMatrix(vector<vector<int>>& grid) {
        // return smallest_path(grid);


        //calling sol 2
        return sol_2(grid);
    }
};
