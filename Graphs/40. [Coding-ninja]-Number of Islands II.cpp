/*
  question link -> https://www.naukri.com/code360/problems/number-of-islands-ii_1266048?count=25&search=&sort_entity=order&sort_order=ASC&leftPanelTabValue=PROBLEM
    the problem is simple just complex wording are given,
    we just have to use disjoint set algorithm
    here we are keeping a visited array to keep a info if the position is visited or not
    for using disjoint set for simple node numbering we are doing the node no starts from 0 and keep going till n*m-1
    a node position (a,b) it's node number is given by a*m + b


    we initially keep all the nodes as not visited

    we start processing all the queries given in q vector where each element is a land to be marked.
    if the node is already visited then the island number won't change and we insert the same island nubmer and move for processing next query

    //in normal cases 
    we mark the vis[row][col] as visited and increase the count of island , which is correct as of now do not increase why we are incrasing before checking 
    since it is well handled when we are decrasing , we are saying by default it will contribute in island count,
    and when it get joined to other island it will decrease correctly.

    we are saying later if this and neighbour node have different ultimate parent it means both are not connected 
    and hence we can connect them and this connection will decreasae the number of islands and we then perform UnionbyRank to join the two nodes,
    we try this on all the four side of node because different islands it can connect on all four side


*/

#include <bits/stdc++.h>
using namespace std;

class DisjointSet{
    vector<int> rank, par;
    public:

        DisjointSet(int n){
            //n+1 since 1 based indexing given
            rank.resize(n+1,0);
            par.resize(n+1);
            for(int i = 0 ; i<=n; i++)par[i]=i;
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
};
bool isValid(int adjr,int adjc,int n,int m ){
    return adjr>=0 && adjr<n && adjc >=0 && adjc< m;
}
vector<int> numOfIslandsII(int n, int m, vector<vector<int>> &q){
	DisjointSet ds(n*m);
    int vis[n][m];
    memset(vis, 0 , sizeof vis);
    int islands_count = 0;
    vector<int> ans ;
    for(auto it: q){
        int row = it[0];
        int col = it[1];
        //if the current position is already visited then no need to visit it again and the processing
        if(vis[row][col]==1){
            //insert the current count int the answer array
            ans.push_back(islands_count);
            continue;
        }
        //normal cases
        //make the current element visited
        vis[row][col] =1 ;
        //this is done for correct calculation here we are assuming that it is contributing in increase in the island and then we are decreseing later in the smaller below for loop
        islands_count++;
        //trying to check if the current node can be connected to any of neigbours
        //below two lines for constructing neighbour nodes easily
        int dr[] = {-1,0,1,0};
        int dc[] = {0,1,0,-1};
        for(int i = 0; i<4; i++){
            int adjr = row + dr[i];
            int adjc = col + dc[i];
            //isValid function tells if the neighbour position is a valid or going out of the array
            if(isValid(adjr, adjc,n,m )){
                //if neigbhour is land
                if(vis[adjr][adjc] ==1){
                    int nodeNo = row*m  + col;
                    int adjNodeNo = adjr * m + adjc;
                    //here we are checking if both have different neighbours it means both are not connected yet and hence we will connect and decreasae the number of island , if both are connected already we 
                    //if both have same parent then it means the node is already processed through this path before and hence do not have to do anything 
                    if(ds.findPar(nodeNo) != ds.findPar(adjNodeNo)){
                        //if both have different parent then it will reduce the island count since will get connected
                        islands_count--;
                        ds.unionByRank(nodeNo, adjNodeNo);
                    } 
                }
            }
        }
        ans.push_back(islands_count);
    }
    return ans;
}
