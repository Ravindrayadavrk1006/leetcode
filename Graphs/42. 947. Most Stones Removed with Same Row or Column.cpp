
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
class Solution {
public:
    //NOTE: THIS IS NOT CORRECT SOLUTION , SINCE WE DON'T KNOW EXACTLY THE NUMBER OF NODES IN THIS QUESTION IN DISJOINT SET
    /*
        from each connected component we can remove all nodes except one since last node will node 
    */
    /*
    int removeStones(vector<vector<int>>& stones) {
        int n = stones.size();
        int max_row = 0; 
        int max_col = 0; 
        for(auto it: stones){
            max_row = max(max_row, it[0]); 
            max_col = max(max_col, it[1]);
        }
        DisjointSet ds(9999*9999);
        for(int i = 0 ; i<n-1 ; i++){
            auto el = stones[i];
            int row = el[0];
            int col = el[1];
            for(int j = i+1; j<n; j++){
                auto adj_el = stones[j];
                int adj_row = adj_el[0];
                int adj_col = adj_el[1];
                if(row == adj_row || col ==  adj_col){
                    int node = row*9999 + col;
                    int adj_node = adj_row*1e3 + adj_col;
                    if(ds.findPar(node) != ds.findPar(adj_node)){
                        ds.unionByRank(node,adj_node);
                    }
                }
            }
        }
        //count the number of nodes which has same as ultimate parent
        int ultimate_par_nodes=0;
        for(auto it: stones){
            int row = it[0];
            int col = it[1];
            int node = row*9999 + col;
            //if parent of node is same as parent
            if(ds.findPar(node) == node)ultimate_par_nodes++ ;
        }
        return  n- ultimate_par_nodes;
    }
    */




    /*
    
        SOLUTION 2
        correct and better approach;
        important concept :
            1.when n for disjointset(n) not given see the approach how we have used col numbering how done, since here we have to connect row and column to find which are connected , we will number the column as maxRowNumber+1+col and rowNumber will be row .
            2. since the same node can appear again and again in the stones given and hence to count the number of connected component we have used map to mark the nodes just once and hence we start to find if a node is connected to itself which means that number of connected component , it become helpfull because the node are not appearing more than once and hence correct calculation

    
    */
    int removeStones(vector<vector<int>>& stones) {
        int maxRow = 0;
        int maxCol = 0;
        for(auto it: stones){
            maxRow = max(maxRow , it[0]);
            maxCol = max(maxCol, it[1]);
        }
        //here we will try to connect rows and columns which have element and are matching
        //indexes are such that row number is node , column+ maxRow + 1 is the node number of column 
        DisjointSet ds(maxRow + maxCol  + 1);
        //let's join the row number
        //since some nodes can not be present in the range of maxRow + maxCol +1 and hence le'ts mark them 
        unordered_map<int,int> mp;
        for(auto it: stones){
            int rowNode = it[0];
            int colNode = it[1] + maxRow + 1;
            //if not joined i.e ds.findPar condition can be put but not or not put not necessary
            //here we are connecting the row and column
            if(ds.findPar(rowNode)!= ds.findPar(colNode)){
                ds.unionBySize(rowNode, colNode);
            }
            

            //this will store the values once and not more than once if same occur which will occur many times if we traverse the stones array eg. (1,2) and (1,5) will occur many times in stones if we try to use it for finding no of disjoint set
            mp[rowNode] = 1;
            mp[colNode] = 1;
        }
        //count will store no of connected components
        int cnt = 0;
        /*
        for(auto it: stones){
            int rowNode = it[0];
            int colNode = it[1]+maxRow + 1;
            //since same rowNode can occur in many stones element given hence this will give wrong solution
            if(ds.findPar(rowNode) == rowNode)cnt++;
            //since same colNode can occur in many stones element given hence this will give wrong solution
            if(ds.findPar(colNode) == colNode)cnt++;
        }
        */
        //since above approach is wrong hence using the map where we made 1 for each node once let's use that
        for(auto it: mp){
            if(ds.findPar(it.first) == it.first)cnt++;
        }
        //total nodes - no of connected component 
        return stones.size() - cnt;
    }
};
