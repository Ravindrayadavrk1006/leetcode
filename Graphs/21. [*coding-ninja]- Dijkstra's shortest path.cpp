#include <bits/stdc++.h> 
/*
    it is normal bfs travesal with one point in head that using min-heap or priority queue instead of normal queue.
    the min-heap is used to store smallest distance node at the top.
    apart from this everything is exactly the bfs travesal

*/
vector<int> sol_dijkstra_algo(vector<vector<int>> &vec, int vertices, int edges, int source){
    //creating adj_list from given vertices
    vector<vector<pair<int,int>>> adj_list(vertices);
    for(auto it: vec){
        adj_list[it[0]].push_back({it[1],it[2]});
        adj_list[it[1]].push_back({it[0],it[2]});
    }
    // creating priority queue or min-heap in c++
    // telling the value is pair<int,int>, second is saying about all the
    // values, and third is compareter function
    // the value will be stored in form { 4,1} i.e 4 is the min dist found till now to reach 1 from starting point i.e 0
    //the storing order is {dist,node} so that min-heap is formed on basis of dist first i.e min distance at top, if min distance is same then it will try sorting on basis of node , which is not required also but distance sorting is required and important
    priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
    vector<int> dist(vertices,INT_MAX);
    //since given that starting point will always be zero so let's mark to reach from 0 to 0 we need 0 distance
    dist[source] = 0;
    pq.push({0,source});
    while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        //important point to note in adj_list pairs {node,distance}
        for(auto it: adj_list[node]){
            //dist to this adj_node from the current parent i.e variable node
            int dist_to_node =  dist[node]+it.second;
            if(dist_to_node < dist[it.first]){
                dist[it.first] =dist_to_node;
                pq.push({dist_to_node,it.first});
            }
        }
    }
    return dist;
}
vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   return sol_dijkstra_algo(vec,vertices, edges,source);

}
