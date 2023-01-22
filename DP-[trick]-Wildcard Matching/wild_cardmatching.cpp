# Intuition
using the concept of DP string matching tried to solve
concept used:
pattern = string with * ,? 
string to match = the other string to match
concept used
1. if the current char are same we we move further to check for remining char
2. if current char in pattern is ? it will compensate for any char in the string to match hence we have to check for remaining pattern in the remaining string(in string to match the current char will be assumed to be matched since ? compensated for it)
3. if there is * it can match for 0 or more chars of string to match hence we usedd the same concept of once matching zero char and other time it matches for 1 char .
concept used --> in point 2 
[GOOD CONCEPT by use of recursion]
eg. c*a*  aa
      x-> 0 macth wil move to check (c*a, aa) 
      y -> 1 char match will make (c*a*,a)  ==> since in this * is still remaining so it will come to the same point using recursion and above x,y point  will be again executed . 
and hence the concept of 0 and 1,2,3.... char will be matched recursively
4. if the chars don't match we return false by default

class Solution {
private:
    bool help(int pos1, int pos2, string& p, string& s, vector<vector<int>> & dp)
    {
        //base cases
        //if both the string are exhausted return true since both would have matched
        if(pos1<0 && pos2<0)return true;
        //if pattern to be matched is exhausted but other string doesn't it means the we have to return false since there is nothing in the pattern which can compensate for the remaining part in given string s 
        if( pos1 <0 )return false;
        //if the given string s is exhausted and pattern is not it means that we have to some char left in pattern the logic here used is only if the pattern have * will compensate because * can be replaced nothing or no char and we finally exhaust the first string too but if there is anything apart from it even ? won't be used since ? matches for one char and all the char in the second string is finished 
        //hence if there is anything apart from * remaining in the first string we return a false
        if(pos2 < 0 )
        {
            for(int i = 0 ; i<=pos1 ; i++)
            {
                if(p[i] != '*')return false;
            }
            return true;
        } 
        //normal dp check
        if(dp[pos1][pos2] != -1)return dp[pos1][pos2];
        //for match
        //if the char in both string are same or if ? in first then also it will compansate for one char in the second string since by logic of ? it can match one char 
        if(p[pos1] == s[pos2] || p[pos1] == '?')
        {
            return dp[pos1][pos2] = help(pos1-1,pos2-1,p,s, dp);
        }
        //if * in first char
        //trying logic 1 [wrong]
        //trying to skip all the char corresponding to * and moving back to same position as the s to match the remaing portion
        //this logic doesn't work eg . try checking in  in  p = "*a*b" , s = "adceb"
        // else if(p[pos1] == '*')return help(pos1-1,pos1-1,p, s);
        /*
        trying logic 2 [correct]
        logic from striver important type learn trick
        for * either we can take zero char or any number of char ==>
        for zero char we move the pos1 to pos1-1 and pos2 remains at the same position
        help(pos1-1,pos2,p,s)  
        for matching one or more char we keep the pos1 at the same position and move the pos2 one position back which states that it moved one position and and since we didn't move the pos1 hence recursion will try to do the same thing again by not taking anything for the * since it is still present in the second option and try to follow this pattern again 
        */
        else if(p[pos1] == '*')return dp[pos1][pos2] =  help(pos1-1,pos2,p,s,dp) ||help(pos1,pos2-1,p,s, dp);
        return dp[pos1][pos2] = false;
    }
public:
    bool isMatch(string s, string p) {
       
        int n = p.size();
        int m = s.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(n-1,m-1,p,s, dp);
    }
};
