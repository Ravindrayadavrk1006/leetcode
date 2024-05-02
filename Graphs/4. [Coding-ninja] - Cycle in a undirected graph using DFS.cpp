https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTabValue=SUBMI
concept of --> cycle in a undirected graph using dfs travesal
/*
    **important point--> cycle means start from a position and end on same position or start at some position and end on some already visited position like half roled wool.
*/
#include<bits/stdc++.h>
using namespace std;
/*
   ----------------- SOL 1 USING DFS---------------
    simple approach for detecting cycle in graph:
    cycle_using_dfs is the main function which uses dfs travesal for finding a cycle. here cycle is assumed if the node get connected to any node apart from it's parent. apart from it's parent because it is told that parallel is not allowed or given
    //cycle is present if while travesing some visited node comes and it is not immediate parent for above condition then we consider it a cycle

    //if a node is not visited yet it means it's a new node , so we will keep traversing using dfs. at any point if we find cycle we return it


    ** since the graph may not be connected so if a node is not visited yet after starting dfs traversal  from node 1, we check if a node is visited we again travese making it a starting point

    other points--> we draw adjacency list from given edges also since the nodes are starting from one hence visit of size n+1

*/
//Using DFS traversal
/*
string cycle_using_dfs(int node, int node_par,vector<int>& visit,vector<vector<int>>& adj_list){
    visit[node]  = 1;
    for(auto el: adj_list[node]){
        //if the node we are trying to visit is already visited and it is not the immediate parent since given no parrell eges
        if(visit[el] == 1 && el != node_par)return "Yes";
        //if it is not visited yet then visit that node
        else if (visit[el] == 0 && cycle_using_dfs(el,  node,visit,adj_list)=="Yes")return "Yes";
    }
    return "No";
}
*/
//using BFS travesal
/*
explanation--->
here it is simle bfs travesal with extra need of remembering the parent value for the current node ,
if while visiting the  adjecent nodes of a node , we find that the node is visited but the adjacent node is not the parent of current node it means it's a cycle 

in solution  --> cycle_using_bfs we are using a array  to remember the parent
in solution --> cycle_using_bfs_2 which is optimal solution , we are placing the parent along with node as a pair in the queue
*/
bool cycle_using_bfs(int node, vector<int>& visit,vector<vector<int>>& adj_list,int n, vector<int>& parent ){
   //intialized that now no nodes parent are known
    queue<int> q;
    q.push(node);
    visit[node] = 1;
    while(!q.empty()){
        int top = q.front();
        q.pop();
        // int neighbours_count = adj_list[node].size();
        for(int i: adj_list[top]){
            if(!visit[i]){
                visit[i] = 1;
                parent[i] = top;
                q.push(i);
            }
            //if visited and current node is not parent of current node, it means found a cycle
            else if( i != parent[top])
                return true; 
        }
    }
    return false;
}

//***USE THIS FOR BFS TRAVERSAL

bool cycle_using_bfs_2(int node, vector<int>& visit,vector<vector<int>>& adj_list,int n ){
   //intialized that now no nodes parent are known
    queue<pair<int,int>> q;
    q.push({node,-1});
    visit[node] = 1;
    while(!q.empty()){
        int curr_node = q.front().first;
        int curr_par = q.front().second;
        q.pop();
        // int neighbours_count = adj_list[node].size();
        for(int i: adj_list[curr_node]){
            if(!visit[i]){
                visit[i] = 1;
                q.push({i,curr_node});
            }
            //coming here means if failed which means node is visited
            //if visited and current node is not parent of current node, it means found a cycle
            else if( i != curr_par )
                return true; 
        }
    }
    return false;
}


string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //n ->nodes and m edges
    vector<int> visit(n+1,0);
    vector<vector<int>> adj_list(n+1);   //creating adjaceny list from edges
    for(auto it: edges){
        adj_list[it[0]].push_back(it[1]);   //since undirected so both way pushing
        adj_list[it[1]].push_back(it[0]); //since undirected so both way pushing
    }
    //************SOL 1 ---->calling for DFS travesal ************
    /*
    //if the graph was connected then single call would have served the purpose since all the nodes would have been connected
    //return cycle_using_dfs(1,-1,visit, adj_list);
    //since the graph may be disconnected so in go all the node would not be visited
    // i from 1 since node start from 1
    for(int i = 1; i <=n; i++){
        if(!visit[i]){
            if(cycle_using_dfs(i,-1,visit, adj_list) == "Yes")return "Yes";
        }
    }
    return "No";
    */


    //************SOL 2 ---->calling for BFS travesal ************
    //if the graph was connected then single call of cycle_using_bfs would have served the purpose since all the nodes would have been connected and will be viisted in one travesal
    //return cycle_using_bfs(1,-1,visit, adj_list);
    //since the graph may be disconnected so in go all the node would not be visited
    // i from 1 since node start from 1
    vector<int> parent(n+1,-1);
    for(int i = 1; i <=n; i++){
        if(!visit[i])

            /* bfs using a parent array*/
            // if(cycle_using_bfs(i,visit, adj_list,n,parent))return "Yes";

            //bfs without using parent array
            if(cycle_using_bfs_2(i,visit, adj_list,n))return "Yes";

    }
    return "No";
}
