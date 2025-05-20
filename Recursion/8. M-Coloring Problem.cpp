
//PROBLEM LINK: https://www.geeksforgeeks.org/problems/m-coloring-problem-1587115620/1
/*
    APPROACH ->
        here we are trying to color all the node , FYI: not using DFS or BFS just directly using recursion
        which check for node 0 - to V-1 , if our recursion reached node V it means we have colored all the nodes
        and we can return true;
        
        for each node we are trying to color it, if we are able to color we go and try for node -> node+1
        if we are not able to color this node with ANY color we return false,
        once we got false we will set the current color to be a default value which represent non-colored and try coloring with other color.
        i.e the backtracking part
        
        
        we have created adjaceny matrix to check for it's neighbour color,
        we have created a vector called color_list which stores the color of each node

*/
class Solution {
  private:
    bool valid_color(int node, int col, vector<int>& color_vec, vector<vector<int>>& adj_list){
        //here we are checking if any of node neighbour has same color as the col which si the color we are trying to color node
        for(auto adj: adj_list[node]){
            if(color_vec[adj] == col)return false;
        }
        return true;
    }
    bool try_coloring(int node, vector<int>& color_vec, vector<vector<int>>& adj_list, int v, int m){
        if(node >= v)return true;
        
        //try coloring the current node
        for(int col=0; col<m; col++){
            if(valid_color(node, col, color_vec, adj_list)){
                color_vec[node] = col;
                if(try_coloring(node+1, color_vec, adj_list, v, m))return true;
                color_vec[node] = m;
            }
        }
        
        //if we tried all the color and the the code would reach here hence we would say can't be colored
        return false;
    }
  public:
    bool graphColoring(int v, vector<vector<int>> &edges, int m) {
        // prepare adjaceny list
        
        vector<vector<int>> adj_list(v);
        for(auto edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
            adj_list[edge[1]].push_back(edge[0]);
        }
        
        //itially make them non-filled that's fill them with integer m which represent not filled till now 
        vector<int> color_vec(v,m);
        
        return try_coloring(0,color_vec, adj_list, v, m);
    }
};
