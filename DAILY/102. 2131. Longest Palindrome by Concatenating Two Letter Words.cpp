class Solution {
private:
    /*
        why below approach -> 
            below approach we are using because in the question it has been given, from the given words we can choose word in any order eg. if    [ab tx  ba xt] are given   we can select ab  + ba and then we can select tx and xt although we selected tx second time and xt is available at very last, so it boils down to if we can select the term of not.
            i.e if we have available reciprocal to select this word or not.
        approach ->
           1.  we are counting the occurances of each word first and storing in a map
           2. if a words[i] is still present in map, we are checking if it's reverse is present if present then we are adding +4 in answer and decrementing both reverse and words[i] count in the map.

           //coming another issue let's say a word is aa then it's reverse will be also aa,
           but if we directly use logic 2 then it will be an issue,
            3.1. ->  we are checking if the word itself is a palindrome if it is we are checking if its count is 2 or more, if yes we add +4 in the answer and decrement map[word[i]] count by 2
            3.1 -> if the count is just 1 then we are using a variable which is a bool variable which says if a word itself is a palindrome so that we can add that single word in middle.
            since if there are many words whose count is 1 only one word can be placed in the middle. that's why that bool variable

    */
    int sol_longestPalindrome(vector<string>& words){
        //this map store the all the word element and keep their count
        unordered_map<string,int> mp;
        int n = words.size();
        for(auto w: words){
            mp[w]++;
        }
        int ans = 0;
        bool single_word_palindrome = false;
        for(int i=0; i<n; i++){
            string rev = words[i];
            reverse(rev.begin(), rev.end());
            //if current word  a palindrome and it's count is 2 or more
            if(words[i][0] == words[i][1] && mp[words[i]]>1){
                //we take same word twice and decrease the word count by 2
                ans+=4;
                mp[words[i]]-=2;
            }
            //the code comes here it means it's the word if palindrome it's count is zero or 1
            //we are saying if the word is a palindrome and it's count is 1 then we make that bool variable true so that we can place it in the middle 
            else if(mp[words[i]]>0 && words[i][0] == words[i][1])single_word_palindrome = true;

            //normal if a word exist and it's reciprocal exit then we do this
            else if(mp[words[i]]>0 && mp[rev] > 0){
                //decrement the word 
                mp[words[i]]--;
                //decrement the reciprocal of the word 
                mp[rev]--;
                //add both the word in the anwer
                ans+=4;
            }
        }

        //if we have a word which is a palindrome i.e 3.2 step, we add 2 in the answer
        if(single_word_palindrome)ans+=2;
        return ans;
    }

public:
    int longestPalindrome(vector<string>& words) {
        return sol_longestPalindrome(words);
    }
};
