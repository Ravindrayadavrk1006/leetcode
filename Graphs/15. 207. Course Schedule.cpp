/*
    application of topological sort, and since it is saying whether you can do find a topological sort or not, so for finding topological sort the graph must be DAG , it is directed since given the prerequeisted array. which is kind of directed nodes.
    now if there exist a cycle then not possible to find topological sort .
    so question boils down to finding cycle in a directed graph

*/
class Solution {
private:
    bool cycle_using_dfs(int node, vector<bool>& visited, vector<bool>& path_visited,  vector<vector<int>>& adj_list){
        visited[node] =true;
        path_visited[node] =true;
        for(int adj_el: adj_list[node]){
            if(!visited[adj_el]){
                if(cycle_using_dfs(adj_el,visited,path_visited,adj_list))
                    return true;
            }
            if(path_visited[adj_el])
                return true;
        }
        path_visited[node]= false;
        return false;
    }
public:
    bool canFinish(int numCourses, vector<vector<int>>& prerequisites) {
        vector<bool> visited(numCourses,false);
        vector<bool> path_visited(numCourses,false);
        vector<vector<int>> adj_list(numCourses);  //create a vector of size numCourses where each element is a vector
        for(auto it: prerequisites){
            adj_list[it[0]].push_back(it[1]);
        }
        for(int i = 0 ; i<numCourses; i++){
            if(!visited[i]){

                //if anywhere find a cycle return false not topological sortable
                if(cycle_using_dfs(i,visited,path_visited,adj_list))
                    return false;
            }
        }
        //if no cycle then able to find a topological sort
        return true;
    }
};
