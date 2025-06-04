/*

    INTUTION:
        try to draw the questino asked using graph

        it is saying we can visit a node if it's status =1 so lets'say we have been given initialBoxes as [0]
        we start from there  if status of 0 is 1 then we take it and try to go to it's all containedBoxes if, the status is 0 we can't take this box 
        we will save this box inside a set so that if we later get the key then we can visit this box,
        we are using visited as well as set because we can visit a node just once and therfore using visited and set


        this problem looks like graph traversal we can use either approach bfs dfs to solve it

        what we can do is we can take the current node, then try to go to it's contained node(like it is it's neigbhour) and finally we try to see the keys contained in the current node and if that node has been seen aka we tried to visit it but it wasn't open then we use the key and open and do the dfs on this node

*/
class Solution {
private:

    //using DFS approach
    int dfs(int pos, vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, unordered_set<int>&  st, vector<int>& visited){
        //if can't be opened
        if(status[pos] == 0){
            //we are inserting in a set, so that in can be accessed only once since once we eat the candies there is nothign to be eaten
            st.insert(pos);
            //return 0
            return 0;
        }
        //we are marking this box as visited, so that we visit a box just once, since if we eat all the candies of a box and when we come again
        //there won't be any candies
        visited[pos] = 1;
        int tot_candies = 0;
        tot_candies+=candies[pos];
        
        //we will try to go it's all neihbours, which are containedBoxes
        for(auto box: containedBoxes[pos]){
            //if not visit then visit this node
            if(!visited[box]){
                tot_candies+=dfs(box, status, candies, keys, containedBoxes, st, visited);
            }
        }
        //now we will have the keys we will see if we have already seen the box,  we now found the key we will try to visit it now
        for(int key: keys[pos]){
            //this line should always be here
            //**IMP**, to set the status 1
            status[key] = 1;
            //if found key node is not visited yet and we have seen it when it's status was 0 we can now see
            if(!visited[key] && st.find(key)!= st.end()){
                tot_candies+=dfs(key, status, candies, keys, containedBoxes, st, visited);
            }
        }

        return tot_candies;
    }

public:
    int maxCandies(vector<int>& status, vector<int>& candies, vector<vector<int>>& keys, vector<vector<int>>& containedBoxes, vector<int>& initialBoxes) {


        //dfs


        
        
        int n = status.size();
        vector<int> visited(n, 0);
        unordered_set<int> st;
        int  final_ans = 0;
        for(int el: initialBoxes){
            // if(status[el] == 0)st.insert(el);
            final_ans+=dfs(el, status, candies, keys, containedBoxes,st, visited);

        }
        return final_ans;
        
    }
};
