#include<bits/stdc++.h>
using namespace std;
/*
    QUESTION LINK :- https://www.naukri.com/code360/problems/shortest-path-in-dag_8381897?leftPanelTabValue=PROBLEM
    important point -> the grah is acyclic and directed i.e DAG
    here we are given the starting point i.e 0 node.

    we have to find shortest distance to all node from 0 .
    so if we have topological sort which starts from 0 , i.e 0 is the lasted node to be visited , in answer stack of topological sort using dfs
    we will have 0 at the topmost of the stack and all other elements which can be visited from 0 will be below in the stack than 0.
    visualize the topological sort.


    now we will have stack elements from topological sort stating which should be done first and at topmost will be 0 node.
    also elements which cannot be visited from there will can be in stack above 0 but since they cannot be visited, so they will have distance of 1e9 and will remain so visulaize it.

    so 0 will be popped now and it's neighbour will be processed , if the distance of 0 node + neighbour edge < value of dist[neighbour] then we update with the lower value else not
    first 0 and it's neighbour will be processed and then 0's neighbour's neighbour will be processed because that will be the order in the stack.



*/
void dfs_topological(int node,vector<bool>&  visited,  vector<vector<pair<int,int>>>& adj_list,stack<int>& st){
    visited[node] = true;
    for(auto adj: adj_list[node]){
        if(!visited[adj.first]){
            dfs_topological(adj.first, visited, adj_list, st);
        }
    }
    st.push(node);
}
    //ans shortest path in a directed acyclic graph
vector<int> ans_spdag(int n, int m, vector<vector<int>> &edges){
    //index is the node ,0th value store connecting node , 1th value store the weight
    vector<vector<pair<int,int>>> adj_list(n);

    //we have the adjaceny list
    for(auto it: edges){
        adj_list[it[0]].push_back({it[1],it[2]});
    }   
    //preparing the topological sort
    //so we will start topological sorting from 0th node since given that it is the starting point
    //this will work since all the nodes reachable from 0 will be below in the stack
    stack<int> st;
    vector<bool> visited(n,false);
    //topological sorting
    for(int i = 0 ; i<n; i++){
        if(!visited[i])dfs_topological(i, visited,adj_list, st);
    }
    //now we will have all the elements in the stack with the starting element at top
    //here we will have toplogical stack, denoting which which element should be done before which
    
    //now finding distance
    vector<int> dist(n, 1e9);
    // 0 node being starting point and to visit this point 0 distance coverered
    dist[0] = 0;
    while(!st.empty()){
        int node = st.top();
        st.pop();
        for(auto it: adj_list[node]){
            int v = it.first;
            int wt = it.second;
            if(dist[node] + wt < dist[v])dist[v] = dist[node] + wt;
        }
    }

    //since here it is saying which are not reachable make them -1 we have started with 1e9 for non reachable because it also helped in comparision , so after doing all that
    //the nodes whose value remain 1e9 will be set to -1
    for(int i = 0 ; i<n; i++){
        if(dist[i] == 1e9)dist[i]= -1;
    }
    return dist;
}
vector<int> shortestPathInDAG(int n, int m, vector<vector<int>> &edges)
{
    return ans_spdag(n,m,edges);
}
