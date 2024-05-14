class Solution {
/*
    basic use of bfs travesal

    so here we are trying to convert a word to every possible word and checking if the word we got is present in wordList it means it's valid node and we should visit it.
    we are doing bfs travesal, it's much more easier and apt for the current scenario.

    here for easily checking if the word is in wordList we are hasing all the values in set , which has all function in O(1) using in place of hashmap

    we are removing the element from hashmap , to mark it visited and everything is same.

    from a node i.e a word we can go to any node in the wordList which can be formed by changing one character from the current word,
    as soon as we reach the endWord we stop doing any further work,
    here bfs comes handy because we are doing level by level and once we have the answer we won't go to other pathways
*/
private:
    int bfs_technique(string beginWord, string endWord, vector<string>& wordList){
        //we are simply using bfs technique
        //since we have to calculate the distance as well so to mark the level we will store level value as int in the queue along with element
        queue<pair<string,int>> q;
        q.push({beginWord,1});
        //we will keep all the eelemnts in set for checking if the element exists in O(1) on avg.
        //also once we have pushed a element we will remove it from the set it will be similar to sybolizing that the elemnt is already visited and should not be visited
        unordered_set st(wordList.begin(),wordList.end());

        //make the word visited by removing from the set so that no elemnt can again visit it
        st.erase(beginWord);
        while(!q.empty()){
            string word = q.front().first;
            int steps = q.front().second;
            q.pop();
            //if the current word is the endWord return the steps 
            if(word==endWord)return steps;
            //trying to replace every character of the current word and check and insert
            for(int i = 0 ; i<word.size(); i++){
                //saving the original character to replace it back when trying to replace done for the current character
                char original = word[i];
                for(char c = 'a'; c<='z'; c++){
                    //trying to replace the current character
                    word[i] = c;
                    //if the current word is not visited yet , that is present in the set visit it and mark it visited
                    if(st.find(word) != st.end()){
                        q.push({word,steps+1});
                        st.erase(word);
                    }
                }
                //making the world back to original so that only character is changed at a time
                //because if we don't do the below step then in the above inner for loop, bat becomes will become zat, and in next itration it will check for zbt,zct,zdt but not bat,bbt,bct and so on
                word[i] = original;
            }
        }
        return 0;
    }
public:
    int ladderLength(string beginWord, string endWord, vector<string>& wordList) {
        return bfs_technique(beginWord, endWord, wordList);
    }
};
