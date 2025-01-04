class Solution {
private:

    //this is recursive appraoch and it is giving TLE
    int solCountPalindrome(int pos, string temp, string& s, unordered_set<string> & st){
        if(temp.size() == 3){
            if(temp[0] == temp[2]&& st.find(temp) == st.end()){
                st.insert(temp);
                return 1;
            }
            else return 0;
        }
        if(pos >= s.size())return 0;


        //take and not-take
        int left = solCountPalindrome(pos+1, temp+s[pos], s, st);
        int right= solCountPalindrome(pos+1, temp, s, st);
        return left+right;
    }

    /*
        refer to editorial as well same thing

        palindrome of length 3-> the first and last character need to be same and middle one can be anything
        read this --> this is the correct solution
        approach ->
        1. we are finding all the unique chars of the given string
        2. for all the unqiue character of the given string we are finding the first occurance and storing it in variable start, and last occurance and storing it in variable end
        and then finding all the unique character between start and end, and addining it's count to answer since that number of palindrome we can form with current start and end , since we have already founded the unique charcater in the step 1 hence there won't be any repition , we are finding the first and last occurance since maximum count of palindrome will be founded between maximum values only


    
    */

    //this is good and better appraoch
    int sol2(string s){
        unordered_set<char> letters;
        int n = s.size();
        //inserting all the chars in letters to store only the unique chars
        for(char c: s){
            letters.insert(c);
        }
        
        int ans = 0;
        //for each unique character of the string
        for(char c: letters){
            //finding first and last index of each character

            /*
                this part of finding first and last for each unique character can be optimized if we prehand calculate it, we can do it as below commented code if we place this code outside  for(char c: letters){ this line

                vector<int> first = vector(26, -1);
                vector<int> last = vector(26, -1);
                for (int i = 0; i < s.size(); i++) {
                int curr = s[i] - 'a';
                if (first[curr] == - 1) {
                    first[curr] = i;
                }
                
            last[curr] = i;
        }

        done in next solution -> sol3_precomputingfirst_and_last
            */
            int start = -1;
            int end = 0;
            for(int pos=0; pos <n; pos++){
                if(s[pos] == c){
                    if(start == -1)start = pos;
                    end = pos;
                } 
            }

            //we have start and end for this character
            //we will find the unique character between the character 
            unordered_set<char> between;
            for(int k = start+1; k<end;k++){
                between.insert(s[k]);
            }
            ans+=between.size();
        }
        return ans;
    }

/*
    calculating the start and end beforehand and then finding the unique chars between them

*/
    int sol3_precomputingfirst_and_last(string s){
        vector<int> start = vector(26, -1);
        vector<int> end= vector(26, -1);
        for (int i = 0; i < s.size(); i++) {
            int curr = s[i] - 'a';
            if (start[curr] == - 1) {
                start[curr] = i;
            }
            
                end[curr] = i;
        }
        int ans = 0;
        for(int i = 0; i<26; i++){
            if(start[i] == -1)continue;
            unordered_set<char> between;
            for(int k = start[i]+1;k< end[i] ; k++){
                between.insert(s[k]);
            }
            ans+=between.size();
        }
        return ans;
    }
public:
    int countPalindromicSubsequence(string s) {
        //SOL RECURSIVE -> giving TLE
        // unordered_set<string> st;
        // return solCountPalindrome(0, "", s, st);



        // return sol2(s);

        return sol3_precomputingfirst_and_last(s);
    }
};
