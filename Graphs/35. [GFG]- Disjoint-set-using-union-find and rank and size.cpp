/*

QUESTION LINK -> https://www.geeksforgeeks.org/problems/union-find/1    
solution class is the solution , DisjointSet is the class of disjoint set it is not part of solution but this is usefull in all the solution and use this only.
if we want we could write the solution using DisjointSet also in this solution
    this is for finding if the nodes are in same group or not , we use the concept of disjoint sets using union by rank to do it
    in depth explanation of the algorithm is in CP notes 
*/

//important core class to implement the disjoint set union by rank and size
class DisjointSet{
    public:
        // we will neeed them outside where this class object is created and hence kept public
        vector<int> rank, par, size;
        DisjointSet(int n){
            //n+1 since 1 based indexing given
            rank.resize(n+1,0);
            //size is usefulll for unionby size
            size.resize(n+1);
            par.resize(n+1);
            for(int i = 0 ; i<=n; i++){
                par[i]=i;
                size[i] =1;
            }

        }
        int findPar(int node){
            if (node == par[node])return node;
            //normal cases
            return par[node] = findPar(par[node]);
        }
        void unionByRank(int u, int v){
            int ult_u = findPar(u);
            int ult_v = findPar(v);
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
     //since rank get distorted and become useless for us instead of just showing which is greater cluster
    //we are using size to keep a track of size or number of nodes in each cluster this will be very usefull later on
        void unionBySize(int u, int v ){
            int ult_u = findPar(u);
            int ult_v = findPar(v);
            if(ult_u == ult_v )return ;
            if(size[ult_u] < size[ult_v]){
                par[ult_u] = ult_v;
                size[ult_v ] += size[ult_u] ;

            }
            //this will hand both the if else and else since in both cases same will be happeing
            else{
                par[ult_v] =ult_u;
                size[ult_u] += size[ult_v];
            }
        }
};




//below is the solution
class Solution
{
    private:
    //this is the main function which does path_compression and finding the parent
        int findPar(int node, int par[]){
            //base case if current node is itself it's own parent
            if(node == par[node])return node;
            //we are storing the ultimate parent in all the node which are connected to parent once we have utlimate parent for one node
            //here path compression is being done
            return par[node] = findPar(par[node],par);
        }
    public:
    
    //Function to merge two nodes a and b.
    void union_( int a, int b, int par[], int rank1[]) 
    {
        //we find the ultimate parent since we will need to join nodes to the ultimate parent of current nodes
        int ult_u = findPar(a,par);
        int ult_v = findPar(b,par);
        //it means the node are already connected we don't need to connect
        if(ult_u == ult_v )return ;
        
        //here code comes it means nodes are not connect so let's connect them 
        if(rank1[ult_v]< rank1[ult_u]){
            par[ult_v] = ult_u;
        }
        if(rank1[ult_u]< rank1[ult_v]){
            par[ult_u] = ult_v;
        }
        //if both have equal ranks then we can do either attach ult_v to ult_u or reverse of it
        if(rank1[ult_u] == rank1[ult_v]){
            par[ult_v] = ult_u;
            rank1[ult_u]++;
        }
    }
    
    //Function to check whether 2 nodes are connected or not.
    bool isConnected(int x,int y, int par[], int rank1[])
    {
        //finding the ultimate parent of x and ultimate parent of y if both are same then they are connected else not 
        int ult_u = findPar(x,par);
        int ult_v = findPar(y,par);
        //it means they are connected 
        if(ult_u == ult_v )return true;
        //not connected
        else return false;
    }
};

