https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM
/*
	explanation : nothing normal dijkstra using normal queue , since it is unweighted graph so normal queue will give same tc as min heap or set
 	we are storing the in form of a list , eg {1} , if the current node is 1
  	{1,4,5} i.e the came from 1 to 4 to 5 and current node is 5 . 
   	so in this way we store the required node which is last elemnt and since the distance is unit distance so , not required to mention the distance
    also we are mentioning the distance of each node in dist array


*/
#include <bits/stdc++.h>
using namespace std;
vector<int> smallest_path(vector<pair<int,int>>& edges , int n , int m, int s , int t){
	vector<vector<int>> adj_list(n+1);
	for(auto it: edges){
		adj_list[it.first].push_back(it.second);
		adj_list[it.second].push_back(it.first);
	}
	queue<vector<int>> q;
	q.push({s});
	vector<int> dist(n+1, INT_MAX);
	dist[s] = 0 ;
	while(!q.empty()){
		auto front_list = q.front();
		int last_element = front_list.back();
		q.pop();
		//returning the answer
		if(last_element == t)return front_list;
		for(int adj_el: adj_list[last_element]){
			if(dist[last_element] + 1 < dist[adj_el]){
				dist[adj_el] = dist[last_element] + 1;
				front_list.push_back(adj_el);
				q.push(front_list);
				front_list.pop_back();
			}
		}
	}
	return {};
}
vector<int> shortestPath( vector<pair<int,int>> edges , int n , int m, int s , int t){
	
	return smallest_path(edges,n,m,s,t);
	
}
