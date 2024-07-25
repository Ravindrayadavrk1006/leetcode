/*
    explanation:
        we are given certain networks and which need to be connected, there are certain cycle edges which are not required for the networks to be connected,
        if the parent of a network vertexes are same , it means that edge is a cycle edge and redundant, here we will be counting all those edges, finally when we have traversed all the edges and hence connected edges which were able to be normally connected using core concept of DISJOINT SET,
        finally we will have par vector as well, the nodes in the par vector which are their own parents that no of separate networks will be there.
        to connect x separate networks we need atleast x-1 edges , if our cycle edges which we have counted are more than or equal to x-1 then we can connect all the network by atleast changing x-1 links.
        hence we return x-1, if number of cycle edges are not equal or greater than x-1 then it's not possible to connect them and hence we return -1


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
    int makeConnected(int n, vector<vector<int>>& connections) {
        vector<int> rank(n,0);
        vector<int> par(n,0);
        //initalizing all the parent by themselves
        for(int i = 0; i<n; i++)par[i]=i;
        DisjointSet ds = DisjointSet();
        //connections given are the edges given
        int cycle_edges = 0;
        for(auto it: connections){
            int u = it[0];
            int v = it[1];
            if(ds.findPar(u,par,rank) != ds.findPar(v,par,rank)){
                ds.unionByRank(u,v,par,rank);
            }
            else{
                cycle_edges++;
            }
        }
        int separate_networks = 0;
        //counting all the nodes which are their own parents that number of disjoint set will be there
        for(int i = 0; i<n; i++)if(par[i]==i)separate_networks++;
        if(cycle_edges>= separate_networks-1){
            return separate_networks-1;
        }
        else return -1;
    }
};
