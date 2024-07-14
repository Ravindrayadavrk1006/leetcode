class Solution {
    /*simple and direct application of floyd warshall algorithm
        see how when floyd warshall is applied for each node i.e ith row , we have the smallest distance from each node to reach at that ith node.
        i.e 0th row denote , the smallest distance taken from each node to reach 0th node
        
    */
private:
    int sol_find_the_city(int n, vector<vector<int>>& edges, int distanceThreshold){
        //creating adj_matrix 
        vector<vector<int>> adj_matrix(n, vector<int>(n,1e9));
        //inserting the given edges in the adj_matrix 
        for(auto edge: edges){
            //since given graph is a undirected graph and hence done two times
            int i = edge[0];
            int j = edge[1];
            int wt = edge[2];
            adj_matrix[i][j] = wt; 
            adj_matrix[j][i] = wt; 
        }
        //making all self eges 0 i.e (0,0), (1,1), (2,2) and so on
        for(int i= 0 ; i< n; i++){
            adj_matrix[i][i] = 0 ;
        }
        //normal floyd warshall algorithm
        for(int via = 0 ; via < n ; via++){
            for(int i = 0 ; i< n ; i ++){
                for(int j = 0 ; j< n ; j++){
                    adj_matrix[i][j] = min((adj_matrix[i][via]+ adj_matrix[via][j]) , adj_matrix[i][j]);
                }
            }
        }
        /*
            below entire section till end deals with calculating the node i.e row which has smallest neighbours reaching to it by threshold value 
        */
        int row_with_min_reachable_neigbours = n+1;
        //n+1 taken so that when it enters the below loop it get updated by atleast one value
        int min_neighbours = n+1;
        //now calculating neighbours for each of the node
        for( int i = 0 ; i< n ; i++){
            int count = 0 ;
            for(int j = 0 ; j< n; j++){
                //excluding the 0 distance ones since (1,1),(0,0),.... all are at zero distance and hence not usefull
                if(adj_matrix[i][j] != 0 && adj_matrix[i][j] <= distanceThreshold ){
                    count++;
                }
            }
            // in below if command <= since asked in question to return the one with smallest count and if have same count then return the node with greatest value i.e if node 0 and 5 have 3 neighbours then return node 5 as answer
            if(count<= min_neighbours){
                min_neighbours = count;
                row_with_min_reachable_neigbours = i ;
            }
        }
        return row_with_min_reachable_neigbours;
    }
public:
    int findTheCity(int n, vector<vector<int>>& edges, int distanceThreshold) {
        return sol_find_the_city(n, edges, distanceThreshold);   
    }
};
