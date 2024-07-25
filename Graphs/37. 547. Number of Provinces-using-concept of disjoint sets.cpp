/*
    explanation:
        normal use of disjoint set, we write normal disjoint set class and then we use it to connect the nodes of the edges , normal working , after all edges are processed , we traverse the par array, all those nodes which are parent of themseleves that no of disjoint sets will be there and hence that no of provinces
        **important this problem can be solved using normal dijkstra algorithm or bfs traversal as well
*/
class DisjointSet{
    // vector<int> rank, par;
    public:

        // DisjointSet(int n){
        //     //n+1 since 1 based indexing given
        //     rank.resize(n+1,0);
        //     par.resize(n+1);
        //     for(int i = 0 ; i<=n; i++)par[i]=i;
        // }
        int findPar(int node, vector<int>& par, vector<int>& rank){
            if (node == par[node])return node;
            //normal cases
            return par[node] = findPar(par[node],par,rank);
        }
        void unionByRank(int u, int v,vector<int>& par, vector<int>& rank){
            int ult_u = findPar(u,par,rank);
            int ult_v = findPar(v,par,rank);
            if(ult_u == ult_v )return ;
            //normal cases
            if(rank[ult_v]< rank[ult_u]){
                par[ult_v] = ult_u;
            }
            if(rank[ult_u]< rank[ult_v]){
                par[ult_u] = ult_v;
            }
            if(rank[ult_v] == rank[ult_u]){
                par[ult_v] = ult_u;
                rank[ult_u]++ ;
            }
        }
};
class Solution {
public:
    int findCircleNum(vector<vector<int>>& isConnected) {
        vector<pair<int,int>> edges;
        int n = isConnected.size();
        //we will form edges from the given adjaceny matrix
        for(int i = 0 ; i< n; i++){
            for(int j=0; j<n; j++){
                if(isConnected[i][j] == 1 && i!=j){
                    edges.push_back({i,j});
                }
            }
        }
        //just printing all the edges
        for(auto it: edges){
            cout<<it.first<<" "<<it.second<<endl;
        }
        vector<int> rank(n,0);
        vector<int> par(n,0);
        //initalizing all the parent by themselves
        for(int i = 0; i<n; i++)par[i]=i;
        DisjointSet ds = DisjointSet();
        //traversing all the edges to connect them 
        for(auto it: edges){
            int u = it.first;
            int v = it.second;
            if(ds.findPar(u,par,rank) != ds.findPar(v,par,rank)){
                ds.unionByRank(u,v,par,rank);
            }
        }
        int provinces_count = 0;
        //counting all the nodes which are their own parents that number of disjoint set will be there
        for(int i = 0; i<n; i++)if(par[i]==i)provinces_count++;
        return provinces_count;
    }
};
