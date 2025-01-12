class Solution {
private:

    //this is basic approach it is giving TLE
    vector<string> solWordsSets(vector<string>& words1, vector<string>& words2){
        int n = words1.size();
        int n2 = words2.size();
        vector<vector<int>> countCharInWords2(n2, vector<int>(26, 0));
         for( int i=0; i<n2; i++){
            for(char ch: words2[i]){
                countCharInWords2[i][ch-'a']++;
            }
        }
        //count and save for each word their each type of char count

        vector<vector<int>> countCharInWords1(n, vector<int>(26, 0));
        for( int i=0; i<n; i++){
            for(char ch: words1[i]){
                countCharInWords1[i][ch-'a']++;
            }
        }
        vector<string> ans;
        for(int i=0;i<n; i++){
            int k =0;
            for(; k<n2; k++){
                int j=0;
                for(; j<26; j++){
                    if(countCharInWords1[i][j] < countCharInWords2[k][j])break;
                }
                if(j != 26)break;
            }
            if(k == n2)ans.push_back(words1[i]);
            
        }
        return ans;
    }
/*
    here approach ->
        from words2 we are forming a single word called unionWord , this word will have the maximum count of each character from each word of words2 , i mean to say that let's say words2 has three string a,b,c   and a has character k 2 times , b has 4 times and c has 1 time then our unionWord will have count of k = 4 


    once we have this unionWord we will count character for each word of words1 and whichver word has all it's character greater or equal to that of unionWord then that is a universal word

*/
    vector<string> optimalWordSubsets(vector<string>& words1, vector<string>& words2){
        /*here we are constucting a single word from words2 , by taking the maximum count of each character from all the word of words2 which has maximum count of that character.
        eg. words2 = [raviiii, raavi, ravvvii]
        so our word vector will have     count of a = 2 , r = 1, v =3, i = 4
        */
        vector<int> unionWord(26, 0);
        for(auto word: words2){
            vector<int> curr(26, 0);
            for(auto c: word){
                curr[c-'a']++;
            }
            for(int i=0; i<26; i++){
                unionWord[i] = max(unionWord[i], curr[i]);
            }
        }
        vector<string> ans;
        //counting for each word of word1
        int n = words1.size();
        vector<vector<int>> countEachWord(n, vector<int>(26,0));
        for(int i =0; i<n; i++){
            //counting each words character count
            for(auto c: words1[i]){
                countEachWord[i][c-'a']++;
            }

            //if all the char are greater or equal in this word with word then it's a universal 
            bool insert = true;
            for(int k=0; k<26; k++){
                if(countEachWord[i][k] < unionWord[k] ){
                    insert = false;
                    break;
                }
            }
            if(insert)ans.push_back(words1[i]);
        }
        return ans;
    }

public:
    vector<string> wordSubsets(vector<string>& words1, vector<string>& words2) {
        // return solWordsSets(words1, words2);

        return optimalWordSubsets(words1, words2);
    }
};
