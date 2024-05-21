class Solution {
private:
        /*
            **important point -> 
                    1. here told to mind the minimum effor it means dijkstra algorithm with priority queue since different weights
                    2. here we do not need to find the distance but absolute maximum absolute diffenece for each node from consecutive so while moving  dist[adj_node] = max(parent_node, adj_node)
                    3. here correlation between simple dijkstra of finding shortest distance.
                    here minimum path means shortest and distance is equated to maximum absolute difference between the consecutive nodes. so for each node where we used to sum it with node dist and edge weight here we have to do max(dist[node],absolute differnce between node and current adj_node)
            here we are using set to keep the element in sorted order on basis of distance but not sort the node position hence using a comparator to sort;
            since two node can be at same distance which is the differentiation point for set for two elements hence we are using multiset to store more than one node at the same distance 

            st.erase(it)  //deletes all occurance of the element in mutliset ;
            so using st.erase(st.find(it))  //to delete first occurance of it, searches in same fashion smaller to larger
        */
        vector<int> pos_arr = {0,-1,0,1,0};
        //optimal approach
        struct CompareByFirst{
            bool operator()(const pair<int,pair<int,int>>& a, const pair<int,pair<int,int>>& b)const {
                return a.first < b.first;
            }
        };
        int sol_min_effort(vector<vector<int>>& grid){
            int row_count = grid.size();
            int col_count = grid[0].size();
                
            //instead of using this set and comparater can use priority_queue with no comparator it will work fine
            multiset<pair<int,pair<int,int>>,CompareByFirst> st;
            // <distance, <node row val, node col val>>
            //i.e pair.first is distance
            //pair.second is node position
            st.insert({0, {0,0}});
            //here used the name dist vector but in fact it is absolute consecute node difference or maximum absolute difference vector instead of dist vector, kept the dist name so that can be easily co-related.
            vector<vector<int>> dist(row_count,vector<int>(col_count,1e9));
            dist[0][0] = 0 ;
            while(!st.empty()){
                auto front = *(st.begin());
                int distance = front.first;
                int row = front.second.first;
                int col = front.second.second;
                cout<<"{"<<distance<<" "<<row<<" "<<col<<"}"<<endl;
                //deleting only one occurance of the solution
                st.erase(st.find(front));
                if(row == row_count-1 && col == col_count-1)return dist[row][col];
                //this statement since it is bfs travesal with no sorting hence all neighbours will be done at same level -> this implies whoever will reach the last n-1,n-1 position first will be answer            
                //traversing all it's neighbours
                for(int i = 0; i< 4 ; i++){
                    int new_i = row  + pos_arr[i];
                    int new_j = col + pos_arr[i+1];
                    if( new_i >= 0 && new_i < row_count && new_j>= 0 && new_j < col_count){
                        int abs_node_difference = abs(grid[row][col] - grid[new_i][new_j]);
                        int max_value = max(dist[row][col],abs_node_difference);
                        //means updated with new value
                        if(max_value < dist[new_i][new_j]){
                            dist[new_i][new_j] = max_value;
                            st.insert({max_value, {new_i,new_j}});
                        } 
                    
                    }  
                }
            }
            // if(dist[row_count-1][col_count-1] == 1e9 )return -1;
            return dist[row_count-1][col_count-1];
        }
public:
    int minimumEffortPath(vector<vector<int>>& heights) {
        return sol_min_effort(heights);
    }
};
