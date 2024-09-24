//https://www.naukri.com/code360/problems/dijkstra-s-shortest-path_920469?leftPanelTabValue=SUBMISSION
#include <bits/stdc++.h> 
/*
    it is normal bfs travesal with one point in head that using min-heap or priority queue instead of normal queue.
    the min-heap is used to store smallest distance node at the top.
    apart from this everything is exactly the bfs travesal

*/
//*********SOL 1 -- >USING PRIORITY QUEUE
vector<int> sol_dijkstra_algo_using_priority(vector<vector<int>> &vec, int vertices, int edges, int source){
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
//------------------------------------------------ SOL 2--------------

vector<int> sol_dijkstra_algo_using_set(vector<vector<int>> &vec, int vertices, int edges, int source){
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
   set<pair<int,int>> st;
    vector<int> dist(vertices,INT_MAX);
    //since given that starting point will always be zero so let's mark to reach from 0 to 0 we need 0 distance
    dist[source] = 0;
    st.insert({0,source});
    while(!st.empty()){
        //** important how we are getting smallest value from the set
        auto front = *(st.begin());
        int node = front.second;
        int distance = front.first;
        //erase the elemnt from the set
        st.erase(front);
        //important point to note in adj_list pairs elmnt order {node,distance}
        for(auto it: adj_list[node]){
            //dist to this adj_node from the current parent i.e variable node
            int dist_to_node =  dist[node]+it.second;
            if(dist_to_node < dist[it.first]){
                //**SLIGHT BETTER IMPROVEMENT ALSO NOT REQUIRED IF FEELING TO HARD
                //we are trying to remove the previous reachable to current node , if it already been visited it means it means
                //it would have taken more distance than current
                //it would be of no use to try to reach to other node from this it node  which is reachable by smaller distance , so let's delete it's previous occurance if present in the set
                //deleting will avoid us trying few iterations 
                // if(dist[it.second] != INT_MAX){  //this alone will say that yes this node has already been visited  by someone else
                //     st.erase({dist[it.first],it.second});
                // }
                dist[it.first] =dist_to_node;
                st.insert({dist_to_node,it.first});
            }
        }
    }
    return dist;
}

//================ SOLUTION 3 NORMAL BFS TRAVERSAL WITHOUT EVEN A SINGLE LINE EXTRA

vector<int> dfs_normal(vector<vector<int>> &vec, int vertices, int edges, int source){
    vector<vector<pair<int,int>>> adj_list(vertices);
    for(auto it: vec){
        adj_list[it[0]].push_back({it[1],it[2]});
        adj_list[it[1]].push_back({it[0],it[2]});
    }
    //we have the adjaceny list
    queue<pair<int,int>> q;
    vector<int> dist(vertices,INT_MAX);
    q.push({0,source});
    dist[source] = 0;
    while(!q.empty()){
        auto front = q.front();
        int node = front.second;
        int distance = front.first;
        q.pop();
        for(auto it: adj_list[node]){
            int neighbour_dist = distance + it.second;
            if(neighbour_dist< dist[it.first]){
                dist[it.first] = neighbour_dist;
                q.push({neighbour_dist, it.first});
            }
        }
    }
    return dist;
}

vector<int> dijkstra(vector<vector<int>> &vec, int vertices, int edges, int source) {
   //calling sol 1
   //return sol_dijkstra_algo_using_priority(vec,vertices, edges,source);

   //calling sol 2
  // return sol_dijkstra_algo_using_set(vec,vertices, edges,source);


    //CALLING  solution 3
    return dfs_normal(vec, vertices, edges, source);
}
