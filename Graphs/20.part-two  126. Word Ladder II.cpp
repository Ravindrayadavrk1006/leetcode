/*
    * imp points-> 
        1. we can get same length multiple answer
        2. [["hit","hot","dot","dog","cog"],["hit","hot","lot","log","cog"]]
        in the above answer , hot is common in both the above, it mmeans we should not instantly delete when we visit it because we can visit it from other element of previous level as well and hence delete a elemnet when all the previous level elements are processed, in bfs

    many learning in the below solution try to see
      1. how to find path , one of most important
*/
class Solution {
private:
    vector<vector<string>> sol(string beginWord, string endWord, vector<string>& wordList){
        unordered_set<string> st(wordList.begin(),wordList.end());
        queue<vector<string>> q;
        //push the beginWord in a list format in the queue
        q.push({beginWord});
        //for storing to remove that are used in the previous level
        vector<string> used_on_level;
        used_on_level.push_back(beginWord);
        int level = 0;
        vector<vector<string>> ans;
        //will be updated with a valid value when a valid path is inserted into the ans
        int smallest_matched_seq_size = -1;
        while(!q.empty()){
            vector<string> vec = q.front();
            //remove the element from queue
            q.pop();
            //it means we are processing next level so delete all the element which we stored in used_on_level frmo the set
            if(vec.size() > level ){
                level++;
                for(string it: used_on_level)st.erase(it);
            }
            
            //from the last word in current vec we can move to other places
            string word = vec.back();
            //this below statement is to say that the smallest answer are found no need to try further uselessly
            if(smallest_matched_seq_size != -1 && vec.size() > smallest_matched_seq_size)break;
            //pushing into answer if we have valid answer
            //here if the last word is endWord then we have the answer
            if(word == endWord){
                //if no path in the anser push this valid path and update smallest_matched_seq_size to the size of this pushed element
                if(ans.size()== 0){
                    ans.push_back(vec);
                    smallest_matched_seq_size = vec.size();
                }
                //all other valid path which are same size as previous push them all in the answer
                else if(vec.size() == smallest_matched_seq_size)ans.push_back(vec);
            }
            for(int i = 0; i<word.size(); i++){
                char original = word[i];
                //change word to form every possible word
                for(char c = 'a';  c<= 'z'; c++){
                    word[i]=c;
                    //if this word is in the set then store it a valid path in queue
                    if(st.find(word) != st.end()){
                        vec.push_back(word);
                        q.push(vec);
                        //also tell to remove this word this word
                        used_on_level.push_back(word);
                        //next pathways should not be done on top of current word but other path in same level, it is same as word[i]=c and then changing back word[i] = original
                        vec.pop_back();
                    }
                }
                word[i] = original;

            }
        }
        return ans;
    }
public:
    vector<vector<string>> findLadders(string beginWord, string endWord, vector<string>& wordList) {
        return sol(beginWord, endWord, wordList);
    }
};
