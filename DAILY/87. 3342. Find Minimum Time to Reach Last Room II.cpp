class Solution {
private:
    /*
        this helper function is only important thing that is happening

        if we look well,

        for (x, y)
        for x even , the (x,0) to move to adjacent elements we require 1 to move and from (x,odd) we will require 2
        for x odd, (x,0) we require 2 to move from it to adjacent elements, and next we will require 1 to move

        ==>
        if x = even , y = even  we require 1 to move from it to adjacent elemnts 
        if x = even, y = odd , we require 2 to move from it to adjacent elements
        if x = odd , y = even , we require 2 to move from it to adjacent elements
        if x = odd , y = odd , we require 1 to move from it to adjacent elements
    */
    int helper_get_move_time(int i, int j){
        //if x is even
        if(i&1){
            if(j&1)return 1;
            return 2;
        }
        if(j&1)return 2;
        return 1;

         /*
            FYI: from  discussion can directly use (i+j)%2 + 1
            i.e if i+j is odd then 2 else 1
        
        */
    }

    //this is very simle dijkstra element and same as done in DAILY -> DAILY/86. 3341. Find Minimum Time to Reach Last Room I.cpp , just for adjacent jump where earlier it used to take just 1, now it takes alternatively, we use above helper function to move whether it takes 1 unit to move or 2 unit to move 

    int sol_minTimeToReach(vector<vector<int>>& moveTime){
        //no of rows 
        int n = moveTime.size();
        //no of columns 
        int m = moveTime[0].size();
        vector<int> dist(n*m, INT_MAX);
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        vector<int> pos = {0, -1, 0, 1, 0};
        pq.push({0,0});
        dist[0] = 0 ;
        while(!pq.empty()){
            //process the topmost node
            int node = pq.top().second;
            int distance = pq.top().first;
            //remove the topmost node
            pq.pop();
            int curr_i = node/m;
            int curr_j = node%m;
            for(int adj=0; adj<4; adj++ ){
                int new_i = curr_i + pos[adj];
                int new_j =  curr_j + pos[adj+1];
                if(new_i < 0 || new_i >= n || new_j <0 || new_j >= m)continue;
                //node number formation using (x,y)
                int adj_node = new_i*m + new_j;
                int adj_dist = max(distance, moveTime[new_i][new_j]) + helper_get_move_time(curr_i, curr_j);
                if(dist[adj_node]> adj_dist){
                    dist[adj_node] = adj_dist;
                    pq.push({adj_dist, adj_node});
                } 
            }
        }
        return dist[n*m -1];
    }
public:
    int minTimeToReach(vector<vector<int>>& moveTime) {
        return sol_minTimeToReach(moveTime);
    }
};
