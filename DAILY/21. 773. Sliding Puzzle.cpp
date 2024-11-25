class Solution {
private:

    /*
        WRONG SOLUTION BECAUSE WE UNDERSTOOD THE PROBLEM WRONG
    */
    vector<int> posChange = {0,-1,0,1,0};
    int ans = INT_MAX;
    bool correctAns(vector<vector<int>> & board){
        int value = 0;
        int pos = 0;
        while(pos<5){
            int row = pos/3;
            int col = pos%3;
            if(board[row][col] != pos+1)return false;
            pos++;
        }
        if(board[1][2] != 0)return false;
        return true;
    }
    void printBoard(vector<vector<int>>& board){
        for(int i = 0; i<2; i++){
            for(int j=0; j<3; j++){
                cout<<board[i][j]<<" ";
            }
            cout<<endl;
        }
        cout<<endl;
        cout<<endl;
    }
    int sol(int pos , vector<vector<int>>& board, int moves){
        if(pos == 6){
            printBoard(board);
            if(correctAns(board))return moves;
            return INT_MAX;
        }
        //normal flow
        int row = pos/3;
        int col = pos%3;
        //without changing
        ans = min(ans, sol(pos+1, board,moves));
        for(int i =0; i< 4; i++){
            int newRow = row + posChange[i];
            int newCol = col + posChange[i+1];
            if(newRow>=0 && newRow<2 && newCol>=0 && newCol<3){
                //swap the positions
                swap(board[row][col], board[newRow][newCol]);
                ans = min(ans, sol(pos+1, board, moves+1 ));
                //swap back to original ones
                swap(board[row][col], board[newRow][newCol]);
            } 
        }
        return ans;
    }

    /*
        here we have to swap and produce all the possible position and each swap is one step and hence we are using normal dfs(beacuse the distance or swap cost is 1 hence unit distance dijstra is being used)
    */
    int sol2(vector<vector<int>>& board){
        //our index are from 0 to 5 and we are storing the adjcent position to each
        //adj[0] states that 0 can be swapped with {1,3}
        vector<vector<int>> adj = {{1,3}, {0,2,4}, {1,5}, {0,4}, {1,3,5}, {2,4}};
        string target = "123450";
        //if visited or not i.e visited array
        set<string> vis;
        //here having queue because instead of priority queue or set because all are at the distance of 1
        queue<string> q;
        string start = "";
        //convert 2d to a string
        for(int i=0; i<2; i++){
            for(int j =0; j<3; j++)start+=to_string(board[i][j]);
        }
        //insert the starting node in the queue
        q.push(start);
        //mark the starting node as visited
        vis.insert(start);
        int step = 0;

        //BFS
        while(!q.empty()){
            int size = q.size();

            //pop all the adjacent node
            while(size--){
                string current = q.front();
                q.pop();

                if(current == target)return step;


                int zero = current.find('0'); //find zero in the string
                //generate the next moves
                for(auto move : adj[zero]){
                    string next = current;
                    swap(next[move], next[zero]);
                    //if not visited yet then insert in the queue and visit it once again
                    if(!vis.count(next)){
                        //mark it visited 
                        vis.insert(next);
                        q.push(next);
                    }
                }
            }
            step++;
        }


        //if reached here then return it
        return -1;
    }
public:
    int slidingPuzzle(vector<vector<int>>& board) {
        // return sol(0,board, 0);

        return sol2(board);
    }
};
