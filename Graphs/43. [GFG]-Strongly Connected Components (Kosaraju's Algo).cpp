/*
    approach is explained in the CP notebook by name of Strongly Connected Component (SCC) using kosaraju's algorithm 
    
    
    procedure:
        1.first do normal dfs and store the elements in a stack with st.push when a node's all neigbours are treavesed using dfs, i.e when backtracking
        2.reverse all the edges and form a adj_list named adjT which is adjaceny transpose
        3. we will have all nodes as non-visited and  now perform the dfs and only perform for those which are not visited , we will perform dfs for all the elemnts of stack
        
        


*/
class Solution
{
    private:
        void dfs(int node, vector<int>& vis, vector<vector<int>>& adj, stack<int> & st){
    	    //we are making it visited since in the second dfs we need to mark the element as visited
    	    vis[node] =1;
    	    for(auto adj_node: adj[node]){
    	        if(!vis[adj_node]){
    	            dfs(adj_node,vis,adj,st);
    	        }
    	        
    	    }
    	    st.push(node);
	    }
    	//in this dfs we don't need to push to stack hence removed
    	void dfsT(int node, vector<int>& vis, vector<vector<int>>& adjT){
    	    //we are making it visited since in the second dfs we need to mark the element as visited
    	    vis[node] =1;
    	    for(auto adj_node: adjT[node]){
    	        if(!vis[adj_node]){
    	            dfsT(adj_node,vis,adjT);
    	        }
    	        
    	    }
    	}
	public:
	//Function to find number of strongly connected components in the graph.
	//adjaceny list is given 
        int kosaraju(int V, vector<vector<int>>& adj)
        {
            vector<int> vis(V,0);
            stack<int> st;
            for(int i = 0; i<V; i++){
                if(!vis[i]){
                    dfs(i,vis,adj,st);
                }
            }
            
            //storing the reversed or traspose of the graph
            vector<vector<int>> adjT(V);
            for(int i=0; i<V; i++){
                //we are setting the visited elements to false since we require in the dfs call empty
                vis[i] = 0;
                for(int el: adj[i]){
                    //the edge was i->el
                    // we are doing el->i
                    adjT[el].push_back(i);
                }
            }
            int countSCC = 0;
            //now third step performing dfs on this reversed graph
            while(!st.empty()){
                int top = st.top();
                st.pop();
                if(!vis[top]){
                    //number of times scc travesal is done that number of scc are present
                    countSCC++ ;
                    //see here we are doing travesal in adjTransponse 
                    dfsT(top,vis,adjT);
                    
                }
            }
            return countSCC;
        }
};
