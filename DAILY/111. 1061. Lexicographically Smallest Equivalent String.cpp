//basic Graph union problem
//issue that here we are doing union by lexicographic which is if ultimate_parent_u < ulimate_parent_v { pare[ulimate_parent_v] =ultimate_parent_u  } else par[ultimate_parent_u] = ultimate_parent_v
class Union_Find{
    public:
        vector<int> rank, par;
        Union_Find(){
            //n+1 since 1 based indexing given
            rank.resize(26,0);
            par.resize(26);
            for(int i = 0 ; i<26; i++){
                par[i]=i;
            }

        }
        int findPar(int node){
            if(node == par[node])return node;
            return par[node] = findPar(par[node]);
        } 
        void unionByRank(int u, int v){
            int ultimate_par_u = findPar(u);
            int ultimate_par_v = findPar(v);
            if(ultimate_par_u == ultimate_par_v)return;
            // if(rank[ultimate_par_u]< rank[ultimate_par_v]){
            //     par[ultimate_par_u] = ultimate_par_v;
            // }
            // if(rank[ultimate_par_v]< rank[ultimate_par_u]){
            //     par[ultimate_par_v] = ultimate_par_u;
            // }
            // if(rank[ultimate_par_u] == rank[ultimate_par_v]){
            //     if(ultimate_par_u == ultimate_par_v)return;
            //     //lexicographic check
            //     if(ultimate_par_u< ultimate_par_v){
            //       par[ultimate_par_v] = ultimate_par_u;
            //       rank[ultimate_par_u]++;  
            //     }
            //     else{
            //         par[ultimate_par_u] = ultimate_par_v;
            //         rank[ultimate_par_v]++;
            //     }
            // }
        }
        void unionByLex(int u, int v){
            int pu = findPar(u);
            int pv = findPar(v);
            if(pu == pv) return;

            // Always keep the smaller letter as the parent
            if(pu < pv){
                par[pv] = pu;
            } else {
                par[pu] = pv;
            }
        }
};
class Solution {
private:
    string sol_basic(string s1, string s2, string baseStr){
        int n = s1.size();
        vector<set<char>> st_vec;
        for(int i=0; i<n; i++){
            //find the current vector in each set of st_vec
            bool st_exist = false;
            int st_vec_size = st_vec.size();
            for(int el = 0; el<st_vec_size; el++){
                if(st_vec[el].find(s1[i]) != st_vec[el].end() || st_vec[el].find(s2[i]) != st_vec[el].end() ){
                    st_vec[el].insert(s1[i]);
                    st_vec[el].insert(s2[i]);
                    st_exist = true;
                }
            }
            //if we were not able to insert in any existing set then insert in a new set
            if(!st_exist){
                set<char> st;
                st.insert(s1[i]);
                st.insert(s2[i]);
                st_vec.push_back(st);
            }
        }
        for(auto st:  st_vec){
            for(auto el: st)cout<<el<<" ";
            cout<<endl;
        }
        //we have already created and inserted all the elmenets in the respective set;
        int q_size = baseStr.size();
        string ans = "";
        for(int i =0; i< q_size; i++){
            //if the current char is not present in s1 or s2 then we can push the char as it is in the answer
            ans.push_back(baseStr[i]);
            for(auto st: st_vec){
                if(st.find(baseStr[i]) != st.end()){
                    ans.pop_back();
                    ans.push_back(*st.begin());
                    continue;
                }
            }
        }
        return ans;
    }
    string sol_not_working(string s1, string s2, string baseStr){
        int n = s1.size();
        //ordered map ordered set
        map<char, set<char> > mp_st;
        //first for each char insert itself
        for(char ch='a'; ch<='z'; ch++){
            mp_st[ch].insert(ch);
        }
        //we are preparing a kind of adjaceny list to 
        for(int i =0; i<n; i++){
            mp_st[s1[i]].insert(s2[i]);
            mp_st[s2[i]].insert(s1[i]);
            for(char ch ='a'; ch<='z'; ch++){
                if(mp_st[ch].find(s1[i]) != mp_st[ch].end())mp_st[ch].insert(s2[i]);
                if(mp_st[ch].find(s2[i]) != mp_st[ch].end())mp_st[ch].insert(s1[i]);
            }
        }
        for(auto mp: mp_st){
            for(auto el: mp.second)cout<<el<<" ";
            cout<<endl;
        }
        string ans = "";
        int base_str_size = baseStr.size();
        for(int i =0; i<base_str_size; i++){
            ans.push_back(*(mp_st[baseStr[i]].begin()));
        }
        return ans;
    }

    //using the concept of UnionFind from Graphs
    string sol_union_find(string s1, string s2, string baseStr){
       Union_Find uv;
       int n = s1.size();
       //it will create all the necessary connections
       for(int i=0; i<n; i++){
            uv.unionByLex(s1[i]-'a', s2[i]- 'a');
       }
       //now we will colate the answer
       string ans = "";
       for(char ch: baseStr){
            int par = uv.findPar(ch-'a');
            ans.push_back(par+'a');
       }
       return ans;
    }

public:
    string smallestEquivalentString(string s1, string s2, string baseStr) {
        // return sol_basic(s1, s2, baseStr);

        // return sol_not_working(s1, s2, baseStr);

        return sol_union_find(s1, s2, baseStr);
    }
};
