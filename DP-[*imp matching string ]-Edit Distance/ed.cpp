//using the concept of string matching 
class Solution {
private:
    [important]
    int help(int pos1,int pos2,string& word1, string& word2,vector<vector<int>>& dp)
    {
        //base cases
        //if we reach pos2 = -1 ==> that we have exhausted all the required element and if some element are remaining in word1 i.e pos1 is between 0 and n-1 then we have to remove those element from word1 hence we return pos1+1 since eg . if pos1 = 2 this mean we have to remove 0,1,2 index element to make it similar to word2
        if(pos2<0)return pos1+1;

        //if pos1 is exhausted i.e pos1<0 => we need to insert the from 0 to pos2 index element of word2 in word1 to make (word1)it similar to word2
        if(pos1<0)return pos2+1;
        if(dp[pos1][pos2] != -1)return dp[pos1][pos2];
        //normal cases
        //if string matches
        //if the char matches
        // we have to search the remaining chars of word2 in word1 since that char is matched so in the remaining string find the remaining part
        if(word1[pos1] == word2[pos2])
        {
            return dp[pos1][pos2]= 0+ help(pos1-1,pos2-1,word1, word2, dp);
        }
        /*if the char doesn't macth we have three choices 
        1. can replace the current char with the required char
        2. can insert the required char 
        3. delete the current char and look in the remaining part
        and return the minimum out of three operations result
        */
        else
        {
            //since all these contribute a 1 in ans as operation hence taking as one
            //INSERT
            //insert when we insert hypothetically the required char same as word2[pos2] char the position in word1 doesn't change because we have inserted ahead of current pos1 and since the char is 
            int a = 1+ help(pos1,pos2-1, word1, word2,dp);
            //REMOVE
            //remove the current char and look for the current word2[pos2] char in the remaining string
            int b = 1+ help(pos1-1,pos2,word1,word2, dp);
            int curr_min = min(a,b);
            //REPLACE
            //replace if we replace the current char with the required char i.e word2[pos2] char at word1[pos1] then we have matched the current required char and we have to look for remaining char in the remaining str
            int c = 1+  help(pos1-1,pos2-1,word1,word2, dp);
            return  dp[pos1][pos2] = min(curr_min,c);
        }
    }
public:
    int minDistance(string word1, string word2) {
        int n = word1.size();
        int m = word2.size();
        vector<vector<int>> dp(n,vector<int>(m,-1));
        return help(n-1,m-1,word1,word2,dp);
    }
};
