class Solution {
public:
    int recursive_sol(int day , bool buy ,int rem_transac, vector<int>& prices,vector<vector<vector<int>>>& dp)
    {
        if(rem_transac==0)return 0;
        if(day == prices.size())return 0;


        //checking if already solved
        if(dp[day][buy][rem_transac] != -1 )return dp[day][buy][rem_transac];
        //normal cases
        //if buy var value is 1 we will buy on that day or we don't buy and decide to buy on another day
        
        if(buy)
        {
            {
                //since we buyed today we won't buy next day
                int buy_today =  -prices[day] + recursive_sol(day+1,0,rem_transac,prices,dp);
                //we didn't buy today and we have possibility to buy another day
                int not_buy_today = 0 + recursive_sol(day+1,1,rem_transac,prices,dp);
                return dp[day][buy][rem_transac] = max(buy_today,not_buy_today);

            }
        }
        //if we don't buy then we can sell today
        else
        {
            //if we sell today we can buy next or further day this below recursion will send the call to above buy if 
            int sell_today = prices[day] + recursive_sol(day+1,1,rem_transac-1,prices,dp);
            int not_sell_today = 0 + recursive_sol(day+1,0,rem_transac,prices,dp);
            return dp[day][buy][rem_transac] =  max(sell_today,not_sell_today);
        }

        //see the tabulation approach in best-time-to-buy-and-sell-stock-ii
    }      
    int maxProfit(int k, vector<int>& prices) {
        vector<vector<vector<int>>> dp(prices.size(),vector<vector<int>>(2,vector<int>(k+1,-1)));
        return recursive_sol(0,1,k,prices,dp);
    }
};
