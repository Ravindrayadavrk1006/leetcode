class Solution {

private:
   /*
        application of dijkstra algorithm because we have the starting point and we have the starting point and we have to find the minimum distance to a node.
        DIJKSTRA ALGORITHM -> usefull since we can use it to find single source shortest path to all node

        we are directly applying the dijkstra algorithm


        few extra points to note -> from current node curr_node -> it's neighour are [curr_node+1, curr_node+6]

        our node are 0 based indexed i.e in given example from 0 to 35.

        important point we are finding the row number and column by dividing the node_value eg. for node 34 row = 34/(board.size()) 
        col  = 34%(board.size())
        other important point given in the quesiton i.e the node number start from leftbottom cell and in every row the order alternate
        if row is odd then indexes from right to left and therefore we are doing col = boar.size-1-col 
        and the row will be since , last row is the 0th row
        i.e the row will become = board.size()-1 -

   
   */
    int dijkstra_algorithm(vector<vector<int>>& board){
       int n = board.size();
       vector<int> dist(n*n, INT_MAX);
       //min-queue
       priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
       //order is {dist, node}
       pq.push({0,0});
       dist[0] = 0;
       //Basic dijkstra algorithm
       while(!pq.empty()){
        int node = pq.top().second;
        int distance = pq.top().first;
        pq.pop();
        for(int i =1; i<=6; i++){
            int adj_node = node + i;
            //if neighbour is a valid node, i.e the adj_node i.e lies in range [0  ,n*n-1]
            if(adj_node < n*n){
                int row = adj_node/n;
                int col = adj_node%n;
                //if it's an odd row then the order are reversed, since the 0th row count start from left to right and 1th row start from right to left and so on, that's wy
                if(row % 2 == 1)col = n-1-col;
                //since 0th row is the last row
                row = n - 1 - row;
                //if while going to adjcent node, it has a snake or ladder to another node, then we this become the adjecent node , but since in the given question the cell number are 1 based hence converting into 0 based by doing -1 
                if(board[row][col] != -1)adj_node =  board[row][col]-1;
                //we are saying that to reach this adjcent node we require +1 more step
                int dist_to_adj = distance + 1;
                //if dist_to_adj is less than the current steps taken to reach this node then we set this minimum value
                //NORMAL dijkstra algorithm
                if(dist_to_adj < dist[adj_node]){
                    dist[adj_node] = dist_to_adj;
                    //also push this to the adj
                    pq.push({dist_to_adj, adj_node});
                }
            }
        }
        
       }
       //if n*n-1 node is not reachable we return -1
       if(dist[n*n-1] == INT_MAX)return -1;
       //if reachable we return the value of that node 
       return dist[n*n -1 ];

    }
public:
    int snakesAndLadders(vector<vector<int>>& board) {
        return dijkstra_algorithm(board);
    }
};
