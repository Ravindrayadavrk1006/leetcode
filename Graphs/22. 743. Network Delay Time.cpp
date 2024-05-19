/*

    normal use of dijkstra algorithm.
    why use dijkstra--> we have been given source so we find sortest distance to reach to all node using dijkstra algorithm,
    finally saying if some node is not reachable so return -1 so we doing that if(dist[i] == INT_MAX)return -1; after executing dijkstra algo.
    if all are reachable then return minimum time to reach all node , which is maximum of the dijsktra dist array
    

*/
class Solution {
private:
    int min_time_to_reach_all_node(vector<vector<int>>& times, int n, int k){
        //nodes start from 1 to n hence n+1
        vector<vector<pair<int,int> >> adj_list(n+1);
        //since directired graph we won't push bidirectional
        for(auto it: times){
            adj_list[it[0]].push_back({it[1],it[2]});
        }
        priority_queue<pair<int,int>,vector<pair<int,int>>,greater<pair<int,int>>> pq;
        vector<int> dist(n+1,INT_MAX);
        //for reaching to node k from source node i.e k only , we require 0 distance
        pq.push({0,k});
        dist[k] = 0;
        while(!pq.empty()){
            int distance = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj_list[node]){
                int dist_to_node = distance + it.second;
                if(dist_to_node < dist[it.first]){
                    pq.push({dist_to_node,it.first});
                    dist[it.first] = dist_to_node;
                }
            }
        }
        //dijkstra algorithm ended above

        //returning the answer logic
        int max_time = INT_MIN;
        for(int i = 1; i<= n; i++){
            if(dist[i] == INT_MAX)return -1;
            else{
                if(dist[i]> max_time)max_time = dist[i];
            }
        }
        return max_time;

    }
public:
    int networkDelayTime(vector<vector<int>>& times, int n, int k) {
        return min_time_to_reach_all_node(times,n,k);
    }
};
