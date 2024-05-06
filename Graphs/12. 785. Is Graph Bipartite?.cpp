/*
    use of bfs-> 
        using bfs since we have to check for neighbours of a node at the same time.

        queue will store the element and it's correspoding color , so that for pushing it's child we can just do !color and store for it's child.

        if bfs for bi-partite if:
            there is cycle then only changes of non bi-partite. so if we reach a visited node and it's color is same as the current node then it is not bi-paritite.

        the graph may not be connected hence using for loop in the function isBipartite to try to call the function if any node not visited.

        every other thing is simple bfs travesal

*/
class Solution {
private:
    bool helper_bfs(int node, vector<vector<int>>& graph, vector<int>& visited){
        //graph is a adjacency list
        //we are storing the node and it's color in the queue to make it easy to mark it's child color 
        //q stores the node and it's color so that we can store it's child as other color 
        queue<pair<int,int>> q;
        //let's suppose 1 is yellow and 0 is green and -1 means not visited
        //so we are using visited array for marking which color is this current node when visited
        visited[node] = 1;
        q.push({node,1});
        while(!q.empty()){
            int vertex = q.front().first;
            int color = q.front().second;
            q.pop();
            //checking all it's adjacent
            for(int adjacent: graph[vertex]){
                //-1 means not visited yet 
                if(visited[adjacent] == -1){
                    //mark it visited and mark and store with a revese color
                    visited[adjacent] = !color;
                    q.push({adjacent,!color});
                }   
                //the node would be visited
                //if the ajcent color is same as parent return false
                else if(visited[adjacent]==color)return false;
            }
        }
        return true;
    }
public:
    bool isBipartite(vector<vector<int>>& graph) {

        int n = graph.size();
        //graph a visited array of size n and initialize with -1 
        // -1 means the node is not yet visited
        vector<int> visited(n,-1) ;
        //this for loop since the graph can be non-connected too
        for(int i = 0; i<n ; i++){
            if(visited[i] == -1){
                if(!helper_bfs(i,graph,visited))return false;
            }
        }
        return true;
    }
};
