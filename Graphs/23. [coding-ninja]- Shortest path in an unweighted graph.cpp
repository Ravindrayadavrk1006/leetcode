https://www.naukri.com/code360/problems/shortest-path-in-an-unweighted-graph_981297?leftPanelTabValue=PROBLEM
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
