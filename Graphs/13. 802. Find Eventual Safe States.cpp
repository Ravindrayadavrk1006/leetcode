/*
    explanation :
        the question is saying if we find cycle in a path then all the nodes in that path will not be safe node .
        
        so we are using dfs algo of finding cycle in a directed graph,
        and when returning after checking all the routes from a node we wil be sure there is no cycle since if there is cycle the code would not reach there and would be returned before -> if(!visited[adj_el]){
                if(helper_cycle_dfs_directed(adj_el,adj_list,visited,path_visited,check))return true;
            }
        so when returning we are sure there is no cycle for the current node , so it will be a safe node.
        we are using a array check , where safe node will be marked as 1
*/
class Solution {
private:
    bool helper_cycle_dfs_directed(int node,vector<vector<int>>& adj_list,vector<bool>& visited, vector<bool>& path_visited, vector<int>& check){
        visited[node] = true;
        path_visited[node]  = true ;
        for(int adj_el : adj_list[node]){
            //if visited in the current path then there is a cycle 
            //we return, once we find a cycle from that point itself
            if(!visited[adj_el]){
                if(helper_cycle_dfs_directed(adj_el,adj_list,visited,path_visited,check))return true;
            }
            else if(path_visited[adj_el])return true;
        }
        path_visited[node] = false;
        //all the path for the current node has been traversed and we didn't find cycle so current node is safe node
        check[node] = true;
        //commented since using the check approach new learning
        //ans.push_back(node)
        return false;
    }
public:
    vector<int> eventualSafeNodes(vector<vector<int>>& graph) {
        //number of nodes
        int n = graph.size();
        vector<bool> visited(n,false);
        vector<bool> path_visited(n,false);

        //we can keep storing in the ans array and sort and return it 
        //or we can keep a check array 
         //for avoiding this sort function ,we can keep a vector of size n named check and can pass that in the dfs function instead of passing ans array  and instead of  ans.push_back(node) we can do check[node] =1 and in the eventualSafeNodes we can run a for loop from i = 0 to i<n , if check[i]=1 we push that in the answer array. in this way we will get O(n) for this part instead of nlogn t.c for this part
        vector<int> ans;

        //using non-sorting approach for answer
        vector<int> check(n,false);
        
        for(int i =0 ; i<n ;i++){
            if(!visited[i])helper_cycle_dfs_directed(i,graph,visited,path_visited,check);
        }
        //sort(ans.begin(),ans.end());
        for(int i = 0 ; i < n ; i++)if(check[i])ans.push_back(i);
        return ans;
    }
};
