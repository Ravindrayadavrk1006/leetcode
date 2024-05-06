problem-path :: --> https://www.naukri.com/code360/problems/detect-cycle-in-a-directed-graph_1062626?leftPanelTabValue=PRO
/*
  here it is same as undirected but with one difference that we are keeping a local path_visit arra for marking the nodes visited int the current path.
  reason for it since a node can be viisted in other path but it's not necessary that we can reach to that node in current path. so to overcome this we are keeping a path_visit to only track if visited in the current path
  also we are keeping a normal visit array so that we don't visit already visited node normally
*/
string cycle_using_dfs(int node,vector<int>& visit,vector<vector<int>>& adj_list, vector<int>& path_visit){
    visit[node]  = 1;
    path_visit[node] = 1;
    for(auto el: adj_list[node]){
        //if the node we are trying to visit is already visited and it is not the immediate parent since given no parrell eges
        if(path_visit[el] == 1)return "Yes";
        //if it is not visited yet then visit that node
        else if (visit[el] == 0 && cycle_using_dfs(el,  node,visit,adj_list)=="Yes")return "Yes";
    }
    path_visit[node] = 0;
    return "No";
}
int detectCycleInDirectedGraph(int n, vector < pair < int, int >> & edges) {
  // Write your code here.
   //n ->nodes and m edges
    vector<int> visit(n+1,0);
    vector<int> path_visit(n+1,0);
    vector<vector<int>> adj_list(n+1);   //creating adjaceny list from edges
    for(auto it: edges){
        adj_list[it[0]].push_back(it[1]);   //since undirected so both way pushing
        // adj_list[it[1]].push_back(it[0]); //since undirected so both way pushing
    }
     for(int i = 1; i <=n; i++){
        if(!visit[i]){
            if(cycle_using_dfs(i,-1,visit, adj_list, path_visit) == "Yes")return true;
        }
    }
    return false;
}
