INTUITION
first standing at position 0 of string s thought what directions i can move and since can just move in two direction by taking current element of s or taking current and next element of s . This prompted me to think that recursion would be best fit for it. Since could see a recursion tree being formed.
After a simple recursive solution got TLE hence thought of implementing DP to remove the TLE problem.

APPROACH
used a recursive approach of standing from current position have possibility to move in two direction.
Have used a DP vector for storing the current traversals.
Since If we have reached the current position then we same it and next time we can use it

COMPLEXITY
Time complexity:
O(n)

Space complexity:
O(n)

Code
class Solution {
public:
    int help(int pos, string s, unordered_map<string,char>& encodes, vector<int>& dp)
    {
        //base condition
        if(pos == s.size())
        {
            return 1;
        }
        if(pos > s.size() )return 0;
        if(dp[pos] != -1)return dp[pos];
         //taking two elements from current position since from current 0-9(single element) or (10-26)(double element can yield result)
         //currently going  0-9(single element) side
        string temp="";
        temp+=s[pos];
        if(!encodes[temp])return 0;
        //related to pos+1
        int left = 0;
        int right = 0;
        if(dp[pos+1] != -1)left=dp[pos+1];
        else left = help(pos+1, s, encodes, dp);
        //taking two elements from current position since from current 0-9(single element) or (10-26)(double element can yield result)
        //currently (10-26)(double element can yield result) going this side
        if(pos+1 < s.size() && encodes[s.substr(pos,2)])
        {
            if(dp[pos+2] != -1) right = dp[pos+2];
            else right=help(pos+2, s, encodes, dp);
        }
        return dp[pos] = left+ right;
    }
    int numDecodings(string s) {
     unordered_map<string,char> encodes={
         {"1",'A'},{"2",'B'},{"3",'C'},{"4",'D'},{"5",'E'},{"6",'F'},
         {"7",'G'},{"8",'H'},{"9",'I'},{"10",'J'},{"11",'K'},{"12",'L'},
         {"13",'M'},{"14",'N'},{"15",'O'},{"16",'P'},{"17",'Q'},{"18",'R'},
         {"19",'S'},{"20",'T'},{"21",'U'},{"22",'V'},{"23",'W'},{"24",'X'},         
         {"25",'Y'},{"26",'Z'}};
        //dp vector for string if the current value is found
        vector<int> dp(s.size()+1,-1);
        return help(0, s, encodes, dp);
     }
};
