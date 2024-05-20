https://www.geeksforgeeks.org/problems/shortest-path-in-weighted-undirected-graph/1
/*
  description : 
    normal dijsktra using set,
    **important -> here we require path , so for that we are usign a parent array,
    where a node will say tell about it's parent in this way we can find the path in backward directions from the destination node and travelling backward
    we will initally store each node as it's parent itself,
    if we while coming back find , that a node value which says it's parent is 1 then we have found the path, from destination node by finding parent and going to that node a
    if we found a parent[i] value same as i it means there is no path from here backward it means the graph is disconnected it means no path
    since the we are travesing backward we will store in stack for easy and better time complexity

    in answer vector they want the first element to be the path distance so finally we will store that as well after everthign is done
*/
class Solution {
    private:
        vector<int> sol(int n, int m, vector<vector<int>>& edges){
            
            //here it is in form of <node, edge weight>
            vector<vector<pair<int,int>>> adj_list(n+1);
            for(auto it: edges){
                adj_list[it[0]].push_back({it[1],it[2]});
                adj_list[it[1]].push_back({it[0],it[2]});
            }
            /**important learning **/
            //for storing the required path we will take a array of size no of nodes
            //each node will remember it's parent in this way we can get the entire path
            //eg. we will go to 5, it will say my parent is 3 , we will go to 3 , 3 will say my parent is 1 , and hence wewill get the path 1->3->5
            vector<int> parent(n+1);
            //we are storing that intially the parent is themselves
            for(int i = 1 ; i<=n ; i++)parent[i]= i;
            
            //normal djikstra algorithm
            vector<int> dist(n+1, INT_MAX);
            //since 1 is the start node
            dist[1] = 0;
            //using set for better time complexity since weights of edge are different so store in sorted order so smaller get processed first
            set<pair<int,int>> st;
            //format {distance,node}
            st.insert({0,1});
            while(!st.empty()){
                auto front = *(st.begin());
                int distance = front.first; 
                int node  = front.second;
                st.erase(front);
                //trying to travese each of it's neighbour
                for(auto it: adj_list[node]){
                    int distance_to_it_node = distance + it.second;
                    if(distance_to_it_node < dist[it.first]){
                        dist[it.first] =distance_to_it_node;
                        st.insert({distance_to_it_node,it.first});
                        //also saving it's parent
                        parent[it.first] = node;
                    }
                }
            }
            
            
            //now we will have parent values in parent vector;
            //since we will start coming back from 5 to it's parent then and so on so we will stack to store the element in reverse order
            stack<int> stck;
            //since we will start from n going backwards
            stck.push(n);
            //will break inside conditionally
            while(true){
                //current node parent
                int par = parent[stck.top()];
                //if current node parent is 1 then we we have the entire ans pushed in the stack so push 1 and break
                if(par == 1){
                    stck.push(1);
                    break;
                }
                //since coming here it means par is not 1
                //it means it has no parent it means no path to reach to 1 in back direction frm here
                else if(par == stck.top())
                    return {-1};
                else 
                    stck.push(par);
            }
            vector<int> ans;
            while(!stck.empty()){
                ans.push_back(stck.top());
                stck.pop();
            }
            ans.insert(ans.begin(),dist[n]);
            return ans;
            
        }
    
      public:
        vector<int> shortestPath(int n, int m, vector<vector<int>>& edges) {
            return sol(n,m, edges);
        }
};
