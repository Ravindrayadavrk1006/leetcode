PROBLEM LIN -> https://www.geeksforgeeks.org/problems/minimum-spanning-tree/1
/*
 for in depth explanation please refere C.P notes notebook

 this is PRIMS ALGORITHM for finding minimum spanning tree
  
*/


//Function to find sum of weights of edges of the Minimum Spanning Tree.
	//this spanningTree_without_mst_edges_storage is for when we don't require the mst edges values just the sum of mst
    int spanningTree_without_mst_edges_storage(int V, vector<vector<int>> adj[])
    {
        //mark all the nodes as non-visited
        vector<bool> vis(V, false);
        //order of element in pq will be {weight, node}
        //set always store the elemnt in the sorted order
        set<pair<int,int>> pq;
        //---modification for storing mst as well end here
        int mst_sum = 0 ;
        //0th node with 0 weight
        pq.insert({0,0});
        while(!pq.empty()){
            auto front = *(pq.begin());
            int wt = front.first;
            int node = front.second;
            pq.erase(front);
            //if node is already visited we don't do anything
            if(vis[node]) continue;
            //mark the current node as visited
            vis[node] = true;
            mst_sum += wt ;
            //if mst_edges were required for anser we would insert the edge here
            for(auto it: adj[node]){
                int adj_node = it[0];
                int adj_wt = it[1];
                //this if condition is just put to remove the burden of storing and then popping and checking if node is already visited but 
                //without if condition also it will if we insert the element directly as well
                if(!vis[adj_node]){
                    pq.insert({adj_wt,adj_node});
                }
            }
            
        }
        return mst_sum ;
        
    }
    
    
    
    
    //modification to store mst as well in above function, above function is just to return the mst sum value
    int spanningTree_with_mst_edges_as_well(int V, vector<vector<int>> adj[])
    {
        //mark all the nodes as non-visited
        vector<bool> vis(V, false);
        //order of element in pq will be {weight, node}
        //set always store the elemnt in the sorted order
        // set<pair<int,int>> pq;
        //------------below two lines are modified code
        set<pair<int,pair<int,int>>> pq;
        vector<pair<int,int>> mst;
        //---------modified code ends here
        int mst_sum = 0 ;
        //0th node with 0 weight
        //---------insert modified to insert the parent also
        pq.insert({0,{0,-1}});
        while(!pq.empty()){
            auto front = *(pq.begin());
            int wt = front.first;
            int node = front.second.first;
            int par = front.second.second;
            pq.erase(front);
            //if node is already visited we don't do anything
            if(vis[node]) continue;
            //mark the current node as visited
            vis[node] = true;
            mst_sum += wt ;
            //----------below line added to insert the edge in the mst vector
            if(par != -1 )mst.push_back({par,node});
            //if mst_edges were required for anser we would insert the edge here
            for(auto it: adj[node]){
                int adj_node = it[0];
                int adj_wt = it[1];
                //this if condition is just put to remove the burden of storing and then popping and checking if node is already visited but 
                //without if condition also it will if we insert the element directly as well
                if(!vis[adj_node]){
                    //-------below is modified to insert parent as well
                    pq.insert({adj_wt,{adj_node,node}});
                }
            }
            
        }
        return mst_sum ;
        
    }
