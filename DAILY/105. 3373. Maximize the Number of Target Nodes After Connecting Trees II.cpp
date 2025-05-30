class Solution {
private:
//giving TLE , helper function
/*
    using approach of github/DAILY/105. 3372. Maximize the Number of Target Nodes After Connecting Trees I
    simple trying to do bfs travesal in the tree2 to get the maximum value of all the nodes bfs traversal and in first tree doing bfs traversal at each node.


*/
    int bfs(int root, vector<vector<int>>& adj_list, bool require_even_level){
        int el_count = adj_list.size();
        vector<int> vis(el_count, 0);
        queue<int> q;
        q.push(root);
        vis[root] = 1;
        //initially we have one node in the queue
        int node_count = 0;
        //if require even level node then add the root node
        if(require_even_level)node_count++;
        //level
        int level = 0;
        //traversing for all required levels
        while(!q.empty()){
            int count_element = q.size();
            for(int i = 0; i<count_element; i++){
                int front = q.front();
                q.pop();
                for(int adj: adj_list[front]){
                    if(!vis[adj]){
                        vis[adj] =1;
                        q.push(adj);
                        //if even level 
                        if(level%2 == 1 && require_even_level)node_count++;
                        if(level%2 == 0  && !require_even_level)node_count++;
                    }
                }
            }
            level++;
        }
        return node_count;
    }
//giving TLE
    vector<int> sol_1(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
        int n = edges1.size();  //i.e 0-to n since here we are getting edges count
        int m = edges2.size(); //0-m
        vector<int> ans(n+1, 0);
        //since m+1 nodes from 0 to m 
        vector<vector<int>> adj_list_tree2(m+1);
        for(auto &edge: edges2){
            //since undirected
            adj_list_tree2[edge[0]].push_back(edge[1]);
            adj_list_tree2[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> adj_list_tree1(n+1);
        for(auto &edge: edges1){
            //since undirected
            adj_list_tree1[edge[0]].push_back(edge[1]);
            adj_list_tree1[edge[1]].push_back(edge[0]);
        }
        // vector<int> target_count_tree2(m+1, 0);
         //we will get the maximum value from tree2
        int tree_2_max_value = INT_MIN;
        //gettting nodes from vector 2;
        for(int i =0; i<=m; i++){
            //here we are getting the maximum value from tree2, also we are passing we don't require even level nodes since, when the first tree connect with second tree, the node to which the first tree will be connected will be an odd node and hence not required to be taken
            tree_2_max_value = max(tree_2_max_value,bfs(i,adj_list_tree2, 0));
        }

        //bfs traversal for each node of tree1
        for(int i = 0; i<=n; i++){
            //we are saying that we need to take even level nodes
            int node_count_in_tree_1_for_node_i = bfs(i, adj_list_tree1, 1);
            ans[i]+=node_count_in_tree_1_for_node_i;
            ans[i]+=tree_2_max_value;
        }
        return ans;
    }

//ACCORDING TO CODEWITHMIK

//helper function sol2
/*
    this function does bfs traversal for each tree,
    focus there is one variable is_tree1

    when the tree is tree1 we are doing few additional thing and in is_tree1 is true case we are using ans_vector;


    the return value of the bfs_travesal which find the maximum value i.e if even position node or odd_position are grater, this value is being used in tree2 only
    because there we just need the maximum of odd_position node or even_position node.
    Reason -> let's say we mark the entire tree  one level as O and next level as 1 and next level 0 and next 1 and so on ...
    we also count the number of nodes marked with 1 and no of nodes marked with 0 , 
    now let's say 0 marked node count  is greater, then we need to connect the tree1 to a 1  position node because it will not take the 1 position nodes and will take the 0 position nodes, if 1 count of nodes were greater then we needed to connect 
    tree1 at 0 position so that it takes all the 1 position marked nodes
    and hence we just return the maximum of (0 marked count node , 1 marked count node)


    in case of tree1 let's say tree is like

    0 ----- 1 ---- 2----6
    |\       |
    | \      |
    |  \     5
    3   4 

now we start marking 0 position  node  as O marked node and it's neigbour as 1 and it's neigbour as 0 and so on 

marking 
node ->      0 1 2 3 4 5 6
marking->    0 1 0 1 1 0 1


for 0th node -> it's neighbour at even distance from it -> 0, 2 5    (0 since self is also included )
for 1st node -> it's neighbour at even distance from it -> 1 6 3 4 
for 2nd node -> it's neighbour at even distance from it -> 2 0 5 
for 3rd node -> it's neighbour at even distance from it -> 3 1 4 6 
for 4th node -> it's neighbour at even distance from it -> 4 1 3 6
for 5th node -> it's neighbour at even distance from it -> 5 0 2 


so if we note the pattern the node which are marked 0 it's neigbhour are all nodes marked 0 
similarly for node marked 1 it's neigbhour are all node marked 1 and 
hence in the below function if is_tree1 is true then we are doing same
we are marking the node to be 0 or 1 and then once the bfs is done and we have the count of node_marked 1 and count node_marked_0 
we make node marked 1 = count_node_marked_1
*/
int bfs_traversal(vector<vector<int>>& adj_list, vector<int>& ans, bool is_tree1){
    int n = adj_list.size();
    vector<int> vis(n,0);
    //node and if the node is 0 or 1
    queue<pair<int,int>> q;
    vis[0] =1;
    q.push({0,0});
    //count node which are marked 0
    int zero_counter = 0; 
    //count node which are marked 1
    int one_counter = 0;

    //normal bfs travesal of a graph since it's a undirected tree and undirected tree is a graph
    while(!q.empty()){

        //get the front node and it's level node_val i.e 0 or 1
        int node = q.front().first;
        int node_val = q.front().second;
        //remove the node
        q.pop();
        //usefull only for tree 1;
        //if it is tree1 then mark whether this node is marked 0 or 1
        if(is_tree1)ans[node] = node_val;
        //if current node is marked 0 then increase zero_counter value
        if(node_val == 0)zero_counter++;
        if(node_val == 1)one_counter++;

        //proceesing current node adjacent node
        for(int adj: adj_list[node]){
            //if it is node visited since bfs means bad m marking visited
            if(!vis[adj]){
                //mark it as visited 
                vis[adj] = 1;
                //push the adjcent node by marking opposite of what it is marked for current node
                q.push({adj, !node_val});
            }
        }
    }

    //specifically for tree1
    //we are makring in the ans array where there is 0 the zero_counter value and node which is marked as 1  one_counter value
    if(is_tree1){
        for(int i =0; i<n; i++){
            if(ans[i] == 0)ans[i] = zero_counter;
            else ans[i] = one_counter;
        }
    }
    //returning the maximum of one_counter or zero_counter this will be used for tree2
    return max(one_counter, zero_counter);

}

/*


*/
vector<int> sol2(vector<vector<int>>& edges1, vector<vector<int>>& edges2){
        int n = edges1.size() + 1;  //i.e 0-to n since here we are getting edges count
        int m = edges2.size() + 1; //0-m
        vector<int> ans(n, 0);
        //Creating adjaceny list for both trees
        vector<vector<int>> adj_list_tree2(m);
        for(auto &edge: edges2){
            //since undirected
            adj_list_tree2[edge[0]].push_back(edge[1]);
            adj_list_tree2[edge[1]].push_back(edge[0]);
        }
        vector<vector<int>> adj_list_tree1(n);
        for(auto &edge: edges1){
            //since undirected
            adj_list_tree1[edge[0]].push_back(edge[1]);
            adj_list_tree1[edge[1]].push_back(edge[0]);
        }

        /*
            DEALING WITH TREE 1->

            we are marking the node of three as 0 or 1 since 0 neigbhour will be marked as 1 and 1 neigbhour will be marked as 0,
            and therfore we are marking each node to be 0 or 1, and the count of nodes which are marked 0 will have that much of nodes at even distance in tree1
        
        */
        bfs_traversal(adj_list_tree1, ans, 1);

        //doing for tree2, the ans will not be used at all, so passing it but won't be used
        //0 represent it is tree2
        int to_be_added = bfs_traversal(adj_list_tree2, ans, 0);
        for(int i =0; i<n; i++){
            ans[i]+=to_be_added;
        }
    return ans;
}
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2) {
        // return sol_1(edges1, edges2);

        return sol2(edges1, edges2);
    }
};
