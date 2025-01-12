/*
    approach ->
        we have to form k palindrome from the string s

        one palindrome can have maximum one odd count character in it, because we can fit one character in middle which shouldn't be present on left and right eg . aabbcbbaa , c , aba
        so for k palindrome if in our string there are maximum k odd count character then only we can form k palindrome, 
        "maximum" k odd count character because because , it's not necessary for a palindrome to have a middle odd character eg. aabb , aa, bbccdd

*/
class Solution {
private:
    bool solCanConstruct(string s, int k){
        //if the size of s is smaller than k it means some string will have to empty and we can't assume empty string and hence return false
        if(s.size()< k)return false;

        //array for counting no of each chars
        vector<int> char_counter(26, 0);
        //counting each chars in the string s
        for(char c: s){
            char_counter[c-'a']++;
        }
        //counting no of chars whose count is odd
        int no_of_odds = 0;
        //counting the odss here
        for(int i=0; i<26; i++){
            if(char_counter[i]%2 != 0)no_of_odds++;
        }

        //we are saying if the number of odds count is greater is greater than the numbre of maximum string we can form then, the answer is false
        if(no_of_odds> k)return false;
        return true;
    }
public:
    bool canConstruct(string s, int k) {
        return solCanConstruct(s, k);
    }
};
