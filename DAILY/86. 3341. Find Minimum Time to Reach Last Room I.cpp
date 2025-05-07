class Solution {
private:
    /*
        approach->
            using dijkstra algorithm with PQ, also since it is a matrix, for each index we are assigining the node value to be i*(no of column) + j

    */
    int sol_minimum_time_to_reach(vector<vector<int>>& moveTime){
        //row
        int n = moveTime.size();
        //col
        int m = moveTime[0].size();

        int total_cells = n*m;
        //intialize the dist arr, all unreachable(int_max)
        vector<int> dist(total_cells, INT_MAX);
        //min-heap
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        //will be used to get the adjacent elements since it's a matrix and can traverse in horizontal and vertical direction
        vector<int> adj = {0,-1, 0, 1, 0};
        //insert the first element
        pq.push({0,0});
        dist[0] = 0;
        while(!pq.empty()){
            int node = pq.top().second;
            int distance = pq.top().first;
            //position of current node in i,j format
            int curr_i = node/m;
            int curr_j = node%m;
            pq.pop(); 
            //checking it neighbours
            for(int el = 0; el < 4; el++){
                int new_i = curr_i+adj[el];
                int new_j = curr_j + adj[el+1];
                //if not a valid neighbour
                if(new_i>=n || new_i< 0 || new_j<0 || new_j>=m)continue;
                //node value cration using i,j
                int adj_node = new_i*m + new_j;
                //here we are saying i.e if current node is 5 and next neighour node min time is 4 then we can reach that neighbour node in 5+1 time only because we have already used that time ,
                //also if neighbour time is 5 and current node time is 4 , then we will be able to reach that node at 5+1 since we can't go to that node before 5
                int to_reach_adj = max(distance, moveTime[new_i][new_j]) + 1;
                if(to_reach_adj < dist[adj_node]){
                    dist[adj_node] = to_reach_adj;
                    pq.push({to_reach_adj, adj_node});
                }
            }
        }
        //this will be last node, since totalnode will be n*m
        return dist[n*m-1];
    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return sol_minimum_time_to_reach(moveTime);
    }
};
