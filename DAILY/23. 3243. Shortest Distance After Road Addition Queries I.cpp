class Solution {
private:
    //applying bfs traversal for all the queries , i.e for each query we are applying bfs once
    vector<int> solFindShortestPath(int n, vector<vector<int>>& queries){
        vector<vector<int>> adjList(n);
        //preparing initial adjList
        for(int i =0; i<n-1; i++){
            adjList[i].push_back(i+1);
        }
        int queriesSize = queries.size();
        vector<int> ans(queriesSize); 
        for(int query = 0;query<queriesSize; query++){
            //adding the current query edge
            adjList[queries[query][0]].push_back(queries[query][1]);
            string temp = "for query "+ to_string(query);
            //now we will do bfs
            vector<bool> visited(n,0);
            queue<int> q;
            int distance = 0;
            //make the current element visited and push in the queue
            visited[0] = true;
            q.push(0);
            while(!q.empty()){
                //get the element from front
                int qSize = q.size();
                bool comeOut = false;
                while(qSize--){
                    int front = q.front();
                    if(front == n-1){
                        comeOut = true;
                        break;
                    }
                    //delete the front element
                    q.pop();
                    //pushing the neighbours
                    for(int adj: adjList[front]){
                        if(!visited[adj]){
                            //make it visited and push in the queue
                            visited[adj] = true;
                            q.push(adj);
                        }
                    }
                }
                if(comeOut)break;
                distance++;
            }
            ans[query] = distance;
        }
        return ans;
    }
public:
    vector<int> shortestDistanceAfterQueries(int n, vector<vector<int>>& queries) {
        return solFindShortestPath(n, queries);
    }
};
