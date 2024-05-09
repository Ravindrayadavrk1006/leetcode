// QUESTION LINK -> https://www.naukri.com/code360/problems/alien-dictionary_630423?leftPanelTabValue=SUBMISSION

#include <bits/stdc++.h>
using namespace std; 
/*

    explanation:
        here they are saying that we will be given words of alien dictionary , and from 
        those words we have to figure out what is the lexical order there.
        like for example in our dictionary we we are given
        [aab, ab,bc,bd,ef] our lexical order is a,b,c,d,e,f


        lexical order is topological sort , i.e a lies before b , b lies before c and so on
        so if somhow we can form directed graph from the given words of character then we can run topological sort and
        we will have our answer.

        now specifics to the question:
            we can get directed graph by comparing the words i.e 1st word with 2nd , 2nd with 3rd and so on
            eg in
            ["caa", "aaa", "aab"],
            we compare caa with aaa ; then aaa with aab 
            when we compare caa with aaa the first different character will give a edge in directed graph
            eg c comes before a(in second word) hence c->a is the order
            comparing aaa and aab
            aa is same in both and then last character a,b   are not equal so it implies a->b , i.e a lies before b
            
        after we have the adjaceny list we are also sure that the graph is DAG and hence from the above we can do topological sort and get the answer
        


        LEARNINGS--->
        lexical order involves concept of topological sort
        st.top()+'a'    //converting a int to character int_val + 'a'
        converting char to int   char_value(eg. a,b,c,d, or any char) - 'a'

*/
void dfs(int node,vector<vector<int>>& adj_list,vector<bool>& visited,stack<int>& st){
    visited[node] = true;
    for(int adj_el : adj_list[node]){
        if(!visited[adj_el])
            dfs(adj_el,adj_list,visited,st);
    }
    //when all the adjacent travesal for the current node done then push the current node in the stack
    st.push(node);
}
string getAlienLanguage(vector<string> &dictionary, int k)
{
        vector<vector<int>> adj_list(k);
        //comparing the words to form the adjacency list
        for(int i = 0 ; i < dictionary.size()-1 ; i++){
            string s1 = dictionary[i];
            string s2 = dictionary[i+1];
            //both the word will be compared for a difference of first character till the size of smaller word
            int till = min(s1.size(),s2.size());
            for(int ptr = 0 ; ptr<till; ptr++){
                if(s1[ptr] != s2[ptr]){
                    //we are storing the relative value 
                    adj_list[s1[ptr]- 'a'].push_back(s2[ptr]-'a');
                    break;
                }
            }
        }
    /*
        ------------------ NORMAL TOPOLOGICAL SORT-----
    */
    //we have adj_list now let's find the topological sort
    //the graph is already DAG so just find the order that's all no need to think about cycle
    vector<bool> visited(k,false);
    stack<int> st;
    for(int i = 0 ; i<k ; i++){
            if(!visited[i])
                dfs(i,adj_list, visited,st);
    }
    string ans;
    while(!st.empty()){
        ans.push_back(st.top()+'a');
        st.pop();
    }
    return ans;

}
