
class Solution {

/*
    there are two part of this question ->
    first we are finding if there is cycle or not using kahns algorithm if there is we return -1,
    if not then we are doing dfs traversal at each node, we are also storing the dfs of nodes in a dp so that when doing dfs of next element if that element dfs is already done then we can use that.
    DP used since   dfs t.c (N+E) and if we do normally N*(N+E) which will be O(N^2) and will give TLE but if we use DP
    then it will be done in N+E and some auxillary space that's all 


*/

/*
    basic cycle using DFS

*/
bool has_cycle_using_kahns_algorithm(int n,vector<int>& indegree, vector<vector<int>>& adj_list){
    queue<int> q;
    int elements_processed = 0;
    //push the elements having indegee 0 into the queue to be processed first as per topological sort
    for(int i=0; i<n; i++){
        if(indegree[i] == 0)q.push(i);
    }
    while(!q.empty()){
        int front = q.front();
        //remove the front element
        q.pop();
        elements_processed++;
        //decrease the indegre of adjcent element
        for(int adj: adj_list[front]){
            //decrase the indgree of current neighbour
            indegree[adj]--;
            //if indegree becomes 0 then insert the element in the queue
            if(indegree[adj] == 0)q.push(adj);
        }
    }
    if(elements_processed < n)return true;
    return false;
}

/*
    -------CONCEPT OF FINDING CYCLE USING 3 COLOR AND DFS-----------
    we are traversing the graph and if a node is not visited(color 0) we makr it 1(being traversed currently) and go traverse it
    if a node is traversed we mark it 2 

    so if we are traversing a node and trying to traverse it's neighbours and if if we find a node[adj] = 1 then it means it was being traversed currently and not completed it means there is a cycle.


*/

/*
    solution we are doing dfs at each node and at each node once dfs of one of it's neigbour completes we try to maximize the value of current node colors with the color of value of it's neigbour
    after all it's neihbour are processed we increment the current node color value, since the current node would also be colored with some color

    when a node is traversed we are returning the current node current color value, why it is explained in the code

    we are using a dp of size dp 26*n   where the column represent a node and row represent it's 26 colors 
    nothing very complex just that 


*/
int dfs(int node, vector<vector<int>>& adj_list, vector<int>& visited, vector<vector<int>>& dp, string& colors){
    //we are currently processing a node 
    /*
        either processing should be completed -> visited[i] = 2 or it should not be visited[i] = 0
        if we each the node and it is being processed i.e visited[i] = 1 
        => we reachd the node again and hence there is a cclye
    */
    if(visited[node] == 1)return INT_MAX;
    //if viisting for the first time
    if(visited[node] == 0){
        //mark it as processing
        visited[node] =1 ;
        for(int adj: adj_list[node]){
            int res = dfs(adj, adj_list, visited, dp, colors);
            //if we found a cycle then return it
            if(res == INT_MAX)return INT_MAX;

            //when current neigbhour is proceed update the current node with the neigbours values
            for(int i =0; i<26; i++){
                dp[i][node] = max(dp[i][node], dp[i][adj]);
            }
        }
        //when all the current nodes neighbour are processed then add the current node color too,
        //in the respective color row
        dp[colors[node]- 'a'][node]++;
        //mark the current node as processed
        visited[node] = 2;
    }
    //this is very important
    //in case of current node is processed the node, whatever node color is that value will be returned
    //that return value will tell that it is already processed since the color count will never be INT_MAX
    /*
        also the return value will return the maximum value at some point
        let's say   a ->b -> c ->c -> c-> 
                    0   1    2   3    4 

        node 4 will return 1, node 3 will return 2, node 2 will return 3 node 4 will return 1 node a will return 1 beacuse count of a is 1 at 0
        but we also returned our answer at some point ie at node c and hence in the for loop of dfs caller
        we can easily try to maximimze to get the answer  
    */
    return dp[colors[node]- 'a'][node];
}
int sol_largest_path_value(string colors, vector<vector<int>>& edges){
    int n = colors.size();
    int m = edges.size();
    vector<int> indegree(n, 0);
    vector<vector<int>> adj_list(n);
    for(auto edge: edges){
        adj_list[edge[0]].push_back(edge[1]);
        indegree[edge[1]]++;
    }
    //checking if has cycle using kahns algorithm , this is not required at all
    //since we are using another approach for finding the cycle i.e 3 colored approach using DFS
    if(has_cycle_using_kahns_algorithm(n, indegree, adj_list))return -1;
    

    //doing bfs on each node 
    //for storing the answer
    int max_color_length = 0; 
    vector<int> visited(n,0);
    //DP for storing each color count at each node, the color at each node are rows and node is columns
    //each node in column has 26 colors a-z 
    vector<vector<int>> dp(26,vector<int>(n,0));

    //doing dfs traversal at each node
    for(int i =0; i<n; i++){
        int res = dfs(i, adj_list, visited, dp, colors);

        //if there is as cycle 
        if(res == INT_MAX)return -1;
        max_color_length = max(max_color_length, res);
    }
    return max_color_length;
}

public:
    int largestPathValue(string colors, vector<vector<int>>& edges) {
        return sol_largest_path_value(colors, edges);
    }
};
