
/*  


    **IMP  -> QUESTION OF FINDING DISTANCE OF ALL NODES FROM A SOURCE IN UNDIRECTED , EITHER WEIGHTED OR UNWEIGHTED GRAPH
    since undirected graph and we have to find shortest distance from a particular node to all 
    other node, we can use bfs since the closet to the source will be done first and so on , all the neigbours will be at the same distance
    
    
    
    APPROACH -> 
    simply we are doing the bfs traversal and instead of checking if visited we are finding distance ,
    if distance is smaller than the previous value then only we are pusing the neighbour.
*/
class Solution {
    private:
        //function name short form of shortest path in undirected grah with unit weights
        vector<int> spuguw(vector<vector<int>>& edges, int N,int M, int src){
            //creating adjacency list
            vector<vector<int>> adj_list(N);
            //if this graph was weighted instead of unit weights we would store store pair, instead of nodes for each adjacnet element and would proceed same way
            for(auto it: edges){
                adj_list[it[0]].push_back(it[1]);
                adj_list[it[1]].push_back(it[0]);
            }
            
            //now we will do bfs starting from source
            //also given the graph is connected so all the nodes will be reachable if not reachable or not connected
            //then also will work fine since will be at distance inf from the source
            vector<int> dist(N,1e9);
            dist[src] = 0;
            queue<int> q;
            q.push(src);
            while(!q.empty()){
                int front = q.front();
                q.pop();
                //if this graph was weighted we would have ajd_node and weights of edge connecting to it stored as pair in the adj_lis 
                //thwn instead of comparingdist[front]+ 1 < dist[adj] by adding +1 we would add the edge weight 
                for(int adj: adj_list[front]){
                    if(dist[front]+ 1 < dist[adj]){
                        dist[adj] = dist[front]+ 1;
                        q.push(adj);
                    }
                }
            }
            for(int i = 0 ; i<N; i++){
                if(dist[i] == 1e9)dist[i]= -1;
            }
            return dist;
        }
        
  public:
    vector<int> shortestPath(vector<vector<int>>& edges, int N,int M, int src){
        return spuguw(edges,N,M,src);
    }
};


//{ Driver Code Starts.
int main() {
    int t;
    cin >> t;
    while (t--) {
        int n, m; cin >> n >> m;
        vector<vector<int>> edges;

        for (int i = 0; i < m; ++i) {
            vector<int> temp;
            for(int j=0; j<2; ++j){
                int x; cin>>x;
                temp.push_back(x);
            }
            edges.push_back(temp);
        }

        int src; cin >> src;

        Solution obj;

        vector<int> res = obj.shortestPath(edges, n, m, src);

        for (auto x : res){
            cout<<x<<" ";
        }
        cout << "\n";
    }
}

// } Driver Code Ends
