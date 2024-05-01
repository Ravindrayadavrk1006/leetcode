https://www.naukri.com/code360/problems/cycle-detection-in-undirected-graph_1062670?leftPanelTabValue=SUBMI
concept of --> cycle in a graph using dfs travesal
/*
    simple approach for detecting cycle in graph:
    cycle_using_dfs is the main function which uses dfs travesal for finding a cycle. here cycle is assumed if the node get connected to any node apart from it's parent. apart from it's parent because it is told that parallel is not allowed or given
    //cycle is present if while travesing some visited node comes and it is not immediate parent for above condition then we consider it a cycle

    //if a node is not visited yet it means it's a new node , so we will keep traversing using dfs. at any point if we find cycle we return it


    ** since the graph may not be connected so if a node is not visited yet after starting dfs traversal  from node 1, we check if a node is visited we again travese making it a starting point

    other points--> we draw adjacency list from given edges also since the nodes are starting from one hence visit of size n+1

*/
string cycle_using_dfs(int node, int node_par,vector<int>& visit,vector<vector<int>>& adj_list){
    visit[node]  = 1;
    for(auto el: adj_list[node]){
        //if the node we are trying to visit is already visited and it is not the immediate parent since given no parrell eges
        if(visit[el] == 1 && el != node_par)return "Yes";
        //if it is not visited yet then visit that node
        else if (visit[el] == 0 && cycle_using_dfs(el,  node,visit,adj_list)=="Yes")return "Yes";
    }
    return "No";
}
string cycleDetection (vector<vector<int>>& edges, int n, int m)
{
    //n ->nodes and m edges
    vector<int> visit(n+1,0);
    vector<vector<int>> adj_list(n+1);   //creating adjaceny list from edges
    for(auto it: edges){
        adj_list[it[0]].push_back(it[1]);   //since undirected so both way pushing
        adj_list[it[1]].push_back(it[0]); //since undirected so both way pushing
    }
    // for(int i =0; i<adj_list.size(); i++){
    //     cout<<i<<"-->";
    //     for(int j = 0 ; j< adj_list[i].size(); j++){
    //         cout<<adj_list[i][j]<<" ";
    //     }
    //     cout<<endl;
    // }
    // Write your code here.
    //if the graph was connected then single call would have served the purpose since all the nodes would have been connected
    //return cycle_using_dfs(1,-1,visit, adj_list);
    //since the graph may be disconnected so in go all the node would not be visited
    // i from 1 since node start from 1
    for(int i = 1; i <=n; i++){
        if(!visit[i]){
            if(cycle_using_dfs(i,-1,visit, adj_list) == "Yes")return "Yes";
        }
    }
    return "No";
}
