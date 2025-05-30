/*
    approach ->
        we are calculating distance of each node from node1 and storing in a vector dist_vec_node1, node which are not reachable are marked -1,  where index i is the node number and value is the distance from node1
        similarly storing the distance of each node from node2 in a vector dist_vec_node2,node which are not reachable are marked -1

        we have kept intial ans to be ans = INT_MAX

        GET MAXIMUM VALUE
        now we are running a for loop checking if node i is reachable from node1 and node2 both or not, if yes
        we ar getting the distance from node1 and distance from node2 and get the maximum of both value.
        MINIMIZE THE MAXIMUM
        now if this value is less  ans we store the current value in ans and also store the current node i in another variable called min_dist_node

*/
class Solution {
private:
    /*
        function for getting the distance of each node from curr_node 
    */
    /*
    Alternate to this 
        we could have used bfs traversal easily to get the distance of each node from a node
    */
    void set_distance(vector<int>& dist_vec, int curr_node, vector<int>& edges){
        int curr_dist = 0;
        int n = edges.size();                   0 1 2 3 4 5 6
        //visited in case of cycle eg. edges = [4 4 4 5 1 2 2]   since we want to consider in how much distance we can reach to that node,
        /*
            in above case there are edges from  0 -> 4 and 4->0    we can reach 0 by 0 distance no need to again come back and see therefore we have put if not visited then only visit it 
        
        */
        vector<int> vis(n, 0);
        //since a node can have only one outgoing node and hence using this way to find the distance
        //we are saying if the current node is not -1 i.e there is a edge from curr_node and also this node is not visited earlier explained above 
        while(curr_node != -1 &&  vis[curr_node] != 1){
            //mark it visited
            vis[curr_node] = 1;
            //store the curnode dist and increasemnet the curr_dist 
            dist_vec[curr_node] = curr_dist++;
            //
            curr_node = edges[curr_node];
        }
    }
    int sol(vector<int>& edges, int node1, int node2){
        int n = edges.size();
        //distance of each node from node1
        vector<int> dist_vec_node1(n,-1);
        //distance of each ndoe from node2
        vector<int> dist_vec_node2(n, -1); 
        //getting the distance of each node from node1 and storing in dist_vec_node1
        set_distance(dist_vec_node1, node1, edges);
        //getting the distance of each node from node2 and storing in dist_vec_node2
        set_distance(dist_vec_node2, node2, edges);

        //now we will be minimizing the maximum i.e get maximum distance to that node from node1 and node2 if both node 
        //reachable to that node and minimize the final value;
        int min_dist = INT_MAX;
        int min_dist_node = -1;
        for(int i=0; i<n; i++){
            //if neither is -1 it means both node1 and node2 can visit to that node
            if(dist_vec_node1[i] != -1 && dist_vec_node2[i] != -1){
                //get the maximum of distance to node i from node1 and node2
                int max_val = max(dist_vec_node1[i], dist_vec_node2[i]);
                //minimzing the final ans
                if(max_val < min_dist){
                    min_dist = max_val;
                    min_dist_node = i;
                }
            }   
        }
        //returning the minimum value
        return min_dist_node;
    }
public:
    int closestMeetingNode(vector<int>& edges, int node1, int node2) {
        return sol(edges, node1, node2); 
    }
};
