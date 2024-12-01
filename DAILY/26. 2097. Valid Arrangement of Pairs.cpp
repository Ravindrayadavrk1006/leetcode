/*
    This is for finding EULER PATH , straight finding euler path 

*/

class Solution {
private:
    int helperBS(int el , vector<vector<int>>& pairs){
        int end = pairs.size() -1;
        int start = 0;
        while(start<=end){
            int mid = (start + end)/2;
            if(pairs[mid][0] == el)return mid;
            if(pairs[mid][0]< el)start = mid+1;
            else end = mid-1;
        }
        return -1;
    }
    int helperBS_1(int el , vector<vector<int>>& pairs){
        int end = pairs.size() -1;
        int start = 0;
        while(start<=end){
            int mid = (start + end)/2;
            if(pairs[mid][1] == el)return mid;
            if(pairs[mid][1]< el)start = mid+1;
            else end = mid-1;
        }
        return -1;
    }

    //SOL 1 
    //IT IS WRONG IN SOME CASES DON'T TRY THIS 


    vector<vector<int>> solValidArrangement(vector<vector<int>>& pairs){
        int n = pairs.size();
        map<int,int> indegree, outdegree;
        set<int> nodes;
        for(auto el: pairs){
            indegree[el[1]]++;
            outdegree[el[0]]++;
            nodes.insert(el[0]);
            nodes.insert(el[1]);
        }
        vector<vector<int>> ans(n);
        cout<<"outdegree"<<endl;
        for(auto el: outdegree){
            cout<<el.first<<" "<<el.second<<endl;
        }
        cout<<"indegree"<<endl;
         for(auto el: indegree){
            cout<<el.first<<" "<<el.second<<endl;
        }
        //finding element whose indegree, outdegree is zero is 0 
        int outzero = -1;
        //it means there is one less element in indegree that is one element is zero
        if(indegree.size() != nodes.size())
        {
            cout<<"zero indegree"<<endl;
            //we have sort is because we need to find also
            sort(pairs.begin(), pairs.end());
            int inzero = - 1;
            auto it = indegree.begin();
            for(auto nodesIt = nodes.begin(); nodesIt != nodes.end(); nodesIt++ ){
               if(*nodesIt != it->first){
                inzero = *nodesIt; 
                break;
               }
               it++;
            }
            for(int i = 0; i<n; i++){
                ans[i] = pairs[helperBS(inzero, pairs)];
                inzero = ans[i][1];
            }
            //now start from there

            return ans;

        }
        else if( outdegree.size() != nodes.size()){
            cout<<"zero outdegree"<<endl;
            int outzero = - 1;
            auto it = outdegree.begin();
            //we have sort is because we need to find also
            sort(pairs.begin(), pairs.end(), [](auto &left, auto &right){
                return left[1]< right[1];
            });
            for(auto nodesIt = nodes.begin(); nodesIt != nodes.end(); nodesIt++ ){
                if(*nodesIt != it->first){
                outzero = *nodesIt; 
                break;
                }
                it++;
            }
            for(int i = n-1; i>=0; i--){
                    ans[i] = pairs[helperBS_1(outzero, pairs)];
                    outzero = ans[i][0];
                }
            return ans;
        }
        else{

            cout<<"none zero"<<endl;
            sort(pairs.begin(), pairs.end());
            int curr = pairs[0][0];
            unordered_map<string,bool> visited;
            for(int i = 0; i<n; i++){
                //issue of visited
                ans[i] = pairs[helperBS(curr, pairs)];
                curr = ans[i][1];
            }
            return ans;
        }
    }

    //SOL 2
    //COPIED FROM OTHER
    //LEARN SOME TRICK IF YOU CAN
    vector<vector<int>> copied_solution(vector<vector<int>>& pairs){
        unordered_map<int, stack<int>> adj;
        unordered_map<int, int> inDegree, outDegree;
        
        for (const auto& pair : pairs) {
            adj[pair[0]].push(pair[1]);
            outDegree[pair[0]]++;
            inDegree[pair[1]]++;
        }
        int start = pairs[0][0];
        for (const auto& [node, _] : adj) {
            if (outDegree[node] > inDegree[node]) {
                start = node;
                break;
            }
        }
        vector<int> path;
        stack<int> stk;
        stk.push(start);

        while (!stk.empty()) {
            int node = stk.top();
            if (!adj[node].empty()) {
                int next = adj[node].top();
                adj[node].pop();
                stk.push(next);
            } else {
                path.push_back(node);
                stk.pop();
            }
        }
        reverse(path.begin(), path.end());
        
        vector<vector<int>> result;
        for (int i = 0; i < path.size() - 1; ++i) {
            result.push_back({path[i], path[i + 1]});
        }

        return result;
    }






    //MY SOLUTION STARTS HERE
    

    //using euler's path concept and using hierhozlers algorithm

    /*
            hierhozlers algorithm

            a graph is a eular path if there exist a path so that we can traverse the entire graph without repeating any edge

            //property all the vertices has equal in and out degree and if there exist at max one vertex  which has out-in = 1 and at max one node has in-out = 1 , the one node where out-in = 1 that will be the starting node, and where in-out = 1 will be ending node if exist otherwise if all have equal in-out degree then any node can be starting and ending node


            here we are finding the starting node and then with that starting node we are doing dfs traversal the dfs traversal here is a bit different,
            we travese all the edges from a node and once all the edges from that node are travesed we push that node in a vector , the reverse of the vector will be our answer because the starting node will be pushed last in the vector


    
    */
    void helperDfs(int node, unordered_map<int,vector<int>>& adjList, vector<int>& st, unordered_map<int,pair<int,int>>& outInDegree)  {

        //travesing all the neighbours from here and then pushing them in stack
        while(outInDegree[node].first != 0){
            int toNode = adjList[node][--outInDegree[node].first];
            helperDfs(toNode, adjList, st, outInDegree);
        }
        st.push_back(node);
    }

    vector<vector<int>> my_sol(vector<vector<int>>& pairs){
        unordered_map<int,vector<int>> adjList;
        //the key is node , the pair in it .first is outdegree , .second is indegree
        unordered_map<int,pair<int,int>> outInDegree;
        unordered_map<int, bool> visited;
        for(auto el: pairs){
            //creating adjlist
            adjList[el[0]].push_back(el[1]);
            //creating indegre and outdegree

            //if the 'FROM' of a pair doesn't exist exist then we create one and add one outgoing edge for it
            if(outInDegree.find(el[0]) == outInDegree.end()){
                outInDegree[el[0]] = {1,0};
            }
            else{
                outInDegree[el[0]].first++;
                // outIndDegree[el[0]] = { outIndDegree[el[0]].first++, outInDegree[el[0]].second };
            }
            if(outInDegree.find(el[1]) == outInDegree.end()){
                outInDegree[el[1]] = {0,1};
            }
            else{
                outInDegree[el[1]].second++;
            }
        }
        //finding the starting node
        int startingNode;
        for(auto el: adjList){
            if(outInDegree[el.first].first - outInDegree[el.first].second  == 1){
                startingNode = el.first;
                break;
            }
            if(outInDegree[el.first].first >0 )startingNode = el.first;
        }

        //here remember stack is just a vector
        vector<int> st;

        //now we will do the dfs traversal and find the solution
        helperDfs(startingNode, adjList, st, outInDegree);
        vector<vector<int>> ans;
        int stSize = st.size();

        //since the start is at last we are forming the edges and storing in the ans
        for(int i = stSize-1; i>0; i--){
            ans.push_back({st[i], st[i-1]});
        }
        return ans;

    }
public:
    vector<vector<int>> validArrangement(vector<vector<int>>& pairs) {
        // return solValidArrangement(pairs);
        // return copied_solution(pairs);


        return my_sol(pairs);
    }
};
