Intuition
Suppose we have eg. acd and ced
we start from last index of both the string
(2,2) if the current chars at the index match then we take the char and check in 2-1,2-1 i.e 1+(1,1) . Now at 1,1 the char at these index doesn't match hence we will try to check other possibilities by once decrementing in first (0,1) and other way decrementing in index in second text2 (1,0) and out of these two try to find which gives max.

Complexity
Time complexity:
O(text1.size()*text2.size())

Space complexity:
for solution 1 -> O(text1.size()*text2.size() i.e dp vector + text1.size()+text2.size() since maximum length can go is both decremented to 0 one after another)

Code
class Solution {
public:
    int help(int pos1, int pos2, string &text1, string& text2, vector<vector<int>>& dp)
    {
        //base case
        /*
        if we make 0 as base case then we have to counter many possibilities like 
        if (0,5) --> have to check (-1,5) and other case (0,4),(0,3),(0,2),(0,1),(0,1) by self hence let's take base case as negative then all the possibilities will be handled by the recursion
        */
        if(pos1 < 0 || pos2 < 0)return 0;
        
        //checking if already found the current recursion
        if(dp[pos1][pos2] != -1)return dp[pos1][pos2];
        //if the current character matches
        if(text1[pos1] == text2[pos2])
        {
            return dp[pos1][pos2] = 1 + help(pos1-1, pos2-1, text1, text2, dp);
        }
        //if current character doesn't match
        //then in one case move pos-1,pos2  and in other pos1,pos2-1
        return dp[pos1][pos2] = max(help(pos1-1,pos2,text1, text2, dp),help(pos1,pos2-1, text1, text2, dp));

    }


    /*
    NEW CONCEPT --> SHIFTING OF INDEX 
    in our above solution the base case was <0 which will give complecations when we try to tabulate the solution hence we will try to shift the index
                         such that -1 ,0,..... n-1
    will be represented by          0,1,.......n 
    */
    int shiftindex(int pos1, int pos2, string& text1, string& text2 ,  vector<vector<int>>& dp)
    {
         if(pos1 == 0 || pos2 == 0)return 0;
        
        //checking if already found the current recursion
        if(dp[pos1][pos2] != -1)return dp[pos1][pos2];
        //if the current character matches
        //since the pos1 is really pos-1 in the string 
        //we are just try to index shift in the dp nowhere else  in the original thing everything remains same hence in the other things apart from dp it remains same
        if(text1[pos1-1] == text2[pos2-1])
        {
            return dp[pos1][pos2] = 1 + shiftindex(pos1-1, pos2-1, text1, text2, dp);
        }
        
        return dp[pos1][pos2] = max(shiftindex(pos1-1,pos2,text1, text2, dp),shiftindex(pos1,pos2-1, text1, text2, dp));


    }
    //writing tabulation from index shift
    int tabulation(string text1, string text2)
    {
        int text1_size = text1.size();
        int text2_size = text2.size();
        vector<vector<int>> dp(text1_size+1, vector<int>(text2_size+1,-1));
        //by seeing the base case in shiftindex make all 0 row and 0th column 0 
        for(int pos2 = 0 ; pos2<= text2_size; pos2++)dp[0][pos2]= 0;
        //making the 0th column elements as zero
        for(int pos1= 0 ; pos1<= text1_size; pos1++)dp[pos1][0]= 0;
        //normal case
        //copy the remaining logic of above
        for(int pos1 = 1 ;pos1<=text1_size; pos1++)
        {
            for(int pos2= 1; pos2<=text2_size; pos2++)
            {
                if(text1[pos1-1] == text2[pos2-1])
                {
                    dp[pos1][pos2] = 1 + dp[pos1-1][pos2-1];
                }
                else
                {
                    dp[pos1][pos2] = max(dp[pos1-1][pos2],dp[pos1][pos2-1]);
                }

            }
        }
        return dp[text1_size][text2_size];
    }

    int space_optimization(string text1, string text2)
    {
        int text1_size = text1.size();
        int text2_size = text2.size();
        vector<int> prev(text2_size+1,0);
        vector<int> curr(text2_size+1, 0);
        for(int pos1 = 1 ;pos1<=text1_size; pos1++)
        {
            for(int pos2= 1; pos2<=text2_size; pos2++)
            {
                if(text1[pos1-1] == text2[pos2-1])
                {
                    curr[pos2] = 1 + prev[pos2-1];
                }
                else
                {
                    curr[pos2] = max(prev[pos2],curr[pos2-1]);
                }

            }
            prev = curr;
        }
        return prev[text2_size];

    }
    int longestCommonSubsequence(string text1, string text2) {
        //BELOW TWO LINES FOR BOTH HELP AND SHIFT INDEX
        // int text1_size = text1.size();
        // int text2_size = text2.size();
        
        
        //NORMAL INT HELP CALLING
        // vector<vector<int>> dp(text1.size(), vector<int>(text2.size(),-1));
        // return help(text1_size-1, text2_size-1,text1,text2, dp);

        //CALLING THE SHIFTING OF INDEX SOLUTION
        //WE WILL PASS text1_size-1 + 1, text2_size-1+1 SINCE SHIFTED BY ONE POS AND ALSO OUR DP SIZE WILL GROW BY ONE
        // vector<vector<int>> dp(text1_size+1, vector<int>(text2_size+1,-1));
        // return shiftindex(text1_size, text2_size,text1,text2, dp);

        //CALLING SOLUTION 3 TABULATION
        // return tabulation(text1, text2);


        //CALLING SPACE OPTIMIZATION 
        return space_optimization(text1,text2);
    }
};
