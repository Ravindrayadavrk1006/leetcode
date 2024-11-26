/*
    it is topological sorting , we can use dfs to do the topological sort or kahns algorithm to do the topological sort, 
    here using the  basic of kahns algorithm to do it because it is more accurate, we don't need the entire kahns algorithm do it

    here saying we have to find the element whose indegree is 0, if there are more than one element whose indegree is 1 then then answer will be -1 since there won't be any clear cut winner.

    we could optimize it more , but let's say we find the indegree of all the nodes and we push the element whose indegree is 0, if finally there are more than one element in the queue, siince in kahns we start the topological sort from all the elements whose indegree is 0 , and kahns is bfs hence we insert all the elemnts whose indegree is 0 is the queue, if there are more than one element with indegree 0 then we  return -1 else we return the starting point i.e first element of the queue

*/
class Solution {
public:
    int findChampion(int n, vector<vector<int>>& edges) {
        //prepare the adjList
        // vector<vector<int>> adjList(n);
        vector<int> indegree(n, 0);
        for(auto edge: edges){
            // adjList[edge[0]].push_back(edge[1]);
            indegree[edge[1]]++;
        }
        queue<int> q;
        for(int i=0; i<n; i++){
            if(indegree[i] == 0)q.push(i); 
        }
        if(q.size()>1)return -1;
        else return q.front();
    }
};
