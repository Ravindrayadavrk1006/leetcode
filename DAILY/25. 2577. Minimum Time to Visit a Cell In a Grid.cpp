class Solution {
private:

    ///GIVING TLE
    //THIS SOLUTION IS A REMINDER!!!!!!!!!!!!!! NEVER USE SET IN DIJKSTRA OF VARIABLE EDGE LENGTH I.E NON UNIT LENGTH EDGES , BUT ALWAYS USE PRIORITY QUEUE INSTEAD
    int solDijkstra(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<bool>> visited(m, vector<bool>(n, false));
        // queue<pair<int,int>> q;
        set<pair<int,pair<int,int>>> q;
        q.insert({0,{0,0}});
        vector<int> neigh = {0,-1,0,1,0};
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        dist[0][0] = 0;
        visited[0][0] = true;
        cout<<"m,n"<<m<<n<<endl;
        //handle one case
        if(grid[0][1]>1 && grid[1][0]>1)return -1;
        while(!q.empty()){
            // pair<int,int> front = q.front();
            auto front = *(q.begin());
            int curr_d  = front.first;
            int row = front.second.first;
            int col = front.second.second;
            if(row == m -1 && col == n-1 )return curr_d;
            q.erase(front);
            cout<<row<<" "<<col<<" dist "<<curr_d<<endl;
            cout<<"pushing neighbours"<<endl;
            
            for(int i = 0; i<4; i++){
                int adj_row = row + neigh[i];
                int adj_col = col + neigh[i+1];
                if(adj_row>=0 && adj_row<m && adj_col >=0 && adj_col<n && !visited[adj_row][adj_col]){
                    // dist[row][col]+1 < dist[adj_row][adj_col] && dist[row][col]+1 >= grid[adj_row][adj_col]
                    if(curr_d +1 >= grid[adj_row][adj_col] && curr_d +1 < dist[adj_row][adj_col]){
                        cout<<"+1  "<<adj_row<<" "<<adj_col<<endl;
                        dist[adj_row][adj_col] = dist[row][col] +1; 
                        q.insert({curr_d +1, {adj_row, adj_col}});
                        visited[adj_row][adj_col] = true;
                    }
                    else if(curr_d +1 < grid[adj_row][adj_col] &&  grid[adj_row][adj_col] < dist[adj_row][adj_col]){
                        // cout<<"+grid   "<<adj_row<<" "<<adj_col<<endl;
                        int to_add = 0;
                        if((grid[adj_row][adj_col]- curr_d)%2 == 0 )to_add = 1;
                        // if(grid[adj_row][adj_col]%2 == 0 && curr_d %2 == 0) to_add = 1;
                        // else if(grid[adj_row][adj_col]%2 != 0 && curr_d %2 != 0)to_add = 1;
                        dist[adj_row][adj_col] = grid[adj_row][adj_col] + to_add ;
                        q.insert({grid[adj_row][adj_col]+to_add, {adj_row, adj_col}});
                        visited[adj_row][adj_col] = true;
                    }
                }

                
            }
            cout<<"end"<<endl;

        }
        // cout<<dist[m-1][n-1]<<endl;
        if(dist[m-1][n-1] == INT_MAX)return -1;
        return dist[m-1][n-1]  ;
    }


    int sol2DijkstraUsingPriorityQ(vector<vector<int>>& grid){
        int m = grid.size();
        int n = grid[0].size();
        vector<vector<int>> dist(m, vector<int>(n, INT_MAX));
        priority_queue<pair<int,pair<int,int>>, vector<pair<int,pair<int,int>>>, greater<pair<int,pair<int,int>>>> pq;

        if(grid[0][1] > 1 && grid[1][0]>1)return  -1;
        dist[0][0] = 0;
        pq.push({0,{0,0}});
        vector<int> neigh = {0,-1,0,1,0};
        while(!pq.empty()){
            auto top = pq.top();
            int curr_d = top.first;
            int row = top.second.first;
            int col = top.second.second;
            //here return statement also works fine,since smaller distance will be first processed so it will be always correct
            // if(row == m-1 && col == n-1)return curr_d;
            pq.pop();
            //trying to push all it's neighbours
            
            for(int i =0; i<4; i++){
                int adj_row = row+neigh[i];
                int adj_col = col + neigh[i+1];

                //WORKING CODE
                // //if element out of grid don't do anything
                if(adj_row<0 || adj_col <0 || adj_row>=m || adj_col >= n)continue;
                //normally do it

                /*
                    note here is the important part of the code

                    directions -> here grid[i][j] is the cell we have to go to
                    they are saying that if we can go a node at time greater than or equal to grid[i][j]
                    it means if our time to reah this node is curr_d +1 >= grid[i][j] then we can reach in curr_d +1,
                    if it's not the case it means to reach grid[i][j] we have to wait , but we can't wait but we can spend the time by oscillating with the neighbours , this part of code is written in else if and else case
                        if we reach the current node at a even distance and then going to a grid[i][j] which is even then we have to spend +1 + grid[i][j] , also if both are odd then also same
                if curr_d,grid[i][j] is (even,odd) or vice versa then we can reach in same time


                let's see

                1 3
                1 5

                let's suppose we are standing at 1,0 in above grid with curr_d = 1;
                we can't go to (1,1) since it's distance is 5 but we can oscillate between (1,0) and (0,0) to spent that time , 

                from (1,0)-> (0,0) curr_d = 2;
                oscillating back
                from (0,0)-> (1,0) curr_d = 3
                still not possible to go to (1,1)
                let's go back again to (0,0)
                (1,0) -> (0,0) -> curr_d = 4
                now will have to come back again to (1,0)
                (0,0) -> (1,0) -> curr_d = 5
                now our time is ripe we can go to (1,1) since curr_d +1 >= grid[i][j] 
                to reach there we need curr_d +1 i.e 6 which grid[i][j] +1;

                similary when curr_d & grid[i][j] are both even then also we will require
                grid[i][j] +1;


                whereas suppose the grid was

                1 3
                1 6
                then check 
                curr_d at (1,0 ) would be 1
                then let's try to ossilate
                 from (1,0)-> (0,0) curr_d = 2;
                 from (0,0)-> (1,0) curr_d = 3
                 from (1,0)-> (0,0) curr_d = 4;
                 from (0,0)-> (1,0) curr_d = 5

                 now we curr_d +1 >= grid[i][j]  i.e  5+1 >= 6
                 i.e we can reach the grid[i][j] at grid[i][j] value time



                here in below code to write this logic we are using
                odd -odd = even
                even - even = even
                even-odd = odd
                odd -even  = odd
                hence using this logic writing
                if diffence is even this means we will reach that node in grid[i][i] +1
                if diffrenece is odd then we can reach to that node in grid[i][j] time 

                writing the same in the below uncommented code 
                the commented code has bare logic of noraml if both are even , if both are odd  
                
                */
                int current_time;
                int diff = grid[adj_row][adj_col] - curr_d;
                if(curr_d +1 >= grid[adj_row][adj_col])current_time = curr_d +1;
                else if(diff %2 == 0)current_time = grid[adj_row][adj_col] +1;
                else current_time = grid[adj_row][adj_col];
                if(current_time < dist[adj_row][adj_col]){
                    dist[adj_row][adj_col] = current_time;
                    pq.push({current_time, {adj_row, adj_col}});
                }

            }
            


            // for(int i = 0; i<4; i++){
            //     int adj_row = row + neigh[i];
            //     int adj_col = col + neigh[i+1];
            //     if(adj_row>=0 && adj_row<m && adj_col >=0 && adj_col<n){
            //         // dist[row][col]+1 < dist[adj_row][adj_col] && dist[row][col]+1 >= grid[adj_row][adj_col]
            //         if(curr_d +1 >= grid[adj_row][adj_col] && curr_d +1 < dist[adj_row][adj_col]){
            //             cout<<"+1  "<<adj_row<<" "<<adj_col<<endl;
            //             dist[adj_row][adj_col] = dist[row][col] +1; 
            //             pq.push({curr_d +1, {adj_row, adj_col}});
            //             // visited[adj_row][adj_col] = true;
            //         }
            //         else if(curr_d +1 < grid[adj_row][adj_col] &&  grid[adj_row][adj_col] < dist[adj_row][adj_col]){
            //             // cout<<"+grid   "<<adj_row<<" "<<adj_col<<endl;
            //             int to_add = 0;
            //             if((grid[adj_row][adj_col]- curr_d)%2 == 0 )to_add = 1;
            //             // if(grid[adj_row][adj_col]%2 == 0 && curr_d %2 == 0) to_add = 1;
            //             // else if(grid[adj_row][adj_col]%2 != 0 && curr_d %2 != 0)to_add = 1;
            //             dist[adj_row][adj_col] = grid[adj_row][adj_col] + to_add ;
            //             pq.push({grid[adj_row][adj_col]+to_add, {adj_row, adj_col}});
            //             // visited[adj_row][adj_col] = true;
            //         }
            //     }

                
            // }

        }
        return dist[m-1][n-1];
        //code will never reach here
        return -1;

    }
public:
    int minimumTime(vector<vector<int>>& grid) {
        // return solDijkstra(grid);

        return sol2DijkstraUsingPriorityQ(grid);
    }
};
