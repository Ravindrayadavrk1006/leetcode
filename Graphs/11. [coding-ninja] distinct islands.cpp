problem link ->  https://www.naukri.com/code360/problems/distinct-islands_630460?leftPanelTabValue=SUBMISSION

/*
    here it is basic dfs but a small change of finding shape 
    //we have found the shape by starting the dfs travesal from a point.we will have the entry point and from this entrypoint
    wherever we go, we save the diffence of this new point with the entrypoint. that's how we get the shape 

*/

#include <bits/stdc++.h>
using namespace std;
 vector<int> pos_arr = {0,-1,0,1,0};
    //normal dfs algorithm 
    void helper_dfs(int i,int j,vector<vector<int>>& visited,int** board,int start_i, int start_j,vector<pair<int,int>>& curr_shape,int n,int m){
        visited[i][j] =1;
        curr_shape.push_back({start_i-i,start_j-j});
        // int n = board.size();
        // int m = board[0].size();
        //checking for current element all for adjecent positions
        for(int pos = 0 ; pos<4; pos++){
            int new_i = i+pos_arr[pos];
            int new_j = j+pos_arr[pos+1];
            //new_i,new_j should be a valid positin and it should not be already visited and should be equal to O since being called when board[i][j]=1 only hence will be O only
            if(new_i < n && new_j < m && new_i >=0 && new_j >= 0 && !visited[new_i][new_j] && board[new_i][new_j] == board[i][j]) 
                helper_dfs(new_i,new_j,visited,board,start_i,start_j,curr_shape,n,m);
        }
    }
int distinct_islands_sol(int** arr,int n, int m){
    vector<vector<int>> visited(n, vector<int>(m,0));
    set<vector<pair<int,int>>> s;
    for(int i = 0; i<n; i++){
        for(int j = 0; j<m; j++){
            //not visited yet and is a land cell
            if(!visited[i][j] && arr[i][j]){
                vector<pair<int,int>> curr_shape;
                helper_dfs(i,j,visited,arr,i,j,curr_shape,n,m);
                s.insert(curr_shape);
            }
        }
    }
    return s.size();
}
int distinctIslands(int** arr, int n, int m)
{
    //Write your code here
    return distinct_islands_sol(arr,n,m);
}
