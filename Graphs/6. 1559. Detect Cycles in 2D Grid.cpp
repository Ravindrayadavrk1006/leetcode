/*
    ----- SOL 1----
    it is exactly question of-> FINDING CYCLE IN A UNDIRECTED GRAPH ,
    the small variation is that from a point we can go in up, down , left , right instead of going to the position in the adjaceny list, with the condition of if going then the element shoudl be same as the current element
    
    
    ***LEARNINGS 
    POINTS 1->
        1.carrying any local variable consumes some time , so if possible to calculate easilyt then do that, if very few test cases are giving tle that could be a reason.
        2. if very few test cases are failing then auto might be a reason , if possible then provide specific type

*/
class Solution {
private:
    //trick for forming pairs like {(0,-1),(-1,0),(0,1),(1,0)}
    vector<int> pos_dir = {0,-1,0,1,0};
    //normal dfs undirected graph cycle finding just going in four directions
    bool helper_find_cycle_using_dfs(int i, int j,int par_i,int par_j, vector<vector<char>>& grid, vector<vector<bool>>& visit, int m, int n) {
        cout<<i<<" "<<j<<endl;
        visit[i][j] = true;

        //going in the four direction from the current position
        for(int pos=0 ; pos<4; pos++){
            //we are using one single pos_dir to form up down left right positions
            int new_i = pos_dir[pos]+i;
            int new_j = pos_dir[pos+1]+j;
            if(new_i <m && new_i>=0 && new_j <n && new_j >=0 && grid[new_i][new_j]==grid[i][j] && (new_i != par_i || new_j != par_j))
                //here using the property of short circuiting that if going to already visited node then that is the answer since OR operator won't go to check the second part
                if(visit[new_i][new_j] || helper_find_cycle_using_dfs(new_i,new_j, i, j,grid,visit,m,n) )
                    return true;
        }
        return false;
    }

    bool has_cycle(vector<vector<char>>& grid) {
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visit(m, vector<bool>(n, false));
        // cout<<"m "<<m<<" n "<<n<<endl;
        // Run for each node as a starting point
        for (int i = 0; i < m; i++) {
            for (int j = 0; j < n; j++) {
                if(!visit[i][j]) {
                    // cout<<"start"<<i<<" "<<j<<endl;
                    if(helper_find_cycle_using_dfs(i,j,-1,-1, grid, visit, m, n))return true;
                    // cout<<"------"<<endl;
                }
            }
        }
        return false;
    }

public:
    bool containsCycle(vector<vector<char>>& grid) {
        return has_cycle(grid);
    }
};
