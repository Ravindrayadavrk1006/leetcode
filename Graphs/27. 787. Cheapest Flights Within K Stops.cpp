class Solution {
/*
    here dijkstra will fail if we store on basis of shortest distance since there comes another parameter ie stops.
    so we will store on basis of stops ans since stops are increasing by +1 so no need to use priority queue normal queue will work fine.

    

*/
private:
    int sol_find_smallest_dist_with_k_stops(int n, vector<vector<int>>& flights, int src, int dst, int k){
        vector<vector<pair<int,int>>> adj_list(n);
        //intermediate is k stops and last stop including will make k+1
        int stop_including_final = k+1 ;
        for(auto it: flights){
            //since directed graph hence only way path given
            adj_list[it[0]].push_back({it[1],it[2]});
        }
        vector<int> dist(n,INT_MAX);
        dist[src]  = 0;
        queue<pair<int,pair<int,int>> > q;
        //stops, node,distance   is the order of each element in pq
        q.push({0,{src,0}});
        while(!q.empty()){
            auto front = q.front();
            int stops = front.first;
            int node = front.second.first;
            int distance = front.second.second;
            // cout<<"node"<<node<<endl;
            q.pop();
            //this is saying if current node has k+1 then further it's chidren won't be pushed
            if(stops > k )continue;
            for(auto adj_el : adj_list[node]){
                int distance_till_adj_el = distance + adj_el.second;

                if(distance_till_adj_el< dist[adj_el.first] && stops+1 <= stop_including_final){
                    q.push({stops+1,{ adj_el.first, distance_till_adj_el}});
                    dist[adj_el.first] = distance_till_adj_el;
                }
            }
        }
        if(dist[dst] == INT_MAX)return -1;
        return dist[dst];
    }
public:
    int findCheapestPrice(int n, vector<vector<int>>& flights, int src, int dst, int k) {
        return sol_find_smallest_dist_with_k_stops(n, flights, src, dst, k);
    }
};
