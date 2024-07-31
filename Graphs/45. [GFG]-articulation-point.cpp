/*
    here two conditions are very important:
    tlow[it]>=tin[node]
        it is saying that adjencent child cannot reach to a node that was dfs traversed before THE node,
        which means there is no way that a child can be reached to any node above THE node whose adjecent is this child node
        which means THE node is articulation , i.e if we remove THE node then the graph would break into two parts
    first_node_child_counter > 1 && parent == -1
        we are separately handling root node since it will mess up things
    
    
    if the adjnode is already visited :
        tlow[node] = min(tlow[node],tin[it]); there is this another change from the briges finding question using tarzans algorithm ,that we are not using tlow of adjenct node
         below to reach other node we will have to go throught the adjcent node hence using tin instead of tlow
  
  
  ****refer to CP NOTES for some clearity
*/
class Solution {
  private:
    int timer = 1;
    void dfs(int node, int parent,vector<int>& vis, vector<int>& tin, vector<int>& tlow,
        vector<int>& mark_articulation,vector<int>adj[]){
            vis[node] = 1;
            tlow[node] = tin[node] = timer;
            timer++ ;
            int first_node_child_counter = 0;
            for(auto it: adj[node]){
                if(it == parent)continue;
                if(!vis[it]){
                    dfs(it,node, vis,tin, tlow,mark_articulation, adj);
                    tlow[node] = min(tlow[node],tlow[it]);
                    //it means if the adj_node is only reachable to current node or higher node it means i can't reach to the node which were visited before node and henc if we remove the node it the two part will become separate component
                    if(tlow[it]>=tin[node] && parent != -1){
                        mark_articulation[node] = 1;
                    }
                    first_node_child_counter++;
                }
                else{
                    tlow[node] = min(tlow[node],tin[it]);
                }
            }
        if(first_node_child_counter > 1 && parent == -1)mark_articulation[node] = 1;
        }
  public:
    vector<int> articulationPoints(int V, vector<int>adj[]) {
        //we are given the adjaceny list and no of nodes
        
        //since the graph is also connected so we don't need to check for all the elements if visited and call the
        //dfs again and again one call will serve the puprose
        vector<int> vis(V);
        vector<int> tin(V);
        vector<int> tlow(V);
        //since we will be visiting the articulation point again and again and to keep it once in answer
        //we will take a mark array where once articulation point is detected we will mark it that it is articulation point and in this way no repetion will happen
        vector<int> mark_articulation(V,0);
        vector<int> ans;
        dfs(0,-1,vis, tin, tlow, mark_articulation, adj);
        // if(first_node_child_counter>1)mark_articulation[0] = 1;
        for(int i=0; i<V; i++){
            if(mark_articulation[i] == 1)ans.push_back(i);
        }
        if(ans.size() == 0)return {-1};
        return ans; 
    }   
};
