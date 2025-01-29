class Solution {


    /*  
        appraoch -> 
    
        we are using the concept of bridges, since a node which is bridge can never be the anwer hence finding all the bridges using the concept of targen algorithm and then travrsing the given edges from last which ever edge is not present in the bridges that is the answer
    */
private:
    int timer = 1;

    //tarjen algorithm for finding bridges in the graph
    void dfs(int node, int par, vector<int>& cin, vector<int>& low, vector<bool>& visited, set<pair<int,int>>& bridge, vector<vector<int>>& adj_list){
        visited[node] = true;
        cin[node] = low[node] = timer;
        timer++;
        for(auto adj: adj_list[node]){
            //if adjcent is parnet
            if (adj == par)continue;
            if(!visited[adj]){
                dfs(adj, node, cin, low, visited, bridge, adj_list);
                //we store the minimum of if lower of adj node in the current node, 
                low[node] = min(low[node], low[adj]);

                //check if this connection can be a bridge
                if(low[adj] > cin[node]){
                    bridge.insert({node, adj});
                }

            }
            //adj node is already visited it means this connection can't be a bridge
            else{
                low[node] = min(low[node], low[adj]);
            }
        }
    }
    vector<int> helper_find_all_bridge(vector<vector<int>>& edges){
        //create adjcency list
        int n = edges.size();
        vector<vector<int>> adj_list(n+1);
        for(auto edge: edges){
            adj_list[edge[0]].push_back(edge[1]);
             adj_list[edge[1]].push_back(edge[0]);
        }
        vector<int> cin(n+1);
        vector<int> low(n+1);
        vector<bool> visited(n+1, 0);
        set<pair<int,int>> bridge;
        dfs(1, -1, cin, low, visited, bridge, adj_list);
        for(int i =n-1; i>=0 ; i--){
            if(bridge.find({edges[i][0], edges[i][1]}) == bridge.end() && bridge.find({edges[i][1], edges[i][0]}) == bridge.end())return edges[i];
        }

        vector<int> def;
        return def;
    }
        //this is wrong appraoch , here we are assuming that if that a edge both it's vertex has more than 1 neighhbour it means it's ans edge which is not the case since in case of bridges this appraoch fails
    vector<int> sol_findRedundantConnection(vector<vector<int>>& edges){
        unordered_map<int,int> indegree;
        for(auto edge: edges){
            indegree[edge[0]]++;
            indegree[edge[1]]++;
        }
        //we have the indegree now start from last
        int n = edges.size();
        for(int i =n-1; i>=0 ; i--){
            if(indegree[edges[i][0]] > 1 && indegree[edges[i][1]]> 1){
                return edges[i];
            }
        }
        vector<int> ans;
        return ans;
    }
public:
    vector<int> findRedundantConnection(vector<vector<int>>& edges) {
        // return sol_findRedundantConnection(edges);


        return helper_find_all_bridge(edges);
    }
};
