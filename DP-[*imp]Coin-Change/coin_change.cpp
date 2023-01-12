important question
Intuition
[standard] dp of counting the no of ways

Approach
returning 1 if the amount we get required else returning zero and then taking the sum of both and returing the sum

Complexity
Time complexity:
O(n*amount)

Space complexity:
O(n*amount) + stackspace of n

Code
class Solution {
public:
    int help(int pos, int amount, vector<int>& coins,vector<vector<int>>& dp)
    {
        if(amount == 0 )return 1;
        if(pos == 0 )
        {
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
