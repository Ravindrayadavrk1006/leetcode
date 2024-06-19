class Solution {
    /*
        explanations: 
			it is dijsktra algorithm with some changes where we count the number of ways here we are starting with the number of ways for node 0 as 1 since we are starting from there 
	apart from counting changes everyting is same. 

	

	we can reach the destination, by different paths and all those different paths can have same smallest distance. By this statement it means we will find ((( (dis + adjW == dist[adjNode]) ))) this condition . 
	
	everything else is normal in the code 	
	

    */
private:
    int sol_no_of_ways(int n, vector<vector<int>>& roads){
        //adjacey list creation
        vector<vector<pair<int,int>>> adj_list(n);
        //inserting into adj list
        for(auto it: roads){
            //it[0] gives in which adj list we have to insert
            adj_list[it[0]].push_back({it[1],it[2]});
            adj_list[it[1]].push_back({it[0],it[2]});
        }

        //create a priority queue 
        //here we are using the priority queue because the weighthed graph is given 
        priority_queue<pair<int,int>, vector<pair<int,int>>, greater<pair<int,int>> > pq;
        //setting LLONG_MAX value as highest value is important instead of INT_MAX
        vector<long long > dist(n,LLONG_MAX);
        //ways are for counting the no of ways for reaching to a node 
        vector<int> ways(n,0);
        //priority queue will start from 0th node with 0 distance 
        //order {distance,node}
        pq.push({0,0});
        dist[0] = 0;
        ways[0]=1;
        int mod = (int)(1e9+7);
        while(!pq.empty()){
            long long dis = pq.top().first;
            int node = pq.top().second;
            pq.pop();
            for(auto it: adj_list[node]){
                int adjNode = it.first; 
                long long adjW = it.second;
                //first time 
                if(adjW + dis < dist[adjNode]){
                    dist[adjNode] = adjW + dis;
                    //also push in pq 
                    pq.push({adjW+dis , adjNode});
                    //this below line means the ways of previous node i.e ways[adjNode] = 1
                    ways[adjNode] = ways[node];
                }
		   //when we find the smallest distance again we add the number of ways we have reach current node to the adjNode 
                else if(dis + adjW == dist[adjNode]){
                    //add the no of ways by which we are reaching currently and no of ways we were reaching earlier 
                    //mod is done to reduce if the value goes too high we can even remove it 
                    ways[adjNode] =( ways[adjNode] + ways[node])%mod;
                }
            }

        }

        return ways[n-1];

    }
public:
    int countPaths(int n, vector<vector<int>>& roads) {
        return sol_no_of_ways(n, roads);
    }
};
