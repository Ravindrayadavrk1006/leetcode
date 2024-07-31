/*
    CONCEPT-> just the implementation of bridges finding using tarzans algorithm

    tarzan's algorithm explanation-> 
        if not getting then see strivers video of targan's algorithm
        we are having two arrays tin and tlow
        tin-> tin will store the time when a node was traversed in dfs 
        tlow -> will store the minimum time to reach this node in dfs
            -> intially we will set tmin = tin for all node
            it will be updated -> 
                1. suppose we reached a already visited nodes when doing dfs for this current node, the already visited node will have tmin time lower than the current node,so we store minimum of tmin of current node and tmin of this already reached node in the tmin of current node.
                2. when coming back after visiting a adj_node, the adj_node could have tmin lower than the current node and hence we will update tmin of current node there as well tmin[node] = min(tmin[adj_node],tmin(node))
        

        bridges finding-> when traversing back or back tracking after doing traversal of adj_node, if current_node has lower inserting time than tmin(which is lowest time to reach the node) of adj_node which says that the adj_node can be visited to this node only through the current node , hence it's a bridge.
        we are taking tin of current node because we are considering the insertion order as well to reach the adj_node;
*/
class Solution {
private:
    //this timer will be used to record the time of insertion and tlow to reach the node
    int timer = 1;
    void dfs(int node, int parent,vector<bool>& vis, vector<int>& tin, vector<int>& tlow, vector<vector<int>>& adj_list,vector<vector<int>>& bridges){
        vis[node] = true;
        tin[node] = tlow[node] = timer;
        timer++;
        for(auto it: adj_list[node]){
            //if node is the parent then we don't do anyting
            if(it == parent)continue;
            //if adj_node is not visited yet
            if(!vis[it]){
                dfs(it,node,vis,tin,tlow,adj_list,bridges);
                tlow[node] = min(tlow[node],tlow[it]);
                //now when backtracking checking if it is a bridge
                if(tin[node]<tlow[it]){
                    bridges.push_back({node,it});
                }
            }
            else{
                tlow[node] = min(tlow[node],tlow[it]);
            }
        }
    }
public:
    vector<vector<int>> criticalConnections(int n, vector<vector<int>>& connections) {
        vector<vector<int>> adj_list(n);
        //creating adj_list from edges
        for(auto it: connections){
            adj_list[it[0]].push_back(it[1]);
            adj_list[it[1]].push_back(it[0]);
        }

        //implementation of core tarzan's algorithm
        vector<int> tin(n);
        vector<int> tlow(n);
        vector<vector<int>> bridges;
        vector<bool> vis(n,false);
        dfs(0,-1,vis,tin, tlow,adj_list,bridges);
        return bridges;
    }
};
