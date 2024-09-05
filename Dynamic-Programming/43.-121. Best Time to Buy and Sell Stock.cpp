class Solution {
public:
    /*  
        BOTH SOLUTION 1 AND 2 ARE SAME JUST ONE START FROM LAST AND ONE FROM BEGINNING I.E ONE TRIES TO SELL AT MAXIMUM AND SOLUTION 2 TRYING TO BUY AT MINIMUM
        in this solution we are starting from the end , assuming that we are going to sell , if current price is less than maximum till now we try to maximum of profit , else we just calculate the maximum sell price till now
    */

    //------ solution 1
    int maxProfit(vector<int>& prices) {
        int n = prices.size();
        if(n == 1)return 0;
        vector<int> sell_price(n);
        sell_price[n-1] = prices[n-1];
        int max_i = sell_price[n-1];
        int max_profit = 0;
        for(int i = n-2; i>-1; i--){
            if(max_i>prices[i]){ 
                max_profit = max(max_profit, max_i-prices[i]);
            }
            max_i = max(max_i, prices[i]);
        }
        return max_profit;
    }

    

    /*
        in below approach we are trying to buy at minimum and maximizing the profit 
    */
    //---------- solution 2
    int maxProfit(vector<int>& prices){
        int n = prices.size();
        if(n == 1)return 0;
        int min_buy = prices[0];
        int max_profit = 0;
        for(int i = 1; i < n; i++){
            if(prices[i]> min_buy){
                int current_profit = prices[i] - min_buy;
                max_profit = max(max_profit, current_profit);
            }
            //here we are trying to minimize the current buy price 
            min_buy = min(min_buy, prices[i]);
        }
        return max_profit;
    }
};
