/*
    explanation:
        it is same problem as rotten tomato problem , where we will insert the elements with 0 value initally in the queue . and start the bfs traversal with assuming these as the initial positions. we try to visit the neear position from the .
    so all the remaining elements will be 1 only and we can easily visualize the solution how it will work since bfs travesal ajecent elements at the same time
*/
class Solution {
private:
    vector<int> pos_vec = {0,-1,0,1,0};
    //idea push all the 0 in the queue and perform bfs for all this 
    //so it is  like the rotten tomato problem
    vector<vector<int>>dist(vector<vector<int>>& mat){
        //n row and m column
        int n = mat.size();
        int m = mat[0].size();
        //intially all are at a size of 0 
        vector<vector<int>>dist_mat(n, vector<int>(m,0));
        vector<vector<int>>visited(n, vector<int>(m,0));
        queue<pair<int,int>> q;
        for(int i = 0;i<n; i++){
            for(int j = 0;j<m; j++){
                if(mat[i][j]==0)
                    {
                        q.push({i,j});
                        visited[i][j] = 1;
                    }
            }
        }

        //we have initial queue ready
        int dist = 0;
        while(!q.empty()){
            int q_size = q.size();
            //all the elements coming will be a
            dist++;
            for(int i = 0 ; i < q_size; i++){
                int row= q.front().first;
                int col = q.front().second;
                q.pop();
                for(int el=0; el<4;el++){
                    int new_row = row + pos_vec[el];
                    int new_col = col + pos_vec[el+1];
                    //no need to check if mat[new_row][new_col] value = 1 or not since initally all the zeros would be inserted so remaining wil be 1 only 
                    if(new_row>=0 && new_col>=0 && new_row <n && new_col < m && !visited[new_row][new_col]){
                        visited[new_row][new_col] = 1;
                        dist_mat[new_row][new_col]= dist;
                        q.push({new_row,new_col});
                    }
                }
            }
        }
        return dist_mat;

    }
public:
    vector<vector<int>> updateMatrix(vector<vector<int>>& mat) {
        return dist(mat);
    }
};
