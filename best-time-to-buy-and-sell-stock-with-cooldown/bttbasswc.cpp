class Solution {
private:
    /*
        approach is same as Best Time to Buy and Sell Stock-ii
        just few changes
        since a cool down required after selling hence added skipped a day after selling recursive_sol(day+2,1,prices, dp);
        and since the base cases may go above prices.size() hence instead of day = prices.size() made day >= prices.size()
    */
     int recursive_sol(int day , bool buy , vector<int>& prices, vector<vector<int>>& dp)
    {
        //base cases
        //if we have explored all the possibilites on all the days then return 0 after exploring all days
        if(day >= prices.size())return 0;


        //checking if already solved
        if(dp[day][buy] != -1 )return dp[day][buy];
        //normal cases
        //if buy var value is 1 we will buy on that day or we don't buy and decide to buy on another day
        
        if(buy)
        {
        //since we buyed today we won't buy next day
        int buy_today =  -prices[day] + recursive_sol(day+1,0,prices, dp);
        //we didn't buy today and we have possibility to buy another day
        int not_buy_today = 0 + recursive_sol(day+1,1,prices, dp);
        return dp[day][buy] = max(buy_today,not_buy_today);
        }
        //if we don't buy then we can sell today
        else
        {
            //here skipping a day for cooldown after selling the stock
            int sell_today = prices[day] + recursive_sol(day+2,1,prices, dp);
            int not_sell_today = 0 + recursive_sol(day+1,0,prices,dp);
            return dp[day][buy] =  max(sell_today,not_sell_today);
        }
        
    }
public:
    int maxProfit(vector<int>& prices) {
        vector<vector<int>> dp(prices.size(),vector<int>(2,-1));
        return recursive_sol(0,1,prices,dp);
    }
};
