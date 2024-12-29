class Solution {
private:

    /*wrong approach since the all words are not in same order*/
    int solNumWays(int pos,int taken_till,int k,vector<string>& words , string& target, int n ){
        if(k >= target.size())return 1;
        if(pos >= n )return 0; 
        int per_word_size = words[0].size();
        int i = pos / per_word_size;
        int j = pos%per_word_size;
        //
        int total_ans = 0;
        if(j <= taken_till){
            return total_ans+=  solNumWays(pos+1, taken_till, k, words, target, n);
        }
        // j is in correct range
        if(words[i][j] != target[k])return total_ans+= solNumWays(pos+1, taken_till, k, words, target, n);
        //we have the correct character
        else if(words[i][j] == target[k]){
            //take it
            total_ans+=solNumWays(pos+1, j , k+1, words, target, n);
            //not take
            total_ans+=solNumWays(pos+1, taken_till, k, words, target, n);
        }

        return total_ans ;
    }
    //from editorial

    /*

        we have been given that all the string in words array are of same size , so first we are counting the number of each type of character at each position
        for example ["acca","bbbb","caca"]
        we will have char_count_arr[0][26] char_count_arr[1][26] char_count_arr[2][26] char_count_arr[3][26]  i.e for each position in a word of word, we will count the number of each character,


        suppose we stack all the word of words one over another , we are counting each type of character in first column , second column aon
       

       //now we try to match the character of the target with from this char_count_arr

        either we can take or we cannt using the same technqiue trying to form
    */
    long from_editorial_recursive(int pos, int target_pos,vector<string>& words, vector<vector<int>>& char_count_arr , string& target, vector<vector<int>>& dp){
        if(target_pos == target.size())return 1;

        //this second part of this condition reduces our trying and hence add in time complexity reductions
        if(pos == words[0].size() || 
            words[0].size() - pos < target.size() - target_pos)return 0;

        if(dp[pos][target_pos] != -1)return dp[pos][target_pos];

        //[**NOTE ]-> when this count was of type int was getting wrong answer, we have converted the function return type to long also
        long count =0;
        int char_pos = target[target_pos] - 'a';

        //take and not take
        //take
        /*
            while taking we are considering all the counts of that targetPos character and then will be checking for further
        */
         count+= char_count_arr[pos][char_pos] * from_editorial_recursive(pos+1, target_pos +1, words, char_count_arr, target, dp) %1000000007;

        //not take
        /*
            if we are not taking we simply try for next index
        */
        count+=from_editorial_recursive(pos+1, target_pos , words, char_count_arr, target, dp);
        return dp[pos][target_pos] =  count% 1000000007 ;
    }
public:
    int numWays(vector<string>& words, string target) {
        // int n = words.size()* words[0].size();
        // return solNumWays(0,-1, 0,words, target, n);



        //for calling the editorial solution
        int per_word_size = words[0].size();


        //counting each character at all positions of the words, positions are from 0 to words[0].size()
         vector<vector<int>> char_count_arr(per_word_size, vector<int>(26,0));
        for(int i = 0; i< words.size(); i++){
            for(int j = 0; j< per_word_size; j++){
                char_count_arr[j][words[i][j] -'a']++;
            }
        }
        vector<vector<int>> dp(per_word_size, vector<int>(target.size(), -1));
        return from_editorial_recursive(0,0, words, char_count_arr, target, dp);
    }
};
