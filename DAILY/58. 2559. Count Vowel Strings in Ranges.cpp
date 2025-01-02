/*
    using prefix sum calculating the count of number of strings which has first and last char vowel till now
    we have build the logic that ans is equal to first query[i][0] has first and last element not equal to vowel then the answer would be counter[query[i][1]] - counter[query[i][0]] 
    else the answer would be ( counter[query[i][1]] - counter[query[i][0]]) + 1 

*/

class Solution {
private:
    vector<int> solVowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int n = words.size();
        vector<int> counter(n,0);
        set<char> st = {'a', 'e','i', 'o', 'u'};
        int i = 0;
        if(st.find(words[0][0]) != st.end() && st.find(words[0][words[0].size()-1]) != st.end() ){
            counter[0] = 1;
        }
        for(i = 1; i<n; i++){
            if(st.find(words[i][0]) != st.end() && st.find(words[i][words[i].size()-1]) != st.end()){
                //increment the current counter
                counter[i] = counter[i-1]+1;
                // counter[i]+=counter[i-1];
                // counter[i]+=1;
            }
            else{
                counter[i] = counter[i-1];
            }
        }
        for(auto el: counter)cout<<el<<" ";
        int q_size = queries.size();

        vector<int> ans(q_size);
        for(int i = 0; i<q_size; i++){
            int first = queries[i][0];
            int second = queries[i][1];
            if(st.find(words[first][0]) != st.end() && st.find(words[first][words[first].size()-1]) != st.end()){
                // cout<<"equal for---->"<<words[first]<<endl;
                ans[i] =  counter[second] + 1  - counter[first];
            }
            else{
                ans[i] = counter[second]   - counter[first];
            }
        }
        return ans;
    }


    vector<int> soltwoVowelStrings(vector<string>& words, vector<vector<int>>& queries){
        int n = words.size();
        vector<int> counter(n, 0);
        int i = 0;
        if(words[i][0] == 'a' ||words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u'){
            counter[0] = 0;
        }
        else counter[0] = 1;
        for(int i = 1; i<n; i++){
            if(words[i][0] == 'a' ||words[i][0] == 'e' || words[i][0] == 'i' || words[i][0] == 'o' || words[i][0] == 'u'){
            counter[i] = counter[i-1];
            }
            else{
                counter[i] = counter[i-1] + 1;
            }

        }
        for(auto el: counter)cout<<el<<" ";
        int q_size = queries.size();
        vector<int> ans(q_size);
        for(int i = 0; i<q_size; i++){
            int first = queries[i][0];
            int second = queries[i][1];

            ans[i] = second- first+1 - (counter[second] - counter[first] + 1);
        }
        return ans;
    }
public:
    vector<int> vowelStrings(vector<string>& words, vector<vector<int>>& queries) {
        // return soltwoVowelStrings(words, queries);

        return solVowelStrings(words, queries);
    }
};
