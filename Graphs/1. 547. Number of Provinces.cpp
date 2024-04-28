/*

    bfs and dfs travesal code are in C.P notebook
    QUESTION -> SEARCH NO OF CONNECTED COMPONENT names as Number of Provinces
    idea and approach: 
        for doing dfs travesal we keep a visited array and if the graph is fully connected in one travesal all the nodes are visited and entire visited array becomes 1 , but for connected component it might happen that entire graph doesn't get visited in one travesal , so we start from node 0 as the starting point and travese the graph normal way . if some other nodes remains unvisited in the graph , we make it the starting point and traverse the graph once again . since the first traversal will make certain elements in the viisted array 1 and they will remain 1 in the next traversal as 1 so it works simple and great.

        here instead of adj list adj matrix is given hence so a small change will there which is done in helper_dfs_graph , since adj[node] will give to a array whose indexes will be node  and value will be if connected to that index or not so we we will check if adj[node][i] is 1 it means it's connected and then normal checks .

*/
class Solution {
private:
    /**/
    void helper_dfs_graph(int node,vector<vector<int>>& adj,vector<int>& vis,int n){
        vis[node] =1;

        //since the given adj is a matrix so index represent the node and value represent if there is a edge or not
        //so
        for(int i = 0 ;i<n; i++){
            if(adj[node][i] && !vis[i]){
                helper_dfs_graph(i,adj,vis,n);
            }
        }
    }
    int no_province(vector<vector<int>>& adj, int n){
        int np = 0;  //no of province
        cout<<"n"<<n<<endl;
        vector<int> vis(n,0);
        int i = 0;   //root node or starting node

        //for each node we run travresal considering it as entry point and if the node is already visited we won't do travesal for this . no of travesal are the number of connected compoenent
        for(int i = 0; i<n ; i++){
            if(!vis[i]){
                np++;
                helper_dfs_graph(i,adj,vis,n);
            }
        }
        return np;
    }
    
public:

    int findCircleNum(vector<vector<int>>& isConnected) {
        int n = isConnected.size();
        return no_province(isConnected,n);
    }
};
