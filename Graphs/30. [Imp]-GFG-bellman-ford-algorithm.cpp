question link :: https://www.geeksforgeeks.org/problems/distance-from-the-source-bellman-ford-algorithm/1
explanation: 
            when used:
                1. directed , make undirected graph directed by writing adjaceny list
                2. if there is negative edge weights it is usefull , djikstra can't be usefull
                3. it can detect negative edge cycle 
            
            
            procedure:
                we update the distance of all nodes n-1 times i.e relaxation of all notes n-1 times.
                very simple simple algorithm ,
                also if we try updating or relaxing for nth time and distance updates it means there is negative weigts cycle
    
    */
    vector<int> bellman_ford(int V, vector<vector<int>>& edges, int S) {
        vector<int> dist(V, 1e8);
        dist[S] = 0;
      //relaxing n-1 times
       for(int i = 0 ; i <V-1 ; i++ ){
           //relaxing all edges
           for(auto edge : edges){
               int u  = edge[0]; 
               int v = edge[1]; 
               int wt = edge[2];
               //checking the condition to update
               //dist[u] != 1e8 states that node is reachable, it is good to check for updating
               if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                   dist[v] = dist[u] + wt;
               }
           
            }
       }
       //nth relaxation to check if there is -ve cycle 
       //idea if on n^th relaxation the dist vector update then it means there is negative cycle
       //since if there is negative cycle the distance will become more smaller 
       for(auto edge : edges){
               int u  = edge[0]; 
               int v = edge[1]; 
               int wt = edge[2];
               //if the distance is updating on nth relaxation then return a array containing {-1} 
               if(dist[u] != 1e8 && dist[u] + wt < dist[v]){
                   return {-1};
               }
       }
        
        //normally return dist
        return dist;
    }
