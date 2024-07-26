/*
    since here elements are in different format so from the accounts array  for simply naming each elements we are using the element position in the accounts array 
    
    
    
    solution 1. approach -> 
        approach is simple using the core disjoint set appraoch , we check ds.findPar(u,par,rank) != ds.findPar(v,par,rank) && accounts[u][0]== accounts[v][0] && hasCommonMail(accounts[u], accounts[v] if the parent are different and if name is same and if have atleast one common email then we join the nodes.

    now for the joined nodes we store the mails in a hashmap where node is all having common parent node will be inserted in a set since we need in sorted order.
    after this is done then we have all the related mail in location, the elements which have different parent will be stored separetely in the map.
    

    finally we fetch the elements of each node map set and then add the node first element in starting and add the set elements after that and save it in answer vector and return it 



    solution 2. approach ->

         here we are assigning mails to their respective node by inserting mails in the map and it's value will be node , 
        if a mail is coming which is already inserted into the node it means it is reapparing in some other node and hence we need to join these two nodes and hence we do union.
        since these two nodes are joined we will have a common parent for these two nodes.

        now we will insert all the comman parent mails into one list
        so we travese all the elements of map and we ultimate parent of each node which is value of map mails. if they have common ulitmate parent we insert mail into common parent mail list


        now we have all the mails of common parentts together and now we just need to sort it and attach the name at the beginning of these list and then insert into the answer


        so in the final loop we are traversing throught each of these mail list , sorting them since sorting is required , if there are no mail in any list then we don't push into the answer.
        we also insert the name to whom these mail belong before inserting all these sorted mail for that name

*/
class DisjointSet{
    public:

        int findPar(int node, vector<int>& par, vector<int>& rank){
            if (node == par[node])return node;
            //normal cases
            return par[node] = findPar(par[node],par,rank);
        }
        void unionByRank(int u, int v,vector<int>& par, vector<int>& rank){
            int ult_u = findPar(u,par,rank);
            int ult_v = findPar(v,par,rank);
            if(ult_u == ult_v )return ;
            //normal cases
            if(rank[ult_v]< rank[ult_u]){
                par[ult_v] = ult_u;
            }
            if(rank[ult_u]< rank[ult_v]){
                par[ult_u] = ult_v;
            }
            if(rank[ult_v] == rank[ult_u]){
                par[ult_v] = ult_u;
                rank[ult_u]++ ;
            }
        }
};
class Solution {
private:
//solution 1 function
    // bool hasCommonMail(vector<string>& u, vector<string>& v){
    //     for(int i = 1 ; i<u.size(); i++){
    //         for(int j = 1 ; j<v.size();j++){
    //             if(u[i] == v[j])return true;
    //         }
    //     }
    //     return false;
    // }
public:
    /*solution 1 is giving TLE for last 4 test cases */
    // vector<vector<string>> accountsMerge(vector<vector<string>>& accounts) {
    //     int n = accounts.size();
    //     vector<int> rank(n,0);
    //     vector<int> par(n);
    //     for(int i=0; i<n; i++)par[i]=i;
    //     DisjointSet ds = DisjointSet();
    //     for(int u = 0 ; u<n; u++){
    //         for(int v=0; v<n; v++){
    //             if(ds.findPar(u,par,rank) != ds.findPar(v,par,rank) && accounts[u][0]== accounts[v][0] && hasCommonMail(accounts[u], accounts[v])){
    //                 ds.unionByRank(u,v,par,rank);
    //             }
    //         }
    //     }

    //     //now we will store the elements with command parents in one position
    //     map<int,set<string>> mp;
    //     for(int i =0 ; i<n; i++){
    //         for(int j=i+1; j<n;j++){
    //             if(par[i]==par[j]){
    //                 //join the elements together and push_back
    //                 // for(int a=1; a<accounts[i].size();a++){
    //                 //     mp[par[i]].insert(accounts[i][a]);
    //                 // }
    //                 //same as above commented code 
    //                 mp[par[i]].insert(accounts[i].begin()+1,accounts[i].end());
    //                 // for(int a=1 ; a<accounts[j].size();a++){
    //                 //     mp[par[i]].insert(accounts[j][a]);
    //                 // }
    //                 //same as above commented code 
    //                 mp[par[i]].insert(accounts[j].begin()+1,accounts[j].end());
    //             }
    //             else{
    //                 if(mp.find(par[i]) == mp.end()){
    //                     // for(int a=1; a<accounts[i].size();a++){
    //                     // mp[par[i]].insert(accounts[i][a]);
    //                     // }
    //                     mp[par[i]].insert(accounts[i].begin()+1,accounts[i].end());
    //                 }
    //                 if(mp.find(par[j]) == mp.end()){
    //                     // for(int a=1; a<accounts[j].size();a++){
    //                     // mp[par[j]].insert(accounts[j][a]);
    //                     // }
    //                     mp[par[j]].insert(accounts[j].begin()+1,accounts[j].end());
    //                 }
    //             }
    //         }
    //     }

    //     //
    //     vector<vector<string>> ans;
    //     for(const auto & it: mp){
    //         vector<string> temp;
    //         temp.push_back(accounts[it.first][0]);
    //         temp.insert(temp.end(), it.second.begin(),it.second.end());
    //         ans.push_back(temp);
    //     }
    //     return ans;
    // }


    //solution 2 approach from striver
    vector<vector<string>> accountsMerge(vector<vector<string>>& accounts){
        int n = accounts.size();
        //storing the mails and to which index or node it belong as value if it is 0th in accounts i.e first element of account , or second or so on
        unordered_map<string,int> mapMailNode;
        DisjointSet ds = DisjointSet();
        vector<int> rank(n,0);
        vector<int> par(n);
        for(int i = 0 ; i<n; i++)par[i] = i;

        for(int i = 0; i< n; i++){
            for(int j=1; j<accounts[i].size(); j++){
                string mail = accounts[i][j];
                //i.e if the mail is not inserted in the map yet
                if(mapMailNode.find(mail) == mapMailNode.end()){
                    //insert the mail in format mail -> node 
                    mapMailNode[mail] = i;
                }
                //if the mail is already inserted it means it is a already occuring mail in diffrent node hence le'ts join the nodes so that later we can handle all the other mail of this node
                else{
                    //i will give current node and mapMailNode[mail] will give the node where this mail is already present unionByRank will join them together
                    ds.unionByRank(i,mapMailNode[mail],par,rank);
                }
            }
        }

        //here we are pushing all the mail which have common parent to the same vector 
        vector<string> mergedMail[n];
        for(auto it: mapMailNode){
            string mail = it.first;
            //find the parent node and insert all the nodes to that parent
            int node = ds.findPar(it.second,par,rank);
            mergedMail[node].push_back(mail);
        }
        //preparing the final answer
        vector<vector<string>> ans;
        for(int i=0; i<n; i++ ){
            if(mergedMail[i].size()==0)continue;
            //normal if there are elements in the mergedMail
            //sorting since asked in the question that the mails need to be sorted
            sort(mergedMail[i].begin(),mergedMail[i].end());
            vector<string> temp;
            temp.push_back(accounts[i][0]);
            for(auto el: mergedMail[i]){
                temp.push_back(el);
            }
            ans.push_back(temp);
        }
        return ans;
    }
};
