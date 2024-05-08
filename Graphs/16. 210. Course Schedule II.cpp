/*
    KAHN'S ALGORITHM:
        here not given that if the graph is DAG or not hence to satisfy that condition before applying kahn's algorithm of finding topological sort, applying algorithm to find cycle in a directed graph , if cycle found it means it is not DAG and hence return  a empty array.


    also remember here asked for finding reverse of toplogical sort, since the course that do not depend on other should be done first hence it is reverse of topological sort and hence storing from last in the final topo response vector
    kahn's algorithm:
        here giving normal explanation of kahn's algorithm , the original one not the reverse one asked in the question, 

        it is dfs traversal and we will start with the element having indegree 0,
        indegree 0 means it may be depended on other but no one depend on it, so this will be first to be inserted in original topo sort,
        
        starting by inserting all the elemnts in the queue which have indgree 0 ,
        we will do till queue is empty,
        for a element we pop it and since it's indegree is 0 , so it will be insert in the topo ans vector from front,
        for it's child , since the one element which ads one indegree to it's adjcent elemnt is removed so their indegree will reduce , so we will reduce indegre of adj_element and if their indegree becomes 0 we will push it in the queue

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
    vector<int> findOrder(int numCourses, vector<vector<int>>& prerequisites) {
        vector<int> indegree(numCourses,0);
        vector<vector<int>> adj_list(numCourses);
        for(auto edge: prerequisites){
            //forming adj_list
            adj_list[edge[0]].push_back(edge[1]);
            //indegree
            indegree[edge[1]]++;
        }

        //since the graph can be DAG so let's find for cycle as well
        //this cycle finding is not part of dag
        vector<bool> visited(numCourses,false);
        vector<bool> path_visited(numCourses,false);
        vector<int> ans;
        for(int i = 0 ; i<numCourses; i++){
            if(!visited[i]){

                //if anywhere find a cycle return false not topological sortable
                if(cycle_using_dfs(i,visited,path_visited,adj_list))
                    return ans;
            }
        }
        for(int node: indegree)cout<<node<<" ";
        cout<<endl;
        queue<int> q;
        for(int i = 0; i<numCourses; i++){
            if(indegree[i] == 0)q.push(i);
        }
        vector<int> topo(numCourses);
        int pos = numCourses;
        while(!q.empty()){
            int front = q.front();
            q.pop();
            topo[--pos] = front;
            //traversing all the adj elements of current front element
            for(int adj_el: adj_list[front]){
                //reduce the indegree since the one element(front) linked to is removed
                indegree[adj_el]--;
                if(indegree[adj_el] == 0){
                    q.push(adj_el);
                }
            }
        }
        return topo;
    }
};
