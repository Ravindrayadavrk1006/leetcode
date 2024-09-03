/*
  approach -> simple application of take and non-take with simple modificaiton of taking the current coin more than one time
*/

class Solution {
public:
    int help(int pos, int amount, vector<int>& coins,vector<vector<int>>& dp)
    {
        if(amount == 0 )return 1;
        if(pos == 0 )
        {
            //standing at position 0 , we can either take it or not take it if take it it will contribute 1 , if can't take it then it would not contribute any
           if(amount%coins[0] == 0)return 1;
           return 0;
        }
        if(dp[pos][amount] != -1)return dp[pos][amount];
        //normal cases
        //not take
        int not_take = help(pos-1, amount, coins, dp);
        int take = 0;
        //pos remains pos since there is a possibility of taking the same coin again
        if(coins[pos]<= amount) take =  help(pos, amount-coins[pos],coins, dp);
        return dp[pos][amount] = not_take + take;
    }
    int change(int amount, vector<int>& coins) {
        int n = coins.size();
        vector<vector<int>> dp(n,vector<int>(amount+1,-1));
        return help(n-1, amount, coins, dp);   
    }
};
