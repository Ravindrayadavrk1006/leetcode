/*
QUESTION LINK -> https://www.geeksforgeeks.org/problems/union-find/1    
    this is for finding if the nodes are in same group or not , we use the concept of disjoint sets using union by rank to do it
    in depth explanation of the algorithm is in CP notes 
*/
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
