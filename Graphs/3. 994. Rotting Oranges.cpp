/*
    explanation:   
        since infection happen with the neighbour , so will do bfs travesal and it is happening in four direction up , down , left, right
        also infection start from all the infected node so intially in the bfs traversal queue we will push all the infected node so the infection start from that point
        we are updating time counter value at the end of checking if any neigbour pushed, the reason for this is that codition of when only infected node remains infected we return 0 and and since it is saying , it takes 1 unit time to infect the neighbour agr neighour hi nhi hai to zero time lga infect hone m.
        when we are pushing into the queue , at the same time we are making visit[i][j] =1 so that other do not push it again
*/
class Solution {
private:
    int counter = 0;
    void helper_bfs_traversal(vector<vector<int>>& visit,vector<vector<int>>& grid,int m , int n,queue<pair<int,int>>& q ){
        while(!q.empty()){
            int q_size = q.size();
            cout<<"q_size"<<q_size<<endl;
            // counter++;
            for(int run= 0; run<q_size; run++){
                int i = q.front().first;
                int j = q.front().second;
                // visit[i][j]= 1;
                q.pop();
                if(j+1 < n && visit[i][j+1] == 0 && grid[i][j+1] ==1 ){
                    q.push({i,j+1});
                    visit[i][j+1] = 1;
                }
                if(i+1 < m && visit[i+1][j] == 0 && grid[i+1][j]==1){
                    q.push({i+1,j});
                    visit[i+1][j] =1;
                }
                if(j-1 >= 0 && visit[i][j-1] == 0 && grid[i][j-1]==1){
                    q.push({i,j-1});
                    visit[i][j-1] =1;
                }
                if(i-1 >= 0 && visit[i-1][j] == 0 && grid[i-1][j]==1){
                    q.push({i-1,j});
                    visit[i-1][j] =1 ;
                }
            
            }
            //if new elements are infected then o
            if(q.size())counter++;
            
        }
    }
    int sol_bfs(vector<vector<int>>& grid){
        int m = grid.size();//row
        int n = grid[0].size(); //col
        cout<<"size m"<<m<<"n "<<n<<endl;
        vector<vector<int>> visit(m,vector<int>(n,0));
        bool break_satisfied = false;
        queue<pair<int,int>> q;
        for(int i = 0; i< m; i++){
            for(int j = 0; j<n ; j++){
                if(grid[i][j] == 2){
                    cout<<"calling function  i"<<i<<"j "<<j<<endl;
                    q.push({i,j});
                    visit[i][j] = 1;
                }
            }
        }
        helper_bfs_traversal(visit, grid,m,n,q);
        for(int i = 0; i< m; i++){
            for(int j = 0; j<n ; j++){
                //if some is fresh is not visited it means entire is not wasted
                if(visit[i][j] == 0 && grid[i][j] == 1)return -1;
            }
        }
        return counter;
    }
public:
    int orangesRotting(vector<vector<int>>& grid) {
        return sol_bfs(grid);
    }
};
