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

//SOLUTION 1 IDEA
        /*
        idea->  if prices[i]<current buy then curr.buy=prices[i] and also current          sell=prices[i]
        else if current sell <prices[i] then current sell=prices[i]
        
        in simple english if while traversing the array and current price[i] is greater less than the current buy value then we will update both current buy and current sell value
otherwise if current sell value is less than current price[i] then we will update the current sell value.
        */
class Solution {
    //SOLUTION 2
private:
    int concise_sol(vector<int> & prices)
    {
        /*
            approach
            eg 16 7 1 2 14 0 12 
            the idea here is if we compare the profit of all the arrays values we will get the best profit 
            for eg if we sell at 12 then we are supposed to buy at the lowest on the any of the previous day. 12 - 0 = profit = 12
            if we sell at 14 we have to buy at lowest among the previous days of 14 which is 1 since min (16,7,1,2)
            using the same concept to maximize the profit
        */
        //initially taking min as a[0] and profit as 0 since if we buy and sell at the same day
        int min_val = prices[0];
        int profit = 0;
        int arr_size = prices.size();
        for(int i=1;i<arr_size; i++)
        {
            //comparing the maximum profit we got for current element with the earlier profit to maximize the profit
            profit = max(prices[i]-min_val, profit);
            //min will be updated since the current element can be lower the previous min
            min_val = min(min_val , prices[i]);
        }
        return profit;
    }
public:
    
    int maxProfit(vector<int>& prices) {

        //calling solution 2
        return concise_sol(prices);



        //SOLUTION 1


        //base case for size zero array
        
        // if (prices.size()==0 || prices.size()==1) return 0;
        // else 
        // {
        //     int current_buy=prices[0];
        //     int current_sell=prices[0];
        //     int latest_buy=prices[0];
        //     int latest_sell=prices[0];
        //     int vec_length=prices.size();
        //     int current_profit=0;
        //     for(int i=1;i<vec_length;i++)
        //     {
        //         if(prices[i]<latest_buy)
        //         {
        //             latest_buy=prices[i];
        //             latest_sell=prices[i];
        //         }
        //         else if(prices[i]>latest_sell)
        //         {
        //             latest_sell=prices[i];
        //         }
        //         if(latest_sell-latest_buy>=current_profit)
        //         {
        //             current_profit=latest_sell-latest_buy;
        //             current_sell=latest_sell;
        //             current_buy=latest_buy;
        //         }
        //     }
        //     return current_profit;
        // }
    }
};
