class Solution {
private:
    /*
        explanation: simple application of prims algorithm for minimum spanning tree
        here few differences 
            1. we are not given edge weights and which is equal to |x-x1| + |y-y1|
            2. all nodes are neighours of each others

        everything is same , simple and direct application of prim's algorithm
    */
    int sol_min_cost_connect_all_points(vector<vector<int>>& points){
        //key will be pair<x,y> and value is bool value
        map<pair<int,int>,bool> vis;
        //making all the points non visited initially
        for(auto point: points){
            // map[make_pair(point[0],point[1])] = false;
            vis[{point[0],point[1]}] = false;
        }
        int mst_sum  = 0 ;
        //for storing the values in format of distance i.e weight and point {wt,{x,y}}
        set<pair<int,pair<int,int>>> st; 
        //inserting first point of points        
        st.insert({0,{points[0][0],points[0][1]}});
        while(!st.empty()){
            auto front = *(st.begin());
            int wt = front.first;
            int x = front.second.first;
            int y = front.second.second;
            st.erase(front);
            //if current point is already visited no need to visit again
            if(vis[{x,y}])continue;
            //if not visited then below code
            vis[{x,y}] = true ;
            mst_sum += wt;
            //inserting the neighbours into the set
            for(auto point: points){
                //this if condition will remove from inserting already visited points in the stack or priority queue
                if(!vis[{point[0],point[1]}]){
                    int adj_x = point[0];
                    int adj_y = point[1];
                    int adj_wt = abs(adj_x - x) + abs(adj_y-y);
                    st.insert({adj_wt,{adj_x,adj_y}});
                }
            }
        }
        return mst_sum;

    }
public:
    int minCostConnectPoints(vector<vector<int>>& points) {
        return sol_min_cost_connect_all_points(points);
    }
};
