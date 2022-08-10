        /*
        idea->  if prices[i]<current buy then curr.buy=prices[i] and also current          sell=prices[i]
        else if current sell <prices[i] then current sell=prices[i]
        *current_buy and current_sell are to be updated when the latest profit i.e latest_sell-latest_buy > current profit;
    
        in simple english if while traversing the array and current price[i] is  less than the latest buy value then we will update both latest_buy and latest_sell value
otherwise if latest_sell value is less than current price[i] then we will update the current sell value. and we will find the current profit by latest_sell-latest_buy and 
if it greater then the current_profit then only we will update 
** important note we can rename the CURRENT to FINAL for better understanding
        */

class Solution {
public:
    int maxProfit(vector<int>& prices) {
        //base case for size zero array
        if (prices.size()==0 || prices.size()==1) return 0;
        else 
        {
            int current_buy=prices[0];
            int current_sell=prices[0];
            int latest_buy=prices[0];
            int latest_sell=prices[0];
            int vec_length=prices.size();
            int current_profit=0;
            for(int i=1;i<vec_length;i++)
            {
                if(prices[i]<latest_buy)
                {
                    latest_buy=prices[i];
                    latest_sell=prices[i];
                }
                else if(prices[i]>latest_sell)
                {
                    latest_sell=prices[i];
                }
                if(latest_sell-latest_buy>=current_profit)
                {
                    current_profit=latest_sell-latest_buy;
                    current_sell=latest_sell;
                    current_buy=latest_buy;
                }
            }
            return current_profit;
        }
    }
};
