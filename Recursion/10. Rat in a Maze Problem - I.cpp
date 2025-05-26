/*    PROBLEM LINK -> https://www.geeksforgeeks.org/problems/rat-in-a-maze-problem/1
        approach ->
            here we are trying to go in the four direction from current position,
            **IMP -> it is saying that the answer need to be in lexographical order i.e 
            DLRU  hence we are tyring in the same order first trying to go in down, then left, then right then up
            
        we are standing at current position i, j
        and then we are checking if we can go in down, left,right or up direction
        for each of this direction, if possible to go(i.e the position is valid and the node is not visited(since in A path can visit a node only once)
        ), and the node value is 1 , if so 
        [**IMP] -> we are making the current node to be visited and going to visit the other node , while coming back we are making it false, so
        that this node can be used in other paths


*/


class Solution {
  private:
    void sol_rat_in_maze(int i, int j, string current_path, vector<vector<bool>>& visited, vector<string>& ans, int n, vector<vector<int>>& maze ){
        if(i == n-1 && j == n-1){
            ans.push_back(current_path);
            return;
        }
        
        //since asked in lexographical order hence trying DLRU
        //DOWN
        if(i+1<n && !visited[i+1][j] && maze[i+1][j] == 1){
            //mark current cell visited and then move to the next one   
            visited[i][j] = true;
            sol_rat_in_maze(i+1, j, current_path+'D', visited, ans, n, maze);
            //unmark it as visited so that this cell can be tried in other path but not in current path
            visited[i][j] = false;
            
        }
        //LEFT 
        if(j-1>=0  && !visited[i][j-1] && maze[i][j-1] == 1){
            //mark it visited
            visited[i][j] = true;
            sol_rat_in_maze(i, j-1 , current_path+'L', visited, ans, n, maze);
            //unmark it as visited so that this cell can be tried in other path but not in current path
            visited[i][j] = false;
        }
        //RIGHT
        if(j+1<n && !visited[i][j+1] && maze[i][j+1] == 1){
            //mark it visited
            visited[i][j] = true;
            sol_rat_in_maze(i, j+1, current_path+'R', visited, ans, n, maze);
            //unmark it as visited so that this cell can be tried in other path but not in current path
            visited[i][j] = false;
            
        }
        
        //UP
        if(i-1 >= 0 && !visited[i-1][j] && maze[i-1][j] == 1){
            //mark it visited
            visited[i][j] = true;
            sol_rat_in_maze(i-1, j, current_path + 'U', visited, ans, n, maze);
            //unmark it as visited so that this cell can be tried in other path but not in current path
            visited[i][j] = false;
        }
    }
  public:
    vector<string> ratInMaze(vector<vector<int>>& maze) {
        vector<string> ans;
        int n = maze.size();
        if(maze[0][0] == 0)return ans;
        vector<vector<bool>> visited(n, vector<bool>(n, false)); 
        sol_rat_in_maze(0,0, "", visited, ans, n, maze);
        return ans;
        
    }
};
