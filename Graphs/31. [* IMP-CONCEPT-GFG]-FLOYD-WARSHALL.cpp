/*
question link : https://www.geeksforgeeks.org/problems/implementing-floyd-warshall2042/1
explanation -> floyd warshall algorithm working is very simple it works by updating updating all the 
nodes to the minimum value by going through(via) all the nodes one by one , in this way we get least value

floyd warshall gives all pair shortest path 

*/
class Solution {
  public:
	void shortest_distance(vector<vector<int>>&matrix){
	    int n = matrix.size();
	    //lets make the -1 values to 1e9 and we will make to -1 while returning we are making to infinite to make similar to our algorithm
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n ; j++){
	            if(matrix[i][j] == -1 )matrix[i][j] = 1e9;
	            //this is done since in adjaceny matrix for raching to itself it takes 0 weights
	            if(i == j )matrix[i][j] = 0;
	        }
	    }
	    //normal floyd warshal algorithm starts here
	    //this via loop is for running through each node
	    for(int via = 0 ; via < n ; via ++){
	       //for all the nodes 
	       for(int i= 0 ; i < n ; i++){
	           for(int j = 0 ; j < n ; j++){
	               matrix[i][j]= min(matrix[i][j],(matrix[i][via]+ matrix[via][j]));
	           }
	       }
	    }
	    
	    
	    //-------floyd warshall algortihm ends here
	    
	    //since we made -1 to 1e9 we need to revert it back hence we will do that
	    for(int i = 0 ; i < n ; i++){
	        for(int j = 0 ; j < n ; j++){
	            if(matrix[i][j] == 1e9 )matrix[i][j] = -1;
	        }
	    }
	}
};
