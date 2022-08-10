        /*
        idea->  if prices[i]<current buy then curr.buy=prices[i] and also current          sell=prices[i]
        else if current sell <prices[i] then current sell=prices[i]
        *current_buy and current_sell are to be updated when the latest profit i.e latest_sell-latest_buy > current profit;
    
        in simple english if while traversing the array and current price[i] is  less than the latest buy value then we will update both latest_buy and latest_sell value
otherwise if latest_sell value is less than current price[i] then we will update the current sell value. and we will find the current profit by latest_sell-latest_buy and 
if it greater then the current_profit then only we will update 
** important note we can rename the CURRENT to FINAL for better understanding
        */


/*
--------------------
                                SOLUTION FROM OTHER PEOPLE
    
    So, if buy at 7 & sell at any time in the future, we'll face loss. Because buying price is way higher then selling price available we have

Now, I have seen a dip & I buy at 1 & sell at 5 my overall profit will be 5 - 1 = 4

But what if, I had buy at 1 & sell at 6 my profit will be 6 - 1 = 5. Which is greater then my overall profit. So, i will update my overall profit with new value.

Now we have done as further we don't have any higher point to sell. We will return our answer.

I hope now question, approach is absolute clear.

code each line explained : Similar for C++, Java

{
        int lsf = Integer.MAX_VALUE; // least so far
        int op = 0; // overall profit
        int pist = 0; // profit if sold today
        
        for(int i = 0; i < prices.length; i++){
            if(prices[i] < lsf){ // if we found new buy value which is more smaller then previous one
                lsf = prices[i]; // update our least so far
            }
            pist = prices[i] - lsf; // calculating profit if sold today by, Buy - sell
            if(op < pist){ // if pist is more then our previous overall profit
                op = pist; // update overall profit
            }
        }
        return op; // return op 
                         
                         
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
