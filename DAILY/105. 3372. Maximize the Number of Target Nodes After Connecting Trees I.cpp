class Solution {
private:
    int dfs(int root, vector<vector<int>>& adj_list, int till_level){
        int el_count = adj_list.size();
        vector<int> vis(el_count, 0);
        // cout<<root<<" "<<till_level<<endl;
        queue<int> q;
        q.push(root);
        vis[root] = 1;
        //initially we have one node in the queue
        int node_count = 1;
        int level = 0;
        if(till_level == level)return node_count;
        //traversing for all required levels
        while(!q.empty() && till_level > level){
            int count_element = q.size();
            for(int i = 0; i<count_element; i++){
                int front = q.front();
                q.pop();
                for(int adj: adj_list[front]){
                    if(!vis[adj]){
                        vis[adj] =1;
                        q.push(adj);
                        node_count++;
                    }
                }
            }
            level++;
        }
        // cout<<"node_count"<<node_count<<endl;
        return node_count;
    }
    vector<int> sol(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k){


        int n = edges1.size();  //i.e 0-to n since here we are getting edges count
        int m = edges2.size(); //0-m
         //base case
        if(k == 0){
            
            vector<int> ans_base_case(n+1, 1);
            return ans_base_case;
        }
        int tree_2_max_el = INT_MIN;
        //since m+1 nodes from 0 to m 
        vector<vector<int>> adj_list_tree2(m+1);
        vector<int> degree_counter_tree2(m+1, 0);
        for(auto &edge: edges2){
            //since undirected
            adj_list_tree2[edge[0]].push_back(edge[1]);
            adj_list_tree2[edge[1]].push_back(edge[0]);
            degree_counter_tree2[edge[0]]++;
            degree_counter_tree2[edge[1]]++;
        }
        vector<pair<int,int>> degree_node;
        for(int i=0; i<=m; i++){
            //push the node value and the node
            degree_node.push_back({degree_counter_tree2[i], i});
        }
        //sort the degree_counter_tree
        sort(degree_node.begin(), degree_node.end(), greater<pair<int,int>>());
        int top = degree_node[0].first;
        int pos = 0;
        //-1 since 1 edge will be used in connecting the tree 1 to tree 2
        //also trying when k-1 >= 1 since if it's just 1 the node from tree2 will be just 1 the reason for that edge will connect only one node in that tree 
        if(k-1 >= 1){
            //trying for all node whose degree is maximum degree of tree2 since there could be multiple node which have maximum degree
            while(pos <= m && degree_node[pos].first == top){
                //pass the root node, adj_list and level till which we have to see
                int curr_count = dfs(degree_node[pos].second, adj_list_tree2, k-1);
                // cout<<"curr_count "<<curr_count<<endl;
                tree_2_max_el = max(tree_2_max_el, curr_count);
                pos++;
            }
        }
        else{
            tree_2_max_el = 1;
        }
        vector<vector<int>> adj_list_tree1(n+1);
        for(auto &edge: edges1){
            //since undirected
            adj_list_tree1[edge[0]].push_back(edge[1]);
            adj_list_tree1[edge[1]].push_back(edge[0]);
        }
        vector<int> ans(n+1, tree_2_max_el);
        for(int i=0; i<=n; i++){
           int node_in_tree_1_for_i =dfs(i, adj_list_tree1, k);
        //    cout<<"node "<<i<<" "<<node_in_tree_1_for_i<<endl;
           ans[i]+=node_in_tree_1_for_i;
        }

        return ans;
    }

    /*
        direct approach->
            we are finding all the nodescounts which are at distance <=k in tree1 from each node
            in tree we are finding all the nodecounts which are at a distance of k-1 from each node since 1 edge will be used for connecting tree from one node to other.


            now we are sorting the tree2 count count because we will always connect tree1 each time to the node in tree2 which have largest number of nodes at distance k-1 and hence in the answer we are adding first element from tree2 node count of each node 
    
    
    */
    vector<int> sol_2(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k){
        int n = edges1.size();  //i.e 0-to n since here we are getting edges count
        int m = edges2.size(); //0-m
        vector<int> ans(n+1, 0);
        if(k == 0){
            fill(ans.begin(), ans.end(), 1);
            return ans;
        }
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
        vector<int> target_count_tree2(m+1, 0);
        //gettting nodes from vector 2;
        for(int i =0; i<=m; i++){
            target_count_tree2[i] = dfs(i,adj_list_tree2, k-1);
        }
        sort(target_count_tree2.begin(), target_count_tree2.end(), greater<int>());
        for(int i =0; i<=n; i++){
            int node_count_in_tree_1_for_node_i = dfs(i, adj_list_tree1, k);
            ans[i]= node_count_in_tree_1_for_node_i + target_count_tree2[0];
        }
        return ans;
    }
public:
    vector<int> maxTargetNodes(vector<vector<int>>& edges1, vector<vector<int>>& edges2, int k) {
        // return sol(edges1, edges2, k);
        return sol_2(edges1, edges2, k);
    }
};
