class Solution {
private:
    vector<int> sol_words_having_char_x(vector<string>& words, char x){
        vector<int> ans;
        int n = words.size();
        for(int i =0; i<n; i++){
            int  curr_word_size = words[i].size();
            for(int j=0; j<curr_word_size; j++){
                if(words[i][j] == x){
                    ans.push_back(i);
                    break;
                }
            }
        }

        return ans;
    }
public:
    vector<int> findWordsContaining(vector<string>& words, char x) {
        return sol_words_having_char_x(words, x);
    }
};
