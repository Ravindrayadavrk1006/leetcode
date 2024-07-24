//This is used in finding mst using kruskals algorithm
//main disjoinset class which uses finding union by rank and finding par explained in the C.P notes -> Disjoint set
class DisjointSet{
    vector<int> rank, par;
    public:
        DisjointSet(int n){
            //making the rank vector of size n and setting initial values as 0
            rank.resize(n+1,0);
            par.resize(n+1);
            for(int i = 0 ; i<=n ; i++)par[i] = i;
            
        }
        int findPar(int node){
            if(node == par[node])return node;
            return par[node] = findPar(par[node]);
        }
        void unionByRank(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            //if the ultimate parent of both nodes is same then we don't need to join or anything simply return 
            if(ult_u == ult_v)return ;
            if(rank[ult_u] < rank[ult_v]){
                par[ult_u] = ult_v;
            }
            if(rank[ult_v] < rank[ult_u]){
                par[ult_v] = ult_u;
            }
            if(rank[ult_u] == rank[ult_v]){
                par[ult_u] = ult_v;
                rank[ult_v]++;
            }
        }
};  //this ; is must needed because it expects a object to be created if not ; 
class Solution
{
	public:
     /*
        solution 2:
        MST USING KRUSKALS ALGORITHM
    */
    int spanningTree(int V, vector<vector<int>> adj[]){
        vector<pair<int, pair<int,int>>> edges;
        //since here adjaceny list is given hence, we need just the edges hence let's form edges
        //here edges will be u to v and v to u as well but it won't affect the result 
        for(int i =0; i< V;i++){
           for(auto it: adj[i]){
               int v = it[0];
               int wt = it[1];
               int u = i ;
               edges.push_back({wt,{u,v}});
           }
        }
        
        DisjointSet ds = DisjointSet(V);
        //sort the edges in ascending order 
        sort(edges.begin(),edges.end());
        int mst_sum  = 0 ;
        
        for(auto it: edges){
            int wt = it.first;
            int u = it.second.first; 
            int v = it.second.second;
            if(ds.findPar(u) != ds.findPar(v)){
                mst_sum+= wt;
                ds.unionByRank(u,v);
            }
            
        }
        return mst_sum;
    }
    
};
