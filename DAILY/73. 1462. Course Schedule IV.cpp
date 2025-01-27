class Solution {
private:

    //wrong approach was trying kahns algorithm and finding a topological sort 
    vector<bool> sol_check(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries){

        //NOTE-> using kahn's algorithm to find the topological sort
        //create adjaceny list
        vector<vector<int>> adj_list(numCourses);
        //indegree 
        vector<int> indegree(numCourses, 0);
        vector<bool> present(numCourses, false);
        for(auto edge: prerequisites){
            adj_list[edge[1]].push_back(edge[0]);
            indegree[edge[0]]++;
            present[edge[0]] = true;
            present[edge[1]] = true;
        }
        queue<int> q;
        for(int i =0; i< numCourses; i++){
            if(present[i] && indegree[i] == 0)q.push(i);
        }
        vector<int> topo;
        while(q.size()){
            int front = q.front();
            //remove the element
            q.pop();
            topo.push_back(front);
            for(int adj: adj_list[front]){
                indegree[adj]--;
                if(indegree[adj] == 0)q.push(adj);
            }
        }
        for(int el: topo)cout<<el<<" ";
        //we will have topological sort here
        //now let's insert these element in a hashmap
        unordered_map<int,int> mp;
        int n = topo.size();
        for(int i =0; i<n; i++){
            mp[topo[i]] = i;
        }
        int queries_size = queries.size();
        vector<bool> ans(queries_size, false);
        for(int i=0; i< queries_size; i++){
            auto query =  queries[i];
            if(mp.find(query[0]) == mp.end())continue;
            if(mp.find(query[1]) == mp.end())continue;
            if(mp[query[0]] > mp[query[1]])ans[i] = true;
        }
        return ans;
    }
    bool dfs(int pos, int find_el,vector<int>& visited, vector<vector<int>>& adj_list){
        visited[pos] = true;
        if(pos ==  find_el)return true;
        for(int adj: adj_list[pos]){
           if(!visited[adj]){
            if (dfs(adj, find_el, visited, adj_list)) return true;
           }
        }
        return false;
    }

    /*
        we have created adj_list and then for each query doing dfs traversal while traversing if we find the query[0] starting from query[1] for each query of queries array then we make it true else false
    
    */
    //correct solution here , we are trying to travel for each query doing dfs traversal and finding the solution
    vector<bool> sol_check2(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries){
        //create adjaceny list
        vector<vector<int>> adj_list(numCourses);
        //indegree 
        // vector<int> indegree(numCourses, 0);

        for(auto edge: prerequisites){
            adj_list[edge[1]].push_back(edge[0]);
        }
        vector<bool> ans(queries.size(), false);
        //for each query
        int q_size = queries.size();
        for(int i = 0 ; i < q_size; i++){
            vector<int> visited(numCourses, false);
            ans[i] = dfs(queries[i][1], queries[i][0],  visited, adj_list);
        }
        return ans;
    }
public:
    vector<bool> checkIfPrerequisite(int numCourses, vector<vector<int>>& prerequisites, vector<vector<int>>& queries) {
        // return sol_check(numCourses, prerequisites, queries);
        return sol_check2(numCourses, prerequisites, queries);
    }
};
